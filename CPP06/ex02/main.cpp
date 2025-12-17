#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

int main()
{
    std::srand(std::time(0)); 

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "\n[Deneme " << i + 1 << "]" << std::endl;
        Base *random_ptr = generate();

        if (random_ptr == NULL)
        {
            std::cerr << "HATA: generate() NULL döndürdü." << std::endl;
            continue;
        }

        identify(random_ptr);
        identify(*random_ptr);
        
        delete random_ptr;
    }

    A a_obj;
    std::cout << "\n[Sınıf A Kontrolü]" << std::endl;
    identify(&a_obj);
    identify(a_obj);
    
    B b_obj;
    std::cout << "\n[Sınıf B Kontrolü]" << std::endl;
    identify(&b_obj);
    identify(b_obj);

    C c_obj;
    std::cout << "\n[Sınıf C Kontrolü]" << std::endl;
    identify(&c_obj);
    identify(c_obj);

    std::cout << "\n===========================================" << std::endl;
    std::cout << "Tüm testler tamamlandı." << std::endl;
    std::cout << "===========================================" << std::endl;

    return 0;
}
