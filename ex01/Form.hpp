#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form {
    public:
        Form();
        Form(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute);
        Form(const Form& copy);
        Form& operator=(const Form& assign);
        ~Form();
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too high !";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too low !";
                }
        };
        
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif