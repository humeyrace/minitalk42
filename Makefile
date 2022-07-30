NAME			= ignore
SERVERNAME		=	server
SERVER_SRC		=	server.c

CLIENTNAME		=	client
CLIENT_SRC		=	client.c 

UTILS_SRC               =       minitalk_utils.c
 
CC			=	@gcc
RM 			=	@rm -f
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVERNAME) $(CLIENTNAME)

$(SERVERNAME) : $(SERVER_SRC) $(UTILS_SRC)
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVERNAME)

$(CLIENTNAME) : $(CLIENT_SRC) $(UTILS_SRC)
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENTNAME)

$(NAME)   : all

fclean: clean
	rm -rf $(SERVERNAME) $(CLIENTNAME) $(UTILSNAME)

clean:
	rm -rf server client

re : fclean all

.PHONY: all fclean re
