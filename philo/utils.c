/**
 * File              : utils.c
 * Author            : Aymane N <anaouadi@students.42wolfsburg.de>
 * Date              : 17.04.2022
 * Last Modified Date: 17.04.2022
 * Last Modified By  : Aymane N <anaouadi@students.42wolfsburg.de>
 */

#include	"philo.h"

void*	p_eat ( void* value )
{
	info_t*	info;

	info = (info_t*) value;
	printf("%ld %d Philosopher is eating\n", printTimeStamp(), info->i);

	pthread_mutex_lock ( info->lock[info->i] );

	/* Keep trying to acquire the forks */
	while ( (info->forks[LEFT] == 1) | (info->forks[RIGHT] == 1) );

	/* Change state of forks to 1 */
	info->forks[LEFT] = 1;
	info->forks[RIGHT] = 1;

	/* Wait for philospher to eat */
	usleep ( info->timeToEat * 1000 );

	/* Put Forks */
	info->forks[LEFT] = 0;
	info->forks[RIGHT] = 0;

	pthread_mutex_unlock ( info->lock[info->i] );
	return ( NULL );
}

void*	p_think ( void* value )
{
	printf("%ld %d Philosopher is thinking\n", printTimeStamp(),*( int* ) value);
	return ( NULL );
}

void*	p_sleep ( void* value )
{
	info_t*	info;

	info = (info_t*) value;
	printf("%ld %d Philosopher is sleeping\n", printTimeStamp(), *( int* ) value);
	usleep ( info->timeToSleep * 1000 );
	return ( NULL );
}

void*	p_dine ( void* value )
{
	printf ("Philosopher Created\n");

	while (1)
	{
		p_eat ( value );
		p_sleep ( value );
		p_think ( value );
	}

	return ( NULL );
}

suseconds_t	printTimeStamp ( void )
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_usec);
}
