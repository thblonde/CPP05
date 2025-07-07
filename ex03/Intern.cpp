#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(Intern const & copy)
{
    std::cout << "Intern copy constructor" << std::endl;
    (void)copy;
}

Intern::~Intern()
{
    std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(Intern const & assign)
{
    std::cout << "Intern copy assignment operator" << std::endl;
    (void)assign;
    return *this;
}

AForm *Intern::presidentialPardon(std::string const target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::robotomyRequest(std::string const target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::shrubberyCreation(std::string const target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string const target)
{
    AForm *form = NULL;
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (Intern::*formPtr[3])(std::string);
    formPtr[0] = &Intern::presidentialPardon;
    formPtr[1] = &Intern::robotomyRequest;
    formPtr[2] = &Intern::shrubberyCreation;
 
    for (int i = 0; i < 3; i ++)
    {
        if (name == forms[i])
            form = (this->*formPtr[i])(target);
    }

    if (form == NULL)
    {
        std::cerr << "Error: invalid form" << std::endl;
        return NULL;
    }

    std::cout << "Intern creates " << name << std::endl;
    return form;
}

