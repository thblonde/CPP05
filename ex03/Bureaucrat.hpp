#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const & copy);
        ~Bureaucrat();

        Bureaucrat& operator=(Bureaucrat const & assign);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        
        void signForm(AForm& src);
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        std::string const _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const & src);

#endif
