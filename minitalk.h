/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:27:09 by esali             #+#    #+#             */
/*   Updated: 2023/02/10 20:02:49 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include "libft/libft.h"

int		main();
int		main(int argc, char *argv[]);
void	toChar(char	*ret, char *bin);
void	handle_sigusr1(int sig);
void	handle_sigusr2(int sig);

#endif
