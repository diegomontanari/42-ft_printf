# Name of the archive I need to create
NAME = libftprintf.a

# Compiler
CC = cc

# Flags I want to use
CFLAGS = -Wall -Werror -Wextra

# To remove my files after the flow is completed
RM = rm -f

# It defines the list of C source files.
SRC = ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_nbr_base.c \
	ft_print_ptr.c ft_print_str.c ft_printf.c ft_strlen.c

# Converts the names of the source files to object file names
OBJS = ${SRC:.c=.o}

# Creates the libftprintf.a archive with the object files (It only contains .o files=
$(NAME): $(OBJS)
		ar rcs ${NAME} ${OBJS}

%.o: %.c # % is a wildcard that stands for "any sequence of ... (here: any file)
		$(CC) $(CFLAGS) -c $< -o $@ # -c compiles without linking (why idk)

all: $(NAME) # All starts the flow and NAME creates the archive

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Makefile RECAP:
# make runs all, which in turn creates libftprintf.a by compiling the .c files into .o 
# and merging them into the executable (in this case, the archive). (It does nothing else and removes nothing.)
# make clean removes only the .o files (compiled objects).
# make fclean runs clean, then also removes the executable (in this case, the archive).
# make re runs fclean (so it deletes everything) and then all to recompile from scratch.
# .PHONY does not affect the execution order, it only serves to avoid issues if files with the same 
# name as the targets exist.
# make alone runs all because it is the first declared target that does not start with a . 
# and is not a .PHONY.

