#include "Caster.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "argument error\n";
        return 1;
    }
    Caster caster(argv[1]);
    std::cout << "char: "  << caster.getCharString() << std::endl;
    std::cout << "int: " << caster.getIntString() << std::endl;
    std::cout <<  "float: " << caster.getFloatString() << std::endl;
    std::cout << "double: " << caster.getDoubleString() << std::endl;
}