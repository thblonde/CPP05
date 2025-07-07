#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("A", 1);
    std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;

    std::cout << std::endl;

    RobotomyRequestForm robot("home");
    std::cout << robot.getName() << ", Form grade to be signed " << robot.getGradeToSign() << "." << std::endl;

    std::cout << std::endl;

    ShrubberyCreationForm   shrub("file");
    std::cout << shrub.getName() << ", Form grade to be signed " << shrub.getGradeToSign() << "." << std::endl;

    std::cout << std::endl;

    PresidentialPardonForm  pres("42");
    std::cout << pres.getName() << ", Form grade to be signed " << pres.getGradeToSign() << "." << std::endl;

    std::cout << std::endl;

    try
    {
        a.signForm(robot);
        robot.execute(a);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        a.signForm(shrub);
        shrub.execute(a);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        a.signForm(pres);
        pres.execute(a);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}