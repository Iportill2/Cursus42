
NAME		= so_long

NAME_BONUS	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g3 #-llsan #-fsanitize=leak 
LMLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM			= rm -rf
LIB			= Libft
MLX			= mlx

SRCS_BONUS=	$(SRC_DIR_BONUS)main_bonus.c \
			$(SRC_DIR_BONUS)error_bonus.c \
			$(SRC_DIR_BONUS)open_file_bonus.c \
			$(SRC_DIR_BONUS)init_game_bonus.c \
			$(SRC_DIR_BONUS)map_tester_bonus.c \
			$(SRC_DIR_BONUS)star_game_bonus.c \
			$(SRC_DIR_BONUS)check_wall_bonus.c \
			$(SRC_DIR_BONUS)create_maps_bonus.c \
			$(SRC_DIR_BONUS)finishable_map_bonus.c \
			$(SRC_DIR_BONUS)info_checker_bonus.c \
			$(SRC_DIR_BONUS)get_xpm_bonus.c \
			$(SRC_DIR_BONUS)move_bonus.c \
			$(SRC_DIR_BONUS)paint_map_bonus.c \
			$(SRC_DIR_BONUS)hook_bonus.c

SRCS	=	$(SRC_DIR)main.c \
			$(SRC_DIR)error.c \
			$(SRC_DIR)open_file.c \
			$(SRC_DIR)init_game.c \
			$(SRC_DIR)map_tester.c \
			$(SRC_DIR)star_game.c \
			$(SRC_DIR)check_wall.c \
			$(SRC_DIR)create_maps.c \
			$(SRC_DIR)finishable_map.c \
			$(SRC_DIR)info_checker.c \
			$(SRC_DIR)get_xpm.c \
			$(SRC_DIR)move.c \
			$(SRC_DIR)paint_map.c \
			$(SRC_DIR)hook.c
			
SRC_DIR	=			src/
SRC_DIR_BONUS	=	src_bonus/
OBJS	= 	$(SRCS:.c=.o)

OBJS_BONUS= $(SRCS_BONUS:.c=.o)

.SILENT:

all:		$(NAME)

bonus: 			$(NAME_BONUS)

%.o: $(SRC_DIR)%.c
		$(CC) $(CFLAGS)  -c $< -o $@

%.o: $(SRC_DIR_BONUS)%.c
		$(CC) $(CFLAGS)  -c $< -o $@


$(NAME):	$(OBJS) 
			make -C $(LIB)
			$(MAKE) -C mlx 2> logs
			make  -C $(MLX)
			$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a $(LIB)/libft.a -o $@ $^



$(NAME_BONUS):	$(OBJS_BONUS)
				make -C $(LIB)
				$(MAKE) -C mlx 2> logs
				make -C $(MLX)
				$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a $(LIB)/libft.a -o $@ $^

clean:
			@make -C $(LIB) clean
			@make -C $(MLX) clean
			@$(RM) $(OBJS) $(OBJS_BONUS)


fclean:		clean
			@make -C $(LIB) fclean
			@$(RM) $(NAME) $(NAME_BONUS) logs

re:			fclean all

.PHONY:		all clean fclean re bonus

