# Mandatory part
NAME			:=	fdf
INCLUDES		:=	-I includes
SOURCE			:=	./source/main.c ./source/validator.c \
					./source/app.c ./source/parser.c \
					./source/pixels.c ./source/bresenham.c \
					./source/utils.c ./source/plot.c \
					./source/key_handlers.c ./source/rotation.c \
					./source/menu.c ./source/projection.c
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
			@cp ./libft/$(LIBFT) .
			@echo "$(GREEN)All object files from *$(NAME)* were created!$(OFF)"
			@$(CC) $(C_FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)
			@echo "$(GREEN)$(NAME) files were sucessfully linked!$(OFF)"
			@echo "$(GREEN)$(NAME) sucessfully created!$(OFF)"


./libft/$(LIBFT):
		make -C libft/
		make -C libft/ bonus

./objects/%.o:		./source/%.c
			@mkdir -p objects
			@$(CC) $(C_FLAGS) -c $(INCLUDES) -o $@ $<

all: 		$(NAME)

clean:
			@$(RM) $(OBJS)
			@$(RM) objects
			@make -C libft/ clean
			@echo "$(RED)The object files from *$(NAME)* were sucessfully removed!$(OFF)"

fclean:		clean
			@$(RM) $(NAME) $(LIBFT)
			@make -C libft/ fclean
			@echo "$(RED)The $(NAME) was removed!$(OFF)"


re:			fclean all

test:		$(NAME)
			@./$(NAME) maps/42.fdf

leak:		$(NAME)
			@valgrind $(VALGRIND_FLAGS) ./$(NAME) maps/42.fdf

.PHONY:		all clean fclean re
