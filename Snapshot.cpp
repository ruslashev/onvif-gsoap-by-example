#include <stdarg.h>  // For va_start, etc.
#include <memory>    // For std::unique_ptr
#include <ctime>
#include <cstring>	// For strcpy
#include <sstream>	// For stringstream
#include <sys/stat.h>
#include "Snapshot.hpp"

Snapshot::Snapshot(std::string path, std::string name)
{
    _snapshotPath = path;
    _snapshotName = name;
}

Snapshot::~Snapshot(void)
{
    this->deleteFromDisk();
}

size_t Snapshot::saveLocally(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

void Snapshot::deleteFromDisk(void)
{
    std::string deleteCmd = "rm " + _snapshotPath + "/" + _snapshotName;

    system(deleteCmd.c_str());
}

CURLcode Snapshot::download(const std::string downloadUri)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char const *url = downloadUri.c_str();
    std::string outfilename_str = _snapshotPath + "/" + _snapshotName;
    char outfilename[FILENAME_MAX];

    std::strcpy(outfilename, outfilename_str.c_str());

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

