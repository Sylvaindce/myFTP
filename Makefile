##
## Makefile for philo in /home/decomb_s/rendu/PSU_2014_philo
## 
## Made by Sylvain DECOMBE
## Login   <decomb_s@epitech.net>
## 
## Started on  Tue Feb 17 10:58:12 2015 Sylvain DECOMBE
## Last update Sat Mar 28 00:50:47 2015 Sylvain DECOMBE
##

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRCS1	=	Client/client.c		\
		Client/man_disp.c	\
		Client/strcp.c		\
		Client/xmalloc.c

SRCS2	=	Server/accept.c		\
		Server/action.c		\
		Server/action2.c	\
		Server/man_cd.c		\
		Server/man_env.c	\
		Server/man_err.c	\
		Server/man_ls.c		\
		Server/man_file.c	\
		Server/man_pwd.c	\
		Server/open.c		\
		Server/server.c		\
		Server/strcp.c		\
		Server/xmalloc.c

OBJS1	=	$(SRCS1:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

NAME1	=	client

NAME2	=	serveur

RM =		rm -f

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
		$(CC) $(SRCS1) -o $(NAME1)

$(NAME2):	$(OBJS2)
		$(CC) $(SRCS2) -o $(NAME2)
clean:
		$(RM) $(OBJS1) $(OBJS2)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
