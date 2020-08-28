#pragma once 

namespace math
{
    template<typename T>
    T ntohl(const T& input)
    {
        size_t size = sizeof(T);
        uint8_t* data = (uint8_t*)alloca(size);
        for (int i = 0; i < size; i++)data[i] = input >> (size - i - 1) * 8;
        return  *(T*)data;
    }
}

