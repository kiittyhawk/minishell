/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:00:51 by llornel           #+#    #+#             */
/*   Updated: 2022/03/20 23:39:15 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_LL_INT 9223372036854775807

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstdup(t_list *lst, void *(*f)(void *));
void		ft_lstadd(t_list **lst, void *content, void *(*f)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_btree		*ft_btree_create_node(void *item);
int			ft_btree_level_count(t_btree *root);
int			ft_btree_nodes_count(t_btree *root);
void		ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void		ft_btree_apply_node_infix(t_btree *root, void (*applyf)(t_btree *));
void		ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void		ft_btree_apply_node_prefix(t_btree *root,
				void (*applyf)(t_btree *));
void		ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void		ft_btree_apply_node_suffix(t_btree *root,
				void (*applyf)(t_btree *));
void		ft_btree_insert_data(t_btree **root, void *item,
				int (*cmpf)(void *, void *));
void		*ft_btree_search_item(t_btree *root, void *data_ref,
				int (*cmpf)(void *, void *));

bool		ft_isalpha(int c);
bool		ft_isdigit(int c);
bool		ft_isalnum(int c);
bool		ft_isascii(int c);
bool		ft_isprint(int c);
bool		ft_isspace(char c);
bool		ft_iswhitespace(char c);
bool		ft_iswildcard(int c);
bool		ft_isplusminus(char s);
bool		ft_strisempty(char *str);
bool		ft_striswildcard(char *str);
bool		ft_strisdigit(char *str);
bool		ft_strexistsdigit(char *str);
bool		ft_strisnumber(char *str);
bool		ft_strischar(char *str, int c);

int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);

char		*ft_itoa(int n);
char		*ft_itoa_base(unsigned long n, int base);
char		*ft_uitoa(unsigned int nbr);
int			ft_atoi(const char *str);
int			ft_atoi_num(const char *str, int *nbr);
long		ft_atol(const char *str);
int			ft_atol_num(const char *str, long *nbr);
double		ft_atod(const char *str);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_memdel(void *ptr);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *src, size_t n);

int			ft_nbrlen(long nbr);
int			ft_nbrlen_base(unsigned long n, int base);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
char		**ft_split(char const *s, char c);
char		**ft_split_sep(char const *str, char const *sep);
void		ft_split_free(char **split);
int			ft_split_size(char const *str, char const *sep);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *str, char const *set);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_strrev(char *str);
void		ft_strdel(char **str);
void		ft_strset(void **dst, void *src);
char		*ft_strreplace(char const *str, char const *set);
int			ft_strsep(const char *str, const char *sep);
int			ft_strnsep(const char *str, const char *sep, int n);

int			ft_min(int a, int b);
int			ft_max(int a, int b);
void		ft_swap(void **a, void **b);

size_t		ft_tabsize(char **tab);
void		ft_tabfree(char **tab);
void		ft_tabprint(char **tab);
void		ft_tabsort(char **tab);
void		ft_tabiter(char **tab, void (*f)(char *));
char		*ft_tabtostr(char **tab, char *sep);
char		**ft_tabdup(char **tab);
char		**ft_tabcat(char **dest, char **src);
char		**ft_tabjoin(char **tab1, char **tab2);
char		**ft_list_to_tab(t_list *lst, void *(*f)(void *));

int			ft_putchar_fd(int fd, char c);
int			ft_putchar(char c);
int			ft_putnchar_fd(int fd, char c, int n);
int			ft_putnchar(char c, int n);
int			ft_putstr_fd(int fd, char *str);
int			ft_putstr(char *str);
int			ft_putendl_fd(int fd, char *str);
int			ft_putendl(char *str);
int			ft_putnbr_fd(int fd, int n);
int			ft_putnbr(int n);
int			ft_putnbr_base_fd(int fd, unsigned long n, char *base);
int			ft_putnbr_base(unsigned long n, char *base);

#endif
