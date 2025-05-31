#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : _name("default"), _isSigned(false), _gradeToSign(25), _gradeToExecute(5) {
    std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : _target(target), _name("PresidentialPardonForm"), _isSigned(false), _gradeToSign(25), _gradeToExecute(5) {
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(25), _gradeToExecute(5) {
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign) {
    if (this != &assign) {
        std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
        _isSigned = assign._isSigned;
    }
    return *this;
}

int PresidentialPardonForm::getGradeToSign() const {
    return _gradeToSign;
}

int PresidentialPardonForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void PresidentialPardonForm::beSigned(Bureaucrat& src) {
    if (src.getGrade() <= getGradeToSign()) {
        _isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed form " << _name << std::endl;
    } else {
        std::cout << "Bureaucrat " << src.getName() << " couldn't sign form " << _name << " because ";
        throw GradeTooLowException();
    }
}

void PresidentialPardonForm::executeForm() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (_isSigned == true && executor.getGrade() <= _gradeToExecute) {
        executeForm();
    }
    else {
        std::cout << "Bureaucrat " << executor.getName() << " couldn't execute form " << _name << " because ";
        throw GradeTooLowException();
    }
}