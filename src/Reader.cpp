#include "Reader.h"
#include "lib.h"
#include <chrono>
#include <list>
#include <string>

void blk::Reader::subsribe(iSubscriber *new_subscriber)
{
    if (new_subscriber) subscribers.insert(new_subscriber);
}

void blk::Reader::unsubsribe(iSubscriber *del_subscriber)
{
    subscribers.erase(del_subscriber);
}

std::list<std::string> blk::Reader::read_block()
{
    bool closed = false;
    std::list<std::string> res{};
    auto t0 = slvr::lib::fixed_time_in_usec();
    for (std::string line; std::getline(m_cin, line);)
    {
        if (line.compare("{") == 0)
        {
            res.splice(res.end(), read_block());
            continue;
        }
        if (line.compare("}") == 0)
        {
            closed = true;
            break;
        }
        res.push_back(line);
    }

    if (!closed)
        res.clear();
    else
        timestamp = t0;
    return res;
}

void blk::Reader::act()
{
    counter = 0;
    std::list<std::string> res{};
    for (std::string line; std::getline(m_cin, line);)
    {
        if (line.compare("{") == 0)
        {
            if (counter != 0) clear();
            res = read_block();
            if (res.size() != 0)
            {
                sp_str_buffer->insert(sp_str_buffer->end(), res.begin(), res.end());
                clear();
            }
            continue;
        }
        if (counter == 0) timestamp = slvr::lib::fixed_time_in_usec();
        sp_str_buffer->push_back(line);
        ++counter;
        if (counter >= m_N) clear();
    }
    if (counter) clear();
}

void blk::Reader::clear()
{
    for (auto el : subscribers)
        el->update(timestamp, sp_str_buffer);

    sp_str_buffer->clear();
    sp_str_buffer->reserve(m_N);
    counter = 0;
}

