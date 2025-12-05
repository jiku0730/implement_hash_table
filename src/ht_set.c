#include "hash_table.h"
#include <stdint.h>
#include <stdbool.h>

uint64_t	hash_key(const char *key);

static const char	*ht_set_entry(ht_entry *entries, size_t capacity,
	const char *key, void *value, size_t *length)
{
	uint64_t	hash;
	size_t		idx;

	hash = hash_key(key);
	idx = (size_t)(hash & (uint64_t)(capacity - 1));
	while (entries[idx].key != NULL)
	{
		if (strcmp(key, entries[idx].key) == 0)
			return (entries[idx].value = value, entries[idx].key);
		idx++;
		if (idx >= capacity)
			idx = 0;
	}
	if (length != NULL)
	{
		key = strdup(key);
		if (!key)
			return (NULL);
		(*length)++;
	}
	entries[idx].key = (char *)key;
	entries[idx].value = value;
	return (key);
}

static bool	ht_expand(ht* tab)
{
	size_t		new_capacity;
	ht_entry*	new_entries;
	size_t		idx;
	ht_entry	ety;

	new_capacity = tab->capacity * 2;
	if (new_capacity < tab->capacity)
		return (false);
	new_entries = calloc(new_capacity, sizeof(ht_entry));
	if (new_entries == NULL)
		return (false);
	idx = 0;
	while (idx < tab->capacity)
	{
		ety = tab->entries[idx];
		if (ety.key != NULL)
			ht_set_entry(new_entries, new_capacity, ety.key, ety.value, NULL);
	}
	free(tab->entries);
	tab->entries = new_entries;
	tab->capacity = new_capacity;
	return (true);
}
const char *ht_set(ht *tab, const char *key, void *value)
{
	const char	*rtv;

	if (value == NULL)
		return (NULL);
	if (tab->length >= tab->capacity / 2)
	{
		if (!ht_expand(tab))
			return (NULL);
	}
	rtv = ht_set_entry(tab->entries, tab->capacity, key, value, &tab->length);
	return (rtv);
}
