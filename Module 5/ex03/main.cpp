#include <iostream>
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Intern.hpp"

int main()
{
    {
        std::cout << "---Test 1---" << std::endl;
        Intern someRandomIntern;
        AForm *rrf;
        AForm *random;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        try
        {
            random = someRandomIntern.makeForm("random", "Bender");
            std::cout << *random << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        Bureaucrat *b1 = new Bureaucrat("Bureaucrat 1", 150);
        std::cout << *b1 << std::endl;
        b1->signForm(*rrf);
        Bureaucrat *b2 = new Bureaucrat("Bureaucrat 2", 50);
        std::cout << *b2 << std::endl;
        b2->signForm(*rrf);
        b2->executeForm(*rrf);
        delete b1;
        delete b2;
        delete rrf;
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "---Test 2---" << std::endl;
        Intern someRandomIntern;
        AForm *rrf;
        AForm *scf;
        AForm *ppf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << *rrf << std::endl;
        std::cout << *scf << std::endl;
        std::cout << *ppf << std::endl;
        Bureaucrat *b1 = new Bureaucrat("Bureaucrat 1", 150);
        std::cout << *b1 << std::endl;
        b1->signForm(*rrf);
        b1->signForm(*scf);
        b1->signForm(*ppf);
        Bureaucrat *b2 = new Bureaucrat("Bureaucrat 2", 5);
        std::cout << *b2 << std::endl;
        b2->signForm(*rrf);
        b2->signForm(*scf);
        b2->signForm(*ppf);
        b2->executeForm(*rrf);
        b2->executeForm(*scf);
        b2->executeForm(*ppf);
        delete b1;
        delete b2;
        delete rrf;
        delete scf;
        delete ppf;
    }
    return 0;
}
