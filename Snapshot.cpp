#include <stdarg.h>  // For va_start, etc.
#include <memory>    // For std::unique_ptr
#include <ctime>
#include <cstring>	// For strcpy
#include <sstream>	// For stringstream
#include <sys/stat.h>
#include "Snapshot.hpp"

std::string string_format(const std::string fmt_str, ...)
{
    int final_n, n = ((int)fmt_str.size()) * 2;
    std::string str;
    std::unique_ptr<char[]> formatted;
    va_list ap;

    while (1) {
        formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
        std::strcpy(&formatted[0], fmt_str.c_str());

        va_start(ap, fmt_str);
        final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);

        if (final_n < 0 || final_n >= n)
            n += abs(final_n - n + 1);
        else
            break;
    }

    return std::string(formatted.get());
}

std::string formattedTimeStamp(void)
{
    std::stringstream timeStampString;
    char timeBuf [80];

    std::time_t result = std::time(nullptr);
    struct tm* now = std::localtime(&result);
    std::strftime(timeBuf, 80, "%Y-%m-%d-%H-%M-%S", now);

    timeStampString << timeBuf;

    return timeStampString.str();
}

Snapshot::Snapshot(std::string path, std::string name)
{
    _timeCreated = formattedTimeStamp();
    _snapshotPath = path;
    _snapshotName = name;
}

Snapshot::~Snapshot(void)
{
    this->deleteFromDisk();
}

std::string Snapshot::getDownloadUri(const std::string snapshotUri)
{
    return string_format("curl --create-dirs -o %s %s", this->_snapshotName.c_str(), snapshotUri.c_str());
}

std::string Snapshot::getUploadUri(const std::string ftpIP, const std::string ftpUser,
        const std::string ftpPwd)
{
    return string_format("curl -C - --ftp-create-dirs -u %s:%s -T %s/%s ftp://%s/",
            ftpUser.c_str(),
            ftpPwd.c_str(),
            this->_snapshotPath.c_str(),
            this->_snapshotName.c_str(),
            ftpIP.c_str());
}

size_t Snapshot::saveLocally(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

void Snapshot::deleteFromDisk(void)
{
    std::string deleteCmd = string_format("rm %s/%s", this->_snapshotPath.c_str(),
            this->_snapshotName.c_str());

    system(deleteCmd.c_str());
}

CURLcode Snapshot::download(const std::string downloadUri)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char const *url = downloadUri.c_str();
    char outfilename[FILENAME_MAX];

    std::strcpy(outfilename, string_format("%s/%s", this->_snapshotPath.c_str(), this->_snapshotName.c_str()).c_str());

    char error[CURL_ERROR_SIZE] = "";
    int timeoutSeconds = 10;

    curl = curl_easy_init();

    if (curl) {
        struct stat st = { 0 };
        if (stat(this->_snapshotPath.c_str(), &st) == -1) {
            mkdir(this->_snapshotPath.c_str(), 0700);
        }

        fp = fopen(outfilename, "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER , error);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT , timeoutSeconds);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Snapshot::saveLocally);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        if (res) {
            printf("Error: %s\n", error);
        }

        curl_easy_cleanup(curl);

        fclose(fp);
    }
    // else {
    //     return -1;
    // }

    return res;
}

