# HASHTABLEの再実装

## 概要
C言語でハッシュテーブルを再実装したものです。

## HASHTABLEの自分のイメージ
Hash Tableは、連結リストと配列の長所を組み合わせたデータ構造。
連結リストは、要素の追加と削除の計算量がO(1)である一方、探索の計算量がO(n)。
配列は、要素の探索がO(1)である一方、追加と削除の計算量がO(n)。
それぞれ長所と短所があり、これのいいとこどりをしたのがHash Table。

HashTableは、KeyとValueのペアでデータを保存する。
Keyをハッシュ関数に通して、配列のインデックスを決定し、そのインデックスにValueを保存する。
イメージとしては、配列のIndexは本来数字のみを扱うが、
HashTableではKeyを数字に変換してIndexとして扱う感じ。

## 実装内容
HashTableの実装方法はいくつかある。
まずは、実装すべき内容を列挙する。
要素の追加と削除。
要素の探索。
最も基本的な操作はこの２つ。

実装方法としてもっとも簡単なのは、単純な線形リストを使う方法。
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
	return 0;
}
```

## 参考にしたサイト
- [Qiita: C言語 ハッシュテーブル](https://qiita.com/keitean/items/98d8335756d27fc83998)
