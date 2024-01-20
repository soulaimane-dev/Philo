# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:50:59 by sbouabid          #+#    #+#              #
#    Updated: 2024/01/20 12:42:39 by sbouabid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCF	=	main.c parsing.c parsing_utils.c philosophers.c eating.c time.c die.c
OBJF	=	$(SRCF:.c=.o)
CC		=	cc
CFLAGS	= -Wall -Wextra -Werror
NAME	=	philo

all: $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -o $(NAME)

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re: fclean all
