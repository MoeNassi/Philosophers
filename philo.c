/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:49 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/04 17:10:29 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	int		i;
	t_list	*philoso;
	t_list	*head;
	int		stock;
	pthread_t	hawahed;

	i = 1;
	stock = ft_atoi(av[1]);
	if (ac - 1 > 3 && ac - 1 < 6)
	{
		if (intchecker(av) && numberofphilo(av) && abovesixteen(av))
		{
			while (i <= stock)
			{
				ft_lstadd_back(&philoso, ft_lstnew(i++));
				if (pthread_create(hawahed, NULL, NULL, &i))
					return (printf("%s\n", "Error"));
				pthread_detach(hawahed);
			}
			head = philoso;
			while (philoso)
			{
				printf("%d\n", head->content);
				head = head->next;
				if (head == philoso)
					break ;
			}
		}
		else
			return (printf("%s\n", "Error"));
	}
}