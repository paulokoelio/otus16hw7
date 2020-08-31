#include <memory>
#include <vector>
#include <sstream>
#include "lib.h"
#include "iPublisher.h"

namespace blk
{

std::string output_policy(const sp_str_buffer_t in_buf)
{
    std::string out;
    std::ostringstream sout;
    slvr::lib::print_container(in_buf.get(), ", ", sout);
    out = sout.str();
    out = " bulk: " + out;
    return out;
}

} // namespace blk

