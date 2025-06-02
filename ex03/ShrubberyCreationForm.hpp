#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& copy); 
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& assign);
        void beSigned(Bureaucrat& src);

        void execute(Bureaucrat const & executor) const;

        int getGradeToSign() const;
        int getGradeToExecute() const;

        void executeForm() const;

    private:
        const std::string _target;
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

#endif