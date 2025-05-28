#include "Form.hpp"

Form::Form() :_name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute)
    : _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    std::cout << "Form constructor" << std::endl;
}

Form::Form(const Form& copy) : _name(copy.getName()), _gradeToSign(copy.getGradeToSign()),
    _gradeToExecute(copy.getGradeToExecute()) {
    std::cout << "Form copy constructor" << std::endl;
    _isSigned = copy._isSigned;
}

Form& Form::operator=(const Form& assign) {
    if (this != &assign) {
        _isSigned = assign._isSigned;
        std::cout << "Form copy assignment operator" << std::endl;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor" << std::endl;
}

std::string Form::getName() const {
    return _name;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat src) {
    if (src.getGrade() <= getGradeToSign()) {
        _isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed form " << _name << std::endl;
    }
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& src) {
    out << src.getName();
    out << src.getGradeToSign();
    out << src.getGradeToExecute();
    return out;
}
