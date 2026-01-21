#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "RobotomyRequestForm operator= called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "RobotomyRequestForm deconstructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeToExecuteTooLowException();

    std::cout << "Ski-bi dibby dib yo da dub dub Yo da dub dub Ski-bi dibby dib yo da dub dub Yo da dub dub"
              << std::endl;

    srand(time(0));

    int randomNbr = rand() % 2;

    if (randomNbr == 1)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " has failed the robotimization." << std::endl;
}
