#include "Bureaucrat.hpp"

int main() {
    
    try {
        Bureaucrat a("A", 151);
        std::cout << a.getName() << " " << a.getGrade() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}