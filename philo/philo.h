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

# define	LEFT		(philo->i + philo->infos->nPhilos - 1) % philo->infos->nPhilos
# define	RIGHT		(philo->i + 1) % philo->infos->nPhilos

typedef	struct	info_s
{
	int					nPhilos;
	int					timeToDie;
	int					timeToEat;
	int					timeToSleep;
	int*				forks;
	pthread_mutex_t**	lock;
}	info_t;

typedef	struct	philo_s
{
	int					lastMeal;
	int					i;
	info_t*				infos;
}	philo_t;

void*		p_eat ( void* value );
void*		p_think ( void* value );
void*		p_sleep ( void* value );
void*		p_dine ( void* value );
suseconds_t	printTimeStamp ( void );
int			init_args ( info_t* info, int argc, char** argv );
int     	ft_atoi(const char *nptr);

#endif /* ifndef PHILO_H */
