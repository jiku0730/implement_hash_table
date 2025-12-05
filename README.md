# Hash Tableの再実装

## 概要
C言語でハッシュテーブルを再実装したものです。

## Hash Tableの自分のイメージ
Hash Tableは、連結リストと配列の長所を組み合わせたデータ構造。<br>
連結リストは、要素の追加と削除の計算量がO(1)である一方、探索の計算量がO(n)。<br>
配列は、要素の探索がO(1)である一方、追加と削除の計算量がO(n)。<br>
それぞれ長所と短所があり、これのいいとこどりをしたのがHash Table。

Hash Tableは、KeyとValueのペアでデータを保存する。<br>
Keyをハッシュ関数に通して、配列のインデックスを決定し、
そのインデックスにValueを保存する。<br>
イメージとしては、配列のIndexは本来数字のみを扱うが、
Hash TableではKeyを数字に変換してIndexとして扱う感じ。

## 実装内容
Hash Tableの実装方法はいくつかある。
まずは、実装すべき内容を列挙する。
要素の追加と削除。
要素の探索。
最も基本的な操作はこの２つ。

### 線形探索
実装方法としてもっとも簡単なのは、単純な配列を使う方法。
一旦はこれを実装していく。
```c
#include "hash_table.h"

typedef struct hash_table
{
	char 	*key;
	int		value;
}			hash_table;

hash_table *linear_search(hash_table *hash_table, size_t size, const char *key)
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
	hash_table	*find = linear_search(ht, size, "orange");

	(void)argc;
	(void)argv;
	if (!find)
		return (1);
	printf("find->key = %s, find->value = %d\n", find->key, find->value);
	return (0);
}
```

```
$ ./implement_hash_table
find->key = orange, find->value = 10
```
今の状態だと、要素の追加と削除ができない。
また、探索も線形探索なので計算量がO(n)となってしまう。
次に、二分探索を実装していく。
### 二分探索
二分探索を実装するためには、まず配列をソートしておく必要がある。
とりあえずここの部分は省略する。
二分探索に限って実装する。
```c
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
```
これにより、探索の計算量がO(log n)となる。

## Hash Tableの実装
必要なAPIを参照する。
```c
// Hash table structure: create with ht_create, free with ht_destroy.
typedef struct ht ht;

// Create hash table and return pointer to it, or NULL if out of memory.
ht* ht_create(void);

// Free memory allocated for hash table, including allocated keys.
void ht_destroy(ht* table);

// Get item with given key (NUL-terminated) from hash table. Return
// value (which was set with ht_set), or NULL if key not found.
void* ht_get(ht* table, const char* key);

// Set item with given key (NUL-terminated) to value (which must not
// be NULL). If not already present in table, key is copied to newly
// allocated memory (keys are freed automatically when ht_destroy is
// called). Return address of copied key, or NULL if out of memory.
const char* ht_set(ht* table, const char* key, void* value);

// Return number of items in hash table.
size_t ht_length(ht* table);

// Hash table iterator: create with ht_iterator, iterate with ht_next.
typedef struct {
    const char* key;  // current key
    void* value;      // current value

    // Don't use these fields directly.
    ht* _table;       // reference to hash table being iterated
    size_t _index;    // current index into ht._entries
} hti;

// Return new hash table iterator (for use with ht_next).
hti ht_iterator(ht* table);

// Move iterator to next item in hash table, update iterator's key
// and value to current item, and return true. If there are no more
// items, return false. Don't call ht_set during iteration.
bool ht_next(hti* it);
```
以上の関数を実装していく。

## 参考にしたサイト
- [Qiita: C言語 ハッシュテーブル](https://qiita.com/keitean/items/98d8335756d27fc83998)
- [Wikipedia: ハッシュテーブル](https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%83%E3%82%B7%E3%83%A5%E3%83%86%E3%83%BC%E3%83%96%E3%83%AB)
- [How to implement a hash table (in C)](https://benhoyt.com/writings/hash-table-in-c/)
- [Wikipedia: 連想配列](https://ja.wikipedia.org/wiki/%E9%80%A3%E6%83%B3%E9%85%8D%E5%88%97)
