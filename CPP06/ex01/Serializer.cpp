#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer& other)
{
    (void)other;
}
Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other; return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    std::cout << "Serializer: Data* (Original Address) is cast to uintptr_t." << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    std::cout << "Serializer: uintptr_t is cast back to Data*." << std::endl;
    return reinterpret_cast<Data*>(raw);
}