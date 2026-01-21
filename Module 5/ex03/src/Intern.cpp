#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "[CLASS CALL] Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &)
{
    std::cout << "[CLASS CALL] Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "[CLASS CALL] Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &)
{
    std::cout << "[CLASS CALL] Intern assignment operator called" << std::endl;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    struct FormStruct
    {
        std::string name;
        AForm *(*create)(const std::string &);
    };

    static const FormStruct forms[] = {
        {"shrubbery creation", [](const std::string &t)
         { return static_cast<AForm *>(new ShrubberyCreationForm(t)); }},
        {"robotomy request", [](const std::string &t)
         { return static_cast<AForm *>(new RobotomyRequestForm(t)); }},
        {"presidential pardon", [](const std::string &t)
         { return static_cast<AForm *>(new PresidentialPardonForm(t)); }}};

    for (int i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    std::cout << "Intern: Error! Form name '" << formName << "' does not exist." << std::endl;
    return nullptr;
}
