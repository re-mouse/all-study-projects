#include <iostream>
#include "PhoneBook.hpp"

int main(){
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "\033[32m" << "ADD SEARCH EXIT\n" << "\033[37m";
        std::cin >> command;
        if (command == "ADD")
            phonebook.AddCommand();
        else if (command == "SEARCH")
            phonebook.SearchCommand();
        else if (command == "EXIT")
            break;
        else
            std::cout << "\033[31m" << "Unknown command\n" << "\033[37m";
    }
}