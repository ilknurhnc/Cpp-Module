#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <cstdlib>

template <typename Type>
class Array
{
    private:
        Type* data;
        unsigned int count;

    public:
        Array() : data(NULL), count(0) {}
        Array(unsigned int n) : count(n)
        {
            data = new Type[n](); 
        }

        Array(const Array& src) : count(src.count)
        {
            data = new Type[count];
            for(unsigned int i = 0; i < count; ++i)
                data[i] = src.data[i];
        }

        Array& operator=(const Array& src)
        {
            if (this != &src)
            {
                delete[] data;
                count = src.count;
            
                if (count > 0)
                {
                    data = new Type[count];
                    for (unsigned int i = 0; i < count; ++i)
                        data[i] = src.data[i];
                } 
                else
                    data = NULL;
            }
            return *this;
        }

        ~Array() {delete[] data;}

        Type& operator[](unsigned int i)
        {
            if (i >= count)
                throw std::out_of_range("Index out of bounds");
            return data[i];
        }
    
        const Type& operator[](unsigned int i) const
        {
            if (i >= count)
                throw std::out_of_range("Index out of bounds");
            return data[i];
        }

        unsigned int size() const {
            return count;
        }
};

#endif