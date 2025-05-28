#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
    Bureaucrat a("A", 149);
    Form f("f",false, 149, 149);
    try {
        // std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
        // std::cout << "Form " << f.getName() << ", sign: " << f.getGradeToSign() << ", execute: " << f.getGradeToExecute() << "." << std::endl;
        // a.decrementGrade();
        // std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
        //try {
            a.signForm(f);
        //}
        // catch (const std::exception& e) {
        //     std::cout << e.what() << std::endl;
        // }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
