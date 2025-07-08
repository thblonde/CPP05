#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  a("A", 100);
        std::cout << a.getName() << ", bureaucrat grade " << a.getGrade()
            << "." << std::endl;
        
        std::cout << std::endl;

        Bureaucrat  b(a);
        std::cout << b.getName() << ", bureaucrat grade " << b.getGrade()
            << "." << std::endl;
        
        std::cout << std::endl;

        Bureaucrat  c;
        c = a;
        std::cout << c.getName() << ", bureaucrat grade " << c.getGrade()
            << "." << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }


    std::cout << std::endl;


    Bureaucrat a("A", 149);
    std::cout << a.getName() << ", bureaucrat grade " << a.getGrade()
        << "." << std::endl;
    a.decrementGrade();
    std::cout << a.getName() << ", bureaucrat grade " << a.getGrade()
        << "." << std::endl;
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
    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade()
        << "." << std::endl;
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
