#include "hash_table.h"

ht *ht_create(void)
{
	ht	*table;

	table = calloc(sizeof(ht), 1);
	if (!table)
		return (NULL);
	table->capacity = INITIAL_CAPACITY;
	table->entries = calloc(table->capacity, sizeof(ht_entry));
	if (!table->entries)
	{
		free(table);
		return (NULL);
	}
	return (table);
}
