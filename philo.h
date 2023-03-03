/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:27 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/03 14:02:04 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

int		numberofphilo(char **checker);
int		ft_atoi(const char *str);
int		abovesixteen(char **sechecker);
int		intchecker(char	**arguments);

#endif