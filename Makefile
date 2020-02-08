##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 4.0
##

SRC_FOLDER    := source
OBJ_FOLDER    := object

VPATH   :=    $(SRC_FOLDER)
SRC	:=	$(notdir $(shell ls $(addsuffix /*.cpp, $(SRC_FOLDER))))
OBJ	:=	$(addprefix $(OBJ_FOLDER)/,$(SRC:.cpp=.o))
OBJM	:=	$(filter-out $(OBJ_FOLDER)/main.o, $(OBJ))

TEST_SRC	:=	$(wildcard $(addprefix tests/, *).cpp)
TEST_NAME	:=	$(basename $(notdir $(TEST_SRC)))
TEST_OBJ	:=	$(addprefix object/, $(addsuffix .o, $(TEST_NAME)))
TFLAGS		:=	-lcriterion

HEADP	:=	./include/
NAME	:=	LifePod

DEPDIR    :=    $(HEADP)deps/
DEPNDENCIES    :=    $(addprefix $(DEPDIR), $(SRC:.cpp=.d))

END     :=	\033[0m
BOLD	:=	\033[1m
RED	:=	\033[31m
GREEN	:=	\033[32m
BLUE	:=	\033[34m
CYAN	:=	\033[36m
WHITE	:=	\033[37m

CC	:=	g++
CFLAGS  :=      -I $(HEADP)  -Wall -Wextra -Werror -lncurses

MAKEFLAGS    += --no-print-directory --slilence --silent

.PHONY: re clean all tests_run
.SILENT: re all $(OBJ) $(NAME) $(OBJ_FOLDER) clear fclean tclean clean tests

-include $(DEPNDENCIES)

all: $(NAME)

print:
	echo -e $(SRC)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -I $(HEADP) $(OBJ) $(CFLAGS)
	echo -e "$(GREEN)* * * * * BINARY $(WHITE)$(BOLD)$(NAME)$(END)$(GREEN) COMPLETED * * * * *$(END)"

tests_run: $(OBJ) $(TEST_OBJ)
	echo -e "$(GREEN)* * * * * STARTING TEST RUN * * * * *$(END)"
	$(CC) -o unit_tests $(OBJM) $(TEST_OBJ) $(TFLAGS) $(CFLAGS)
	./unit_tests -j4 $(VERBOSE)

$(OBJ): | $(OBJ_FOLDER) $(DEPDIR)

$(OBJ):$(OBJ_FOLDER)/%.o: %.cpp
	$(CC) $(CFLAGS)  -c -o $@ $<	\
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"    \
	|| echo -e "[ $(RED)KO$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"
	gcc -MM $< > $(DEPDIR)/$*.d $(CFLAGS)
	sed -i -e 's|.*:|$@:|' $(DEPDIR)/$*.d

$(OBJ_FOLDER) $(DEPDIR):
	mkdir -p $@

clear:
	echo -e "$(BOLD)Deleting junks files$(END)"
	rm -fv source/*~
	rm -fv *~
	rm -fv include/*~
	echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

clean:
	echo -e "$(BOLD)Deleting OBJ.o files"
	rm -f $(OBJ)
	echo -e "$(BOLD)Deleting deps files"
	rm -f $(DEPNDENCIES)
	echo -e "$(END)$(CYAN)* * * * * DONE * * * * *$(END)"

fclean: clean
	echo -e "$(BOLD)Deleting $(NAME)$(END)"
	rm -f $(NAME)
	echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

tclean:
	echo -e "$(BOLD)Deleting tests$(END)"
	rm -f $(TEST_OBJ)
	echo -e "$(CYAN)* * * * * TESTS REMOVED * * * * *$(END)"

re:	clear fclean tclean all

$(OBJ_FOLDER)/%.o: tests/%.cpp
	@$(CC) -I $(HEADP) $(CFLAGS) $(TFLAGS) -c -o $@ $< \
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"      \
    || echo -e "[ $(RED)KO$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"
