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
	info_t	info;

	int			forks[5];
	pthread_t	philosophers[5];
	info.forks = forks;
	pthread_mutex_t	mutex[5];
	philo_t			philos[5];
	info.lock = malloc ( sizeof(pthread_mutex_t*) * 5 );
	info.philos = malloc ( sizeof(philo_t*) * 5 );

	for ( int i = 0;  i < 5; i++ )
	{
		forks[i] = 0;
		info.lock[i] = &mutex[i];
		info.philos[i] = &philos[i];
	}

	if ( init_args ( &info, argc, argv ) == -1 )
		return (1);

	for ( int i = 0; i < 5; i++ )
	{
		info.i = i;
		pthread_create ( &philosophers[i], NULL, p_dine, &info );
		usleep (500);
	}

	for ( int i = 0; i < 5; i++ )
	{
		printf ("Thread n: %d\n", i);
		pthread_join ( philosophers[i], NULL );
	}

	return (0);
}
