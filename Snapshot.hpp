#include <string>
#include <curl/curl.h>
#include <curl/easy.h>

class Snapshot {
    std::string _snapshotPath;
    std::string _snapshotName;

    static size_t saveLocally(void *ptr, size_t size, size_t nmemb, FILE *stream);
    void deleteFromDisk(void);

public:
    Snapshot(std::string path, std::string name);
    ~Snapshot(void);
    CURLcode download(const std::string downloadUri);
};

