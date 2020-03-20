##
## PROJECT, 2020
## Makefile
## File description:
## Hu 1.0
##

SRC_FOLDER    := source
OBJ_FOLDER    := object

LANG    :=    .cpp
VPATH   :=    $(SRC_FOLDER)
SRC	:=	$(notdir $(shell ls $(addsuffix /*$(LANG), $(SRC_FOLDER))))
OBJ	:=	$(addprefix $(OBJ_FOLDER)/,$(SRC:$(LANG)=.o))
OBJM	:=	$(filter-out $(OBJ_FOLDER)/main.o, $(OBJ))

TEST_SRC	:=	$(wildcard $(addprefix tests/, *)$(LANG))
TEST_NAME	:=	$(basename $(notdir $(TEST_SRC)))
TEST_OBJ	:=	$(addprefix object/, $(addsuffix .o, $(TEST_NAME)))
TFLAGS		:=	-lcriterion

HEADP	:=	./include/
NAME	:=	LifePod

DEPDIR    :=    .deps
DEPNDENCIES    :=    $(addprefix $(DEPDIR), $(SRC:$(LANG)=.d))

END     :=	\033[0m
BOLD	:=	\033[1m
RED	:=	\033[31m
GREEN	:=	\033[32m
CYAN	:=	\033[36m

CC	:=	g++
CFLAGS  :=      -I $(HEADP) -Wall -Wextra -Werror -lncurses -std=c++17

MAKEFLAGS    += --no-print-directory --silence --silent

.PHONY: re clean all tests_run
.SILENT: re all $(OBJ) $(NAME) $(OBJ_FOLDER) clear fclean tclean clean tests

SAY    := $(BOLD)[$(CYAN)壺$(END)$(BOLD)]:

all: $(NAME)

-include $(DEPNDENCIES)

print:
	echo -e $(SRC)

start_compile:
	echo -e "$(SAY) Praise for the almighty $(CYAN)binary$(END)$(BOLD) !$(END)"
	
$(NAME): start_compile $(OBJ)
	$(CC) -o $(NAME) -I $(HEADP) $(OBJ) $(CFLAGS)
	echo -e "$(SAY) Ameno ! $(CYAN)$(NAME)$(END)$(BOLD) is among us !$(END)\n"

tests_run: $(OBJ) $(TEST_OBJ)
	echo -e "$(SAY) Are you doubting my faith ?$(END)"
	$(CC) -o unit_tests $(OBJM) $(TEST_OBJ) $(TFLAGS) $(CFLAGS)
	./unit_tests -j4 $(VERBOSE) || `$(WRI) && ri -i tests_runf`

$(OBJ): | $(OBJ_FOLDER) $(DEPDIR)

$(OBJ):$(OBJ_FOLDER)/%.o: %$(LANG)
	$(CC) $(CFLAGS)  -c -o $@ $<	\
	&& echo -e "$(BOLD)$(CYAN)"$< "$(END)$(BOLD)has been blessed.$(END)"    \
	|| echo -e "$(BOLD)$(RED)" $< "$(END)$(BOLD)has been cursed.$(END)"
	gcc $(CFLAGS) -MM -MP -MT $@ $< > $(DEPDIR)/$*.d
	
$(OBJ_FOLDER) $(DEPDIR):
	mkdir -p $@

clear:
	echo -e "$(SAY) Purging heretics files..."
	rm -fv source/*~
	rm -fv *~
	rm -fv include/*~
	echo -e "$(SAY) Done.$(END)\n"

clean:
	echo -e "$(SAY) ..."
	rm -vf $(OBJ)
	rm -f $(DEPNDENCIES)
	echo -e "$(SAY) What ? I am just \"rewriting\" the holy book.$(END)\n"

fclean: clean
	echo -e "$(BOLD)Deleting $(NAME)$(END)"
	rm -f $(NAME)
	echo -e "$(SAY) It is a false god. In such, it has been \"deleted\"$(END)\n"

tclean:
	echo -e "$(BOLD)Deleting your skepticism."
	rm -vf $(TEST_OBJ)
	rm -vf tests_run
	echo -e "$(CYAN)* * * * * SKEPTICISM REMOVED * * * * *$(END)\n"

re:	clear fclean tclean all

$(OBJ_FOLDER)/%.o: tests/%$(LANG)
	@$(CC) -I $(HEADP) $(CFLAGS) $(TFLAGS) -c -o $@ $< \
	&& echo -e "$(BOLD)$(CYAN)"$< "$(END)$(BOLD)is ready.$(END)"    \
	|| echo -e "$(BOLD)$(RED)" $< "$(END)$(BOLD)is not ready.$(END)"
	gcc $(CFLAGS) -MM -MP -MT $@ $< > $(DEPDIR)/$*.d

hello:
	echo -e "$(SAY) I am Hu, a wandering believer. My praise are currently to $(NAME).$(END)"
	echo -e "$(SAY) My big brother is named Ri. You may know him ?$(END)"
