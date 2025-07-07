#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  a("BA", 100);
    std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
    Form        fa("FA", false, 99, 99);
    std::cout << fa.getName() << ", Form grade to be signed " << fa.getGradeToSign() << "." << std::endl;
    
    try
    {
        a.signForm(fa);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    Bureaucrat  b("BA", 2);
    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    Form        fb("FB", false, 1, 1);
    std::cout << fb.getName() << ", Form grade to be signed " << fb.getGradeToSign() << "." << std::endl;
    
    try
    {
        b.signForm(fb);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    b.incrementGrade();
    
    try
    {
        b.signForm(fb);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
