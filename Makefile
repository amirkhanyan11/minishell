NAME = minishell

COCOBOLOPATH = ./cocobolo/
COCOBOLO = ${COCOBOLOPATH}cocobolo.a

SRCSPATH = ./src/lifecycle/ ./src/other/ ./src/builtins/ ./src/name_lookup/ ./src/exec/
INCPATH = ./includes/ ${COCOBOLOPATH}cocobolo_includes/ ./readline_lib/include/
OBJSPATH = ./objs/

# SRCS = $(wildcard $(SRCSPATH)*.c)
# OBJS = $(patsubst $(SRCSPATH)%.c, $(OBJSPATH)%.o, $(SRCS))

vpath %.c ${SRCSPATH}

SRCS = $(foreach D, ${SRCSPATH}, $(wildcard ${D}*.c))
OBJS = $(foreach D, ${SRCSPATH}, $(patsubst ${D}%.c, ${OBJSPATH}%.o, ${SRCS}))

END = \x1b[0m
GREEN = \x1b[33;1m
YELLOW = \x1b[32;1m
PURPLE = \x1b[35;1m
CYAN = \x1b[1;36m
BLUE = \x1b[1;34m
YELLOW = \x1b[1;33m
GREEN = \x1b[1;32m
RED = \x1b[1;31m

CC = gcc
DEBUG = -fsanitize=address
WFLAGS = -Wall -Wextra -Werror
CFLAGS = $(foreach H, $(INCPATH), -I$(H)) #${DEBUG} #${WFLAGS}

LREADLINE = -L/usr/lib -lreadline

all : ${OBJSPATH} ${NAME}

${OBJSPATH} :
	@mkdir -p objs

${NAME} : ${COCOBOLO} ${OBJS}
	@${CC} ${CFLAGS} ${OBJSPATH}*.o ${COCOBOLO} ${LREADLINE} -o $@
	@echo "${GREEN} minishell compiled! ${END}"

${OBJSPATH}%.o : %.c Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${COCOBOLO} :
	@make -C ${COCOBOLOPATH} all

clean :
	@make -C ${COCOBOLOPATH} clean
	@rm -rf ${OBJSPATH} ${OPTIONALOBJS}

fclean : clean
	@make -C ${COCOBOLOPATH} fclean
	@rm -f ${NAME}

re : fclean all

config :
	./readline_config.sh readline_lib

push :

	make fclean
	git add .
	git commit -m "."
	git push

leaks : re

	valgrind --leak-check=full --show-leak-kinds=all ./${NAME}

.PHONY : all clean fclean re leaks config

