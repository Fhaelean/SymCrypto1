/*#include "Header.h"
#define SIZE 5000000

string RUSSIAN_ALPHABET = "��������������������������������"; // 32 �������
vector<pair<string, double>> RUSSIAN_LETTERS_FREQUENCIES = 
{
{"�", 0.10983},
{"�", 0.08483},
{"�", 0.07998},
{"�", 0.07367},
{"�", 0.067},
{"�", 0.06318},
{"�", 0.05473},
{"�", 0.04746},
{"�", 0.04533},
{"�", 0.04343},
{"�", 0.03486},
{"�", 0.03203},
{"�", 0.02977},
{"�", 0.02804},
{"�", 0.02615},
{"�", 0.02001},
{"�", 0.01898},
{"�", 0.01735},
{"�", 0.01687},
{"�", 0.01641},
{"�", 0.01592},
{"�", 0.0145},
{"�", 0.01208},
{"�", 0.00966},
{"�", 0.0094},
{"�", 0.00718},
{"�", 0.00639},
{"�", 0.00486},
{"�", 0.00361},
{"�", 0.00331},
{"�", 0.00267},
{"�", 0.00037}};

int matchStatistic(string text, int r) 
{
	int statistic = 0;
	int textLength = text.length();

	for (int i = 0; i < textLength - r; i++)
	if (text[i] == text[i + r])
	statistic++;

	return statistic;
}

vector<string> fragments(string text, int parts) 
{
	vector<string> fragms;
	//    string buffer = "";

	for (int i = 0; i < parts; i++)
	fragms.push_back(string());

	for (int i = 0, textLength = text.length(); i < textLength; i++) 
	{
		fragms[i % parts] += text[i];
	}

	return fragms;
}

map<string, double> monogramsFrequency(string alphabet, string text) 
{
	map<string, double> map;
	int textLength = text.length();

	for (char c : alphabet)
	map[string(1, c)] = 0.0;

	for (char c : text)
	map[string(1, c)] += 1;

	for (char c : alphabet)
	map[string(1, c)] /= (double) textLength;

	return map;
}

vector<int> potentialKeys(string alphabet, string cipherText) 
{
	vector<int> potentialKeys;
	map<string, double> map;
	map = monogramsFrequency(alphabet, cipherText);
	vector<pair<double, string>> lettersFrequencies;
	for (pair<string, double> p : map)
	lettersFrequencies.push_back(make_pair(p.second, p.first));
	sort(lettersFrequencies.rbegin(), lettersFrequencies.rend());
	char mostFrequentlyLetter = lettersFrequencies[0].second[0];

	for (pair<string, double> pair : RUSSIAN_LETTERS_FREQUENCIES)
	potentialKeys.push_back((mostFrequentlyLetter - pair.first[0] + alphabet.length()) % alphabet.length());

	return potentialKeys;
}

string decrypt(string alphabet, string cipherText, string key) 
{
	string plainText = "";
	int alphabetLength = alphabet.length();
	int textLength = cipherText.length();
	char firstLetter = alphabet[0];

	for (int i = 0, j = 0; i < textLength; i++) 
	{
		char c = cipherText[i];
		plainText += (char) ((c - key[j] + alphabetLength) % alphabetLength + firstLetter);
		j = ++j % key.length();
	}

	return plainText;
}

string decrypt(string alphabet, string cipherText) 
{
	string plainText = "";
	transform(cipherText.begin(), cipherText.end(), cipherText.begin(), ::tolower);
	int keyLength = 1;

	cout << "���������� ���������� �������� ��� ������ ��������:" << endl;
	while (true) 
	{
		cout << setw(2) << keyLength << ". " << matchStatistic(cipherText, keyLength) << endl;
		if (((double)matchStatistic(cipherText, keyLength) / matchStatistic(cipherText, keyLength - 1)) > 1.5)
		break;
		keyLength++;
	}
	cout << "����� ����� = " << keyLength << endl;

	vector<vector<int>> potentialKeysArray;
	vector<int> potentialKeysIndices;
	vector<string> fragms;
	fragms = fragments(cipherText, keyLength);
	string key = "";

	for (int j = 0; j < keyLength; j++)
	{
		potentialKeysIndices.push_back(0);
		potentialKeysArray.push_back(potentialKeys(alphabet, fragms[j]));
		key.push_back(alphabet[potentialKeysArray[j][0]]);
	}

	//    for (auto p1 : potentialKeysArray) {
	//        for (auto p2 : p1)
	//            cout << alphabet[p2] << " ";
	//        cout << endl;
	//    }

	while (true) 
	{
		plainText = decrypt(alphabet, cipherText, key);
		cout << endl;
		cout << "����:  " << key << endl;
		cout << "�������������� �����: " << plainText.substr(0, 50) << endl;
		int l = cipherText.length();
		cout << "�������� ����� � �����?" << endl;
		cout << "�����: ";
		string answer;
		cin >> answer;

		if (answer != "yes")
		{
			freopen("out1.txt", "w", stdout);
			cout << "�������������� �����: " << plainText.substr(0, l) << endl;
			fclose(stdout);
			break;
		}
		

		cout << "������� ������ �����, ����� �������� � (���������� � ����): ";
		int index;
		cin >> index;
		potentialKeysIndices[index] += 1;
		key.replace(index, 1, 1, alphabet[potentialKeysArray[index][potentialKeysIndices[index]]]);
	}
		return plainText;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	ifstream wif("in.txt");
	string cipherText;
	getline(wif, cipherText);
	decrypt(RUSSIAN_ALPHABET, cipherText);
	return 0;
}*/