# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 16:47:11 by motaouss          #+#    #+#              #
#    Updated: 2021/09/23 16:47:18 by motaouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRCS			=	main.c				\
					utils.c				\
					copy_map.c			\
					map_init.c			\
					check_map.c			\
					text_init.c			\
					initial_render.c	\
					key_press.c			\
					move_rend.c			\
					update_rend.c		\
					free_alloc.c

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all