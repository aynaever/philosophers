/**
 * File              : main.c
 * Author            : Aymane N <anaouadi@students.42wolfsburg.de>
 * Date              : 16.04.2022
 * Last Modified Date: 16.04.2022
 * Last Modified By  : Aymane N <anaouadi@students.42wolfsburg.de>
 */

#include	"philo.h"

int main(int argc, char** argv)
{
	t_info			info;
	if ( init_args ( &info, argc, argv ) == -1 )
		return (1);

	pthread_mutex_t	mutex[info.n_philos];
	t_philo			philos[info.n_philos];
	int				forks[info.n_philos];
	pthread_t		philosophers[info.n_philos];

	info.forks = forks;
	info.lock = malloc ( sizeof(pthread_mutex_t*) * info.n_philos );
	info.threads = malloc ( sizeof(pthread_t*) * info.n_philos);

	for ( int i = 0;  i < info.n_philos; i++ )
	{
		forks[i] = 0;
		pthread_mutex_init(&mutex[i], NULL);
		info.lock[i] = &mutex[i];
		info.threads[i] = &philosophers[i];
		philos[i].infos = &info;
	}

	for ( int i = 0; i < info.n_philos; i++ )
	{
		philos[i].i = i;
		pthread_create ( &philosophers[i], NULL, p_dine, &philos[i] );
	}

	for ( int i = 0; i < info.n_philos; i++ )
	{
		pthread_join ( philosophers[i], NULL );
	}

	return (0);
}
