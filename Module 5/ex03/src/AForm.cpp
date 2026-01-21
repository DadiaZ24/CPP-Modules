#include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "AForm constructor called" << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false),
                                                                             _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "AForm constructor called" << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "AForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
        this->_gradeToSign = other._gradeToSign;
        this->_gradeToExecute = other._gradeToExecute;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because is grade is too low." << std::endl;
    else
    {
        _isSigned = true;
        std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high. Only accept grades between 1-150";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low. Only accept grades between 1-150";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed yet.";
}

const char *AForm::GradeToExecuteTooLowException::what() const throw()
{
    return "The grade of the executor is not high enough to execute the form";
}

const char *AForm::FormCreationException::what() const throw()
{
    return "The Form you are trying to create does not exist";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
