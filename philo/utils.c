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
	philo_t*	philo;

	philo = (philo_t*) value;
	printf("%ld %d Philosopher is eating\n", printTimeStamp(), philo->i);

	pthread_mutex_lock ( philo->infos->lock[philo->i] );

	philo->lastMeal = printTimeStamp();
	/* Change state of forks to 1 */
	philo->infos->forks[LEFT] = 1;
	philo->infos->forks[RIGHT] = 1;

	/* Wait for philospher to eat */
	usleep ( philo->infos->timeToEat * 1000 );

	/* Put Forks */
	philo->infos->forks[LEFT] = 0;
	philo->infos->forks[RIGHT] = 0;

	pthread_mutex_unlock ( philo->infos->lock[philo->i] );
	return ( NULL );
}

void*	p_think ( void* value )
{
	philo_t*	philo;

	philo = (philo_t*) value;
	printf("%ld %d Philosopher is thinking\n", printTimeStamp(), philo->i);

	/* Keep trying to acquire the forks */
	while ( (philo->infos->forks[LEFT] == 1) | (philo->infos->forks[RIGHT] == 1) );

	return ( NULL );
}

void*	p_sleep ( void* value )
{
	philo_t*	philo;

	philo = (philo_t*) value;
	printf("%ld %d Philosopher is sleeping\n", printTimeStamp(), philo->i);
	usleep ( philo->infos->timeToSleep * 1000 );
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
