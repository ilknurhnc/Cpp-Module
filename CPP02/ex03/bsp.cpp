#include "Point.hpp"

static Fixed area(Point const &a, Point const &b, Point const &c) {
    // determinant Formülü: |Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)| / 2
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getY() - a.getY()) +
                  c.getX() * (a.getY() - b.getY()));
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return area / Fixed(2);
}


bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed total = area(a, b, c);                // Üçgenin alanı
    Fixed t1 = area(point, a, b);               // Alt üçgen 1
    Fixed t2 = area(point, b, c);               // Alt üçgen 2
    Fixed t3 = area(point, c, a);               // Alt üçgen 3

    // Kenar üzerinde veya köşedeyse: False
    if (t1 == Fixed(0) || t2 == Fixed(0) || t3 == Fixed(0))
        return false;

    // Alan toplamı üçgenin alanına eşitse içeridedir
    return (t1 + t2 + t3 == total);
}
