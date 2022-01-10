#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void read_record()
{
	fstream fin;

	// Open an existing file
	fin.open("Applications.csv", ios::in);
	// Read the Data from the file
	// as String Vector
	vector<string> row;
	string line, word, temp;
int count=0;
if(fin.is_open()){
	while (fin >> temp) {

		// read an entire row and
		// store it in a string variable 'line'
		getline(fin, line);

		// used for breaking words
		stringstream s(line);

		// read every column data of a row and
		// store it in a string variable, 'word'
		while (getline(s, word, ',')) {

			// add all the column data
			// of a row to a vector
			row.push_back(word);
		}
			count = 1;
			//cout << " " << row[0] << " : \n";
			cout << "Name: " << row[0] << "\n";
			cout << "Maths: " << row[1] << "\n";
			cout << "Physics: " << row[2] << "\n";
			cout << "Chemistry: " << row[3] << "\n";
			cout << "Biology: " << row[4] << "\n";
	}
	if (count == 0)
		cout << "Record not found\n";
	}else{
		cout<<"File not open";
	}
}
int main(){
	read_record();
}
