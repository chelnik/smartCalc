SRC =   listFunction.c supportFunction.c validator.c parser.c priorityFunction.c printers.c forFunc.c 
# MAIN = templ.c
MAIN = main.c
OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror
FLAGS_PLATFORM = -lcheck
# NAME_LIB	=	s21_math.a
# MATH_DIR=../math/
# SRC_MATH = $(addprefix $(MATH_DIR), s21_abs.c	s21_fabs.c\
# 	s21_sin.c	s21_cos.c\
# 	s21_fmod.c	s21_tan.c\
# 	s21_pow.c	s21_asin.c\
# 	s21_exp.c	s21_acos.c\
# 	s21_log.c	s21_sqrt.c\
# 	s21_ceil.c	s21_floor.c\
# 	s21_atan.c	remove_circle.c)

# OBJ_MATH		=	$(SRC_MATH:%.c=%.o)

all: test

test:
	@make clean
	@gcc -g $(CFLAGS) $(MAIN) $(SRC) && ./a.out
	@make clean


clean:
	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out
# valgrind:
# 	gcc -std=c11 -g main.c $(SRC) -lcheck -o unit.out
# 	CK_FORK=no valgrind --leak-check=full -s ./unit.out

# valgrind: $(NAME)
# 	@echo -------------------MEMORY_LEAKS-------------------
# 	@echo $(CC) -g $(TEST) $(NAME) $(FLAGS_PLATFORM) -o unit.out
# 	@echo CK_FORK=no valgrind --leak-check=full -s ./unit.out	

# Сборка библиотеки
# $(NAME_LIB): $(OBJ_MATH) $(HEADER)
# 	@ar rcs $(NAME_LIB) $?
# 	@rm -f *.o

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@


# fclean: clean
# 	@rm -f $(NAME_LIB)
# 	@rm -rf report

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h $(SRC)
	@echo ---------------------CPPLINT----------------------
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c $(SRC) $(TEST) *.h *.c
	rm CPPLINT.cfg

leak:
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(MAIN) $(SRC) $(FLAGS_PLATFORM) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out