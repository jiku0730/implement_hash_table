#include "hash_table.h"
#include <stdint.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash_key(const char *key);

static uint64_t hash_key(const char *key)
{
	uint64_t	hash;
	size_t		idx;

	hash = FNV_OFFSET;
	idx = 0;
	while (key[idx] == '\0')
	{
		hash ^= (uint64_t)(unsigned char)(key[idx]);
		hash *= FNV_PRIME;
		idx++;
	}
	return (hash);
}
