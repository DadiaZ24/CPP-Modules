#ifndef AFORM_HPP
#define AFORM_HPP

// COLORS:
#define RESET "\033[0m"
#define CLASS_CALL "\033[35m"
#define TEST "\033[36m"
#define SOUND "\033[33m"
#define TITLE "\033[32m"

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
    const std::string _name;
    bool _isSigned;
    int _gradeToSign;
    int _gradeToExecute;

public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeToExecuteTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormCreationException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
#endif
