# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 10:09:05 by lsoto-do          #+#    #+#              #
#    Updated: 2023/12/28 10:09:06 by lsoto-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Animal
CFLAGS      = -std=c++98 -pedantic -Wall -Wextra  -Werror -g 
CC			= c++
RM          = rm -f
ANIMAL_PATH = Animal/
CAT_PATH	= Cat/
DOG_PATH	= Dog/
WRONG_PATH	= WrongAnimal/
SRCS_PATH	= src/
OBJS_PATH	= obj/
MAKE_OBJ_DIR	=	$(OBJS_PATH) $(addprefix $(OBJS_PATH), $(ANIMAL_PATH) $(CAT_PATH) $(DOG_PATH) $(WRONG_PATH)) 
DEPS_PATH	= deps/
INCS        = -I./includes


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

SRC        		=	main.cpp

ANIMAL			=	Animal.cpp

ANIMAL_FILES 	=	$(addprefix $(ANIMAL_PATH), $(ANIMAL))

CAT				=	Cat.cpp

CAT_FILES 		=	$(addprefix $(CAT_PATH), $(CAT))

DOG				=	Dog.cpp

DOG_FILES 		=	$(addprefix $(DOG_PATH), $(DOG))

WRONG			=	WrongAnimal.cpp WrongCat.cpp

WRONG_FILES 	=	$(addprefix $(WRONG_PATH), $(WRONG))

DEPS			= 	$(addprefix $(DEPS_PATH),	$(SRC:.cpp=.d) $(ANIMAL:.cpp=.d) $(CAT:.cpp=.d) $(DOG:.cpp=.d) $(WRONG:.cpp=.d))

SRC				+=	$(ANIMAL_FILES) $(CAT_FILES) $(DOG_FILES) $(WRONG_FILES) 

OBJS 			=	$(addprefix $(OBJS_PATH), $(SRC:.cpp=.o))
				
all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(LIGHT_GREEN)Created $(NAME) executable$(DEF_COLOR)"
	
$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp | $(MAKE_OBJ_DIR) $(DEPS_PATH)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCS) -MMD -MP -c $< -o $@
			@mv $(basename $@).d $(DEPS_PATH)

$(MAKE_OBJ_DIR):
	@echo "$(GREEN)Creating $(NAME) Obj Dir $(DEF_COLOR)"
	@mkdir -p $(MAKE_OBJ_DIR)


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
