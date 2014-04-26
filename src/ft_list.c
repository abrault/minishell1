/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 23:31:27 by abrault           #+#    #+#             */
/*   Updated: 2014/04/26 23:33:04 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list		*add_list(char *tok, t_list *list)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list->val = tok;
	new_list->next = list;
	return (new_list);
}

t_list		*get_path(char **environ)
{
	char	*tok;
	t_list	*list;

	list = NULL;
	if (environ == NULL)
		return (NULL);
	tok = ft_strtok(environ[0] + 5, ':');
	while (tok)
	{
		list = add_list(tok, list);
		tok = ft_strtok(NULL, ':');
	}
	return (list);
}

t_list		*inverse_list(t_list *list)
{
	t_list			*temp;
	t_list			*ret;

	temp = NULL;
	ret = NULL;
	while (list)
	{
		temp = list;
		list = temp->next;
		temp->next = ret;
		ret = temp;
	}
	return (ret);
}
