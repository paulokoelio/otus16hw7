#include "Writer.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <fstream>

namespace blk
{

Writer::Writer(std::shared_ptr<iPublisher> publ, std::string subdir) : publisher(publ), subdirectory(subdir)
{
    if (!publisher) {
        throw std::invalid_argument("Writer object cannot subscribe to nullptr.");
        return;
    }
    if ( ! std::filesystem::exists(subdirectory) && (! subdirectory.has_filename()) ) 
    {
        try
        {
            std::filesystem::create_directories(subdirectory);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Writer object cannot create subdirectory during construction" << '\n';
            throw;
        }
    } 
    if (subdirectory.has_filename()) throw std::invalid_argument("Writer constructor: subdirectory seems to be a filename");
    
    publisher->subsribe(this);
}

Writer::~Writer() 
{
    publisher->unsubsribe(this);
}

void Writer::update(const unsigned long long &n_timestamp, sp_str_buffer_t n_buffer)
{
    const std::string name(prefix + std::to_string(n_timestamp) + extension);
    const std::filesystem::path file_out = subdirectory / name ;  
    std::ofstream sout(file_out.native());
    if (!sout.is_open()) throw std::runtime_error("Writer object cannot create new log file") ;
    sout << output_policy(n_buffer);
}

} // namespace blk

