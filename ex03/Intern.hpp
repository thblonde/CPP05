#ifndef INTERN_H
# define INTERN_H
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern(Intern const & copy);
        ~Intern();

        Intern& operator=(Intern const & assign);

        AForm *makeForm(std::string name, std::string const target);
        AForm *presidentialPardon(std::string const target);
        AForm *robotomyRequest(std::string const target);
        AForm *shrubberyCreation(std::string const target);
};

#endif