NAME = container

CXX = clang++
CXX_FLAGS = -Wextra -Wall -Werror -std=c++98

SRCS_DIR = ./
SRCS = main.cpp

OBJS_DIR = ./objects/
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))
DEP = $(OBJS:.o=.d)

$(NAME) : $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

-include $(DEP)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -MMD -o $@ -c $<

all : $(NAME)

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re