//----------------------------------------------------------------------------------------------------------------------
// CS 2010 Paul Moesher 4/13/18
//-----------------------------------------------------------------------------------------------------------------------


#include <iostream>

#include <fstream>

#include <string>

#include <iomanip>

using namespace std;

// function declaration

int readFile(string salsaName[], int jarsSold[], int size);

void display(string salsaName[], int jarsSold[], int size);

int mostJarsSold(int jarsSold[], int size);

int main() {

	const int size = 15; // max size of array

	string salsaName[size]; // array containing the names of salsa

	int jarsSold[size]; // array containing number of jars sold for each type

	int numTypes = readFile(salsaName, jarsSold, size);

	if (numTypes > 0)

	{

		display(salsaName, jarsSold, numTypes);

		int mostIndex = mostJarsSold(jarsSold, numTypes);

		cout << "\n The company sold " << jarsSold[mostIndex] << " jars of " << salsaName[mostIndex] << " salsa last month." << endl;

	}
	system("pause");
	return 0;

}

// function to read the file and populate values in salsaName and jarsSold and return the number of records in file

int readFile(string salsaName[], int jarsSold[], int size)

{

	ifstream fin("lab12.txt");

	int numRecords = 0;

	if (fin.is_open())

	{

		while (!fin.eof() && numRecords < size)

		{

			fin >> salsaName[numRecords];

			fin >> jarsSold[numRecords];

			numRecords++;

		}

	}
	else

		cout << "\n Unable to open file ";

	fin.close();

	return numRecords;;

}

// function to display the sales of salsa

void display(string salsaName[], int jarsSold[], int size)

{

	int totalJarsSold = 0;

	cout << "\t Ele# \t Salsa type \t Jars sold" << endl;

	for (int i = 0; i<size; i++)

	{

		cout << "\t " << i << setw(12) << salsaName[i] << setw(15) << jarsSold[i] << endl;

		totalJarsSold += jarsSold[i];

	}

	cout << "\n\t Total jars sold : \t" << totalJarsSold << endl;

}

// function to return the index of most jars of salsa sold

int mostJarsSold(int jarsSold[], int size)

{

	int max = 0;

	for (int i = 1; i<size; i++)

	{

		if (jarsSold[i] > jarsSold[max])

			max = i;

	}

	return max;

}