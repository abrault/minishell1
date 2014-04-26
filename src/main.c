/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 19:33:12 by abrault           #+#    #+#             */
/*   Updated: 2014/04/26 23:40:26 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char		**get_tab(int i, t_list *list)
{
	int				j;
	char			**tab;

	j = 0;
	if ((tab = (char**)malloc(sizeof(*tab) * (i + 1))) == NULL)
		return (NULL);
	while (i > j)
	{
		tab[j] = list->val;
		list = list->next;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

t_list		*get_array(int *i, char *line)
{
	char		*tok;
	t_list		*list;
	int			q;

	q = 0;
	while (line[q] != '\0')
	{
		if (line[q] == '\t')
			line[q] = ' ';
		q++;
	}
	list = NULL;
	tok = ft_strtok(line, ' ');
	if (*line == '\0')
		tok = NULL;
	while (tok)
	{
		*i = *i + 1;
		list = add_list(tok, list);
		tok = ft_strtok(NULL, ' ');
	}
	return (inverse_list(list));
}

int			main(int ac, char **av, char **environ)
{
	t_list		*path;
	char		*line;
	int			i;
	t_list		*list;
	char		**tab;

	write(1, "$> ", 2);
	path = get_path(environ);
	(void)ac;
	(void)av;
	while (get_next_line(0, &line))
	{
		i = 0;
		list = NULL;
		list = get_array(&i, line);
		tab = get_tab(i, list);
		if (!try_command(path, environ, tab))
			ft_putendl("Command not found ...");
		write(1, "$> ", 2);
	}
	return (0);
}
