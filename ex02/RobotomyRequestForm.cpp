#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("default", false, 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
: AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy)
: AForm(copy.getName(), copy._isSigned, copy.getGradeToSign(), copy.getGradeToExecute())
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
    *this = copy;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & assign)
{
    std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
    if (this != &assign)
        this->_isSigned = assign._isSigned;
    return *this;
}

void RobotomyRequestForm::executeForm() const
{
    std::cout << "* drilling noises *" << std::endl;
    std::srand(std::time(0));

    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed..." << std::endl;
}
