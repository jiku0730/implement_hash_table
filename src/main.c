#include "hash_table.h"

typedef struct hash_table
{
	char 	*key;
	int		value;
}			hash_table;

hash_table *liner_serch(hash_table *hash_table, size_t size, const char *key)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		if (strcmp(hash_table[idx].key, key) == 0)
			return (&hash_table[idx]);
		idx++;
	}
	return (NULL);
}
int main(int argc, char const *argv[])
{
	hash_table	ht[] = {{"apple", 3}, {"orange", 10}, {"banana", 5}};
	size_t		size = sizeof(ht) / sizeof(ht[0]);
	hash_table	*find = liner_serch(ht, size, "orange");

	(void)argc;
	(void)argv;
	if (!find)
		return (1);
	printf("find->key = %s, find->value = %d\n", find->key, find->value);
	return 0;
}
