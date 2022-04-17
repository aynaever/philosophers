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
        {
                i++;
        }
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

void	init_args ( info_t* info, char** argv )
{
	info->nPhilos = ft_atoi ( argv[1] );
	info->timeToDie = ft_atoi ( argv[2] );
	info->timeToEat = ft_atoi ( argv[3] );
	info->timeToSleep = ft_atoi ( argv[4] );
}
