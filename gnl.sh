#!/bin/bash

DEFAULT="\033[0m"
BOLD="\033[1m"
UNDERLINE="\033[4m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BBLUE="\033[1;34m"
BLUE="\033[0;34m"
PURPLE="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

ptitle()
{
	printf "${BBLUE}${1}${DEFAULT}\n"
	printf "${BBLUE}---------------------${DEFAULT}\n"
}

t_btest()
{
	NAME=HelloWorld_25
	clang -Wall -Wextra -Werror -I libft/includes -o srcs/mainb.o -c srcs/mainb.c
	clang -o test_gnl srcs/mainb.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/t_${1}.txt > ./result/t_${1}.output
	DIFF=$(diff ./result/t_${1}.output ./result/r_${1}.txt)
	if [ "$DIFF" != "" ]
	then
		printf "${1}\033[20G ${RED}✗${DEFAULT}\n"
	else
		printf "${1}\033[20G ${GREEN}✓${DEFAULT}\n"
	fi
}

btest()
{
	ptitle "Basics tests"
	t_btest HelloWorld_25
	t_btest alonglongline
	t_btest empty
	t_btest longlinenonl
	t_btest loremipsumdolor
	t_btest oneline
	t_btest simple
	t_btest text
	t_btest bintest
	t_btest zerononwl
}

t_1test()
{
	ptitle "Multi fd simple test"
	clang -Wall -Wextra -Werror -I libft/includes -o srcs/main1.o -c srcs/main1.c
	clang -o test_gnl srcs/main1.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/11 ./test/12 ./test/13 > ./result/1test.output
	DIFF=$(diff ./result/1test.output ./result/r_1test.txt)
	if [ "$DIFF" != "" ]
	then
		printf "1test\033[20G ${RED}✗${DEFAULT}\n"
	else
		printf "1test\033[20G ${GREEN}✓${DEFAULT}\n"
	fi
}

t_2test()
{
	ptitle "Multi fd hard test"
	clang -Wall -Wextra -Werror -I libft/includes -o srcs/main2.o -c srcs/main2.c
	clang -o test_gnl srcs/main2.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/21 ./test/22 ./test/23 > ./result/2test.output
	DIFF=$(diff ./result/2test.output ./result/r_2test.txt)
	if [ "$DIFF" != "" ]
	then
		printf "2test\033[20G ${RED}✗${DEFAULT}\n"
	else
		printf "2test\033[20G ${GREEN}✓${DEFAULT}\n"
	fi
	valgrind --leak-check=full --show-leak-kinds=all ./test_gnl test/21 test/22 test/23 | grep "blocks"
}

get_data()
{
	cp -R ../libft .
	cp ../get_next_line.c .
	cp ../get_next_line.h libft/includes
	make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o srcs/mainb.o -c srcs/mainb.c
	clang -o test_gnl srcs/mainb.o get_next_line.o -I libft/includes -L libft/ -lft
}

if [ $# -eq 0 ]
then
	get_data
elif [ $1 = "clean" ]
then
	make -C libft/ fclean
	rm -f ./result/*.output
	rm -f ./*.o
	rm -f test_gnl
	rm -f srcs/main*.o
	rm -rf test_gnl.dSYM
elif [ $1 = "btest" ]
then
	get_data
	btest
elif [ $1 = "1test" ]
then
	get_data
	t_1test
elif [ $1 = "2test" ]
then
	get_data
	t_2test
elif [ $1 = "all" ]
then
	get_data
	btest
	t_1test
	t_2test
fi
