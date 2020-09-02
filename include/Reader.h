#ifndef READER_H_
#define READER_H_

#include "iPublisher.h"
#include <ctime>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <vector>

namespace blk
{

class Reader : public iPublisher
{

private:
    sp_str_buffer_t sp_str_buffer;
    std::set<iSubscriber *> subscribers;
    std::istream &m_cin;
    int m_N;
    int counter;
    unsigned long long timestamp;

    std::list<std::string> read_block();
    void clear();

public:
    Reader(std::istream &cin, int N) : sp_str_buffer(std::make_shared<str_buffer_t>()), subscribers({}), m_cin(cin), m_N(N), counter(0)
    {
        sp_str_buffer->reserve(N);
    }
    Reader(const Reader &x) = delete;
    Reader(Reader &&x) = delete;
    virtual ~Reader() = default;
    Reader &operator=(const Reader &x) = delete;
    Reader &operator=(Reader &&x) = delete;

    virtual void subsribe(iSubscriber *new_subscriber) override;
    virtual void unsubsribe(iSubscriber *del_subscriber) override;
    void act();
};

} // namespace blk

#endif /* READER_H_ */

