#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const & copy); 
        PresidentialPardonForm(std::string const & target);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm const & assign);

        void executeForm() const;

    private:
        std::string const _target;
};

#endif