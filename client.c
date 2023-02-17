/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:43 by esali             #+#    #+#             */
/*   Updated: 2023/02/16 21:54:17 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//sends eiter SIGUSR1 or SIGUSR2
void send_signal(char* bin, int pid)
{
	while(*bin)
	{
		if(*bin == '0') {
			kill(pid, SIGUSR1);
			// ft_printf("\n0");
		}
		else
		{
			kill(pid, SIGUSR2);
			// ft_printf("\n1");
		}
		usleep(100);
		bin++;
	}
}

//changes a character to its binary representation
void	tobin(char c, int pid)
{
	int		i;
	char	bin[9] ;

	i = 8;
	while (i > 0)
	{
		if (c % 2 == 0)
			bin[i-1] = '0';
		else
			bin[i-1] = '1';
		c = c / 2;
		i--;
	}
	bin[8] = '\0';
	send_signal(bin, pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if(argc != 3 )
	 	return (0);
	pid = atoi(argv[1]);
	while(*argv[2])
	{
		tobin(*argv[2], pid);
		argv[2]++;
	}
	send_signal("00000000", pid); //final \0 to show that string is finished
	return (0);
}


