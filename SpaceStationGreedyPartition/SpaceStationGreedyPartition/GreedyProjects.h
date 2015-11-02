//Name: Ese Okonofua SN: 10107285
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
	int projectCost;
public:
	Project(const int& projectNumber, const int& startTime, const int& finishTime);
	int Si() const;
	int Fi() const; //Getters for private attributes.
	int PN() const;
	int ProjectCost() const;
	friend ostream& operator<<(ostream& out, const Project& project); //What printing a project does
};

class ResearchPeriod { //Object holding research specifications. e.g. # Of Projects,Research critical period, Optimal List of Projects 
	string document;
	vector<Project> projects;//Projects that are read from the inputfile.

	vector<Project> sortProjectsFinishTime(vector<Project>& projects); //Sorts projects based on finish time in descending order
	vector<Project> mergeFinishTime(vector<Project>& leftProject, vector<Project>& rightProject);

	vector<Project> findOptimal(); //Function to find optimal projects to use, Algorithm explained in .cpp file
	vector<Project> optimalProjects;

	vector<Project> sortProjectCost(vector<Project>& projects);
	vector<Project> mergeProjectCost(vector<Project>& leftProject, vector<Project>& rightProject);

	void partitionProjects(); //Function to partition the project objects Algorithm Explained in .Cpp file
	int projectSum(vector<Project>& list); //Finds the sum in a list of projects
	vector<Project> partition1;
	vector<Project> partition2;

	int reasearchStartTime;
	int researchEndTime;
	int numOfProjects;

public:
	ResearchPeriod(const string& document); //Constructor with document holding research specifications	
	int getResearchStartTime();
	int getResearchEndTime();

	//Finds optimal projects to do 
	vector<Project> getProjects();
	vector<Project> getOptimalProjects();

	//Partition Solutions
	vector<Project> getPartition1();
	vector<Project> getPartition2();

};
vector<int> getTimeLine(string& line);
Project getProject(string& line); //Reads SpaceStation.txt and returns a list of project objects.

#endif