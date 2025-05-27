#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& assign);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
    private:
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& src);

#endif