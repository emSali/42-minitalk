/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:43 by esali             #+#    #+#             */
/*   Updated: 2023/02/11 11:47:18 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

// ToDo: check if pid is only numbers

int	main(int argc, char *argv[])
{
	int	pid;

	pid = atoi(argv[1]);

	if(argc < 2 || ft_strlen(argv[1]) != 5)
		return (0);
	kill(pid, SIGUSR2);
	usleep(10000);
	kill(pid, SIGUSR1);
	usleep(10000);
	kill(pid, SIGUSR1);
	usleep(10000);
	kill(pid, SIGUSR2);
	usleep(10000);
	kill(pid, SIGUSR2);
	usleep(10000);
	kill(pid, SIGUSR1);
	usleep(10000);
	kill(pid, SIGUSR1);
	usleep(10000);
	kill(pid, SIGUSR2);
	usleep(10000);
	kill(pid, SIGUSR2);
	usleep(10000);
	kill(pid, SIGUSR1);
	usleep(10000);
	kill(pid, SIGUSR1);
	usleep(10000);
	kill(pid, SIGUSR2);
	return (0);

	/*
	1. while loop that is going through argv[2]
	2. take ascii nr of char adn change into 8bit binary
	3. send sigusr1 for 0 and sigusr2 for 1
	*/
}
