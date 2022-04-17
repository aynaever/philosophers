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

	/* int			forks[5]; */
	pthread_t	philosophers[5];

	/* for ( int i = 0;  i < 5; ++i ) */
	/* 	forks[i] = 0; */

	init_args ( &info, argv );

	for ( int i = 0; i < 5; i++ )
	{
		pthread_create ( &philosophers[i], NULL, p_dine, &i );
		usleep (500);
	}

	for ( int i = 0; i < 5; i++ )
	{
		printf ("Thread n: %d\n", i);
		pthread_join ( philosophers[i], NULL );
	}

	return (argc);
}
