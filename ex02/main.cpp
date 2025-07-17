#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("A", 1);
    std::cout << a << std::endl;

    std::cout << std::endl;

    RobotomyRequestForm robot("home");
    std::cout << robot.getName() << ", Form grade to be signed: "
        << robot.getGradeToSign() << ", grade to be executed: "
        << robot.getGradeToExecute() << std::endl;

    std::cout << std::endl;

    ShrubberyCreationForm   shrub("file");
    std::cout << shrub.getName() << ", Form grade to be signed: "
        << shrub.getGradeToSign() << ", grade to be executed: "
        << shrub.getGradeToExecute() << std::endl;

    std::cout << std::endl;

    PresidentialPardonForm  president("42");
     std::cout << president.getName() << ", Form grade to be signed: "
        << president.getGradeToSign() << ", grade to be executed: "
        << president.getGradeToExecute() << std::endl;

    std::cout << std::endl;

    try
    {
        a.signForm(robot);
        a.executeForm(robot);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        a.signForm(shrub);
        a.executeForm(shrub);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        a.signForm(president);
        a.executeForm(president);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat  b("B", 150);
    std::cout << b << std::endl;

    std::cout << std::endl;

    try
    {
        b.signForm(president);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    Bureaucrat  c("C", 72);
    std::cout << c << std::endl;

    std::cout << std::endl;

    try
    {
        c.signForm(robot);
        c.executeForm(robot);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    
    return 0;
}