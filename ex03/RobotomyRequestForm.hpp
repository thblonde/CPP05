#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <fstream>
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const & copy); 
        RobotomyRequestForm(std::string const & target);
        ~RobotomyRequestForm();
        
        RobotomyRequestForm& operator=(RobotomyRequestForm const & assign);

        void executeForm() const;

    private:
        std::string const _target;
};

#endif
