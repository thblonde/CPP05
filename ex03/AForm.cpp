#include "AForm.hpp"

AForm::AForm()
: _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(std::string const name, bool isSigned, int const gradeToSign,
int const gradeToExecute)
: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
    std::cout << "AForm constructor" << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
}

AForm::AForm(AForm const & copy)
: _name(copy.getName()), _gradeToSign(copy.getGradeToSign()),
_gradeToExecute(copy.getGradeToExecute())
{
    std::cout << "AForm copy constructor" << std::endl;
    *this = copy;
}

AForm::~AForm()
{
    std::cout << "AForm destructor" << std::endl;
}

AForm& AForm::operator=(AForm const & assign)
{
    std::cout << "AForm copy assignment operator" << std::endl;
    if (this != &assign)
        this->_isSigned = assign._isSigned;
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat& src)
{
    if (src.getGrade() <= this->_gradeToSign)
    {
        this->_isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed form "
            << this->_name << std::endl;
    }
    else
    {
        std::cout << "Bureaucrat " << src.getName() << " couldn't sign form "
            << this->_name << " because ";
        throw GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->_isSigned == true && executor.getGrade() <= this->_gradeToExecute)
    {
        std::cout << "Bureaucrat " << executor.getName()
            << " executed form " << this->_name << std::endl;
        this->executeForm();
    }
    else
    {
        std::cout << "Bureaucrat " << executor.getName()
            << " couldn't execute form " << this->_name << " because ";
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low !";
}
