SRC =   listFunction.c supportFunction.c validator.c parser.c priorityFunction.c
# MAIN = templ.c
MAIN = main.c
OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror


all: test

test:
	@make clean
	@gcc -g $(MAIN) $(SRC) && ./a.out
	@make clean


clean:
	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out
valgrind:
	gcc -std=c11 -g main.c $(SRC) -lcheck -o unit.out
	CK_FORK=no valgrind --leak-check=full -s ./unit.out

# valgrind: $(NAME)
# 	@echo -------------------MEMORY_LEAKS-------------------
# 	@echo $(CC) -g $(TEST) $(NAME) $(FLAGS_PLATFORM) -o unit.out
# 	@echo CK_FORK=no valgrind --leak-check=full -s ./unit.out	