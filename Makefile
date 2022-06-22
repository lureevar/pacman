CC=g++
CFLAGS=-Wall -Wextra -Werror -g -O2
ALLEGRO=-lallegro -lallegro_image -lallegro_font

SRC=src
BIN=bin
OBJ=obj
HDR=include

SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

NAME=$(BIN)/pacman.out

all: $(BIN) $(OBJ) $(NAME)

$(NAME): $(OBJS) main.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(ALLEGRO)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -I $(HDR) -c $< -o $@ $(ALLEGRO)

$(BIN):
	mkdir $@

$(OBJ):
	mkdir $@

clean:
	rm -rf $(BIN) $(OBJ)

run: all
	./$(NAME)
