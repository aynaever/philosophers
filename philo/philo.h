/**
 * File              : philo.h
 * Author            : Aymane N <anaouadi@students.42wolfsburg.de>
 * Date              : 17.04.2022
 * Last Modified Date: 17.04.2022
 * Last Modified By  : Aymane N <anaouadi@students.42wolfsburg.de>
 */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define	LEFT		(info->i + info->nPhilos - 1) % info->nPhilos
# define	RIGHT		(info->i + 1) % info->nPhilos

typedef	struct	philo_s
{
	int					lastMeal;
}	philo_t;

typedef	struct	info_s
{
	int					nPhilos;
	int					timeToDie;
	int					timeToEat;
	int					timeToSleep;
	int					i;
	philo_t**			philos;
	int*				forks;
	pthread_mutex_t**	lock;
}	info_t;

void*		p_eat ( void* value );
void*		p_think ( void* value );
void*		p_sleep ( void* value );
void*		p_dine ( void* value );
suseconds_t	printTimeStamp ( void );
int			init_args ( info_t* info, int argc, char** argv );
int     	ft_atoi(const char *nptr);

#endif /* ifndef PHILO_H */
