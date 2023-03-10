/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:49 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/10 16:36:40 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	currenttime(t_list *scurrtime)
{
	struct timeval	time;
	size_t			stockthetime;
	size_t			stock;

	stockthetime = 0;
	stock = gettimeofday(&time, NULL);
	stockthetime = (time.tv_sec * 1000) - (time.tv_usec / 1000) - scurrtime->ghbiy.timee;
	return (stockthetime);
}

void	*philoeatorsleep(void *philo)
{
	t_list	*philos;
	size_t	timecur;

	philos = (t_list *)philo;
	timecur = 0;
	while(philos)
	{
		timecur = currenttime(philos);
		printf("%zu\t", timecur);
		printf("%d\t", philos->content);
		printf("eating %d\n", philos->content);
		usleep(100);
		timecur = currenttime(philos);
		printf("%zu\t", timecur);
		printf("thinking %d\n", philos->content);
		usleep(100);
		timecur = currenttime(philos);
		printf("%zu\t", timecur);
		printf("sleeping %d\n", philos->content);
		usleep(100);
	}
	return (0);
}

int main(int ac, char **av)
{
	int			i;
	t_list		*philoso;
	t_list		*head;
	t_stock		he;
	struct timeval	time;
	int			stock;

	i = 1;
	stock = ft_atoi(av[1]);
	if (ac - 1 > 3 && ac - 1 < 6)
	{
		if (intchecker(av) && numberofphilo(av) && abovesixteen(av))
		{
			while (i <= stock)
				ft_lstadd_back(&philoso, ft_lstnew(i++));
			head = philoso;
			he.timee = 0;
			he.timee = gettimeofday(&time, NULL);
			while (philoso)
			{
				if (pthread_create(&head->hawahed, NULL, &philoeatorsleep, head))
					return (printf("%s\n", "Error"));
				pthread_detach(head->hawahed);
				head = head->next;
				if (head == philoso)
					break ;
			}
		}
		else
			return (printf("%s\n", "Error"));
	}
	else
		return (printf("%s\n", "Error"));
}