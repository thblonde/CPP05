#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string const name, bool isSigned, int const gradeToSign, int const gradeToExecute);
        Form(Form const & copy);
        ~Form();
        Form& operator=(Form const & assign);

        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat& src);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too high !";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too low !";
                }
        };

    private:
        std::string const _name;
        bool _isSigned;
        int const _gradeToSign;
        int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, Form const & src);

#endif