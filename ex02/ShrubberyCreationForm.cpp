#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : _name("default"), _isSigned(false), _gradeToSign(145), _gradeToExecute(137) {
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : _target(target), _name("ShrubberyCreationForm"), _isSigned(false), _gradeToSign(145), _gradeToExecute(137) {
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(145), _gradeToExecute(137) {
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign) {
    if (this != &assign) {
        std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
        _isSigned = assign._isSigned;
    }
    return *this;
}

int ShrubberyCreationForm::getGradeToSign() const {
    return _gradeToSign;
}

int ShrubberyCreationForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void ShrubberyCreationForm::beSigned(Bureaucrat& src) {
    if (src.getGrade() <= getGradeToSign()) {
        _isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed form " << _name << std::endl;
    } else {
        std::cout << "Bureaucrat " << src.getName() << " couldn't sign form " << _name << " because ";
        throw GradeTooLowException();
    }
}

void ShrubberyCreationForm::executeForm() const {
   std::string fileName = _target + "_shrubbery";

    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error: open file" << std::endl;
        exit(1);
    }

    file << "    /\\" << std::endl;
    file << "   /**\\" << std::endl;
    file << "  /****\\" << std::endl;
    file << " /******\\" << std::endl;
    file << "   ||||" << std::endl;
    file << "   ||||" << std::endl; 

    file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (_isSigned == true && executor.getGrade() <= _gradeToExecute) {
        executeForm();
    }
    else {
        std::cout << "Bureaucrat " << executor.getName() << " couldn't execute form " << _name << " because ";
        throw GradeTooLowException();
    }
}
