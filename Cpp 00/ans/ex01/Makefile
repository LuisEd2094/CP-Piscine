NAME        = phonebook
CFLAGS      = -Wall -Wextra  -Werror -g -std=c++98 -pedantic
CC			= c++
RM          = rm -f
CONTACT_PATH = Contact/
PHONE_PATH	=	PhoneBook/
FT_LIB_PATH	=	ft_lib/
SRCS_PATH	= src/
OBJS_PATH	= obj/
MAKE_OBJ_DIR	=	$(OBJS_PATH) $(addprefix $(OBJS_PATH), $(CONTACT_PATH) $(PHONE_PATH) $(FT_LIB_PATH)) 
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

CONTACT			=	Contact_class.cpp

PHONE			=	PhoneBook_class.cpp

FT_LIB			=	remove_white_spaces.cpp

FT_LIB_FILES	=	$(addprefix $(FT_LIB_PATH), $(FT_LIB))

CONTACT_FILES 	=	$(addprefix $(CONTACT_PATH), $(CONTACT))

PHONE_FILES 	=	$(addprefix $(PHONE_PATH), $(PHONE))

DEPS			= 	$(addprefix $(DEPS_PATH),	$(SRC:.cpp=.d) $(CONTACT:.cpp=.d) $(PHONE:.cpp=.d) $(FT_LIB:.cpp=.d))

SRC				+=	$(CONTACT_FILES) $(PHONE_FILES) $(FT_LIB_FILES)

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