#include "hash_table.h"

void	ht_destroy(ht *table)
{
	size_t	idx;

	idx = 0;
	while (idx < table->capacity)
	{
		free(table->entries[idx].key);
		idx++;
	}
	free(table->entries);
	free(table);
}
