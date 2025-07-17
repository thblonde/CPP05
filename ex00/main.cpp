#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  a("A", 100);
        std::cout << a << std::endl;
        
        std::cout << std::endl;

        Bureaucrat  b(a);
        std::cout << b << std::endl;
        
        std::cout << std::endl;

        Bureaucrat  c;
        c = a;
        std::cout << c << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }


    std::cout << std::endl;


    Bureaucrat a("A", 149);
    std::cout << a << std::endl;
    a.decrementGrade();
    std::cout << a << std::endl;
    try
    {
        a.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << std::endl;


    Bureaucrat  b("B", 1);
    std::cout << b << std::endl;
    try
    {
        b.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    std::cout << std::endl;


    try
    {
        Bureaucrat  z("Z", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    return 0;
}
