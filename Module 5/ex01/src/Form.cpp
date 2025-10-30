#include "../includes/Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Form constructor called" << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), 
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Form constructor called" << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_isSigned = other._isSigned;
        this->_gradeToSign = other._gradeToSign;
        this->_gradeToExecute = other._gradeToExecute;
    }
    return *this;
}

Form::~Form() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because is grade is too low." << std::endl;
    else {
        _isSigned = true;
        std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    }
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high. Only accept grades between 1-150";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low. Only accept grades between 1-150";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}

