/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:13:12 by anaouadi          #+#    #+#             */
/*   Updated: 2022/04/29 16:14:10 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*p_eat(void *value)
{
	t_philo	*philo;

	philo = (t_philo *) value;
	take_forks(value);
	pthread_mutex_lock(philo->infos->lock[philo->i]);
	philo->last_meal = print_time_stamp();
	printf(BLUE"%ld %d Philosopher is eating\n", print_time_stamp(), philo->i);
	usleep(philo->infos->time_to_eat * 1000);
	put_forks(value);
	pthread_mutex_unlock(philo->infos->lock[philo->i]);
	return (NULL);
}

void	*p_think(void *value)
{
	t_philo	*philo;

	philo = (t_philo *) value;
	printf(YELLOW"%ld %d Philosopher is thinking\n"\
	, print_time_stamp(), philo->i);
	return (NULL);
}

void	*p_sleep(void *value)
{
	t_philo	*philo;

	philo = (t_philo *) value;
	printf(CYAN"%ld %d Philosopher is sleeping\n", print_time_stamp(), philo->i);
	usleep(philo->infos->time_to_sleep * 1000);
	return (NULL);
}

void	*p_dine(void *value)
{
	t_philo	*philo;

	philo = (t_philo *) value;
	philo->last_meal = print_time_stamp();
	while (1)
	{
		if (p_eat(value) != NULL )
			return (NULL);
		p_sleep(value);
		p_think(value);
	}
	return (NULL);
}

suseconds_t	print_time_stamp(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec + tp.tv_usec);
}
