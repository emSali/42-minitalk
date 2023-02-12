/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:53:25 by esali             #+#    #+#             */
/*   Updated: 2023/02/11 12:44:32 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*bin;

void handle_sigusr(int signal)
{
	char	*save;

	save = ft_strdup(bin);
	//free(bin);
	if (signal == SIGUSR1)
		bin = ft_strjoin(save, "0");
	if (signal == SIGUSR2)
		bin = ft_strjoin(save, "1");
	ft_printf("\n%s", bin);
	free(save);
}

/*
void	handle_sigusr1(int signal)
{
	char	*save;
	
	if(signal == 1)
	printf("o");
	save = ft_strdup(bin);
	free(bin);
	bin = ft_strjoin(save, "0");
	free(save);
	ft_printf("\n%s", bin);
	if (strlen(bin) == 8)
	{
		ft_printf("\nstrlen of bin is 8");
		free(bin);
		bin = (char *)malloc(sizeof(char) * 1);
		bin = "\0";
	}
}

void	handle_sigusr2(int signal)
{
	char	*save1;
	
	if(signal == 1)
	printf("o");
	save1 = ft_strdup(bin);
	free(bin);
	bin = ft_strjoin(save1, "1");
	free(save1);
	ft_printf("\n%s", bin);
	if (strlen(bin) == 8)
	{
		ft_printf("\nstrlen of bin is 8");
		free(bin);
		bin = (char *)malloc(sizeof(char) * 1);
		bin = "\0";
	}
}
*/

void	toChar()
{
	int i;

	//do conversion here
	
	free(bin);
	bin = (char *)malloc(sizeof(char) * 1);
	bin = "\0";
}

int	main()
{
	bin = (char *) malloc(sizeof(char) * 1);
	if (bin == NULL)
		return (0);
	bin = "\0";
	ft_printf("%i", getpid());
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
	{
		pause();
		if (ft_strlen(bin) == 8)
			toChar();
	}
		
	return (0);
}


