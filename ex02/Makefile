NAME = aform
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
	PresidentialPardonForm.cpp RobotomyRequestForm.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re: clean all
