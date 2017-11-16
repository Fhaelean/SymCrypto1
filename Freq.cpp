#include "Header.h"
#define SIZE 3000000

void bigrams()
{
	char *textbi = new char[SIZE];
	char cbi;
	int nbi = 0;

	FILE * doc = fopen("text.txt", "r");
	while (fscanf(doc, "%c", &cbi) != EOF)
	{
		if ('à' <= cbi && cbi <= 'ÿ')
		{
			textbi[nbi++] = cbi;
		}
		if ('À' <= cbi && cbi <= 'ß')
		{
			textbi[nbi++] = cbi + 32;
		}
	}
	fclose(doc);
	freopen("bigrams.txt", "w", stdout);
	float h2 = 0;
	float *bi = new float[1024];
	for (int i = 0; i < 1024; ++i)
	{
		bi[i] = 0;
	}
	for (int i = 0; i < nbi - 1; ++i)
	{
		if (textbi[i] != ' ' && textbi[i + 1] != ' ')
		{
			bi[(textbi[i] + 32) * 32 + textbi[i + 1] + 32]++;
		}
	}
	for (int i = 0; i < 1024; ++i)
	{
		bi[i] = bi[i] / (float)(nbi - 1);
	}

	multimap <float, int> big;
	for (int i = 0; i < 1024; ++i)
	{
		big.insert(pair <float, int>(bi[i], i));
	}
	for (auto i = big.begin(); i != big.end(); ++i)
	{
		cout << (char)((i->second / 32) - 32) << (char)((i->second % 32) - 32) << "    " << i->first << endl;
		if (i->first) h2 = h2 - (i->first * log(i->first) / log(2.0));
	}
	cout << "H2 = " << h2 / 2 << endl;
	fclose(stdout);
}

void bigramsSp()
{
	char *text = new char[SIZE];
	char c;
	int n = 0;

	FILE * doc = fopen("text.txt", "r");
	while (fscanf(doc, "%c", &c) != EOF)
	{
		if ('à' <= c && c <= 'ÿ')
		{
			text[n++] = c;
		}
		if ('À' <= c && c <= 'ß')
		{
			text[n++] = c + 32;
		}
		if ((c == ' ' || c == '\t' || c == '\n') && text[n - 1] != ' ')
		{
			text[n++] = ' ';
		}
	}
	fclose(doc);
	freopen("bisp.txt", "w", stdout);
	float h2 = 0;
	int sizeb = 1088;
	float *bi = new float[sizeb];
	for (int i = 0; i < sizeb; ++i)
	{
		bi[i] = 0;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		if (text[i] != ' ' && text[i + 1] != ' ')
		{
			bi[(text[i] + 32) * 32 + text[i + 1] + 32]++;
		}
		else if (text[i] == ' ' && text[i + 1] != ' ')
		{
			bi[(text[i]) * 32 + text[i + 1] + 32]++;
		}
		else if (text[i] != ' ' && text[i + 1] == ' ')
		{
			bi[(text[i] + 32) * 32 + text[i + 1] - 32]++;
		}
	}
	for (int i = 0; i < sizeb; ++i)
	{
		bi[i] = bi[i] / (float)(n - 1);
	}
	multimap <float, int> big;
	for (int i = 0; i < sizeb; ++i)
	{
		big.insert(pair <float, int>(bi[i], i));
	}
	for (auto i = big.begin(); i != big.end(); ++i)
	{
		char ch;
		if ((i->second % 32) == 0)
		{
			ch = ' ';
		}
		else
		{
			ch = ((char)((i->second % 32) - 32));
		}
		cout << (char)((i->second / 32) - 32) << ch << "    " << i->first << endl;
		if (i->first) h2 = h2 - (i->first * log(i->first) / log(2.0));
	}
	cout << "H2 = " << h2 / 2 << endl;
	fclose(stdout);
}

int main()
{
	setlocale(LC_ALL,"Russian");
	char *text = new char[SIZE];
	char c;
	int n = 0;

	FILE * doc = fopen("text.txt", "r");
	while (fscanf(doc, "%c", &c) != EOF)
	{
		if ('à' <= c && c <= 'ÿ')
		{
			text[n++] = c;
		}
		if ('À' <= c && c <= 'ß')
		{
			text[n++] = c + 32;
		}
		if ((c == ' ' || c == '\t' || c == '\n') && text[n - 1] != ' ')
		{
			text[n++] = ' ';
		}
	}
	fclose(doc);

	freopen("monandsp.txt", "w", stdout);
	float h1 = 0;
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
		cout << at -> first << "    " << (1.0 * (at -> second) / n) << endl; 
		h1 = h1 - ((1.0 * (at -> second) / n) * log(1.0 * (at -> second) / n) / log(2.0));
	}
	cout << "H1 = " << h1 << endl;
	fclose(stdout);

	freopen("mon.txt", "w", stdout);
	float h1s = 0;
	int space = 0;
	map <char, int> charss;
	map <char, int>::iterator begins, ats, ends;

	for (unsigned int i = 0; i < n; i++)
	{
		if (text[i] != ' ')
		{
			charss[text[i]]++;
		}
		else space++;
	}
	begins = charss.begin();
	ends = charss.end();
	for (ats = begins; ats != ends; ats++)
	{
		cout << ats -> first << "    " << (1.0 * (ats -> second) / (n - space)) << endl;
		h1s = h1s - ((1.0 * (ats -> second) / (n - space)) * log(1.0 * (ats -> second) / (n - space)) / log(2.0));
	}
	cout << "H1 = " << h1s << endl;
	fclose(stdout);
	bigrams();
	bigramsSp();
	return EXIT_SUCCESS;
}