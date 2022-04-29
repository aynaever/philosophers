/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:53:56 by anaouadi          #+#    #+#             */
/*   Updated: 2022/04/29 15:08:33 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define RED "\033[31m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"

typedef struct s_info
{
	int					n_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					*forks;
	pthread_mutex_t		**lock;
	pthread_t			**threads;
}	t_info;

typedef struct s_philo
{
	int					last_meal;
	int					i;
	t_info				*infos;
}	t_philo;

void		*p_eat(void *value);
void		*p_think(void *value);
void		*p_sleep(void *value);
void		*p_dine(void *value);
suseconds_t	printTimeStamp(void);
int			init_args(info_t *info, int argc, char **argv);
int			ft_atoi(const char *nptr);

#endif /* ifndef PHILO_H */
