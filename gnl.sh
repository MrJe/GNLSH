#!/bin/bash

t_hello()
{
	clang -Wall -Wextra -Werror -I libft/includes -o mainb.o -c mainb.c
	clang -o test_gnl mainb.o get_next_line.o -I libft/includes -L libft/ -lft
	./test_gnl ./test/t_HelloWorld_25.txt > ./result/t_HelloWorld_25.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/t_HelloWorld_25.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/t_HelloWorld_25.output ./result/r_HelloWorld_25.txt
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	./test_gnl ./test/t_alonglongline.txt > ./result/t_alonglongline.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/t_alonglongline.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/t_alonglongline.output ./result/r_alonglongline.txt
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	./test_gnl ./test/t_empty.txt > ./result/t_empty.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/t_empty.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/t_empty.output ./result/r_empty.txt
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	./test_gnl ./test/t_longlinenonl.txt > ./result/t_longlinenonl.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/t_longlinenonl.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/t_longlinenonl.output ./result/r_longlinenonl.txt
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	./test_gnl ./test/t_longtext.txt > ./result/t_longtext.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/t_longtext.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/t_longtext.output ./result/r_longtext.txt
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	./test_gnl ./test/t_loremipsumdolor.txt > ./result/t_loremipsumdolor.output
	echo "- - - E C H O - . O U T P U T - - -"
	cat ./result/t_loremipsumdolor.output
	echo "- - - - - - - D I F F - - - - - - -"
	diff ./result/t_loremipsumdolor.output ./result/r_lorempsumdolor.txt
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
	t_hello
elif [ $1 == "1test" ]
then
	t_1test
elif [ $1 == "2test" ]
then
	t_2test
elif [ $1 == "all" ]
then
	t_hello
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	t_1test
	echo "###################################"
	echo "############# N E X T #############"
	echo "###################################"
	t_2test
fi
