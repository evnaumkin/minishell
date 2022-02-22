# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:38:14 by llornel           #+#    #+#              #
#    Updated: 2022/02/20 10:12:38 by llornel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCLUDES		= ./includes
SRC_PATH 		= ./src
OBJ_PATH 		= ./obj

BUILTIN_PATH 	= $(SRC_PATH)/ft_builtin
ENV_PATH 		= $(SRC_PATH)/ft_env
EXEC_PATH 		= $(SRC_PATH)/ft_exec
PARSE_PATH 		= $(SRC_PATH)/ft_parse
UTILS_PATH 		= $(SRC_PATH)/ft_utils
TEST_PATH 		= $(SRC_PATH)/ft_test


HEADER 			= $(INCLUDES)/minishell.h \
				  $(INCLUDES)/const.h

SRC_FILE		= $(BUILTIN_PATH)/ft_builtin.c \
				  $(BUILTIN_PATH)/ft_builtin_cd.c \
				  $(BUILTIN_PATH)/ft_builtin_exit.c \
				  $(BUILTIN_PATH)/ft_builtin_pwd.c \
				  $(BUILTIN_PATH)/ft_builtin_echo.c \
				  $(BUILTIN_PATH)/ft_builtin_env.c \
				  $(BUILTIN_PATH)/ft_builtin_unset.c \
				  $(BUILTIN_PATH)/ft_builtin_export.c \
				  $(ENV_PATH)/ft_env_size.c \
				  $(ENV_PATH)/ft_env_new.c \
				  $(ENV_PATH)/ft_env_last.c \
				  $(ENV_PATH)/ft_env_find.c \
				  $(ENV_PATH)/ft_env_remove.c \
				  $(ENV_PATH)/ft_env_get.c \
				  $(ENV_PATH)/ft_env_set.c \
				  $(ENV_PATH)/ft_env_add_front.c \
				  $(ENV_PATH)/ft_env_add_back.c \
				  $(ENV_PATH)/ft_env_del.c \
				  $(ENV_PATH)/ft_env_clear.c \
				  $(ENV_PATH)/ft_env_iter.c \
				  $(ENV_PATH)/ft_env_value.c \
				  $(ENV_PATH)/ft_env_print.c \
				  $(ENV_PATH)/ft_env_utils.c \
				  $(ENV_PATH)/ft_env.c \
				  $(UTILS_PATH)/ft_check.c \
				  $(UTILS_PATH)/ft_error.c \
				  $(UTILS_PATH)/ft_free.c \
				  $(UTILS_PATH)/ft_init.c \
				  $(EXEC_PATH)/ft_file.c \
				  $(EXEC_PATH)/ft_execute.c \
				  $(EXEC_PATH)/ft_path.c \
				  $(UTILS_PATH)/ft_signal.c \
				  $(TEST_PATH)/ft_test_cd.c \
				  $(TEST_PATH)/ft_test_echo.c \
				  $(TEST_PATH)/ft_test.c \
				  $(PARSE_PATH)/ft_lexer.c \
				  $(SRC_PATH)/ft_minishell.c \
				  minishell.c

SRCS			= $(SRC_FILE)
#OBJS			= $(patsubst $(SRC_PATH)%, $(OBJ_PATH)%, $(SRCS:.c=.o))
#OBJS 			= $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
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

#$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADER) Makefile
#$(OBJS) : $(OBJ_PATH)/%.o: %.c $(HEADER) Makefile
#				mkdir -p $(OBJ_PATH)
#%.o:			%.c ./$(HEADER)/minishell.h Makefile
%.o:			%.c $(HEADER) Makefile
				${CC} $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(LIBRL_INCLUDES) -c $< -o $(<:.c=.o)
#				${CC} $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(LIBRL_INCLUDES) -o $@ -c $<

all:			${NAME}

#all: 			$(OBJ_PATH) $(NAME)

#$(OBJ_PATH):
#				mkdir $@

${NAME}:		${OBJS}
				$(LIBFT_MAKE)
				${CC} ${CFLAGS} ${OBJS} -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(DFLAGS) $(LFLAGS) $(RLFLAGS) -o ${NAME}
#				${CC} ${CFLAGS} ${OBJS} -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(LFLAGS) $(RLFLAGS) -o ${NAME}
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
