#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
: AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy)
: AForm(copy.getName(), false, copy.getGradeToSign(), copy.getGradeToExecute()),
_target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & assign)
{
    std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
    if (this != &assign)
        this->_isSigned = assign._isSigned;
    return *this;
}

void PresidentialPardonForm::executeForm() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
