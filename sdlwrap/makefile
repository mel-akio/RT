# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/07 17:58:07 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2018/07/05 11:52:57 by aberneli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc
NAME = sdlwrap
SRCS = main.c loop.c init.c set.c framebuffer.c
OBJS = $(SRCS:.c=.o)
HEADERS = sdlwrap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -O2 -L./SDL2/lib -lSDL2main -lSDL2 -lSDL2_image $(OBJS) -o $(NAME)

./%.o: ./%.c $(HEADERS)
	$(CC) -O2 -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

normy:
	norminette $(SRCS) $(HEADERS)
