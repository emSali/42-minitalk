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

void	handle_sigusr1()
{
	char	*save;

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
		//if (bin == NULL)
		bin = "\0";
	}
}

void	handle_sigusr2()
{
	bin = ft_strjoin(bin, "1");
	ft_printf("\n%s", bin);
	if (strlen(bin) == 8)
	{
		ft_printf("\nstrlen of bin is 8");
		free(bin);
		bin = (char *)malloc(sizeof(char) * 1);
		//if (bin == NULL)
		bin = "\0";
	}
}

// void	toChar(char* bin)
// {

// }

int	main()
{
	bin = (char *) malloc(sizeof(char) * 1);
	if (bin == NULL)
		return (0);
	bin = "\0";
	ft_printf("%i", getpid());
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);

	while(1);
	return (0);
}


