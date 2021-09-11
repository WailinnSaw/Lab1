#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Item
{
	string Id;
	string Name;
	string Quantity;
	string Price;
};
bool isValid(ofstream& outFile,Item items[]);
void getData(ifstream& inFile, ofstream& outFile, Item items[], Item errorItems[], int& itemCount);
void printItems(Item items[]);



const int maxItems = 3;

int main()
{
	Item testGoodItem[maxItems];
	Item testBadItem[maxItems];

	int itemCount = 0;
	//read data from txt file.
	ifstream myTestFile;
	ofstream errorTestFile;

	getData(myTestFile,errorTestFile, testGoodItem, testBadItem ,itemCount);
	printItems(testGoodItem);


	return 0;
}

void getData(ifstream& inFile, ofstream& outFile,Item items[], Item errorItems[], int& itemCount)
{

	inFile.open("TestFile.txt");
	if (!inFile)
	{
		cout << "Error can not open file" << endl;
	}
	else
	{

		while (itemCount < maxItems && !inFile.eof())
		{
			/*getline(inFile,testItem.Id,' ');
			getline(inFile, items[itemCount].Name, ' ');
			getline(inFile, items[itemCount].Quantity, ' ');
			getline(inFile, items[itemCount].Price);	*/

			if (isValid(outFile, errorItems))
			{
				inFile >> items[itemCount].Id;
				inFile >> items[itemCount].Name;
				inFile >> items[itemCount].Quantity;
				inFile >> items[itemCount].Price;
			}

			itemCount++;
		}
		inFile.close();
	}
}

void printItems(Item items[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << items[i].Id << ' '
			<< items[i].Name << ' '
			<< items[i].Quantity << ' '
			<< items[i].Price << endl;
	}
}
bool isValid(ofstream& outFile, Item items[])
{
	outFile.open("Errors.txt",ios::app);
	if (!outFile)
	{
		cout << "Error opening/creating file" << endl;
		return true;
	}
	outFile << "This will show errors" << endl;
	outFile.close();
	return true;
}