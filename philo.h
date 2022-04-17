/**
 * File              : philo.h
 * Author            : Aymane N <anaouadi@students.42wolfsburg.de>
 * Date              : 17.04.2022
 * Last Modified Date: 17.04.2022
 * Last Modified By  : Aymane N <anaouadi@students.42wolfsburg.de>
 */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

void*	p_eat ( void* value );
void*	p_think ( void* value );
void*	p_sleep ( void* value );
void*	p_dine ( void* value );
suseconds_t	printTimeStamp ( void );

#endif /* ifndef PHILO_H */
