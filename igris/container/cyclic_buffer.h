#ifndef RALGO_CYCLIC_BUFFER_H
#define RALGO_CYCLIC_BUFFER_H

#include <igris/datastruct/ring_counter.h>
#include <igris/container/unbounded_array.h>

namespace igris
{
    template <class T, class Alloc=std::allocator<T>> class cyclic_buffer
    {
    public:
        igris::unbounded_array<T,Alloc> data;
        ring_counter counter;

        cyclic_buffer(size_t size) : data(size)
        {
            ring_counter_init(&counter, size);
        }

        size_t size() 
        { 
            return counter.size; 
        }

        T push(T val)
        {
            ring_counter_increment(&counter, 1);
            T ret = data[ring_counter_get(&counter)];
            data[ring_counter_get(&counter)] = val;
            return ret;
        }

        /// Получить элемент z*i, где z - дискретный оператор.
        /// 0 - последний, 1 - предпоследний
        // и так далее
        T operator[](int i) { return data[ring_counter_prev(&counter, i)]; }
    };
}

#endif
