#include "Header.h"
#define SIZE 5000000

bool pred(const std::pair< int, int > &a, const std::pair< int, int > &b)
{
	return a.second < b.second;
}

float index(const int *text, const int & n, const int & t)
{
	float index = 0;
	for (int i = 0; i < t; ++i)
	{
		float k = 0;
		int a[32] = { 0 };
		for (int j = i; j < n; j = j + t)
		{
			++a[text[j]];
		}
		for (int j = 0; j < 32; ++j)
		{
			k = k + (a[j] * (a[j] - 1));
		}
		k = k / ((n / t)*(n / t - 1));
		index = index + k;
	}
	return index / t;
}

int resultfunc(int l, int o)
{
	int result = 0;
	if (l < o)
	{
		result = o - l;
	}
	else if (l > o)
	{
		result = (o - l) + 32;
	}
	else if (l == o)
	{
		result = 0;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int *text = new int[SIZE];
	char *text1 = new char[SIZE];
	char c;
	int n = 0;
	int n1 = 0;

	FILE * doc = fopen("in.txt", "r");
	while (fscanf(doc, "%c", &c) != EOF)
	{
		if ('à' <= c && c <= 'ÿ')
		{
			text[n++] = c + 32;
			text1[n1++] = c;
		}
	}
	fclose(doc);

	for (int i = 1; i < 101; ++i)
	{
		cout << "i = " << i << "  index = " << index(text, n, i) << endl;
	}

	int o = 14;
	int ccc = 0;
	int keyl = 0;
	cout << "Enter key lenght = " << endl;
	cin >> keyl;
	ccc = (n / keyl);
	int *resarr = new int[keyl];
	char **arr1;
	arr1 = new char *[ccc];
	for (int i = 0; i < ccc; i++)
	{
		arr1[i] = new char[keyl];
	}

	char **arr;
	arr = new char *[ccc];
	for (int i = 0; i < ccc; i++)
	{
		arr[i] = new char[keyl];
	}
	int k = 0;
	for (int i = 0; i < ccc; i++)
	{
		for (int j = 0; j < keyl; j++)
		{
			arr[i][j] = text[k];
			k++;
		}
	}

	/*for (int i = 0; i < ccc; i++)
	{
		for (int j = 0; j < keyl; j++)
		{
			cout << (char)(arr[i][j]-32) << "\t| ";
		}
		cout << endl;
	}
	for (int i = 0; i < ccc; i++)
	{
		cout << (char)(arr[i][0] - 32) << "\t| ";
		cout << endl;
	}*/
	int ii = 0;
	int l;
	map <char, int> chars;
	map <char, int>::iterator begin, at, end;
	for (int j = 0; j < keyl; j++)
	{
		for (unsigned int i = 0; i < ccc; i++)
		{
			chars[arr[i][j] - 32]++;
		}
		int max = 0;
		begin = chars.begin();
		end = chars.end();
		for (at = begin; at != end; at++)
		{
			//cout << at->first << "    " << (at->second) << endl;
		}

		std::vector< std::pair< int, int > > vec(chars.begin(), chars.end());
		vector< std::pair< int, int > >::iterator it;
		std::sort(vec.begin(), vec.end(), pred);
		for (auto p : vec)
			std::cout << (char)p.first << '\t' << (1.0 * (p.second) / ccc) << std::endl;

		for (it = vec.begin(); it != vec.end(); it++)
		{
			max = it->first;
			if (it->first > max)
			{
				max = it->first;
			}
		}
		//cout << "MAX" << max << endl;
		l = max + 32;
		int result = resultfunc(l, o);
		
		resarr[ii] = result;
		ii++;

		for (int i = 0; i < ccc; i++)
		{
			int elem = 0;
			int re = 0;
			elem = arr[i][j];
			re = (elem + result) % 32;
			arr1[i][j] = re;
			//cout << (char)(re - 32);
		}
		chars.clear();
	}

	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < keyl; j++)
		{
			cout << (char)(arr1[i][j] - 32) << "\t| ";
		}
		cout << endl;
	}

	int cul = 0;
	char yes = 0;
	while (yes != 'n')
	{
		cout << "Enter 'y' to change culumn: ";
		cin >> yes;

		if (yes == 'y')
		{
			// o = 19,17,21;
			cout << "Enter number of culumn to change (0) = ";
			cin >> cul;
			cul - 1;

			cout << "Enter number of letter = ";
			cin >> o;
			for (int i = 0; i < ccc; i++)
			{
				arr1[i][cul] = ((arr1[i][cul] - resarr[cul]) % 32);
			}
			int result = resultfunc(l, o);
			resarr[cul] = result;
			for (int i = 0; i < ccc; i++)
			{
				int elem = 0;
				int re = 0;
				elem = arr[i][cul];
				re = (elem + result) % 32;
				arr1[i][cul] = re;
				//cout << (char)(re - 32);
			}
		}
		cout << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < keyl; j++)
			{
				cout << (char)(arr1[i][j] - 32) << "\t| ";
			}
			cout << endl;
		}
	}
	freopen("kkkk.txt", "w", stdout);
	for (int i = 0; i < ccc; i++)
	{
		for (int j = 0; j < keyl; j++)
		{
			cout << (char)(arr1[i][j] - 32) << "\t| ";
		}
		cout << endl;
	}
	fclose(stdout);

	return EXIT_SUCCESS;
}*/