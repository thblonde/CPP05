#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute)
    : _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "AForm constructor" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned) , _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    std::cout << "AForm copy constructor" << std::endl;
}

AForm& AForm::operator=(const AForm& assign) {
    if (this != &assign) {
        std::cout << "AForm copy assignment operator" << std::endl;
        _isSigned = assign._isSigned;
    }
    return *this;
}

void AForm::beSigned(Bureaucrat& src) {
    if (src.getGrade() <= _gradeToSign) {
        _isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed form " << _name << std::endl;
    } else {
        std::cout << "Bureaucrat " << src.getName() << " couldn't sign form " << _name << " because ";
        throw GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const {
    if (_isSigned == true && executor.getGrade() <= _gradeToExecute) {
        executeForm();
    } else {
        std::cout << "Bureaucrat " << executor.getName() << " couldn't execute form " << _name << " because ";
        throw GradeTooLowException();
    }
}
