CC ?= cc
CFLAG ?= -Wall -Wextra -Werror

SRCS := src/main.c
NAME := implement_hash_table
INCLUDE := includes

all:
	$(CC) $(CFLAG) $(SRCS) -I$(INCLUDE) -o $(NAME)
