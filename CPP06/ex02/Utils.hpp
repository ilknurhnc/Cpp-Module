#ifndef UTILS_HPP
# define UTILS_HPP

# include "Base.hpp" // Base sınıfını Base* ve Base& kullanabilmek için dahil et

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif