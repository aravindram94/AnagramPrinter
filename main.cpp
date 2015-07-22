#include <iostream>
#include <fstream>
#include<map>
#include<string>

using namespace std;


unsigned long long int hashCode(string input)
{
    std::map<char,int> CHAR_TO_PRIME;

    CHAR_TO_PRIME['A'] = 2;
    CHAR_TO_PRIME['B'] = 3;
    CHAR_TO_PRIME['C'] = 5;
    CHAR_TO_PRIME['D'] = 7;
    CHAR_TO_PRIME['E'] = 11;
    CHAR_TO_PRIME['F'] = 13;
    CHAR_TO_PRIME['G'] = 17;
    CHAR_TO_PRIME['H'] = 19;
    CHAR_TO_PRIME['I'] = 23;
    CHAR_TO_PRIME['J'] = 29;
    CHAR_TO_PRIME['K'] = 31;
    CHAR_TO_PRIME['L'] = 37;
    CHAR_TO_PRIME['M'] = 41;
    CHAR_TO_PRIME['N'] = 43;
    CHAR_TO_PRIME['O'] = 47;
    CHAR_TO_PRIME['P'] = 53;
    CHAR_TO_PRIME['Q'] = 59;
    CHAR_TO_PRIME['R'] = 61;
    CHAR_TO_PRIME['S'] = 67;
    CHAR_TO_PRIME['T'] = 71;
    CHAR_TO_PRIME['U'] = 73;
    CHAR_TO_PRIME['V'] = 79;
    CHAR_TO_PRIME['W'] = 83;
    CHAR_TO_PRIME['X'] = 89;
    CHAR_TO_PRIME['Y'] = 97;
    CHAR_TO_PRIME['Z'] = 101;

    //cout << "In" << " " << input.length() << endl;
    unsigned long long hashcode  = 1;
    int i = 0 ;
    for(;i<input.length();i++)
    {
        hashcode *= CHAR_TO_PRIME[input[i]];
    }
    cout << input << " " << hashcode << endl;
    return hashcode;
}


map<unsigned long long int, string> createHashMap(string fileName)
{
	ifstream wordFile("sowpods.txt");
	string line;
	int hashVal;
	map<unsigned long long int, string> hashCodeMap;
	while (wordFile >> line)
	{
	    //cout << line << endl;
		hashVal = hashCode(line);
		if (hashCodeMap.find(hashVal) == hashCodeMap.end())
		{
			hashCodeMap.insert(std::pair<unsigned long long int, string>(hashVal, line));
		}
		else
		{
		    string appendedVal;
			appendedVal = hashCodeMap[hashVal] + " " + line;
			//cout << appendedVal << endl;
			hashCodeMap[hashVal] = appendedVal;
		}

	}

    return hashCodeMap;
}

void printHashMap(map<unsigned long long int, string> hCMap)
{
	map<unsigned long long int, string>::iterator it;

	for (it = hCMap.begin(); it != hCMap.end(); it++)
	{
		cout << it -> first << " : " << it -> second << endl;
	}
}

int main()
{
    //std::map<int, string> MAP = createHashMap("sowpods.txt");
    printHashMap(createHashMap("sowpods.txt"));
    return 0;
}
