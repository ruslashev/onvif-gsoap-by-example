#include <string>
#include <curl/curl.h>
#include <curl/easy.h>

class Snapshot {
    std::string _snapshotPath;
    std::string _snapshotName;
    std::string _timeCreated;

    static size_t saveLocally(void *ptr, size_t size, size_t nmemb, FILE *stream);
    void deleteFromDisk(void);

public:
    Snapshot(std::string path, std::string name);
    ~Snapshot(void);
    std::string getDownloadUri(const std::string snapshotUri);
    std::string getUploadUri(const std::string ftpIP, const std::string ftpUser, const std::string ftpPwd);
    CURLcode download(const std::string downloadUri);
};

