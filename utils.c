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
	printf("%ld %d Philosopher is eating\n", printTimeStamp(),*( int* ) value);

	return ( NULL );
}

void*	p_think ( void* value )
{
	printf("%ld %d Philosopher is thinking\n", printTimeStamp(),*( int* ) value);

	return ( NULL );
}

void*	p_sleep ( void* value )
{
	printf("%ld %d Philosopher is sleeping\n", printTimeStamp(), *( int* ) value);

	return ( NULL );
}

void*	p_dine ( void* value )
{
	printf ("Philosopher Created\n");

	p_eat ( value );
	p_sleep ( value );
	p_think ( value );

	return ( NULL );
}

suseconds_t	printTimeStamp ( void )
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_usec);
}
