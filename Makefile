# Mandatory part
NAME			:=	fdf
INCLUDES		:=	-I includes
SOURCE			:=	./source/main.c ./source/validator.c \
					./source/app.c ./source/parser.c \
					./source/pixels.c ./source/bresenham.c \
					./source/utils.c ./source/plot.c
OBJS			:=	$(SOURCE:./source/%.c=./objects/%.o)
HEADERS			:=	./includes/fdf.h ./includes/libft.h

# General purpose
LIBFT			:=	libft.a
CC				:=	cc
C_FLAGS			:=	-Wall -Werror -Wextra
MLX_FLAGS		:=	-lmlx -lXext -lX11 -lm
VALGRIND_FLAGS 	:=	--leak-check=full
AR				:=	ar
AR_FLAGS		:=	-rcs
RM				:=	rm -rf

# Colors
OFF				:=	\033[0m
RED				:=	\033[0;31m
GREEN			:=	\033[0;32m

$(NAME):	./libft/$(LIBFT) $(OBJS) $(HEADERS)
			cp ./libft/$(LIBFT) .
			$(CC) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

./libft/$(LIBFT):
		make -C libft/
		make -C libft/ bonus

./objects/%.o:		./source/%.c
			$(CC) -c $(INCLUDES) -o $@ $< $(MLX_FLAGS)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C libft/ clean

fclean:		clean
			$(RM) $(NAME) $(LIBFT)
			make -C libft/ fclean

re:			fclean all

test:		$(NAME)
			@./$(NAME) maps/42.fdf

leak:		$(NAME)
			@valgrind $(VALGRIND_FLAGS) ./$(NAME) maps/42.fdf

.PHONY:		all clean fclean re
