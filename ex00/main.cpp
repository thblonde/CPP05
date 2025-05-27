#include "Bureaucrat.hpp"

int main() {
    Bureaucrat a("A", 23);
    Bureaucrat b(a);
    Bureaucrat c;

    c = b;
    std::cout << a.getName() << a.getGrade() << std::endl;
    std::cout << b.getName() << b.getGrade() << std::endl;
    std::cout << c.getName() << c.getGrade() << std::endl;
    return 0;
}