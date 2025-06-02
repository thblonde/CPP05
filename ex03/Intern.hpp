#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& assign);
        AForm *makeForm(std::string name, const std::string target);
        AForm* presidentialPardon(const std::string target);
        AForm* robotomyRequest(const std::string target);
        AForm* shrubberyCreation(const std::string target);
        ~Intern();
};

#endif