/**
\file
\brief Реализация функции blk::version() для вывода версии решения ДЗ

Версия решения ДЗ может быть определена при вызове функции blk::version()
в коде программы, или при запуске приложения без параметров.
*/
#include "version.h"

namespace blk
{

    const char *version()
    {
        return PROJECT_VERSION;
    }

} // namespace blk

