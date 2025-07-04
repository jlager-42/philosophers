CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

NAME = philosophers.a
SRC = 
OBJ = $(SRC:.c=.o)

clean:
	$(RM) $(OBJ) $(TEST_OBJ)
fclean: clean
	$(RM) $(NAME) $(TEST_EXEC)
re: fclean all
.PHONY: all clean fclean re test run_test