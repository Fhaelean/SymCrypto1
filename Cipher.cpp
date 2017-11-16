#include "Header.h"
#define SIZE 3000000

void cypher(const char *text, const int n, const int l)
{
	char *key = new char[l];
	int *key2 = new int[l];
	char c;
	int s = 0;
	if (l == 2)
	{
		FILE * doc = fopen("key2.txt", "r");
		while (fscanf(doc, "%c", &c) != EOF)
		{
			key[s++] = c;
		}
		fclose(doc);
	}
	if (l == 3)
	{
		FILE * doc = fopen("key3.txt", "r");
		while (fscanf(doc, "%c", &c) != EOF)
		{
			key[s++] = c;
		}
		fclose(doc);
	}
	if (l == 4)
	{
		FILE * doc = fopen("key4.txt", "r");
		while (fscanf(doc, "%c", &c) != EOF)
		{
			key[s++] = c;
		}
		fclose(doc);
	}
	if (l == 5)
	{
		FILE * doc = fopen("key5.txt", "r");
		while (fscanf(doc, "%c", &c) != EOF)
		{
			key[s++] = c;
		}
		fclose(doc);
	}
	if (l == 10)
	{
		FILE * doc = fopen("key10.txt", "r");
		while (fscanf(doc, "%c", &c) != EOF)
		{
			key[s++] = c;
		}
		fclose(doc);
	}
	if (l == 20)
	{
		FILE * doc = fopen("key20.txt", "r");
		while (fscanf(doc, "%c", &c) != EOF)
		{
			key[s++] = c;
		}
		fclose(doc);
	}
	for (int i = 0; i < l; ++i)
	{
		if (key[i] == '�')
			key2[i] = 0;
		if (key[i] == '�')
			key2[i] = 1;
		if (key[i] == '�')
			key2[i] = 2;
		if (key[i] == '�')
			key2[i] = 3;
		if (key[i] == '�')
			key2[i] = 4;
		if (key[i] == '�')
			key2[i] = 5;
		if (key[i] == '�')
			key2[i] = 6;
		if (key[i] == '�')
			key2[i] = 7;
		if (key[i] == '�')
			key2[i] = 8;
		if (key[i] == '�')
			key2[i] = 9;
		if (key[i] == '�')
			key2[i] = 10;
		if (key[i] == '�')
			key2[i] = 11;
		if (key[i] == '�')
			key2[i] = 12;
		if (key[i] == '�')
			key2[i] = 13;
		if (key[i] == '�')
			key2[i] = 14;
		if (key[i] == '�')
			key2[i] = 15;
		if (key[i] == '�')
			key2[i] = 16;
		if (key[i] == '�')
			key2[i] = 17;
		if (key[i] == '�')
			key2[i] = 18;
		if (key[i] == '�')
			key2[i] = 19;
		if (key[i] == '�')
			key2[i] = 20;
		if (key[i] == '�')
			key2[i] = 21;
		if (key[i] == '�')
			key2[i] = 22;
		if (key[i] == '�')
			key2[i] = 23;
		if (key[i] == '�')
			key2[i] = 24;
		if (key[i] == '�')
			key2[i] = 25;
		if (key[i] == '�')
			key2[i] = 26;
		if (key[i] == '�')
			key2[i] = 27;
		if (key[i] == '�')
			key2[i] = 28;
		if (key[i] == '�')
			key2[i] = 29;
		if (key[i] == '�')
			key2[i] = 30;
		if (key[i] == '�')
			key2[i] = 31;
	}
	cout << "Key = ";
	for (int i = 0; i < l; ++i)
	{
		cout << (char)(key2[i] - 32);
	}
	cout << endl;

	int x = 0;
	cout << "�� = ";
	float freq[32] = { 0 };
	for (int i = 0; i < n; ++i)
	{
			cout << (char)(((text[x] + 32) + key2[x % l]) % 32 - 32);
			freq[((text[x] + 32) + key2[x % l]) % 32] += 1;
			++x;
	}
	cout << endl;
	float index = 0;
	for (int i = 0; i < 32; ++i)
	{
		index = index + (1.0 * freq[i] / x)*(1.0*freq[i] / x);
	}
	cout << "Index = " << index << endl;
	delete[]key;
	delete[]key2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char *text = new char[SIZE];
	char c;
	int n = 0;

	FILE * doc = fopen("textCipher.txt", "r");
	while (fscanf(doc, "%c", &c) != EOF)
	{
		if ('�' <= c && c <= '�')
		{
			text[n++] = c;
		}
		if ('�' <= c && c <= '�')
		{
			text[n++] = c + 32;
		}
	}

	float indopen = 0;
	map <char, int> chars;
	map <char, int>::iterator begin, at, end;

	for (unsigned int i = 0; i < n; i++)
	{
		chars[text[i]]++;
	}
	begin = chars.begin();
	end = chars.end();
	for (at = begin; at != end; at++)
	{
		indopen = indopen + (1.0 * (at->second) / n)*(1.0 * (at->second) / n);
	}
	cout << "Index open = " << indopen << endl;

	freopen("cypher2.txt", "w", stdout);
	cypher(text, n, 2);
	freopen("cypher3.txt", "w", stdout);
	cypher(text, n, 3);
	freopen("cypher4.txt", "w", stdout);
	cypher(text, n, 4);
	freopen("cypher5.txt", "w", stdout);
	cypher(text, n, 5);
	freopen("cypher10.txt", "w", stdout);
	cypher(text, n, 10);
	freopen("cypher20.txt", "w", stdout);
	cypher(text, n, 20);

	return EXIT_SUCCESS;
}