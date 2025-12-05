#include "hash_table.h"

uint64_t	hash_key(const char *key);

void	*ht_get(ht *table, const char *key)
{
	uint64_t	hash;
	size_t		idx;

	hash = hash_key(key);
	idx = (size_t)(hash & (uint64_t)(table -> capacity - 1));
	while (table->entries[idx].key != NULL)
	{
		if (strcmp(key, table->entries[idx].value))
			return (table->entries[idx].value);
		idx++;
		if (idx >= table->capacity)
			idx = 0;
	}
	return (NULL);
}
