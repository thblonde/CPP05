#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(std::string const name, bool isSigned, int const gradeToSign, int const gradeToExecute);
        AForm(AForm const & copy);
        virtual ~AForm();
        AForm& operator=(AForm const & assign);
        
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        void beSigned(Bureaucrat& src);
        void execute(Bureaucrat const & executor) const;
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
    protected:
        virtual void executeForm() const = 0;
        std::string const _name;
        bool _isSigned;
        int const _gradeToSign;
        int const _gradeToExecute;
};

#endif