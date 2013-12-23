/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:50:49 by abrault           #+#    #+#             */
/*   Updated: 2013/12/23 17:11:25 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	**getTab(int i, t_list *list)
{
	int			j;
	char		**tab;

	j = 0;
	tab = (char**)malloc(sizeof(*tab) * i);
	while (i > j)
	{
		tab[j] = list->val;
		list = list->next;
		j++;
	}
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
		list = add_element(tok, list);
		tok = ft_strtok(NULL, ' ');
	}
	return (inverse_list(list));
}

int		main(void)
{
	t_list		*list;
	pid_t		proc;
	char		**tab;
	int			i;

	while (1)
	{
		write(1, "$>", 3);
		list = getArray(&i);
		tab = getTab(i, list);
		printf("|%s|", tab[0]);
		printf("|%s|", tab[1]);
	}
	return (0);
}
