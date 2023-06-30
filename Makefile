# Main Variables
NAME     = cub3D
COMPILER = cc
# CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
OUTPUT   = ./$(NAME)
LIBS     = -I./includes/
LIBS_DIR = includes

# Libft
LIBFT     = ft
MLX   	  = -L /usr/local/lib/ -lmlx -lX11 -lXext -lm
LIBFT_DIR = ./lib$(LIBFT)/
# MLX_DIR   = ./$(MLX)/

# Compiled directories
SRC = src
OBJ = obj
SUBDIRS = game utils parser

# Folder directions
SRC_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ)/, $(dir)))

# File directions
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
LIB_DIR = $(foreach dir, $(LIBS_DIR), $(wildcard $(dir)/*.h))

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

all: $(NAME)
	@echo > /dev/null

bonus: all

# $(NAME): $(LIB_DIR) Makefile $(OBJS)
# 	@make WAIT_COMPILE_MSG
# 	@echo "${GREEN}-> Compiling LIBFT...${RESET}"
# 	@make -C $(LIBFT_DIR) all
# 	@$(COMPILER) -g $(CFLAGS) $(LIBS) -L$(MLX_DIR) -l$(MLX) -L$(LIBFT_DIR) -l$(LIBFT) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
# 	@make DONE_MSG

$(NAME): $(LIB_DIR) Makefile $(OBJS)
	@make WAIT_COMPILE_MSG
	@echo "${GREEN}-> Compiling LIBFT...${RESET}"
	@make -C $(LIBFT_DIR) all
	@$(COMPILER) $(OBJS) -o $(NAME)  $(LIBS)  -L$(LIBFT_DIR) -l$(LIBFT)  $(MLX)
	@make DONE_MSG


$(OBJ)/%.o: $(SRC)/%.c $(LIB_DIR)
	@mkdir -p $(OBJ) $(OBJ_DIR)
	@echo "${YELLOW}Compiling $<${RESET}"
	@$(COMPILER) $(CFLAGS) $(LIBS) -c $< -o $@

clean: DELETE_OBJ_MSG
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)
fclean: clean DELETE_PROGRAM_MSG
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
re: fclean all

# Helper messages
WAIT_COMPILE_MSG:
	@echo "${YELLOW}Please wait until program compiling...${RESET}"
DONE_MSG:
	@echo "${GREEN}! run ./${NAME} to start program !${RESET}"
DELETE_OBJ_MSG:
	@echo "${RED}Object files deleting...${RESET}"
DELETE_PROGRAM_MSG:
	@echo "${RED}! ATTENTION !\n${NAME} is deleting...${RESET}"

.PHONY: all clean fclean re