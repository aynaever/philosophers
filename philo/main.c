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
	pthread_mutex_t	mutex[5];
	philo_t			philos[5];
	int				forks[5];
	pthread_t		philosophers[5];

	info.forks = forks;
	info.lock = malloc ( sizeof(pthread_mutex_t*) * 5 );
	info.threads = malloc ( sizeof(pthread_t*) * 5);

	for ( int i = 0;  i < 5; i++ )
	{
		forks[i] = 0;
		info.lock[i] = &mutex[i];
		info.threads[i] = &philosophers[i];
		philos[i].infos = &info;
	}

	if ( init_args ( &info, argc, argv ) == -1 )
		return (1);

	for ( int i = 0; i < 5; i++ )
	{
		philos[i].i = i;
		pthread_create ( &philosophers[i], NULL, p_dine, &philos[i] );
	}

	for ( int i = 0; i < 5; i++ )
	{
		printf ("Thread n: %d\n", i);
		pthread_join ( philosophers[i], NULL );
	}

	return (0);
}
