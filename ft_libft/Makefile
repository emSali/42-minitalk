# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 13:12:29 by esali             #+#    #+#              #
#    Updated: 2023/02/12 16:07:18 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_strlcat.c ft_atoi.c ft_strdup.c ft_strlen.c ft_isdigit.c \
					printf/ft_printf.c printf/ft_putstr.c printf/ft_putint.c \
					printf/ft_puthex.c printf/ft_putptr.c

OBJS			=	$(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
RUN				= ar rcs
BUFF			= BUFFER_SIZE=42
NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(RUN) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
