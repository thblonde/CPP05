#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const & copy); 
        ShrubberyCreationForm(std::string const & target);
        ~ShrubberyCreationForm();
        
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const & assign);
        
        void executeForm() const;

    private:
        std::string const _target;
};

#endif