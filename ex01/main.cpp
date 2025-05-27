#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
    try {
        Bureaucrat a("A", 149);
        std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
        a.decrementGrade();
        std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
        Form f("f",false, 151, 150);
        std::cout << "Form " << f.getName() << ", sign: " << f.getGradeToSign() << ", execute: " << f.getGradeToExecute() << "." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
