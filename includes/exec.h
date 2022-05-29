/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:38 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 16:52:37 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

int			ft_process_exit_signal(int status);
int			ft_process_exit_status(int status);
int			ft_wait_process(void);

int			ft_dup_error(int fdold, int fdnew);
int			ft_close_error(int fd);
int			ft_restore_fd(int fd, int fdup);

int			ft_close_fd(int fd);
int			ft_close_pipe(int fdin, int fdout);
int			ft_restore_std(int fdin, int fdout);
int			ft_do_pipe(int fdin, int fdout, int closefd[3],
				t_exec_cmd *exec_cmd);

int			ft_do_redirects(t_exec_cmd *exec_cmd);
int			ft_do_simplecmd(t_exec_cmd *exec_cmd);

int			ft_exec_error(char *command, int flag);
int			ft_exists_cmd(t_exec_cmd *exec_cmd);
int			ft_exists_cmds(t_list *exec_cmds);
int			ft_exists_redirects(t_list *redirects);
int			ft_execve(char *command, char **args, char **envp);
int			ft_execute_cmd(t_exec_cmd *exec_cmd);
int			ft_execute_jobs(t_list **exec_cmds);
int			ft_execute_job(t_exec_cmd *exec_cmd);
int			ft_execute_builtin(t_exec_cmd *exec_cmd);

int			ft_build_cmd(t_list **exec_cmds, t_command *command);
int			ft_build_job(t_list **exec_cmds, t_list *lst);
int			ft_run_job(t_list **exec_cmds);
int			ft_executor(t_list **lst);

#endif
