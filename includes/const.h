/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:48:13 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:31:02 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define PROMPT					"msh-1.0$ "
# define ERR_PROMPT				"msh"

# define EXIT_SUCCESS			0
# define EXIT_FAILURE			1
# define EXIT_FATAL				2
# define EXIT_NOTEXECUTABLE		126
# define EXIT_NOTFOUND			127
# define EXIT_SIGOFFSET			128
# define EXIT_CTRL_D			129
# define EXIT_CTRL_C			130
# define EXIT_CTRL_SLASH 		131
# define EXIT_RANGE				255
# define EXIT_SYNTAX_ERROR		258

# define ERROR					-1
# define ERR_CODE_NUMBER_AGRS	1
# define ERR_CODE_INVALID_AGRS	2
# define ERR_CODE_VALUE_AGRS	3
# define ERR_CODE_MALLOC		4
# define ERR_CODE_INPUT_EMPTY	5
# define ERR_CODE_PTHREAD		6
# define ERR_CODE_SLEEP			7
# define ERR_CODE_TIMEOFDAY		8
# define ERR_CODE_FORK			9

# define ERR_MSG_MALLOC 			"malloc could not allocate memory"
# define ERR_MSG_FORK				"Could not fork a child process"
# define ERR_MSG_UNDEFINED			"error undefined behavior"
# define ERR_MSG_USAGE				"minishell without arguments"
# define ERR_MSG_NUMBER_AGRS		"invalid number of arguments"
# define ERR_MSG_INVALID_AGRS		"invalid arguments"
# define ERR_MSG_VALUE_AGRS			"invalid value of arguments"
# define ERR_MSG_SYNTAX_TOKEN		"invalid syntax at token"
# define ERR_MSG_NO_FILE_OR_DIR		"No such file or directory"
# define ERR_MSG_NOT_DIR			"Not a directory"
# define ERR_MSG_PERMISSION_DENIED	"permission denied"
# define ERR_MSG_CANNOT_READ		"cannot read file."
# define ERR_MSG_CANNOT_DELETE		"cannot delete file."
# define ERR_MSG_QUOTES				"quotes not paired"
# define ERR_MSG_COMMANDS			"command not found"
# define ERR_MSG_IDENTIFIER			"not a valid identifier"
# define ERR_MSG_TOO_MANY_ARGS		"too many arguments"
# define ERR_MSG_NUMERIC			"numeric arguments required"
# define ERR_MSG_SYNTAX_ERROR		"syntax error near unexpected token"
# define ERR_MSG_BASH_GETCWD		"getcwd: cannot access parent directories"
# define ERR_MSG_WORK_DIR			"error retrieving current directory"

# define HEREDOC_MAX				16
# define SHLVL_MIN					0
# define SHLVL_MAX					1000

# define WORD_NONE					"none"
# define WORD_WORD					"word"
# define WORD_EMPTY					""
# define WORD_SPACE					" "
# define WORD_WILDCARD				"*"
# define WORD_TAB					"\t"
# define WORD_ASSIGN				"="
# define WORD_BACKSLASH				"\\"
# define WORD_SQUOTE				"\'"
# define WORD_DQUOTE				"\""
# define WORD_BACKQUOTE				"`"
# define WORD_LESS					"<"
# define WORD_GREAT					">"
# define WORD_PIPE					"|"
# define WORD_SEMI					";"
# define WORD_AND					"&"
# define WORD_LBRACE				"{"
# define WORD_RBRACE				"}"
# define WORD_LPAREN				"("
# define WORD_RPAREN				")"
# define WORD_DASH					"-"
# define WORD_LBRACK				"["
# define WORD_RBRACK				"]"
# define WORD_NEWLINE				"newline"
# define WORD_AND_AND				"&&"
# define WORD_OR_OR					"||"
# define WORD_DGREAT				">>"
# define WORD_DLESS					"<<"
# define WORD_LESS_AND				"<&"
# define WORD_DLESS_LESS			"<<<"
# define WORD_GREAT_AND				">&"
# define WORD_DSEMI					";;"
# define WORD_SEMI_AND				";&"
# define WORD_DSEMI_AND				";;&"
# define WORD_DLESS_DASH			"<<-"
# define WORD_AND_GREAT				"&>"
# define WORD_AND_DGREAT			"&>>"
# define WORD_LESS_GREAT			"<>"
# define WORD_GREAT_PIPE			">|"
# define WORD_PIPE_AND				"|&"
# define WORD_EOF					"EOF"

# define TOKEN_NONE					-1
# define TOKEN_WORD					1
# define TOKEN_EMPTY				0
# define TOKEN_SPACE				' '
# define TOKEN_WILDCARD				'*'
# define TOKEN_TAB					'\t'
# define TOKEN_ASSIGN				'='
# define TOKEN_BACKSLASH			'\\'
# define TOKEN_SQUOTE				'\''
# define TOKEN_DQUOTE				'\"'
# define TOKEN_BACKQUOTE			'`'
# define TOKEN_LESS					'<'
# define TOKEN_GREAT				'>'
# define TOKEN_PIPE					'|'
# define TOKEN_SEMI					';'
# define TOKEN_AND					'&'
# define TOKEN_NEWLINE				'\n'
# define TOKEN_LBRACE				'{'
# define TOKEN_RBRACE				'}'
# define TOKEN_LPAREN				'('
# define TOKEN_RPAREN				')'
# define TOKEN_DASH					'-'
# define TOKEN_LBRACK				'['
# define TOKEN_RBRACK				']'
# define TOKEN_AND_AND				288
# define TOKEN_OR_OR				289
# define TOKEN_DGREAT				290
# define TOKEN_DLESS				291
# define TOKEN_LESS_AND				292
# define TOKEN_DLESS_LESS			293
# define TOKEN_GREAT_AND			294
# define TOKEN_DSEMI				295
# define TOKEN_SEMI_AND				296
# define TOKEN_DSEMI_AND			297
# define TOKEN_DLESS_DASH			298
# define TOKEN_AND_GREAT			299
# define TOKEN_AND_DGREAT			300
# define TOKEN_LESS_GREAT			301
# define TOKEN_GREAT_PIPE			302
# define TOKEN_PIPE_AND				303
# define TOKEN_EOF					304

#endif