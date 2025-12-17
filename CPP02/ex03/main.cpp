#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    // Üçgenin köşeleri
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // Noktaları tanımlıyoruz
    Point p1(5, 5);    // Üçgenin içinde
    Point p2(5, 0);    // Kenarda
    Point p3(10, 10);  // Dışarıda

    // 1. Nokta
    if (bsp(a, b, c, p1))
        std::cout << "(5, 5) üçgenin İÇİNDE.\n";
    else
        std::cout << "(5, 5) üçgenin DIŞINDA.\n";

    // 2. Nokta
    if (bsp(a, b, c, p2))
        std::cout << "(5, 0) üçgenin İÇİNDE.\n";
    else
        std::cout << "(5, 0) üçgenin DIŞINDA.\n";

    // 3. Nokta
    if (bsp(a, b, c, p3))
        std::cout << "(10, 10) üçgenin İÇİNDE.\n";
    else
        std::cout << "(10, 10) üçgenin DIŞINDA.\n";

    return 0;
}
