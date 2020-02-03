##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 3.3
##

SRC	=	$(wildcard $(addprefix source/, *).cpp)
NOM	=	$(basename $(notdir $(SRC)))
OBJ	=	$(addprefix object/, $(addsuffix .o, $(NOM)))
OBJM	=	$(filter-out object/main.o, $(OBJ))

TEST_SRC	=	$(wildcard $(addprefix tests/, *).cpp)
TEST_NAME	=	$(basename $(notdir $(TEST_SRC)))
TEST_OBJ	=	$(addprefix object/, $(addsuffix .o, $(TEST_NAME)))
TFLAGS		=	--coverage -lcriterion

HEADP	=	./include/
NAME	=	LifePod

END     =	\033[0m
BOLD	=	\033[1m
RED	=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
CYAN	=	\033[36m
WHITE	=	\033[37m

CC	=	g++
CFLAGS    =     -Wall -Wextra -lncurses

.PHONY: re clean tests_run

all:  $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "$(GREEN)* * * * * BINARY $(WHITE)$(BOLD)$(NAME)$(END)$(GREEN) COMPLETED * * * * *$(END)"

tests_run: all $(TEST_OBJ)
	@echo -e "$(GREEN)* * * * * STARTING TEST RUN * * * * *$(END)"
	@$(CC) -o unit_tests $(OBJM) $(TEST_OBJ) $(TFLAGS) $(LFLAGS) $(CFLAGS) $(PFLAGS)
	@./unit_tests -j4 $(VERBOSE)

clear:
	@echo -e "$(BOLD)Deleting junks files$(END)"
	@rm -fv source/*~
	@rm -fv *~
	@rm -fv include/*~
	@rm -fv vgcore.*
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

clean:
	@echo -e "$(BOLD)Deleting OBJ.o files"
	@rm -f $(OBJ)
	@echo -e "$(END)$(CYAN)* * * * * DONE * * * * *$(END)"

tclean:
	@echo -e "$(BOLD)Deleting tests$(END)"
	@rm -f $(TEST_OBJ)
	@echo -e "$(CYAN)* * * * * TESTS REMOVED * * * * *$(END)"

fclean: clean
	@echo -e "$(BOLD)Deleting $(NAME)$(END)"
	@rm -f $(NAME)
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

re:	clear fclean tclean all

object/%.o: tests/%.cpp
	@$(CC) -I $(HEADP) $(CFLAGS) -fPIC -fno-builtin -c -o $@ $< \
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"      \
    || echo -e "[ $(RED)KO$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"

object/%.o: source/%.cpp
	@$(CC) -I $(HEADP) $(CFLAGS) -fPIC -fno-builtin -c -o $@ $<	\
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"      \
    || echo -e "[ $(RED)KO$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"

