#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    std::cout << "Bureaucrat constructor" << std::endl;
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()) {
    std::cout << "Bureaucrat copy constructor" << std::endl;
    _grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign) {
    std::cout << "Bureaucrat copy assignment operator" << std::endl;
    if (this != &assign)
        _grade = assign._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor" << std::endl;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (getGrade() == 1)
        throw GradeTooHighException();
    _grade--;
    std::cout << _name << " grade increment." << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (getGrade() == 150)
        throw GradeTooLowException();
    _grade++;
    std::cout << _name << " grade decrement." << std::endl;
}

void Bureaucrat::signForm() {
    Form::beSigned(*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
    out << src.getName();
    out << src.getGrade();
    return out;
}