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

char	*str;

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

char	toChar(char *octet)
{
	char	c;
	int		i;

	i = 7;
	c = 0;
	if (!ft_strncmp(octet, "00000000", 8))
	{
		return '\n';
	}
	while (i >= 0)
	{
		if (octet[i] == '1')
			c = c + ft_pow(7 - i);
		i--;
	}
	return c;
}

void	print_char()
{
	char	*octet;
	int		len;
	int		i;
	char	c;

	len = ft_strlen(str);
	//ft_printf("\nlen is %i", len);
	i = 0;
	while(i < len)
	{
		octet = ft_substr(str, i, 8); //possible to just send pointer to 8 bit further to tochar()
		c = toChar(octet);
		printf("%c", c);
		i = i + 8;
		free(octet);
	}

	free(str); //makes sure global variable is empty before receiving next string
	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return;
	*str = '\0';
}


void	check_last_eight_bits()
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = ft_strchr(&str[len - 8], '1'); // checks if there is a '1' in 8 last char
	if ( res == NULL)
		print_char();
}

void	handle_sigusr(int signal)
{
	char	*save;

	save = ft_strdup(str);
	free(str);
	if (signal == SIGUSR1)
		str = ft_strjoin(save, "0");
	if (signal == SIGUSR2)
		str = ft_strjoin(save, "1");
	free(save);
	if (ft_strlen(str) % 8 == 0)
		check_last_eight_bits();

}

int	main()
{
	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (0);
	*str = '\0';
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		pause();
	return (0);
}
