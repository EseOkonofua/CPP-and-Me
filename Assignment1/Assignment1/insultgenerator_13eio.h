// Ese Okonofua 13eio 10107285 
#pragma once
#include <vector>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <iostream>


#include <list>
using namespace std;
//HeaderGuard
#ifndef insultgenerator_13eio_H
#define insultgenerator_13eio_H


class InsultGenerator { //Insult generator class.
	const string THOU = "Thou"; //Private attributes for Thou and !.
	const string END = "!";
	vector<string> col1,col2,col3;  //Vectors to hold values in each column of the text file.
	vector<string> generateInsults(const int& insultCount) const; //Helper function to generate random insults.
	vector<string> getWords(string& line) const; //Helper function to split words into columns.
public:
	void initialize(); //Initialize column attributes...uses generateInsults helper function.
	string talkToMe(); //Generate 1 random insult.
	vector<string> generate(const int& insultCount) const; //generate a number of insults...uses generateInsults helper function.
	void generateAndSave(const string& filename, const int insultCount); //Generates a number of insults and records it into a text file. Uses generate insults helper function.
};

class FileException { //FileException class for file related errors.
	string message;
public:
	FileException(const string& message);
	string& what();
};

class NumInsultsOutOfBounds { //Generate insults out of bounds for generate related errors.
	string message;
public:
	NumInsultsOutOfBounds(const string& message);
	string& what();
};

#endif