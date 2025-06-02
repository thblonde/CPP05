#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat a("a", 1);

    Intern i;

    AForm* f = i.makeForm("shrubery creation", "a");
    if (!f) {
        return 1;
    }

    a.signForm(*f);

    try {
        a.executeForm(*f);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
