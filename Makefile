##
## EPITECH PROJECT, 2023
## B-NWP-400-COT-4-1-myteams-christ.hounkanrin
## File description:
## Makefile
##

SRC_SERVER	=	$(wildcard src/src_linked_list/*.c\
		src/src_server/*.c)

SRC_CLIENT	=	$(wildcard src/src_linked_list/*.c \
		src/src_client/*.c)

NAME_SERVER 	=	myteams_server

NAME_CLIENT 	=	myteams_cli

LIBS	=	-L ./libs/myteams/ -lmyteams -luuid -g

all: general

general:
	gcc $(SRC_SERVER) -o $(NAME_SERVER) -g3 $(LIBS)
	gcc $(SRC_CLIENT) -o $(NAME_CLIENT) -g3 $(LIBS)

clean:
	rm -f *#
	rm -f *~
	rm -f *.gcda

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_TEST)
	rm -f *.gcno

re:	fclean all
