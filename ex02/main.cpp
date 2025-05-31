#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b("b", 1);
    RobotomyRequestForm a("home");

    try {
        b.signForm(a);
        a.execute(b);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}