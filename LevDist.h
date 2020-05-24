#include <iostream>
#include "stack.h"
#include <string>
#include <exception>
using namespace std;

class LevenshteinDistance
{
private:
	void Prescription(string** matrix_prescription, int size_s, int size_t)
	{
		int i = size_s;
		int j = size_t;

		while ((i != 0) || (j != 0))
		{
			string current = matrix_prescription[i][j];
			sequence.push(current);//inserting an element in the stack

			if ((current == "R") || (current == "M"))
			{
				i--;
				j--;
			}
			else
				if (current == "D")
					i--;
				else
					j--;
		}
	}
	size_t size_word(string word)
	{
		basic_string <char>::size_type length;

		length = word.length();
		return length;
	};

public:
	Stack<string>sequence;
	size_t Distance(string source, string target)
	{
		int size_s = size_word(source);
		int size_t = size_word(target);

		if ((size_s != 0) && (size_t != 0))
		{
			if ((size_s == 1) && (size_t == 1))
			{
				if (source[0] == target[0])
				{
					sequence.push("M");
					return 0;
				}
				else
				{
					sequence.push("R");
					return 1;
				}
			}
			else
			{
				int** matrix_distance = new int*[size_s + 1];
				string** matrix_prescription = new string*[size_s + 1];

				for (int i = 0; i <= size_s; i++)
				{
					matrix_distance[i] = new int[size_t + 1];
					matrix_prescription[i] = new string[size_t + 1];
				}

				matrix_distance[0][0] = 0;
				matrix_prescription[0][0] = "0";

				for (int j = 1; j <= size_t; j++)
				{
					matrix_distance[0][j] = j;
					matrix_prescription[0][j] = "I";
				}
				for (int i = 1; i <= size_s; i++)
				{
					matrix_distance[i][0] = i;
					matrix_prescription[i][0] = "D";

					for (int j = 1; j <= size_t; j++)
					{
						if (source[i - 1] != target[j - 1])
						{
							int min = matrix_distance[i - 1][j];//left element
							matrix_prescription[i][j] = "D";

							if (min > matrix_distance[i][j - 1])
							{
								min = matrix_distance[i][j - 1];//high element
								matrix_prescription[i][j] = "I";
							}
							else
								if (min > matrix_distance[i - 1][j - 1])//diagonal element
								{
									min = matrix_distance[i - 1][j - 1];
									matrix_prescription[i][j] = "R";
								}

							matrix_distance[i][j] = min + 1;
						}
						else
						{
							matrix_distance[i][j] = matrix_distance[i - 1][j - 1];
							matrix_prescription[i][j] = "M";
						}
					}
				}

				Prescription(matrix_prescription, size_s, size_t);

				cout << endl;
				for (int j = 0; j <= size_t; j++)
				{
					for (int i = 0; i <= size_s; i++)
					{
						cout << matrix_prescription[i][j];
						if (i == size_s)
							cout << endl;
					}
				}

				cout << endl << "Distance Of Lowenstein: ";
				return matrix_distance[size_s][size_t];
			}
		}
		else
			if ((size_s == 0) && (size_t == 0))
				throw invalid_argument("Error! No word entered");
			else
				if (size_s == 0)
				{
					for (int i = 0; i < size_t; i++)
						sequence.push("I");
					return size_t;
				}
				else
				{
					for (int i = 0; i < size_s; i++)
						sequence.push("D");
					return size_s;
				}
	}
};
