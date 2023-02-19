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

// int	ft_pow(int power)
// {
// 	int	ret;

// 	if (power == 0)
// 		return (1);
// 	ret = 2;
// 	while (power > 1)
// 	{
// 		ret = ret * 2;
// 		power--;
// 	}
// 	return (ret);
// }

// char	toChar(char *octet)
// {
// 	char	c;
// 	int		i;

// 	i = 7;
// 	c = 0;
// 	if (!ft_strncmp(octet, "00000000", 8))
// 	{
// 		return '\n';
// 	}
// 	while (i >= 0)
// 	{
// 		if (octet[i] == '1')
// 			c = c + ft_pow(7 - i);
// 		i--;
// 	}
// 	return c;
// }

// void	print_char()
// {
// 	int		len;
// 	int		i;
// 	char	c;

// 	len = ft_strlen(str);
// 	i = 0;
// 	while(i < len)
// 	{
// 		//octet = ft_substr(str, i, 8); //possible to just send pointer to 8 bit further to tochar()
// 		c = toChar(&str[i]);
// 		write(1, &c, 1);
// 		i = i + 8;
// 		//free(octet);
// 	}
// 	free(str); //makes sure global variable is empty before receiving next string
// 	str = (char *)malloc(sizeof(char) * 1);
// 	if (!str)
// 		return;
// 	str[0] = '\0';
// }


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
	if (len % 8 == 0)
	{
		printf("\n%s", str);
		fflush(stdout);
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
