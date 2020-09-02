#ifndef IPUBLISHER_H_
#define IPUBLISHER_H_

#include <memory>
#include <vector>
#include <string>
#include "lib.h"

namespace blk
{

using str_buffer_t = std::vector<std::string>;
using sp_str_buffer_t = std::shared_ptr<str_buffer_t>;

class iSubscriber
{
public:
    virtual ~iSubscriber() = default;
    virtual void update(const unsigned long long & n_timestamp, sp_str_buffer_t n_buffer) = 0;
};

class iPublisher
{
public:
    virtual ~iPublisher() = default;
    virtual void subsribe(iSubscriber* new_subscriber) = 0;
    virtual void unsubsribe(iSubscriber* del_subscriber ) = 0;    
};

std::string output_policy(const sp_str_buffer_t in_buf);

} // namespace blk

#endif /* IPUBLISHER_H_ */

