#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#ifndef greedy_13eio_H
#define greedy_13eio_H //Header guard

class Project { //Project Object to hold start time, end time and project # attributes.;
	int startTime;
	int finishTime; //Attributes of a project.
	int projectNumber;
public:
	Project(const int& projectNumber, const int& startTime, const int& finishTime);
	int Si() const;
	int Fi() const; //Getters for private attributes.
	int PN() const;
	friend ostream& operator<<(ostream& out, const Project& project); //What printing a project does
};

class ResearchPeriod { //Object holding research specifications. e.g. # Of Projects,Research critical period, Optimal List of Projects 
	string document;
	vector<Project> projects;
	vector<Project> optimalProjects;
	int reasearchStartTime;
	int researchEndTime;
	int numOfProjects;
public:
	ResearchPeriod(const string& document); //Constructor with document holding research specifications
	void sortProjects(); //Sorts projects based on finish time
	vector<Project> optimal(); //Finds optimal projects to do 
	vector<Project> getProjects();
	int getResearchStartTime();
	int getResearchEndTime();

};
vector<int> getTimeLine(string& line);
Project getProject(string& line); //Reads SpaceStation.txt and returns a list of project objects.

#endif