##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

OUT 	=	panoramix
SOURCE	=	src/main.c			\
			src/my_metadata.c	\
			src/threads.c
CC		=	gcc
CFLAGS	=	-W -Wall -Wshadow -Wextra -I./includes
LDFLAGS	=	-lpthread
OBJS	=	$(SOURCE:.c=.o)


$(OUT):	$(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS) $(LDFLAGS)

all:	$(OUT)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(OUT)

re:		fclean all

debug:	CFLAGS	+=	-ggdb
debug:	re

.PHONY:	all clean fclean re debug
