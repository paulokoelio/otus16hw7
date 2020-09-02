#ifndef SPEAKER_H_
#define SPEAKER_H_

#include "iPublisher.h"
#include <iostream>

namespace blk
{

class Speaker : public iSubscriber
{
private:
    std::shared_ptr<iPublisher> publisher;
    std::ostream &m_out;

public:
    Speaker(std::shared_ptr<iPublisher> publ, std::ostream &sout);
    virtual ~Speaker();
    virtual void update(const unsigned long long &n_timestamp, sp_str_buffer_t n_buffer) override;

    Speaker(const Speaker &x) = delete;
    Speaker(Speaker &&x) = delete;
    Speaker &operator=(const Speaker &x) = delete;
    Speaker &operator=(Speaker &&x) = delete;
};

} // namespace blk

#endif /* SPEAKER_H_ */

