/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:55 by esali             #+#    #+#             */
/*   Updated: 2023/02/16 21:41:23 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//check in handle_sig if modulo str is 0, if so check if last 8 digits are 0
// if thats the case convert and print str
char	*str;

void	handle_sigusr(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\n0");
	if (signal == SIGUSR2)
		ft_printf("\n1");

}

int main()
{
	ft_printf("%i", getpid());
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		pause();
	return (0);
}
