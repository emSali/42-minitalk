# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 12:28:02 by esali             #+#    #+#              #
#    Updated: 2023/02/10 19:23:36 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minitalk.a

SRCS 		= client.c server.c

OBJS 		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. 
RUN			= ar rcs

%.o: %.c
	$(CC) -c $(CFLAGS) -I headers $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) server.o $(NAME) -o server
	$(CC) $(CFLAGS) client.o $(NAME) -o client

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(NAME) $(OBJS)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
