#pragma once

#include <mbgl/storage/file_source.hpp>

namespace mbgl {

namespace util {
template <typename T> class Thread;
} // namespace util

class MaptilerFileSource : public FileSource {
public:
    MaptilerFileSource();
    ~MaptilerFileSource() override;

    std::unique_ptr<AsyncRequest> request(const Resource&, Callback) override;
    bool canRequest(const Resource&) const override;

private:
    class Impl;
    std::unique_ptr<util::Thread<Impl>> impl;
};

} // namespace mbgl
