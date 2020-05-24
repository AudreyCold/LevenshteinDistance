#include <iostream>
#include <conio.h>
#include "LevDist.h"
#include <clocale>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string source = "pig";
	string target = "tang";
	LevenshteinDistance LevDist;
	int i = 0, j = 0;

	cout << source << " ----> " << target;
	cout << LevDist.Distance(source, target);
	cout << endl;

	while (LevDist.sequence.get_size() != 0)
	{
		string letter = LevDist.sequence.pop();

		cout << endl;
		if (letter == "R")
		{
			cout << "R: '" << source[i] << "' to '" << target[j] <<"'"<< endl;
			i++; j++;
		}
		else
			if (letter == "M")
			{
				cout << "M: '" << source[i] << "' and '" << target[j] << "'" << endl;
				i++; j++;
			}
			else
				if (letter == "D")
				{
					cout << "D: '" << source[i] << "' from source string" << endl;
					i++;
				}
				else
				{
					cout << "I: '" << target[j] << "' in source string" << endl;
					j++;
				}
	}

	_getch();
	return 0;
}