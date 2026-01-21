#include <iostream>
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"

int main()
{
    {
        std::cout << TITLE << "Test 1" << RESET << std::endl;
        std::cout << TITLE << "Failed Tests" << RESET << std::endl;
        Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 150);
        std::cout << *bureaucrat << std::endl;
        ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
        std::cout << *shrubbery << std::endl;
        bureaucrat->signForm(*shrubbery);
        bureaucrat->executeForm(*shrubbery);
        RobotomyRequestForm *robotomy = new RobotomyRequestForm("Home");
        std::cout << *robotomy << std::endl;
        bureaucrat->signForm(*robotomy);
        bureaucrat->executeForm(*robotomy);
        PresidentialPardonForm *presidential = new PresidentialPardonForm("Home");
        std::cout << *presidential << std::endl;
        bureaucrat->signForm(*presidential);
        bureaucrat->executeForm(*presidential);
        delete bureaucrat;
        delete shrubbery;
        delete robotomy;
        delete presidential;
        std::cout << std::endl;
    }
    {
        std::cout << TITLE << "------Test 2------" << std::endl;
        std::cout << "------Sucessuful Test------" << RESET << std::endl;
        Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 1);
        std::cout << *bureaucrat << std::endl;
        ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
        std::cout << *shrubbery << std::endl;
        bureaucrat->signForm(*shrubbery);
        bureaucrat->executeForm(*shrubbery);
        RobotomyRequestForm *robotomy = new RobotomyRequestForm("Robocop");
        std::cout << *robotomy << std::endl;
        bureaucrat->signForm(*robotomy);
        bureaucrat->executeForm(*robotomy); // 50% chance of success
        PresidentialPardonForm *presidential = new PresidentialPardonForm("Emilio");
        std::cout << *presidential << std::endl;
        bureaucrat->signForm(*presidential);
        bureaucrat->executeForm(*presidential);
        delete bureaucrat;
        delete shrubbery;
        delete robotomy;
        delete presidential;
        std::cout << std::endl;
    }
    return 0;
}
