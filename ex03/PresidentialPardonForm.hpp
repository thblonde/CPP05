#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& copy); 
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& assign);
        void beSigned(Bureaucrat& src);

        void execute(Bureaucrat const & executor) const;

        int getGradeToSign() const;
        int getGradeToExecute() const;

        void executeForm() const;

    private:
        std::string _target;
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

#endif