// SpaceStationGreedyPartition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GreedyProjects.h"
int main()
{
	ResearchPeriod period = ResearchPeriod("SpaceStation.txt");
	cout << period.getResearchStartTime() << endl;
	cout << period.getResearchEndTime() << endl << endl;

	vector<Project> projects = period.getProjects();
	for (auto& i : projects)
		cout << i;

    return 0;
}


vector<int> getTimeLine(string& line) {  //Reads spaceStation.txt and returns the alloted work period in an integer array of size 2;
	vector<int> timeLine;
	int Pos(line.find("\t"));
	string firstNumber = line.substr(0, Pos);
	line = line.substr(Pos + 1);
	string secondNumber(line);
	timeLine.push_back(atoi(firstNumber.c_str()));
	timeLine.push_back(atoi(secondNumber.c_str()));
	return timeLine;
}

Project getProject(string& line) {
	int Pos(line.find("\t"));
	string projectNumber = line.substr(0, Pos);
	line = line.substr(Pos + 1);
	Pos = line.find("\t");
	string startTime = line.substr(0, Pos);
	line = line.substr(Pos + 1);
	string finishTime = line;
	Project project = Project(atoi(projectNumber.c_str()), atoi(startTime.c_str()), atoi(finishTime.c_str()));
	return project;
}

Project::Project(const int & projectNumber, const int & startTime, const int & finishTime): projectNumber(projectNumber), startTime(startTime), finishTime(finishTime){}

int Project::Si() const{return startTime;}

int Project::Fi() const{return finishTime;}

int Project::PN() const{return projectNumber;}

ostream& operator<<(ostream& out, const Project& project) {
	out << "Project Number: " << project.projectNumber << "| Start Time: " << project.startTime << "| Finish Time: " << project.finishTime << endl;
	return out;
}


ResearchPeriod::ResearchPeriod(const string & document):document(document)
{
	string line;
	ifstream myfile(document);
	if (myfile.fail())
		cerr << "File can not be read!" << endl;
	else if (myfile.is_open()) {
		getline(myfile, line);
		vector<int> timeLine = getTimeLine(line);
		reasearchStartTime = timeLine[0];
		researchEndTime = timeLine[1];
		getline(myfile, line);
		numOfProjects = atoi(line.c_str());
		while (getline(myfile, line)) {
			projects.push_back(getProject(line));
		}
		myfile.close();
	}
}

void ResearchPeriod::sortProjects()
{
	
}

vector<Project> ResearchPeriod::getProjects()
{
	return projects;
}

int ResearchPeriod::getResearchStartTime()
{
	return reasearchStartTime;
}

int ResearchPeriod::getResearchEndTime()
{
	return researchEndTime;
}
