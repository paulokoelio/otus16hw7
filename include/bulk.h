/**
\file
\brief Заголовочный файл общий для приложения bulk

Заголовочный файл с подключением всех остальных заголовочных файлов, 
необходимых для компиляции bulk.
*/
#ifndef BULK_H_
#define BULK_H_

#include "Reader.h"
#include "Speaker.h"
#include "Writer.h"
#include "version.h"
#include <string>
#include <vector>

namespace blk
{

constexpr char default_subdir[]{"./log/"};

class Bulk
{
private:
    bool ready;
    bool started;

public:
    Bulk() : ready(false), started(false) {}
    Bulk(const Bulk &x) = delete;
    Bulk(Bulk &&x) = delete;
    ~Bulk() = default;
    Bulk &operator=(const Bulk &x) = delete;
    Bulk &operator=(Bulk &&x) = delete;

    void start(const int argc, const char **argv);
};

} // namespace blk

#endif /* BULK_H_ */

