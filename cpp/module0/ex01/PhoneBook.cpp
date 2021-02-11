#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contactsQuantity = 0;
}

void PhoneBook::DisplayContactInfo(Contact contact)
{
    std::cout << "\033[1m\033[34m" << contact.firstName << "\n";
    std::cout << contact.lastName << "\n";
    std::cout << contact.nickname << "\n";
    std::cout << contact.login << "\n";
    std::cout << contact.postalAddress << "\n";
    std::cout << contact.emailAddress << "\n";
    std::cout << contact.phoneNumber << "\n";
    std::cout << contact.birthdayDate << "\n";
    std::cout << contact.favoriteMeal << "\n";
    std::cout << contact.underwearColor << "\n";
    std::cout << contact.darkestSecret << "\n" << "\033[0m";
}

void PhoneBook::DisplayAllContacts()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    for (int i = 0; i < this->contactsQuantity; i++){
        if (this->contacts[i].firstName.length() > 10)
        {
            firstName = this->contacts[i].firstName.substr(0, 9);
            firstName.append(1, '.');
        }
        else
            firstName = this->contacts[i].firstName;
        if (this->contacts[i].lastName.length() > 10)
        {
            lastName = this->contacts[i].lastName.substr(0, 9);
            lastName.append(1, '.');
        }
        else
            lastName = this->contacts[i].lastName;
        if (this->contacts[i].nickname.length() > 10)
        {
            nickname = this->contacts[i].nickname.substr(0, 9);
            nickname.append(1, '.');
        }
        else
            nickname = this->contacts[i].nickname;
        std::cout << "\033[1m\033[35m" << std::string(9, ' ') << i << '|'
        << std::string(10 - firstName.length(), ' ')
        << firstName << '|' 
        << std::string(10 - lastName.length(), ' ')
        << lastName << '|'
        << std::string(10 - nickname.length(), ' ')
        << nickname << "\033[0m" << "\n";
    }
}

void PhoneBook::SearchCommand()
{
    int id;
    DisplayAllContacts();
    std::cout << "\033[32m" << "Choose what contact show you" << "\033[37m" << "\n";
    std::cin >> id;
    while(std::cin.fail()) {
        std::cout << "\033[31m" << "Unvaliable contact index, input again" << "\033[37m" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> id;
    }
    if (id < 0 || id >= this->contactsQuantity || id > 7)
    {
        std::cout << "\033[31m" << "No such contact\n" << "\033[37m";
    }
    else
        DisplayContactInfo(this->contacts[id]);
}

std::string PhoneBook::InputFieldInfo(std::string fieldName)
{
    std::string value;
    std::cout << "\033[33m" "Enter Contact " << fieldName << "\033[37m" << "\n";
    std::cin >> value;
    return (value);
}

void PhoneBook::ChangeContactInformation (int id)
{
    this->contacts[id].firstName = InputFieldInfo("First Name");
    this->contacts[id].lastName = InputFieldInfo("Last Name");
    this->contacts[id].nickname = InputFieldInfo("Nickname");
    this->contacts[id].login = InputFieldInfo("Login");
    this->contacts[id].postalAddress = InputFieldInfo("Postal Address");
    this->contacts[id].emailAddress = InputFieldInfo("Email Address");
    this->contacts[id].phoneNumber = InputFieldInfo("Phone Number");
    this->contacts[id].birthdayDate = InputFieldInfo("Birthday Date");
    this->contacts[id].favoriteMeal = InputFieldInfo("Favorite Meal");
    this->contacts[id].underwearColor = InputFieldInfo("Underwear Color");
    this->contacts[id].darkestSecret = InputFieldInfo("Darkest secret");
}

void PhoneBook::AddCommand()
{
    if (this->contactsQuantity > 7)
        std::cout << "Not enough space to add another contact\n";
    else
    {
        this->ChangeContactInformation(contactsQuantity);
        contactsQuantity++;
    }
}