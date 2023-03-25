/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:49 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/25 13:36:08 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	currenttime(void)
{
	struct timeval				time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	printactivity(t_list *philo, char *message)
{
	pthread_mutex_lock(&philo->hadiankhdembiha);
	printf("%lld %d %s\n", currenttime() - philo->ghbiy->timee, philo->content, message);
	if (philo->flag)
		pthread_mutex_unlock(&philo->hadiankhdembiha);
}

void	*philoeatorsleep(void *philo)
{
	t_list			*philos;

	philos = (t_list *)philo;
	if (philos->content % 2)
		usleep(200);
	while (philos->flag)
	{
		pthread_mutex_lock(&philos->fork);
		printactivity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->next->fork);
		printactivity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->printactiv);
		philos->lasttime = currenttime();
		philos->eating++;
		pthread_mutex_unlock(&philos->printactiv);
		printactivity(philos, "is eating");
		ft_go_sleep(philos->ghbiy->time_eat);
		pthread_mutex_unlock(&philos->fork);
		pthread_mutex_unlock(&philos->next->fork);
		printactivity(philos, "is sleeping");
		ft_go_sleep(philos->ghbiy->time_sleep);
		printactivity(philos, "is thinking");
	}
	return (NULL);
}

int main(int ac, char **av)
{
	int			i;
	t_list		*philoso;
	t_list		*head;
	t_stock		all;
	int			stock;

	i = 1;
	stock = ft_atoi(av[1]);
	if (ac - 1 > 3 && ac - 1 < 6)
	{
		if (intchecker(av) && numberofphilo(av) && abovesixteen(av))
		{
			while (i <= stock)
				ft_lstadd_back(&philoso, ft_lstnew(i++, &all));
			copythisht(av, philoso);
			all.timee = currenttime();
			head = philoso;
			while (philoso)
			{
				head->lasttime = currenttime();
				if (pthread_create(&head->hawahed, NULL, &philoeatorsleep, head) != 0)
					return (printf("%s\n", "Error"));
				pthread_detach(head->hawahed);
				head = head->next;
				if (head == philoso)
					break ;
			}
			while(1)
			{
				pthread_mutex_lock(&philoso->printactiv);
				// if (philoso->eating  philoso->ghbiy->stop)
				// 	break ;
				if ((currenttime() - philoso->lasttime) > philoso->ghbiy->time_die)
				{
					printactivity(philoso, "died");
					philoso->flag = 0;
					break ;
				}
				pthread_mutex_unlock(&philoso->printactiv);				
				philoso = philoso->next;
			}
			pthread_mutex_unlock(&philoso->printactiv);				
		}
		else
			return (printf("%s\n", "Error"));
	}
	else
		return (printf("%s\n", "Error"));
}