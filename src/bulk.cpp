/**
\file
\brief Реализация приложения bulk

Основной файл-сценарий приложения bulk. 
*/
#include "bulk.h"
#include <string>

void blk::Bulk::start(const int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Version of bulk is " << blk::version() << "\t It requires parameter N in command line to start." << std::endl;
        return;
    }
    int n;
    try
    {
        n = std::stoi(std::string(argv[1]));
    }
    catch (const std::exception &e)
    {
        std::cerr << "Version of bulk is " << blk::version() << "\t Cannot convert command line parameter to integer. " << '\n';
        return;
    }
    ready = true;

    auto reader = std::make_shared<blk::Reader>(std::cin, n);
    auto speaker = std::make_shared<blk::Speaker>(reader, std::cout);
    auto writer = std::make_shared<blk::Writer>(reader, std::string(default_subdir));

    started = true;
    reader->act();
}

