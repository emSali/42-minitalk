/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:55 by esali             #+#    #+#             */
/*   Updated: 2023/02/19 18:56:17 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	toChar(char *octet)
{
	char	c;
	int		i;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		if (octet[i] == '1')
			c = c + ft_pow(7 - i);
		i--;
	}
	write(1, &c, 1);
}

void	handle_sigusr(int signal)
{
	static char	*str;
	static int	len;

	len++;
	if (str == NULL)
	{
		str = ft_strdup("");
		len = 1;
	}
	if (signal == SIGUSR1)
		str = ft_addchar(str, '0');
	if (signal == SIGUSR2) {
		str = ft_addchar(str, '1');
	}
	if (len == 8)
	{
		toChar(str);
		free(str);
		str = NULL;
	}
}

int	main()
{
	ft_printf("%i\n", getpid());
	while(1) {
		signal(SIGUSR1, handle_sigusr);
		signal(SIGUSR2, handle_sigusr);
		pause();
	}
	return (0);
}

//sdjhalkjsdhajkhlasdhaskdhaksdjhakjhsdljkabsxbajsblxjhnlsxhelloasdaskdhaksdjhakjhsdljkabsxbajsblxjhn1
