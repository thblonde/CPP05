#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", false, 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
: AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy)
: AForm(copy.getName(), false, copy.getGradeToSign(), copy.getGradeToExecute())
{
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & assign)
{
    std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
    if (this != &assign)
        this->_isSigned = assign._isSigned;
    return *this;
}

void ShrubberyCreationForm::executeForm() const
{
    std::string fileName = this->_target + "_shrubbery";

    std::ofstream file;
    
    file.open(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: opening file" << std::endl;
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
