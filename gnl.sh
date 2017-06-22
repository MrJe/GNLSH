#!/bin/bash

DEFAULT="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
BBLUE="\033[1;34m"

ptitle()
{
	printf "${BBLUE}${1}${DEFAULT}\n"
	printf "${BBLUE}---------------------${DEFAULT}\n"
}

get_exe()
{
	clang -Wall -Wextra -Werror -I libft/includes -o srcs/${1}.o -c srcs/${1}.c
	clang -o test_gnl srcs/${1}.o get_next_line.o -I libft/includes -L libft/ -lft
}

get_diff()
{
	DIFF=$(diff ./result/t_${1}.output ./result/r_${1}.txt)
	if [ "$DIFF" != "" ]
	then
		printf "${1}\033[20G ${RED}✗${DEFAULT}\n"
	else
		printf "${1}\033[20G ${GREEN}✓${DEFAULT}\n"
	fi
}

t_error()
{
	ptitle "Errors tests"
	get_exe maine
	./test_gnl / > ./result/t_racine.output
	get_diff racine
	./test_gnl ./test/t_alonglongline.txt > ./result/t_errlongline.output
	get_diff errlongline
}

t_btest()
{
	./test_gnl ./test/t_${1}.txt > ./result/t_${1}.output
	get_diff ${1}
}

t_3test()
{
	./test_gnl test/${1} test/${2} test/${3} > ./result/t_${4}.output
	get_diff ${4}
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
	t_3test 21 22 23 btmulti
}

t_1test()
{
	ptitle "Multi fd simple test"
	get_exe main1
	t_3test 11 12 13 1test
	t_3test 21 22 23 12test
}

t_2test()
{
	ptitle "Multi fd hard test"
	get_exe main2
	t_3test 21 22 23 2test
	t_3test 11 12 13 21test
}

get_data()
{
	cp -R ../libft .
	make -C libft/
	cp ../get_next_line.c .
	mkdir libft/includes 2> /dev/null
	cp libft/*.h libft/includes 2> /dev/null
	cp ../get_next_line.h libft/includes
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	get_exe mainb
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
elif [ $1 = "error" ]
then
	get_data
	t_error
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
	t_error
	t_1test
	t_2test
fi
