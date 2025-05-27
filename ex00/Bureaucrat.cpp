#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat constructor" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
    out << src.getName();
    out << src.getGrade();
    return out;
}