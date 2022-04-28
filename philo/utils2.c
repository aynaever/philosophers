/**
 * File              : utils2.c
 * Author            : Aymane N <anaouadi@students.42wolfsburg.de>
 * Date              : 17.04.2022
 * Last Modified Date: 17.04.2022
 * Last Modified By  : Aymane N <anaouadi@students.42wolfsburg.de>
 */

#include	"philo.h"

int     ft_start(const char *s)
{
        int     i;

        i = 0;
        while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r'
                || s[i] == '\v' || s[i] == '\f' || s[i] == ' ')
                i++;
        return (i);
}

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

int     ft_atoi(const char *nptr)
{
        int     len;
        int     i;
        int     sign;
        int     rslt;

        len = ft_strlen(nptr);
        i = ft_start(nptr);
        rslt = 0;
        sign = 1;
        if (nptr[i] == '-')
        {
                i++;
                sign = -1;
        }
        else if (nptr[i] == '+')
                i++;
        while (i < len)
        {
                if (nptr[i] >= '0' && nptr[i] <= '9')
                        rslt = nptr[i] + rslt * 10 - 48;
                else
                        break ;
                i++;
        }
        return (sign * rslt);
}

int	init_args ( info_t* info, int argc, char** argv )
{
	if ( argc >= 5 && argc <= 6 )
	{
		info->nPhilos = ft_atoi ( argv[1] );
		info->timeToDie = ft_atoi ( argv[2] );
		info->timeToEat = ft_atoi ( argv[3] );
		info->timeToSleep = ft_atoi ( argv[4] );
		info->i = 0;
		return (0);
	}
	else
	{
		printf ( "Please Enter Arguments as follows: <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
}
