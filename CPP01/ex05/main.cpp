#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("WARNING");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("ERROR");

    return 0;
}