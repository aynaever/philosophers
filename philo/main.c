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
	info_t			info;
	if ( init_args ( &info, argc, argv ) == -1 )
		return (1);

	pthread_mutex_t	mutex[info.nPhilos];
	philo_t			philos[info.nPhilos];
	int				forks[info.nPhilos];
	pthread_t		philosophers[info.nPhilos];

	info.forks = forks;
	info.lock = malloc ( sizeof(pthread_mutex_t*) * info.nPhilos );
	info.threads = malloc ( sizeof(pthread_t*) * info.nPhilos);

	for ( int i = 0;  i < info.nPhilos; i++ )
	{
		forks[i] = 0;
		pthread_mutex_init(&mutex[i], NULL);
		info.lock[i] = &mutex[i];
		info.threads[i] = &philosophers[i];
		philos[i].infos = &info;
	}

	for ( int i = 0; i < info.nPhilos; i++ )
	{
		philos[i].i = i;
		pthread_create ( &philosophers[i], NULL, p_dine, &philos[i] );
	}

	for ( int i = 0; i < info.nPhilos; i++ )
	{
		pthread_join ( philosophers[i], NULL );
	}

	return (0);
}
