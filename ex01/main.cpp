#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  b1("b1", 100);
    std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << "."
        << std::endl;
    
    std::cout << std::endl;

    Form        f1("f1", false, 99, 99);
    std::cout << f1.getName() << ", Form grade to be signed "
        << f1.getGradeToSign() << "." << std::endl;
    
    try
    {
        b1.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    Bureaucrat  b2("b2", 2);
    std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade()
        << "." << std::endl;
    
    std::cout << std::endl;

    Form        f2("f2", false, 1, 1);
    std::cout << f2.getName() << ", Form grade to be signed "
        << f2.getGradeToSign() << "." << std::endl;
    
    try
    {
        b2.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    b2.incrementGrade();
    
    std::cout << std::endl;

    std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade()
        << "." << std::endl;
    
    try
    {
        b2.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
