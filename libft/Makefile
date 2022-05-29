# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 20:46:46 by llornel           #+#    #+#              #
#    Updated: 2022/03/11 02:38:43 by llornel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	        = libft.a

INCLUDES		= ./includes
SRC_PATH 		= ./src
OBJ_PATH 		= ./obj

BTREE_PATH 		= $(SRC_PATH)/ft_btree
COMMON_PATH 	= $(SRC_PATH)/ft_common
CNVRT_PATH 		= $(SRC_PATH)/ft_cnvrt
GNL_PATH 		= $(SRC_PATH)/ft_gnl
ISCHECK_PATH 	= $(SRC_PATH)/ft_ischeck
LIST_PATH 		= $(SRC_PATH)/ft_list
MEMORY_PATH 	= $(SRC_PATH)/ft_memory
OUTPUT_PATH 	= $(SRC_PATH)/ft_output
PRINTF_PATH 	= $(SRC_PATH)/ft_printf
STRING_PATH 	= $(SRC_PATH)/ft_string
TAB_PATH 		= $(SRC_PATH)/ft_tab

HEADER 			= $(INCLUDES)/libft.h \
				  $(INCLUDES)/get_next_line.h \
				  $(INCLUDES)/ft_printf.h

SRC_FILE		=   $(ISCHECK_PATH)/ft_isalpha.c \
				    $(ISCHECK_PATH)/ft_isdigit.c \
					$(ISCHECK_PATH)/ft_isalnum.c \
					$(ISCHECK_PATH)/ft_isascii.c \
					$(ISCHECK_PATH)/ft_isprint.c \
					$(ISCHECK_PATH)/ft_iscomma.c \
					$(ISCHECK_PATH)/ft_iswildcard.c \
					$(ISCHECK_PATH)/ft_isspace.c \
					$(ISCHECK_PATH)/ft_iswhitespace.c \
 					$(ISCHECK_PATH)/ft_isplusminus.c \
 					$(COMMON_PATH)/ft_swap.c \
  					$(COMMON_PATH)/ft_nbrlen.c \
					$(COMMON_PATH)/ft_maths.c \
					$(CNVRT_PATH)/ft_atoi.c \
					$(CNVRT_PATH)/ft_atol.c \
					$(CNVRT_PATH)/ft_atod.c \
					$(CNVRT_PATH)/ft_itoa.c \
					$(CNVRT_PATH)/ft_uitoa.c \
           			$(MEMORY_PATH)/ft_bzero.c \
            		$(MEMORY_PATH)/ft_calloc.c \
					$(MEMORY_PATH)/ft_memdel.c \
					$(MEMORY_PATH)/ft_memset.c \
					$(MEMORY_PATH)/ft_memccpy.c \
					$(MEMORY_PATH)/ft_memcpy.c \
					$(MEMORY_PATH)/ft_memmove.c \
					$(MEMORY_PATH)/ft_memchr.c \
            		$(MEMORY_PATH)/ft_memcmp.c \
					$(STRING_PATH)/ft_strisempty.c \
					$(STRING_PATH)/ft_striswildcard.c \
					$(STRING_PATH)/ft_strischar.c \
					$(STRING_PATH)/ft_strisdigit.c \
 					$(STRING_PATH)/ft_strisnumber.c \
					$(STRING_PATH)/ft_strtolower.c \
					$(STRING_PATH)/ft_strtoupper.c \
            		$(STRING_PATH)/ft_strdup.c \
            		$(STRING_PATH)/ft_strndup.c \
 					$(STRING_PATH)/ft_strlen.c \
 					$(STRING_PATH)/ft_strlcpy.c \
 					$(STRING_PATH)/ft_strlcat.c \
 					$(STRING_PATH)/ft_strcpy.c \
 					$(STRING_PATH)/ft_strcat.c \
 					$(STRING_PATH)/ft_strncpy.c \
 					$(STRING_PATH)/ft_strncat.c \
					$(STRING_PATH)/ft_substr.c \
					$(STRING_PATH)/ft_strjoin.c \
					$(STRING_PATH)/ft_strstr.c \
					$(STRING_PATH)/ft_strnstr.c \
					$(STRING_PATH)/ft_strdel.c \
					$(STRING_PATH)/ft_strchr.c \
					$(STRING_PATH)/ft_strrchr.c \
					$(STRING_PATH)/ft_strcmp.c \
					$(STRING_PATH)/ft_strncmp.c \
					$(STRING_PATH)/ft_strrev.c \
					$(STRING_PATH)/ft_strtrim.c \
					$(STRING_PATH)/ft_tolower.c \
					$(STRING_PATH)/ft_toupper.c \
					$(STRING_PATH)/ft_strset.c \
					$(STRING_PATH)/ft_strreplace.c \
					$(STRING_PATH)/ft_strsep.c \
					$(STRING_PATH)/ft_strnsep.c \
					$(TAB_PATH)/ft_split_free.c \
					$(TAB_PATH)/ft_split_size.c \
					$(TAB_PATH)/ft_split_sep.c \
					$(TAB_PATH)/ft_split.c \
					$(TAB_PATH)/ft_tabfree.c \
					$(TAB_PATH)/ft_tabprint.c \
					$(TAB_PATH)/ft_tabsort.c \
					$(TAB_PATH)/ft_tabsize.c \
					$(TAB_PATH)/ft_tabdup.c \
					$(TAB_PATH)/ft_tabcat.c \
					$(TAB_PATH)/ft_tabjoin.c \
					$(TAB_PATH)/ft_tabiter.c \
					$(TAB_PATH)/ft_list_to_tab.c \
					$(TAB_PATH)/ft_tabtostr.c \
					$(OUTPUT_PATH)/ft_putchar_fd.c \
					$(OUTPUT_PATH)/ft_putnbr_fd.c \
					$(OUTPUT_PATH)/ft_putnbr_base.c \
					$(OUTPUT_PATH)/ft_putstr_fd.c \
					$(OUTPUT_PATH)/ft_putendl_fd.c \
					$(LIST_PATH)/ft_lstadd.c \
					$(LIST_PATH)/ft_lstadd_back.c \
					$(LIST_PATH)/ft_lstadd_front.c \
					$(LIST_PATH)/ft_lstclear.c \
					$(LIST_PATH)/ft_lstdelone.c \
					$(LIST_PATH)/ft_lstiter.c \
					$(LIST_PATH)/ft_lstlast.c \
					$(LIST_PATH)/ft_lstmap.c \
					$(LIST_PATH)/ft_lstnew.c \
					$(LIST_PATH)/ft_lstdup.c \
					$(LIST_PATH)/ft_lstsize.c \
					$(BTREE_PATH)/ft_btree_apply_infix.c \
					$(BTREE_PATH)/ft_btree_apply_prefix.c \
					$(BTREE_PATH)/ft_btree_apply_suffix.c \
					$(BTREE_PATH)/ft_btree_create_node.c \
					$(BTREE_PATH)/ft_btree_insert_data.c \
					$(BTREE_PATH)/ft_btree_level_count.c \
					$(BTREE_PATH)/ft_btree_nodes_count.c \
					$(BTREE_PATH)/ft_btree_search_item.c \
					$(GNL_PATH)/get_next_line_utils.c \
					$(GNL_PATH)/get_next_line.c \
					$(PRINTF_PATH)/ft_utils.c \
					$(PRINTF_PATH)/ft_parsers.c \
					$(PRINTF_PATH)/ft_parsers_flag.c \
					$(PRINTF_PATH)/ft_handler_int.c \
					$(PRINTF_PATH)/ft_handler_uint.c \
					$(PRINTF_PATH)/ft_handler_char.c \
					$(PRINTF_PATH)/ft_handler_str.c \
					$(PRINTF_PATH)/ft_handler_ptr.c \
					$(PRINTF_PATH)/ft_handler_hex.c \
					$(PRINTF_PATH)/ft_handler_percent.c \
					$(PRINTF_PATH)/ft_output_char.c \
					$(PRINTF_PATH)/ft_output_str.c \
					$(PRINTF_PATH)/ft_output_int.c \
					$(PRINTF_PATH)/ft_output_uint.c \
					$(PRINTF_PATH)/ft_output_ptr.c \
					$(PRINTF_PATH)/ft_output_hex.c \
					$(PRINTF_PATH)/ft_output_percent.c	\
					$(PRINTF_PATH)/ft_printf.c

#SRCS			=	$(addprefix $(OBJ_PATH)/, $(SRC_FILE))
SRCS			=	$(SRC_FILE)
OBJS			=	$(SRCS:.c=.o)
#OBJS			= $(patsubst $(SRC_PATH)/%, $(OBJ_PATH)/%, $(SRCS:.c=.o))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
DFLAGS 			= -g -fsanitize=address
LIBC 			= ar rc
LIBR 			= ranlib
RM				= rm -f
NORM			= norminette -R CheckForbiddenSourceHeader

%.o:			%.c $(HEADER) Makefile
				${CC} $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)


${NAME}:		${OBJS}
				${LIBC} ${NAME} ${OBJS}
				${LIBR} ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

norm:
				${NORM} $(SRCS) $(HEADER)

.PHONY: 		all clean fclean re norm .c.o
