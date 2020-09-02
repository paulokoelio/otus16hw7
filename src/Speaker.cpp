#include "Speaker.h"
#include <exception>
#include <iostream>
#include <stdexcept>

namespace blk
{

Speaker::Speaker(std::shared_ptr<iPublisher> publ, std::ostream &sout) : publisher(publ), m_out(sout)
{
    if (!publisher)
    {
        throw std::invalid_argument("Speaker object cannot subscribe to nullptr.");
        return;
    }
    publisher->subsribe(this);
}

Speaker::~Speaker()
{
    publisher->unsubsribe(this);
}

void Speaker::update(const unsigned long long &n_timestamp, sp_str_buffer_t n_buffer)
{
    m_out << output_policy(n_buffer);
    (void)n_timestamp; // для устранения предупреждения о неиспользуемой переменной
}

} // namespace blk

