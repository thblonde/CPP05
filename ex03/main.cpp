#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern      intern;

    std::cout << std::endl;

    Bureaucrat  bureaucrat1("A", 1);
    std::cout << bureaucrat1 << std::endl;
    
    std::cout << std::endl;

    AForm       *form1;
    try
    {
        form1 = intern.makeForm("shrubbery creation", "home");
        bureaucrat1.signForm(*form1);
        bureaucrat1.executeForm(*form1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    AForm       *form2;
    try
    {
        form2 = intern.makeForm("presidential pardon", "42");
        bureaucrat1.signForm(*form2);
        bureaucrat1.executeForm(*form2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    AForm       *form3;
    try
    {
        form3 = intern.makeForm("robotomy request", "Thomas");
        bureaucrat1.signForm(*form3);
        bureaucrat1.executeForm(*form3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    delete form1;
    delete form2;
    delete form3;

    return 0;
}
