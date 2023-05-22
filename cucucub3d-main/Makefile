NAME = cub3d

SRCS =	main.c \
		src/init.c \
		src/fov.c \
		utils/utils.c \
		utils/utils2.c \
		utils/utils_error.c \
		utils/ft_split.c \
		utils/ft_atoi.c \
		utils/utils_map.c \
		utils/utils_move.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		parsing/check.c \
		parsing/check2.c \
		src/key_action.c \
		parsing/gabin.c \
		parsing/gabin2.c

OBJS = $(SRCS:.c=.o)

# ------------------------------ Flags -------------------------------

CC = @gcc -g #-fsanitize=address
FLAGS			:= -Wall -Wextra -Werror -g -g3

# ------------------------------ Colors ------------------------------

# Colors

GREY 	 := "\033[1;30m"
RED 	 :=	"\033[1;31m"
GREEN 	 := "\033[1;32m"
YELLOW 	 := "\033[1;33m"
BLUE	 :=	"\033[1;36m"
PURPLE	 :=	"\033[1;35m"
WHITE	 :=	"\033[1;37m"
END		 :=	"\033[0;0m"

# ------------------------------ Messages ------------------------------

MAKE_MESS		= • Make :

FILES_OK		= has been successfully compiled!

FILES_DELETE	= • Clean : please make am fclean to delete cub3d

FCLEAN_DELETE	= • Fclean : cub3d was been successfully deleted!

CUB3D = ${RED}"\n  ▄████████ ███    █▄  ▀█████████▄  ▀█████████▄   ████████▄\n"${END} \
		${RED}"███    ███ ███    ███   ███    ███          ███  ███   ▀███\n"${END} \
		${RED}"███    █▀  ███    ███   ███    ███          ███  ███    ███\n"${END} \
		${RED}"███        ███    ███  ▄███▄▄▄██▀   ▄▄▄▄▄▄▄▄██▀  ███    ███\n"${END} \
		${RED}"███        ███    ███ ▀▀███▀▀▀██▄   ▀▀▀▀▀▀▀▀█▄   ███    ███\n"${END} \
		${RED}"███    █▄  ███    ███   ███    ██▄          ██▄  ███    ███\n"${END} \
		${RED}"███    ███ ███    ███   ███    ███          ███  ███   ▄███\n"${END} \
		${RED}"████████▀  ████████▀  ▄█████████▀  ▄█████████▀   ████████▀\n"${END}
                                             

# ------------------------------ so_long --------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o  $(NAME) MLX42/libmlx42.a -I include -lglfw -L /Users/$$USER/.brew/opt/glfw/lib -lm -ldl -g -g3
	@echo $(CUB3D)
	@echo ${GREEN}"$(MAKE_MESS) $(NAME) $(FILES_OK)"${END}

# ------------------------------ Rules -----------------------------------

clean:
	@rm -rf ${OBJS}
	
	@echo ${RED}"$(FILES_DELETE)"${END}

fclean: clean 
	@rm -rf $(NAME)
	@echo ${RED}"$(FCLEAN_DELETE)"${END}

re : fclean all