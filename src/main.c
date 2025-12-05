#include "hash_table.h"

typedef struct hash_table
{
	char	*key;
	int		value;
}			hash_table;

hash_table *linear_search(hash_table *ht, size_t size, const char *key)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		if (strcmp(ht[idx].key, key) == 0)
			return (&ht[idx]);
		idx++;
	}
	return (NULL);
}

hash_table *binary_search(hash_table *ht, size_t size, const char *key)
{
	if (size + size < size)
		return (NULL);

	size_t	low = 0;
	size_t	high = size;
	while (low < high)
	{
		size_t	mid = (low + high) / 2;
		int		diff = strcmp(ht[mid].key, key);
		if (diff == 0)
			return (&ht[mid]);
		else if (diff > 0)
			high = mid;
		else if (diff < 0)
			low = mid + 1;
	}
	return (NULL);
}

int main(int argc, char const *argv[])
{
	hash_table	ht[] = {{"apple", 3}, {"banana", 5}, {"orange", 10}, {"pinapple", 12}};
	size_t		size = sizeof(ht) / sizeof(ht[0]);
	hash_table	*find_linear = linear_search(ht, size, "pinapple");
	hash_table	*find_binary = binary_search(ht, size, "pinapple");

	(void)argc;
	(void)argv;
	if (!find_linear)
		return (1);
	printf("find_linear->key = %s, find_linear->value = %d\n", \
		find_linear->key, find_linear->value);
	if (!find_binary)
		return (1);
	printf("find_binary->key = %s, find_binary->value = %d\n", \
		find_binary->key, find_binary->value);
	return (0);
}
