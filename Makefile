CC=gcc
INC=-Iinclude
CFLAGS=-Wall -Wextra $(INC)
ifdef DEBUG
	CFLAGS += -g -ggdb
endif
LD=gcc
LIBS=-lraylib
LDFLAGS=$(LIBS)
NAME=Codysee
OBJS=$(SRCS:.c=.o)

SRCS=           \
	src/main.c \
	src/game.c


HEADERS=               \
	include/game.h \
	include/macros.h

$(NAME): $(OBJS)
	@$(LD) -o $(NAME) $(OBJS) $(LDFLAGS)
ifdef DEBUG
	@echo "[DEBUG] -> Debug version activated"
endif
	@echo "[INFO] -> Compilation complete"

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

rdebug:
	@make re DEBUG=1 --no-print-directory -C .

.PHONY: all clean fclean re run rdebug
