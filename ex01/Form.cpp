#include "Form.hpp"

Form::Form()
: _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string const name, bool isSigned, int const gradeToSign,
int const gradeToExecute)
: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor" << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
}

Form::Form(Form const & copy)
: _name(copy.getName()), _gradeToSign(copy.getGradeToSign()),
_gradeToExecute(copy.getGradeToExecute())
{
    std::cout << "Form copy constructor" << std::endl;
    *this = copy;
}

Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
}

Form& Form::operator=(Form const & assign)
{
    std::cout << "Form copy assignment operator" << std::endl;
    if (this != &assign)
        this->_isSigned = assign._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat& src)
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

std::ostream& operator<<(std::ostream& out, Form const & src)
{
    out << src.getName();
    out << src.getGradeToSign();
    out << src.getGradeToExecute();
    return out;
}
