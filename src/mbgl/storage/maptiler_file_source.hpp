#include <mbgl/storage/file_source.hpp>
#include <mbgl/util/logging.hpp>
#include <mbgl/util/thread.hpp>

#ifndef MBGL_MAPTILER_FILE_SOURCE_H
#define MBGL_MAPTILER_FILE_SOURCE_H

namespace mbgl {
    // File source for supporting .mbtiles maps.
    // can only load resource URLS that are absolute paths to local files
    class MaptilerFileSource : public FileSource {
    public:
        MaptilerFileSource();

        ~MaptilerFileSource() override;

        std::unique_ptr <AsyncRequest> request(const Resource &, Callback) override;

        static bool acceptsURL(const std::string &url);

    private:
        class Impl;

        std::unique_ptr <util::Thread<Impl>> thread;
    };

} // namespace mbgl


#endif //MBGL_MAPTILER_FILE_SOURCE_H