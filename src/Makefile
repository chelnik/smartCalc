SRC = createMatrix.c

OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror


all: test

test:
	@make clean
	@gcc -g main.c && ./a.out
	@make clean


clean:
	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out