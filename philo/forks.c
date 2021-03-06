/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:05 by anaouadi          #+#    #+#             */
/*   Updated: 2022/04/29 17:31:03 by anaouadi         ###   ########.fr       */
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
		if (philo->infos->time_to_die <= (print_time_stamp() - philo->last_meal))
		{
			printf(RED"%ld %d died\n", print_time_stamp(), philo->i);
			return ((void *) &philo->infos);
		}
	}
	pthread_mutex_lock(philo->infos->lock[philo->i]);
	philo->infos->forks[left] = 1;
	philo->infos->forks[right] = 1;
	return (NULL);
}

void	*put_forks(void *value)
{
	t_philo	*philo;
	int		left;
	int		right;

	philo = (t_philo *) value;
	right = (philo->i + 1) % philo->infos->n_philos;
	left = (philo->i + philo->infos->n_philos - 1) % philo->infos->n_philos;
	philo->infos->forks[left] = 0;
	philo->infos->forks[right] = 0;
	return (NULL);
}
