/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:05 by anaouadi          #+#    #+#             */
/*   Updated: 2022/04/29 16:10:36 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*take_forks(void *value)
{
	t_philo	*philo;
	int		left;
	int		right;

	philo = (t_philo *) value;
	right = (philo->i + 1) % philo->infos->n_philos;
	left = (philo->i + philo->infos->n_philos - 1) % philo->infos->n_philos;
	while ((philo->infos->forks[left] == 1) | (philo->infos->forks[right] == 1))
	{
		if (philo->infos->time_to_die <= (philo->last_meal * 1000))
		{
			printf(RED"%ld %d died\n", print_time_stamp(), philo->i);
			return ((void *) &philo->infos);
		}
	}
	return (NULL);
}
