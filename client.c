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

//changes a character to its binary representation

void send_signal(char* bin, int pid)
{
	ft_printf("\npid: %i, bin: %c \n", pid, bin[0]);
	/*
	while(*bin)
	{
		if(*bin == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		*bin++;
	}
	*/
	free(bin);
}

void	tobin(char c, int pid)
{
	int		i;
	char	*bin ;

	bin = (char *)malloc(9 * sizeof(char));
	if (bin == NULL)
		return;
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
	printf("\n%i %s", pid, bin);

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
	return (0);
	//send_signal("00000000", pid);
}


