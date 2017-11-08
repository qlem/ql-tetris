##
## Makefile for tetris in /home/qlem/rendu/tetris
## 
## Made by qlem
## Login   <clement.dommerc@epitech.eu>
## 
## Started on  Fri Jul 14 17:48:28 2017 qlem
## Last update Fri Nov  3 23:04:01 2017 qlem
##

NAME		:=	tetris

CC		:=	gcc

RM		:=	rm -f

CFLAGS		:=	-W -Wextra -Wall -Werror ## -ansi -pedantic

SRC_DIR		:=	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc

SRC		:=	check_rotate.c		\
			color.c			\
			debug.c			\
			event.c			\
			logic_menu.c		\
			free.c			\
			logic_game.c		\
			logic_start_end.c	\
			get_tetrimino.c		\
			init_menu.c		\
			init_tetrimino_1.c	\
			init_tetrimino_2.c	\
			init_var_game.c		\
			int_to_str_1.c		\
			int_to_str_2.c		\
			load_tetrimino.c	\
			main.c			\
			move_down.c		\
			move_left.c		\
			move_right.c		\
			render_game_1.c		\
			render_game_2.c		\
			render_menu.c		\
			render_over.c		\
			render_start.c		\
			rotate.c		\
			score.c			\
			timer_game.c		\
			timer_core.c		\
			audio.c
SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ		:=	$(SRC:.c=.o)
OBJ		:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcaca -lSDL2 -lSDL2_mixer

clean:
		$(RM) src/*~ obj/*~ inc/*~ *~
		$(RM) src/#*# obj/#* inc/#*# #*#
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
