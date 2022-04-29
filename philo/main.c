/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:42:34 by anaouadi          #+#    #+#             */
/*   Updated: 2022/04/29 18:47:22 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argc, char **argv)
{
	t_info			info;
	pthread_mutex_t	mutex[info.n_philos];
	t_philo			philos[info.n_philos];
	int				forks[info.n_philos];
	int				i;
	pthread_t		philosophers[info.n_philos];

	if (init_args(&info, argc, argv) == -1)
		return (1);
	info.forks = forks;
	info.lock = malloc(sizeof(pthread_mutex_t *) * info.n_philos);
	info.threads = malloc(sizeof(pthread_t *) * info.n_philos);
	i = 0;
	while (i < info.n_philos)
	{
		forks[i] = 0;
		pthread_mutex_init(&mutex[i], NULL);
		info.lock[i] = &mutex[i];
		info.threads[i] = &philosophers[i];
		philos[i].infos = &info;
		i++;
	}
	i = 0;
	while (i < info.n_philos)
	{
		philos[i].i = i;
		pthread_create ( &philosophers[i], NULL, p_dine, &philos[i] );
		i++;
	}
	i = 0;
	while (i < info.n_philos)
	{
		pthread_join ( philosophers[i], NULL );
		i++;
	}
	return (0);
}
