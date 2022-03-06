SRCS	= ft_memset.c ft_strcmp.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memdel.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_itoa.c ft_putnbr_fd.c ft_strtrim.c ft_split.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

INCLUDE	= -I ./includes/ft.h

CC		= gcc
RM		= rm -f

AR		= ar rcs

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} $?

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re libft.a
