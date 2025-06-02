#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& copy) {
    std::cout << "Intern copy constructor" << std::endl;
    (void)copy;
}

Intern& Intern::operator=(const Intern& assign) {
    std::cout << "Intern copy assignment operator" << std::endl;
    (void)assign;
    return *this;
}

AForm* Intern::presidentialPardon(const std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::robotomyRequest(const std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::shrubberyCreation(const std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, const std::string target) {
    AForm *form = NULL;
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (Intern::*formPtr[3])(std::string);
    formPtr[0] = &Intern::presidentialPardon;
    formPtr[1] = &Intern::robotomyRequest;
    formPtr[2] = &Intern::shrubberyCreation;
 
    for (int i = 0; i < 3; i ++) {
        if (name == forms[i])
            form = (this->*formPtr[i])(target);
    }

    if (form == NULL) {
        std::cerr << "Error: invalid form" << std::endl;
        return NULL;
    }

    std::cout << "Intern creates " << name << std::endl;
    return form;
}

Intern::~Intern() {
    std::cout << "Intern destructor" << std::endl;
}
