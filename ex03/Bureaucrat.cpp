#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade)
: _name(name)
{
    std::cout << "Bureaucrat constructor" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
: _name(copy.getName())
{
    std::cout << "Bureaucrat copy constructor" << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & assign)
{
    std::cout << "Bureaucrat copy assignment operator" << std::endl;
    if (this != &assign)
        this->_grade = assign._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    std::cout << this->_name << " grade increment." << std::endl;
    if (this->_grade == 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    std::cout << this->_name << " grade decrement." << std::endl;
    if (this->_grade == 150)
        throw GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm& src)
{
    src.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form) const
{
    form.execute(*this);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const & src)
{
    out << src.getName();
    out << src.getGrade();
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low !";
}
