/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:53:25 by esali             #+#    #+#             */
/*   Updated: 2023/02/16 21:41:25 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*octet;

void handle_sigusr(int signal)
{
	char	*save;

	save = ft_strdup(octet);
	//free(octet);
	if (signal == SIGUSR1)
		octet = ft_strjoin(save, "");
	if (signal == SIGUSR2)
		octet = ft_strjoin(save, "1");
	ft_printf("\n%s", octet);
	free(save);
}

/*
void	handle_sigusr1(int signal)
{
	char	*save;

	if(signal == 1)
	printf("o");
	save = ft_strdup(octet);
	free(octet);
	octet = ft_strjoin(save, "0");
	free(save);
	ft_printf("\n%s", octet);
	if (strlen(octet) == 8)
	{
		ft_printf("\nstrlen of octet is 8");
		free(octet);
		octet = (char *)malloc(sizeof(char) * 1);
		octet = "\0";
	}
}

void	handle_sigusr2(int signal)
{
	char	*save1;

	if(signal == 1)
	printf("o");
	save1 = ft_strdup(octet);
	free(octet);
	octet = ft_strjoin(save1, "1");
	free(save1);
	ft_printf("\n%s", octet);
	if (strlen(octet) == 8)
	{
		ft_printf("\nstrlen of octet is 8");
		free(octet);
		octet = (char *)malloc(sizeof(char) * 1);
		octet = "\0";
	}
}
*/

int	ft_pow(int power)
{
	int	ret;

	if (power == 0)
		return (1);
	ret = 2;
	while (power > 1)
	{
		ret = ret * 2;
		power--;
	}
	return (ret);
}

void	toChar(char *str)
{
	int		i;
	int		bin;
	char	c[2];
	//do conversion here

	i = 7;
	bin = 0;
	while (i >= 0)
	{
		if (octet[i] == 1)
			bin = bin + ft_pow(i);
	}
	c[0] = bin;
	c[1] = '\0';
	str = ft_strjoin(str, c);
	free(octet);
	octet = (char *)malloc(sizeof(char) * 1);
	octet = "\0";
	printf("\nstr: %s", str);
}

int	main()
{
	char*	str;

	octet = (char *) malloc(sizeof(char) * 1);
	if (octet == NULL)
		return (0);
	octet = "\0";
	str = (char *) malloc(sizeof(char) * 1);
	if (str == NULL)
		return (0);
	str = "\0";

	ft_printf("%i", getpid());
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
	{
		if (ft_strlen(octet) == 8)
			toChar(str);
		pause();
	}
	return (0);
}


