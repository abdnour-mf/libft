NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c

OBJS = $(SRCS:.c=.o)
#Take every .c in SRCS and replace .c with .o.

%.o: %.c 
#Whenever you need a .o, you can create it from the corresponding .c
	$(CC) $(CFLAGS) -c $< -o $@

#< is the first prerequisite (the .c file)
#@ is the target (the .o file)
#-c : compile the .c file into an object file
#-o : specify the name of the output file

$(NAME): $(OBJS)
#name is the target, and it depends on the .o files which are objs
	ar rcs $(NAME) $(OBJS)

all: $(NAME)
#When I ask for all, make sure libft.a exists and is up to date

clean:
#clean up the .o files
	rm -f $(OBJS)
fclean: clean
#clean up the .o files and the libft.a file
	rm -f $(NAME)
re: fclean all
#rebuild everything from scratch