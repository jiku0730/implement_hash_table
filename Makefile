CC ?= cc
CFLAG ?= -Wall -Wextra -Werror
AR := ar rcs

SRCS := src/ht_create.c \
		src/ht_set.c \
		src/ht_length.c \
		src/ht_destroy.c \
		src/ht_get.c \
		src/utils/hash_key.c \

OBJS := $(SRCS:src/%.c=obj/%.o)
NAME := hash_table.a
INCLUDE := includes

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAG) -I$(INCLUDE)  -c $^ -o $@
