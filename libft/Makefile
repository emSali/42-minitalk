# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 13:12:29 by esali             #+#    #+#              #
#    Updated: 2023/02/19 17:58:29 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_strlcat.c ft_atoi.c ft_strdup.c ft_strlen.c ft_isdigit.c \
					printf/ft_printf.c printf/ft_putstr.c printf/ft_putint.c \
					printf/ft_puthex.c printf/ft_putptr.c ft_strjoin.c ft_strchr.c \
					ft_strlcpy.c ft_substr.c ft_strncmp.c ft_addchar.c

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
