/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:27 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/20 15:02:51 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct	l_stock
{
	size_t		timee;
}				t_stock;

typedef struct	l_list
{
	struct l_list	*next;
	struct l_list	*prev;
	pthread_t		hawahed;
	pthread_mutex_t	fork;
	pthread_mutex_t	printactiv;
	int				content;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				flag;
	struct l_stock	*ghbiy;
	long long		lasttime;
}				t_list;

int			numberofphilo(char **checker);
int			ft_atoi(const char *str);
int			abovesixteen(char **sechecker);
int			intchecker(char	**arguments);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content, t_stock *l, char **stocking);
void		copythisht(char **stocking, t_list *full);
long long	currenttime(void);
void		ft_got_sleep(long long how);

#endif