# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 17:07:31 by sbouabid          #+#    #+#              #
#    Updated: 2024/01/25 18:39:48 by sbouabid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCF	=	main.c parsing.c utils.c started_life.c rotine.c died.c
OBJF	=	$(SRCF:.c=.o)
CC		=	cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=thread
NAME	=	philo

all: $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -o $(NAME)

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re: fclean all
