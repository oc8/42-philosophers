NAME			= philo_one
PRINT_NAME		= $(CYAN)$(BOLD)$(NAME)$(END)
LST_SRCS		= \
	main.c
SRCS_DIR		= srcs
OBJS_DIR		= objs
SRCS			= $(addprefix $(PATH_SRCS)/,$(LST_SRCS))
OBJS			= $(LST_SRCS:%.c=$(OBJS_DIR)/%.o) $(OBJS_SHARED)
CC				= clang
FLAGS			= -Wall -Wextra -Werror
# FLAGS			= -Wall -Wextra -Werror -Ofast
# FLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address
# FLAGS			= -Wall -Wextra -Werror -g #(lldb)
INCLUDE			= -I./inc # -I./${LIBFT}/inc
FLAG_LIBFT		= # -L./${LIBFT} -lft
RM				= rm -rf
MKDIR			= mkdir -p
LIBFT			= ../42-libft

all:			$(NAME) # libft

$(OBJS_DIR):
				$(MKDIR) $@

libft: 
				make -C ${LIBFT}

${NAME}:		${OBJS_DIR} ${OBJS} # libft
				${CC} ${FLAGS} ${INCLUDE} ${OBJS} $(FLAG_LIBFT) -o ${NAME}
				@echo "$(ERASE)$(GREEN)⤖ $(PRINT_NAME) : $(GREEN)ok$(END)"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c inc/*.h
				$(MKDIR) $(dir $@)
				${CC} ${FLAGS} $(INCLUDE) -c  $< -o $@
				@printf "$(ERASE)$(GREEN)⤖ $(PRINT_NAME) : $(END)[$(GREEN)$<$(END)]\n"

clean:
				${RM} $(OBJS)
				make clean -C $(LIBFT)

fclean:			clean
				${RM} $(OBJS_DIR) $(NAME)
				make fclean -C $(LIBFT)
				@echo "$(ERASE)$(GREEN)⤖ $(PRINT_NAME) : $(GREEN)clean$(END)"

re:				fclean all

.PHONY: 		clean fclean all re libft
.SILENT:		clean fclean all re libft $(OBJS) $(NAME) $(OBJS_DIR)

ERASE	= \033[2K\r
GREY	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
PINK	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
END		= \033[0m
BOLD	= \033[1m
UNDER	= \033[4m
SUR		= \033[7m
