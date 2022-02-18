# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:38:14 by llornel           #+#    #+#              #
#    Updated: 2022/02/18 10:59:59 by llornel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCLUDES		= ./includes
SRC_PATH 		= ./src
OBJ_PATH 		= ./obj

HEADER 			= $(INCLUDES)/minishell.h \
				  $(INCLUDES)/const.h

SRC_FILE		= $(SRC_PATH)/ft_builtin_cd.c \
				  $(SRC_PATH)/ft_builtin_exit.c \
				  $(SRC_PATH)/ft_builtin_pwd.c \
				  $(SRC_PATH)/ft_check.c \
				  $(SRC_PATH)/ft_env_list.c \
				  $(SRC_PATH)/ft_env_utils.c \
				  $(SRC_PATH)/ft_env.c \
				  $(SRC_PATH)/ft_error.c \
				  $(SRC_PATH)/ft_file.c \
				  $(SRC_PATH)/ft_free.c \
				  $(SRC_PATH)/ft_init.c \
				  $(SRC_PATH)/ft_lexer.c \
				  $(SRC_PATH)/ft_minishell.c \
				  $(SRC_PATH)/ft_signal.c \
				  $(SRC_PATH)/ft_test_cd.c \
				  $(SRC_PATH)/ft_test.c \
				  minishell.c

SRCS			= $(SRC_FILE)
#OBJS			= $(patsubst $(SRC_PATH)/%, $(OBJ_PATH)/%, $(SRCS:.c=.o))
OBJS			= $(SRCS:.c=.o)

LIBFT_PATH		= ./libft
LIBFT_NAME		= $(LIBFT_PATH)/libft.a
LIBFT_INCLUDES	= $(LIBFT_PATH)/includes
LIBFT_MAKE		= ${MAKE} -C ${LIBFT_PATH}

LIBRL_NAME		= readline
LIBRL_INCLUDES  = /usr/local/opt/readline/include
LIBRL_PATH      = /usr/local/opt/readline/lib
#LIBRL_HEADER	= /Users/$(USER)/.brew/opt/readline/include/
#LIBRL_PATH  	= /Users/$(USER)/.brew/opt/readline/lib/

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
DFLAGS 			= -g -fsanitize=address
LFLAGS			= -L $(LIBFT_PATH) -lft
RLFLAGS			= -I$(LIBRL_INCLUDES) -L$(LIBRL_PATH) -l$(LIBRL_NAME)
RM				= rm -f
NORM			= norminette -R CheckForbiddenSourceHeader

# $(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c ./$(HEADER)/minishell.h Makefile
#				mkdir -p $(OBJ_PATH)
#%.o:			%.c ./$(HEADER)/minishell.h Makefile
%.o:			%.c $(HEADER) Makefile
				${CC} $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(LIBRL_INCLUDES) -c $< -o $(<:.c=.o)

all:			${NAME}

${NAME}:		${OBJS}
				$(LIBFT_MAKE)
				${CC} ${CFLAGS} ${OBJS} -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(DFLAGS) $(LFLAGS) $(RLFLAGS) -o ${NAME}
#				${CC} ${CFLAGS} ${OBJS} -I $(HEADER) $(LFLAGS) $(RLFLAGS) -o ${NAME}


clean:
				$(LIBFT_MAKE) clean
				${RM} ${OBJS}

fclean:			clean
				$(LIBFT_MAKE) fclean
				${RM} ${NAME}

re:				fclean all

bonus:			${NAME}

norm:
				$(LIBFT_MAKE) norm
				${NORM} $(SRCS) $(HEADER)

.PHONY: 		all clean fclean re bonus norm .c.o
