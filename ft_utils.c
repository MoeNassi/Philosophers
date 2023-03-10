/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:51:35 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/06 09:58:41 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;
	t_list	*nex;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = (*lst);
	nex = (*lst);
	while (nex->next != head)
		nex = nex->next;
	nex->next = new;
	new->next = head;
	new->prev = nex;
	head->prev = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->content = content;
	new->next = new;
	new->prev = new;
	return (new);
}

int	ft_atoi(const char *str)
{
	int							i;
	size_t						c;
	int							minus;

	minus = 1;
	i = 0;
	c = 0;
	while ((str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-')
		minus *= (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		i++;
	}
	return (c * minus);
}