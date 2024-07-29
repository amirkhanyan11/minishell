ROOT = ./
NAME = cocobolo.a

SRCSPATH = ${ROOT}cocobolo_src/ ${ROOT}optional/ ${ROOT}list/ ${ROOT}get_next_line/
OBJSPATH = ${ROOT}cocobolo_objs/
INCPATH = ${ROOT}cocobolo_includes/

END = \x1b[0m
GREEN = \x1b[33;1m
YELLOW = \x1b[32;1m
PURPLE = \x1b[35;1m
CYAN = \x1b[1;36m
BLUE = \x1b[1;34m
YELLOW = \x1b[1;33m
GREEN = \x1b[1;32m
RED = \x1b[1;31m

vpath %.c ${SRCSPATH}

SRCS = $(foreach L, ${SRCSPATH}, $(wildcard ${L}*.c))
OBJS =  $(foreach L, ${SRCSPATH}, $(patsubst ${L}%.c, ${OBJSPATH}%.o, ${SRCS}))

CC = gcc
# DEBUG = -fsanitize=address
# DEBUG = -g
CFLAGS = $(foreach H, ${INCPATH}, -I${H}) ${DEBUG} #-Wall -Wextra -Werror

all : ${OBJSPATH} ${NAME}

${OBJSPATH} :
	@mkdir -p cocobolo_objs

${NAME} : ${OBJS}
	@ar -rcs ${NAME} ${OBJSPATH}*.o

${OBJSPATH}%.o : %.c Makefile
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	@rm -rf ${OBJSPATH}

fclean : clean
	@rm -f ${NAME}

re : fclean all

push :
	make fclean
	git add .
	git commit -m "updated cocobolo library"
	git push

.PHONY : all clean fclean re push

