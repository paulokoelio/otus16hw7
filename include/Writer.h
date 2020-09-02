#ifndef WRITER_H_
#define WRITER_H_

#include "iPublisher.h"
#include <iostream>
#include <filesystem>
#include <string>

namespace blk
{

class Writer : public iSubscriber
{
private: 
    std::shared_ptr<iPublisher> publisher;
    std::filesystem::path subdirectory;
public:
    Writer(std::shared_ptr<iPublisher> publ, std::string subdir);
    virtual ~Writer() ;
    virtual void update(const unsigned long long & n_timestamp, sp_str_buffer_t n_buffer) override ;
    static constexpr char prefix[]{"bulk"};
    static constexpr char extension[]{".log"};

    Writer(const Writer &x) = delete;
    Writer(Writer &&x) = delete;
    Writer &operator=(const Writer &x) = delete;
    Writer &operator=(Writer &&x) = delete;
};

} // namespace blk

#endif /* WRITER_H_ */

