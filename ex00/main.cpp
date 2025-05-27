#include "Bureaucrat.hpp"

int main() {
    
    try {
        Bureaucrat a("A", 149);
        std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
        a.decrementGrade();
        std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
        a.decrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
