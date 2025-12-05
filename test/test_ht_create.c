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

int	test_ht_create_basic(void)
{
	ht		*table;
	size_t	idx;

	table = ht_create();
	if (table == NULL)
		return (printf("table == NULL\n"), -1);
	if (table->capacity != INITIAL_CAPACITY)
		return (printf("table->capacity != INITIAL_CAPACITY\n"), -1);
	if (table->entries == NULL)
		return (-1);
	idx = 0;
	while (idx < table->capacity)
	{
		if (table->entries[idx].key != NULL)
			return (-1);
		if (table->entries[idx].value != 0)
			return (-1);
		idx++;
	}
	ht_destroy(table);
	return (0);
}

int	main(void)
{
	if (test_ht_create_basic() == -1)
	{
		printf("test_ht_create_basic: NG\n");
		return (1);
	}
	printf("test_ht_create_basic: OK\n");
	return 0;
}
