/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:50:49 by abrault           #+#    #+#             */
/*   Updated: 2013/12/23 17:17:17 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	**getTab(int i, t_list *list)
{
	int		j;
	char		**tab;

	j = 0;
	tab = (char**)malloc(sizeof(*tab) * (i + 1));
	while (i > j)
	{
		tab[j] = list->val;
		list = list->next;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

t_list	*getArray(int *i)
{
	char		*line;
	char		*tok;
	t_list		*list;

	list = NULL;
	get_next_line(0, &line);
	tok = ft_strtok(line, ' ');
	if (*line == '\0')
		tok = NULL;
	while (tok)
	{
		*i = *i + 1;
		list = add_element(tok, list);
		tok = ft_strtok(NULL, ' ');
	}
	return (inverse_list(list));
}

void	ft_exe(char **tab, int i)
{
	pid_t		father;
	char		*str;
	int		status;
	int		res;

	if (i)
	{
		str = (char*)malloc(sizeof(char) *( 5 + ft_strlen(tab[0])));
		ft_strcpy(str, "/bin/");
		ft_strcat(str, tab[0]);
		father = fork();
		if (father > 0)
		{
			wait(&status);
			write(1, "$>", 2);
		}
		if (father == 0)
		{
			res = execve(str, tab, NULL);
			if (res == -1)
				write(1, "Command not found ...\n$>", 24);
		}
		free(str);
	}
}

int	main(void)
{
	t_list		*list;
	pid_t		proc;
	char		**tab;
	int		i;
	int		nb_elem;

	tab = NULL;
	write(1, "$>", 2);
	while (1)
	{
		nb_elem = 0;
		i = 0;
		list = getArray(&i);
		if (tab != NULL)
			free(tab);
		tab = getTab(i, list);
		if (i)
		{
			if (ft_strcmp("exit", tab[0]) == 0)
				return (0);
			ft_exe(tab, i);
		}
		else
			write(1, "$>", 2);
	}
	return (0);
}
