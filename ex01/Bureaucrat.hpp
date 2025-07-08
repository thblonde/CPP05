#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

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
        
        void signForm(Form& src);

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

    private:
        std::string const _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& out,Bureaucrat const & src);

#endif
