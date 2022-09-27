# Mandatory part
NAME		:= fdf
INCLUDES	:= -I includes
SOURCE		:= ./source/main.c
OBJS		:= $(SOURCE:./source/%.c=./objects/%.o)
HEADERS		:= ./includes/fdf.h

# General purpose
LIBFT		:= libft.a
CC			:= cc
C_FLAGS		:= -Wall -Werror -Wextra -lm
MLX_FLAGS	:= -lmlx -lXext -lX11
AR			:= ar
AR_FLAGS	:= -rcs
RM			:= rm -rf

# Colors
OFF			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m

$(NAME):	./libft/$(LIBFT) $(OBJS) $(HEADERS)
			cp ./libft/$(LIBFT) .

./libft/$(LIBFT):
		make -C libft/

./objects/%.o:		./source/%.c
			$(CC) -c $(CFLAGS) -o $@ $<

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C libft/ clean

fclean:		clean
			$(RM) $(NAME) $(LIBFT)
			make -C libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re
