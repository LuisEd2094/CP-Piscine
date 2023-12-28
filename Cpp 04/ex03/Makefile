# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 10:29:59 by lsoto-do          #+#    #+#              #
#    Updated: 2023/12/28 10:30:00 by lsoto-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = a.out
CFLAGS      = -std=c++98 -pedantic -Wall -Wextra  -Werror -g 
CC			= c++
RM          = rm -f
AMATERIA_PATH = AMateria/
CHARACTER_PATH	= Character/
M_SOURCE_PATH	= MateriaSource/
SPELLS_PATH	= Spells/
SRCS_PATH	= src/
OBJS_PATH	= obj/
MAKE_OBJ_DIR	=	$(OBJS_PATH) $(addprefix $(OBJS_PATH), $(AMATERIA_PATH) $(CHARACTER_PATH) $(M_SOURCE_PATH) $(SPELLS_PATH)) 
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

AMATERIA		=	AMateria.cpp

AMATERIA_FILES 	=	$(addprefix $(AMATERIA_PATH), $(AMATERIA))

CHARACTER		=	Character.cpp

CHARACTER_FILES =	$(addprefix $(CHARACTER_PATH), $(CHARACTER))

M_SOURCE		=	MateriaSource.cpp

M_SOURCE_FILES 	=	$(addprefix $(M_SOURCE_PATH), $(M_SOURCE))

SPELLS			=	Cure.cpp Ice.cpp

SPELLS_FILES 	=	$(addprefix $(SPELLS_PATH), $(SPELLS))

DEPS			= 	$(addprefix $(DEPS_PATH),	$(SRC:.cpp=.d) $(AMATERIA:.cpp=.d) $(CHARACTER:.cpp=.d) $(M_SOURCE:.cpp=.d) $(SPELLS:.cpp=.d))

SRC				+=	$(AMATERIA_FILES) $(CHARACTER_FILES) $(M_SOURCE_FILES) $(SPELLS_FILES) 

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
