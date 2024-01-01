# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 10:45:29 by lsoto-do          #+#    #+#              #
#    Updated: 2024/01/01 10:45:30 by lsoto-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = a.out
CFLAGS      = -Wall -Wextra  -Werror -g -std=c++98 -pedantic
CC			= c++
RM          = rm -f
OBJS_PATH	= obj/
MAKE_OBJ_DIR	= $(OBJS_PATH)
DEPS_PATH	= deps/

#Colors


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
LIGHT_GREEN = \033[1;92m

###

SRC         =	Bureaucrat.cpp  main.cpp

DEPS		= 	$(addprefix $(DEPS_PATH), $(SRC:.cpp=.d))

OBJS        =	$(addprefix $(OBJS_PATH), $(SRC:.cpp=.o)) 
				
all: $(NAME)
	
$(OBJS_PATH)%.o: %.cpp | $(MAKE_OBJ_DIR) $(DEPS_PATH)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 
			@mv $(basename $@).d $(DEPS_PATH)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)
	@echo "$(LIGHT_GREEN)Created $(NAME) executable$(DEF_COLOR)"

$(MAKE_OBJ_DIR):
	@echo "$(GREEN)Creating $(NAME) Obj Dir $(DEF_COLOR)"
	@mkdir -p $(OBJS_PATH)


$(DEPS_PATH):
	@echo "$(GREEN)Creating $(NAME) Deps Dir $(DEF_COLOR)"
	@mkdir -p $(DEPS_PATH)

-include $(DEPS)


clean: clean_objects

fclean:  clean_objects
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) executable cleaned!$(DEF_COLOR)"

clean_objects:
	@echo "$(GREEN)$(NAME) Objects and Dependencies cleaned!$(DEF_COLOR)"
	@$(RM) -r $(OBJS_PATH) $(DEPS_PATH)


re: fclean all 

.PHONY: all fclean clean re 
