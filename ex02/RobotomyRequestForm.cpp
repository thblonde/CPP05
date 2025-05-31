#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : _name("default"), _isSigned(false), _gradeToSign(72), _gradeToExecute(45) {
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : _target(target), _name("RobotomyRequestForm"), _isSigned(false), _gradeToSign(72), _gradeToExecute(45) {
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(72), _gradeToExecute(45) {
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assign) {
    if (this != &assign) {
        std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
        _isSigned = assign._isSigned;
    }
    return *this;
}

int RobotomyRequestForm::getGradeToSign() const {
    return _gradeToSign;
}

int RobotomyRequestForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void RobotomyRequestForm::beSigned(Bureaucrat& src) {
    if (src.getGrade() <= getGradeToSign()) {
        _isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed form " << _name << std::endl;
    } else {
        std::cout << "Bureaucrat " << src.getName() << " couldn't sign form " << _name << " because ";
        throw GradeTooLowException();
    }
}

void RobotomyRequestForm::executeForm() const {
    std::cout << "* drilling noises *" << std::endl;
    std::srand(std::time(0));

    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed..." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (_isSigned == true && executor.getGrade() <= _gradeToExecute) {
        executeForm();
    }
    else {
        std::cout << "Bureaucrat " << executor.getName() << " couldn't execute form " << _name << " because ";
        throw GradeTooLowException();
    }
}
