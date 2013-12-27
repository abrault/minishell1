/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:51:45 by abrault           #+#    #+#             */
/*   Updated: 2013/12/23 16:14:22 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "libft/libft.h"

typedef struct s_list	t_list;

struct s_list
{
	char				*val;
	t_list				*next;
};

t_list	*inverse_list(t_list *list);
t_list	*add_element(char *str, t_list *list);
t_list	*getArray();
char	*extract_line(char **str);
char	*re_malloc(char *buff, char *str);
int	traitement(char **stock, char **line);
char	*ft_strtok(char *str, char sepa);

#endif /* !MINISHELL_H */
