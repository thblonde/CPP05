#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        virtual ~AForm();
        AForm& operator=(const AForm& assign);
        
        virtual void beSigned(Bureaucrat& src);
        virtual void execute(Bureaucrat const & executor) const;
        
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too high !";
                }
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too low !";
                }
        };
        
    protected:
        virtual void executeForm() const = 0;

    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

#endif