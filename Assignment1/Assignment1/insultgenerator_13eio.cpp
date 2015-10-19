// // Ese Okonofua 13eio 10107285 
//
#include "stdafx.h" //Can be removed...Visual studio standard.
#include "insultgenerator_13eio.h"

using namespace std;

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string & message) : message(message) {}
string & NumInsultsOutOfBounds::what() { return message; }

vector<string> InsultGenerator::getWords(string& line) const
{
	vector<string> wordList;
	int Pos(line.find("\t"));
	string firstName(line.substr(0, Pos ));
	line = line.substr(Pos + 1, -1);
	Pos = line.find("\t");
	string secondName(line.substr(0, Pos ));
	line = line.substr(Pos + 1, -1);
	string thirdName(line);
	wordList.push_back(firstName);
	wordList.push_back(secondName);
	wordList.push_back(thirdName);
	return wordList;
}

vector<string> InsultGenerator::generateInsults(const int & insultCount) const
{
	if (insultCount > 10000 || insultCount < 0)
		throw NumInsultsOutOfBounds("Number of insults out of bounds error!(1-10000)");
	srand(unsigned(time(0)));
	vector<string> insultList;
	vector<string> col1Clone(col1);
	vector<string> col2Clone(col2);
	vector<string> col3Clone(col3);
	random_shuffle(col1Clone.begin(), col1Clone.end());
	random_shuffle(col2Clone.begin(), col2Clone.end());
	random_shuffle(col3Clone.begin(), col3Clone.end());
	for (string words1 : col1Clone) {
		if (insultList.size() == insultCount)
			break;
		for (string words2 : col2Clone) {
			if (insultList.size() == insultCount)
				break;
			for (string words3 : col3Clone) {
				if (insultList.size() == insultCount)
					break;
				string insult = THOU + " " + words1 + " " + words2 + " " + words3 + END;
				insultList.push_back(insult);
			}
		}
	}
	sort(insultList.begin(), insultList.end());
	return insultList;
}

void InsultGenerator::initialize()
{
	string line;
	ifstream myfile;
	myfile.open("InsultsSource.txt", ios::in);
	if (myfile.fail()) {
		throw FileException("Error accessing file!");
	}
	else if (myfile.is_open()) {
		while (getline(myfile, line)) {
			vector<string> row = getWords(line);
			col1.push_back(row.at(0));
			col2.push_back(row.at(1));
			col3.push_back(row.at(2));
		}
		myfile.close();
	}
}

string InsultGenerator::talkToMe()
{
	vector<string> insultList = generateInsults(1);
	string insult = insultList.at(0);
	return insult;
}

vector<string> InsultGenerator::generate(const int& insultCount) const
{
	vector<string> insultList = generateInsults(insultCount);
	return insultList;
}

void InsultGenerator::generateAndSave(const string& filename, const int insultCount)
{
	vector<string> insultList = generateInsults(insultCount);
	ofstream myfile;
	myfile.open(filename, ios::out);
	if (myfile.fail()) {
		throw FileException("Error accessing file!");
	}
	else if (myfile.is_open()) {
		for (string insult : insultList)
			myfile << insult << endl;
		myfile.close();
	}
}

int main()
{
	InsultGenerator ig;
	vector<string> insults;
	double start, finish;

	// The initialize() method should load all the source phrases from the InsultsSource.txt file into the attributes.
	// If the file cannot be read, the method should throw an exception.
	try {
		ig.initialize();
	}
	catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}

	// talkToMe() returns a single insult, generated at random.
	cout << "A single insult:" << endl;
	cout << ig.talkToMe() << endl;

	// Check number to generate limits.
	try {
		insults = ig.generate(-100);
	}
	catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	try {
		insults = ig.generate(40000);
	}
	catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}

	// generate() generates the requested number of unique insults.
	cout << "\n100 insults, all different:" << endl;
	insults = ig.generate(100);
	if (insults.size() > 0)
		for (int i = 0; i < 100; i++)
			cout << insults[i] << endl;
	else
		cerr << "Insults could not be generated!" << endl;

	// generateAndSave() generates the requested number of unique insults and saves them to the filename
	// supplied.  If the file cannot be written, the method should throw an exception.  Note that the
	// insults in the file should be in alphabetical order!
	// Check the number to generate limits first:
	try {
		ig.generateAndSave("Nothing.txt", 40000);
	}
	catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	cout << "\nSaving 1000 unique insults to a file...";
	try {
		ig.generateAndSave("SavedInsults.txt", 1000);
	}
	catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}
	cout << "done." << endl;

	// Test ability to generate the maximum number of insults and how long it takes.
	try {
		start = clock();
		insults = ig.generate(10000);
		finish = clock();

	}
	catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	cout << "\n" << insults.size() << " insults generated." << endl;
	cout << (finish - start) << " msec to complete." << endl;

	return 0;
}

