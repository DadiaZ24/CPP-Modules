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

AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *
Intern::makeForm(const std::string &formName, const std::string &target)
{
    struct FormStruct
    {
        std::string name;
        AForm *(*create)(const std::string &);
    };

    static const FormStruct forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    std::cout << "Intern: Error! Form name '" << formName << "' does not exist." << std::endl;
    throw AForm::FormCreationException();
}
