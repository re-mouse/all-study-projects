#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        void AddCommand();
        void SearchCommand();
        void DisplayContactInfo(Contact cont);
        std::string InputFieldInfo(std::string fieildName);
        void ChangeContactInformation(int id);
        void DisplayAllContacts();
    private:
        Contact contacts[8];
        int     contactsQuantity;
};

#endif