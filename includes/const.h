/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:48:13 by llornel           #+#    #+#             */
/*   Updated: 2022/03/03 21:19:57 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define PROMPT "msh-1.0$ "
# define ERR_PROMPT "msh: "

# define EXIT_SUCCESS 			0
# define EXIT_FAILURE			1
# define EXIT_BUILTIN			1
/* A file to be executed was found, but it was not an executable utility. */
# define EXIT_NOTEXECUTABLE 	126
/* A utility to be executed was not found. */
# define EXIT_NOTFOUND 			127
/* A command was interrupted by a signal. */
# define EXIT_SIGOFFSET 		128
# define EXIT_CTRL_D 			130
# define EXIT_RANGE 			255
# define EXIT_SYNTAX_ERROR 		258

# define ERR_CODE_NUMBER_AGRS   1
# define ERR_CODE_INVALID_AGRS  2
# define ERR_CODE_VALUE_AGRS 	3
# define ERR_CODE_MALLOC 		4
# define ERR_CODE_INPUT_EMPTY	5
# define ERR_CODE_PTHREAD 		6
# define ERR_CODE_SLEEP 		7
# define ERR_CODE_TIMEOFDAY 	8

# define ERR_MSG_MALLOC 			"error malloc"
# define ERR_MSG_UNDEFINED			"error undefined behavior"
# define ERR_MSG_USAGE 				"minishell without arguments"
# define ERR_MSG_NUMBER_AGRS		"invalid number of arguments"
# define ERR_MSG_INVALID_AGRS		"invalid arguments"
# define ERR_MSG_VALUE_AGRS			"invalid value of arguments"
# define ERR_MSG_SYNTAX_TOKEN		"invalid syntax at token"
# define ERR_MSG_NO_FILE_OR_DIR 	"no such file or directory"
# define ERR_MSG_NOT_DIR	        "Not a directory"
# define ERR_MSG_PERMISSION_DENIED 	"permission denied"
# define ERR_MSG_CANNOT_READ 		"cannot read file."
# define ERR_MSG_CANNOT_DELETE 		"cannot delete file."
# define ERR_MSG_QUOTES				"quotes not paired"
# define ERR_MSG_COMMANDS			"command not found"
# define ERR_MSG_IDENTIFIER			"not a valid identifier"
# define ERR_MSG_TOO_MANY_ARGS		"too many arguments"
# define ERR_MSG_NUMERIC			"numeric arguments required"
# define ERR_MSG_SYNTAX_ERROR       "syntax error near unexpected token"

# define TOKEN_SPACE				" "
# define TOKEN_TAB					"\t"
# define TOKEN_NEWLINE				"\n"
# define TOKEN_ASSIGN				'='
# define TOKEN_BACKSLASH			"\\"
# define TOKEN_SQUOTE				"\'"
# define TOKEN_DQUOTE				"\""
# define TOKEN_PIPE					"|"
# define TOKEN_SEMI				    ";"
# define TOKEN_LESS					"<"
# define TOKEN_GREAT				">"
# define TOKEN_OR_IF				"||"
# define TOKEN_AND_IF				"&&"
# define TOKEN_DSEMI				";;"
# define TOKEN_DLESS				"<<"
# define TOKEN_DGREAT				">>"
# define TOKEN_LESSAND				"<&"
# define TOKEN_GREATAND 			">&"
# define TOKEN_LESSGREAT			"<>"
# define TOKEN_DLESSDASH			"<<-"
# define TOKEN_CLOBBER				">|"

#endif
