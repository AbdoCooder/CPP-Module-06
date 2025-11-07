CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(gdb),1)
	CFLAGS += -g
endif

NAME = Serialize
SRC =  main.cpp $(NAME).cpp
HEADERS = $(NAME).hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
