#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

# define INITIAL_CAPACITY 16
typedef struct
{
	char	*key;
	void	*value;
}			ht_entry;

typedef struct
{
	ht_entry	*entries;
	size_t		capacity;
	size_t		length;
}				ht;

ht			*ht_create(void);
void		ht_destroy(ht *table);
void		*ht_get(ht *table, const char *key);
const char	*ht_set(ht *table, const char *key, void *value);
size_t		ht_length(ht *table);

#endif
