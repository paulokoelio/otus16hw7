#ifndef LIB_H_
#define LIB_H_

#include <chrono>
#include <iostream>

namespace slvr
{

namespace lib
{

/**
Вспомогательная функция, возвращающая значение непрерывного счетчика времени
в микросекундах в момент ее вызова.
*/
unsigned long long fixed_time_in_usec();

/**
Шаблонная вспомогательная функция, выводит содержимое контейнера @container 
в одну строку используя разделитель @delimiter и оператор <<.
\param[in] container    ссылка на контейнер, элементы которого будут выводиться
\param[in] delimiter    разделитель между элементами контейнера
\param[out] new_out     объект типа std::ostream в который будет осуществлен вывод контейнера
*/
template<class T>
std::ostream & print_container(const T & container, const std::string delimiter = std::string(", "), std::ostream & new_out = std::cout )
{
    if (container.cbegin() == container.cend()) return new_out;
    auto it = container.cbegin();
    new_out << *it;
    ++it;
    for (;it != container.cend(); ++it) new_out << delimiter << *it;
    new_out << '\n';
    return new_out;
}

/**
Шаблонная вспомогательная функция, выводит содержимое контейнера @container 
в одну строку используя разделитель @delimiter и оператор <<.
\param[in] container    указатель на контейнер, элементы которого будут выводиться
\param[in] delimiter    разделитель между элементами контейнера
\param[out] new_out     объект типа std::ostream в который будет осуществлен вывод контейнера
*/
template<class T>
std::ostream & print_container( T * container, const std::string delimiter = std::string(", "), std::ostream & new_out = std::cout )
{
    if (container->cbegin() == container->cend()) return new_out;
    auto it = container->cbegin();
    new_out << *it;
    ++it;
    for (;it != container->cend(); ++it) new_out << delimiter << *it;
    new_out << '\n';
    return new_out;
}

} // namespace lib

} // namespace slvr

#endif /* LIB_H_ */
