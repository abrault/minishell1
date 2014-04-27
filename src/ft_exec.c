/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 19:33:12 by abrault           #+#    #+#             */
/*   Updated: 2014/04/27 14:46:02 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

void		ft_exe(char *command, char **option, char **environ)
{
	pid_t		father;
	int			status;
	int			res;

	father = fork();
	if (father > 0)
		wait(&status);
	if (father == 0)
		res = execve(command, option, environ);
	free(command);
	(void)res;
}

int			special_command(char *str)
{
	if (ft_strcmp(str, "exit") == 0)
		exit(0);
	return (0);
}

char		*find_path(t_list *l_path, char *prog)
{
	char		*path;

	while (l_path)
	{
		path = malloc(sizeof(ft_strlen(l_path->val) + ft_strlen(prog) + 2));
		ft_strcpy(path, l_path->val);
		ft_strcat(path, "/");
		ft_strcat(path, prog);
		if (access(path, X_OK) == 0)
			return (path);
		l_path = l_path->next;
		free(path);
	}
	return (NULL);
}

int			try_command(t_list *l_path, char **environ, char **tab)
{
	char		*path;

	(void)environ;
	if (!special_command(tab[0]))
	{
		path = find_path(l_path, tab[0]);
		if (path != NULL)
		{
			ft_exe(path, tab, environ);
		}
		else
			return (0);
	}
	return (1);
}
