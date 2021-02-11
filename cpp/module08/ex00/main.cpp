#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(12);
    v.push_back(1245);
    v.push_back(412);
    for (int i = 0; i < (int)v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    std::cout << easyfind(v, 412);
}