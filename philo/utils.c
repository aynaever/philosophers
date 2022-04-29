/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:13:12 by anaouadi          #+#    #+#             */
/*   Updated: 2022/04/29 17:33:32 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*p_eat(void *value)
{
	t_philo	*philo;

	philo = (t_philo *) value;
	if (take_forks(value) != NULL)
		return ((void *) &philo->infos);
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
	int		i;

	philo = (t_philo *) value;
	printf(CYAN"%ld %d Philosopher is sleeping\n", print_time_stamp(), philo->i);
	i = 0;
	while (i < philo->infos->time_to_sleep / 5)
	{
		/* printf("%d I'm sleeping %d \n", philo->i,i); */
		if (philo->infos->time_to_die <= (print_time_stamp() - philo->last_meal))
		{
			printf(RED"%ld %d died\n", print_time_stamp(), philo->i);
			return ((void *) &philo->infos);
		}
		i+=5;
		usleep(5 * 1000);
	}
	return (NULL);
}

void	*p_dine(void *value)
{
	t_philo	*philo;

	philo = (t_philo *) value;
	philo->last_meal = print_time_stamp();
	while (1)
	{
		/* printf("time_to_die=%ld\n", philo->infos->time_to_die); */
		/* printf("diff time=%ld\n", print_time_stamp() - philo->last_meal); */
		/* printf("last meal=%ld\n", philo->last_meal); */
		/* printf("time stamp=%ld\n", print_time_stamp()); */
		if (p_eat(value) != NULL )
			return (NULL);
		if (p_sleep(value) != NULL )
			return (NULL);
		p_think(value);
	}
	return (NULL);
}

long int	print_time_stamp(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}
