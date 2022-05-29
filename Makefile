# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:38:14 by llornel           #+#    #+#              #
#    Updated: 2022/03/26 19:07:54 by llornel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCLUDES		= ./includes
SRC_PATH 		= ./src
OBJ_PATH 		= ./obj

BUILTIN_PATH 	= $(SRC_PATH)/ft_builtin
COMM_PATH 		= $(SRC_PATH)/ft_common
DATA_PATH 		= $(SRC_PATH)/ft_data
EXEC_PATH 		= $(SRC_PATH)/ft_exec
EXP_PATH 		= $(SRC_PATH)/ft_expand
PARSER_PATH 	= $(SRC_PATH)/ft_parser
PATH_PATH		= $(SRC_PATH)/ft_path
VAR_PATH 		= $(SRC_PATH)/ft_var
UTILS_PATH 		= $(SRC_PATH)/ft_utils

HEADER 			= $(INCLUDES)/const.h \
				  $(INCLUDES)/data.h \
				  $(INCLUDES)/var.h \
				  $(INCLUDES)/common.h \
				  $(INCLUDES)/path.h \
				  $(INCLUDES)/builtin.h \
				  $(INCLUDES)/parser.h \
				  $(INCLUDES)/exec.h \
				  $(INCLUDES)/minishell.h

SRC_FILE		= $(COMM_PATH)/ft_init.c \
				  $(COMM_PATH)/ft_error.c \
				  $(COMM_PATH)/ft_error_utils.c \
				  $(COMM_PATH)/ft_free.c \
				  $(COMM_PATH)/ft_echoctl.c \
				  $(COMM_PATH)/ft_signal.c \
				  $(COMM_PATH)/ft_signal_handlers.c \
				  $(COMM_PATH)/ft_copy.c \
				  $(COMM_PATH)/ft_token_list.c \
				  $(COMM_PATH)/ft_token_check.c \
				  $(COMM_PATH)/ft_token_check_str.c \
				  $(DATA_PATH)/ft_var_data.c \
				  $(DATA_PATH)/ft_word_data.c \
				  $(DATA_PATH)/ft_redirect_data.c \
				  $(DATA_PATH)/ft_command_data.c \
				  $(DATA_PATH)/ft_wordlist_data.c \
				  $(DATA_PATH)/ft_cmdlist_data.c \
				  $(DATA_PATH)/ft_exec_cmd_data.c \
				  $(DATA_PATH)/ft_execlist_data.c \
				  $(VAR_PATH)/ft_var_check.c \
				  $(VAR_PATH)/ft_var_valid.c \
				  $(VAR_PATH)/ft_var_find.c \
				  $(VAR_PATH)/ft_var_remove.c \
				  $(VAR_PATH)/ft_var_get.c \
				  $(VAR_PATH)/ft_var_set.c \
				  $(VAR_PATH)/ft_var_init.c \
				  $(VAR_PATH)/ft_var_parse.c \
				  $(EXP_PATH)/ft_expand_tilde.c \
				  $(EXP_PATH)/ft_expand_dollar.c \
				  $(EXP_PATH)/ft_expand_iter.c \
				  $(EXP_PATH)/ft_expand_line.c \
				  $(EXP_PATH)/ft_expand_utils.c \
				  $(EXP_PATH)/ft_expand_word.c \
				  $(EXP_PATH)/ft_expand_heredoc.c \
				  $(PATH_PATH)/ft_file_utils.c \
				  $(PATH_PATH)/ft_path_check.c \
				  $(PATH_PATH)/ft_path_utils.c \
				  $(PATH_PATH)/ft_dir_utils.c \
				  $(BUILTIN_PATH)/ft_builtin.c \
				  $(BUILTIN_PATH)/ft_builtin_cd_utils.c \
				  $(BUILTIN_PATH)/ft_builtin_cd_cdpath.c \
				  $(BUILTIN_PATH)/ft_builtin_cd_path.c \
				  $(BUILTIN_PATH)/ft_builtin_cd_home.c \
				  $(BUILTIN_PATH)/ft_builtin_cd_tilde.c \
				  $(BUILTIN_PATH)/ft_builtin_cd.c \
				  $(BUILTIN_PATH)/ft_builtin_exit.c \
				  $(BUILTIN_PATH)/ft_builtin_pwd.c \
				  $(BUILTIN_PATH)/ft_builtin_echo.c \
				  $(BUILTIN_PATH)/ft_builtin_env.c \
				  $(BUILTIN_PATH)/ft_builtin_unset.c \
				  $(BUILTIN_PATH)/ft_builtin_export.c \
				  $(PARSER_PATH)/ft_syntax.c \
				  $(PARSER_PATH)/ft_syntax_check.c \
				  $(PARSER_PATH)/ft_lexer_check.c \
				  $(PARSER_PATH)/ft_lexer_quotes.c \
				  $(PARSER_PATH)/ft_lexer_special.c \
				  $(PARSER_PATH)/ft_lexer.c \
				  $(PARSER_PATH)/ft_parcer_command.c \
				  $(PARSER_PATH)/ft_parcer_pipe.c \
				  $(PARSER_PATH)/ft_parcer.c \
				  $(PARSER_PATH)/ft_parcer_redirection.c \
				  $(PARSER_PATH)/ft_parcer_words.c \
				  $(PARSER_PATH)/ft_handle_heredoc.c \
				  $(PARSER_PATH)/ft_handle_file.c \
				  $(EXEC_PATH)/ft_pipe.c \
				  $(EXEC_PATH)/ft_dup.c \
				  $(EXEC_PATH)/ft_dup_utils.c \
				  $(EXEC_PATH)/ft_do_redirects.c \
				  $(EXEC_PATH)/ft_do_simplecmd.c \
				  $(EXEC_PATH)/ft_build_cmd.c \
				  $(EXEC_PATH)/ft_build_job.c \
				  $(EXEC_PATH)/ft_run_job.c \
				  $(EXEC_PATH)/ft_exec_utils.c \
				  $(EXEC_PATH)/ft_execute.c \
				  $(EXEC_PATH)/ft_execute_cmd.c \
				  $(EXEC_PATH)/ft_process.c \
				  $(EXEC_PATH)/ft_execute_job.c \
				  $(EXEC_PATH)/ft_executor.c \
				  $(SRC_PATH)/ft_minishell.c \
				  minishell.c

SRCS			= $(SRC_FILE)
OBJS			= $(SRCS:.c=.o)

LIBFT_PATH		= ./libft
LIBFT_NAME		= $(LIBFT_PATH)/libft.a
LIBFT_INCLUDES	= $(LIBFT_PATH)/includes
LIBFT_MAKE		= ${MAKE} -C ${LIBFT_PATH}

LIBRL_NAME		= readline
LIBRL_INCLUDES	= /Users/$(USER)/.brew/opt/readline/include/
LIBRL_PATH  	= /Users/$(USER)/.brew/opt/readline/lib/

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
DFLAGS 			= -g -fsanitize=address
LFLAGS			= -L $(LIBFT_PATH) -lft
RLFLAGS			= -I$(LIBRL_INCLUDES) -L$(LIBRL_PATH) -l$(LIBRL_NAME)
RM				= rm -f
NORM			= norminette -R CheckForbiddenSourceHeader

%.o:			%.c $(HEADER) Makefile
				${CC} $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(LIBRL_INCLUDES) -c $< -o $(<:.c=.o)

all:			${NAME}

${NAME}:		${OBJS}
				$(LIBFT_MAKE)
				${CC} ${CFLAGS} ${OBJS} -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(LFLAGS) $(RLFLAGS) -o ${NAME}


clean:
				$(LIBFT_MAKE) clean
				${RM} ${OBJS}

fclean:			clean
				$(LIBFT_MAKE) fclean
				${RM} ${NAME}

re:				fclean all

bonus:			${NAME}

norm:
				$(LIBFT_MAKE) norm
				${NORM} $(SRCS) $(HEADER)

.PHONY: 		all clean fclean re bonus norm .c.o
