/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 19:17:41 by abrault           #+#    #+#             */
/*   Updated: 2014/04/27 00:01:33 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFF_SIZE 4096

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <libft.h>

typedef struct s_list	t_list;
typedef struct s_read	t_read;

struct s_list
{
	char				*val;
	t_list				*next;
};

struct					s_read
{
	int					size;
	int					index;
	int					fd;
	char				*read;
	t_read				*next;
};

int						get_next_line(int const fd, char **line);
t_list					*add_list(char *tok, t_list *list);
t_list					*get_path(char **environ);
t_list					*inverse_list(t_list *list);
void					ft_exe(char *command, char **option, char **environ);
int						try_command(t_list *path, char **environ, char **tab);

#endif /* !MINISHELL_H */
