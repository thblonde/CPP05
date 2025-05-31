#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <fstream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& copy); 
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& assign);
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