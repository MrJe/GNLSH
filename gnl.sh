#!/bin/bash

DEFAULT="\033[0m"
BOLD="\033[1m"
UNDERLINE="\033[4m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PURPLE="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

next()
{
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
}

t_btest()
{
	NAME=HelloWorld_25
	clang -Wall -Wextra -Werror -I libft/includes -o mainb.o -c mainb.c
	clang -o test_gnl mainb.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/t_${1}.txt > ./result/t_${1}.output
	DIFF=$(diff ./result/t_${1}.output ./result/r_${1}.txt)
	if [ "$DIFF" != "" ]
	then
		printf "${1}\033[20G ${RED}✗${DEFAULT}\n"
	else
		printf "${1}\033[20G ${GREEN}✓${DEFAULT}\n"
	fi
}

t_1test()
{
	clang -Wall -Wextra -Werror -I libft/includes -o main1.o -c main1.c
	clang -o test_gnl main1.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/11 ./test/12 ./test/13 > ./result/1test.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/1test.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/1test.output ./result/r_1test.txt
}

t_2test()
{
	clang -Wall -Wextra -Werror -I libft/includes -o main2.o -c main2.c
	clang -o test_gnl main2.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/21 ./test/22 ./test/23 > ./result/2test.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/2test.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/2test.output ./result/r_2test.txt
}

btest()
{
	t_btest HelloWorld_25
	t_btest alonglongline
	t_btest empty
	t_btest longlinenonl
	t_btest loremipsumdolor
	t_btest oneline
	t_btest simple
	t_btest text
}

if [ $# -eq 0 ]
then
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
elif [ $1 == "clean" ]
then
	make -C libft/ fclean
	rm -f ./result/*.output
	rm -f ./*.o
	rm -f test_gnl
elif [ $1 == "btest" ]
then
	btest
elif [ $1 == "1test" ]
then
	t_1test
elif [ $1 == "2test" ]
then
	t_2test
elif [ $1 == "all" ]
then
	btest
	next
	t_1test
	next
	t_2test
fi
