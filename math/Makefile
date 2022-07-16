NAME_LIB	=	s21_math.a

SRC_MATH=s21_abs.c	s21_fabs.c\
	s21_sin.c	s21_cos.c\
	s21_fmod.c	s21_tan.c\
	s21_pow.c	s21_asin.c\
	s21_exp.c	s21_acos.c\
	s21_log.c	s21_sqrt.c\
	s21_ceil.c	s21_floor.c\
	s21_atan.c	remove_circle.c\

OBJ_MATH		=	$(SRC_MATH:%.c=%.o)

# CC 		= gcc -std=c11

# CFLAGS	= -Wall -Wextra -Werror


# Сборка библиотеки
$(NAME_LIB): $(OBJ_MATH) $(HEADER)
	@ar rcs $(NAME_LIB) $?
	@rm -f *.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out

fclean: clean
	@rm -f $(NAME_LIB)
	@rm -rf report

