// SpaceStationGreedyPartition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GreedyProjects.h"
int main()
{
	ResearchPeriod period = ResearchPeriod("SpaceV2.txt");
	vector<Project> projects = period.getProjects();
	vector<Project> optimal = period.optimal();
	for (auto& i : optimal)
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
		projects = sortProjects(projects);
		myfile.close();
	}
}

vector<Project> ResearchPeriod::optimal()
{
	vector<Project> optimalResults;
	Project selectedProject = projects[0]; //Point to first project
	for (auto& i : projects) {
		if (i.Fi() >= researchEndTime && i.Si() <= selectedProject.Si())
			selectedProject = i;
		else if (i.Fi() < researchEndTime) {
			optimalResults.push_back(selectedProject);
			break;
		}	
	}

	for (int i= 0; selectedProject.Si() > reasearchStartTime ; i++) {
		if (projects[i].Si() < selectedProject.Si() && projects[i].Fi() >= optimalResults.back().Si()) 
			selectedProject = projects[i];
		else if (projects[i].Fi() < optimalResults.back().Si()) {
			optimalResults.push_back(selectedProject);
			selectedProject = projects[i];
		}
		else if (projects[i].Si() <= reasearchStartTime) 
			optimalResults.push_back(projects[i]);	
	}
	optimalResults.push_back(selectedProject);
	return optimalResults;
}

vector<Project> ResearchPeriod::sortProjects(vector<Project>& projects)
{
	if (projects.size() <= 1)
		return projects;
	else {
		vector<Project> projectLeft(projects.begin(), projects.begin()+ projects.size() / 2);
		vector<Project> projectRight(projects.begin() + projects.size() / 2, projects.end());
		projectLeft = sortProjects(projectLeft);
		projectRight = sortProjects(projectRight);

		return merge(projectLeft, projectRight);
	}

	

}

vector<Project> ResearchPeriod::merge(vector<Project>& leftProject, vector<Project>& rightProject)
{
	vector<Project> result;
	while (leftProject.size() != 0 && rightProject.size() != 0) {
		if (leftProject[0].Fi() >= rightProject[0].Fi()) {
			result.push_back(leftProject[0]);
			leftProject.erase(leftProject.begin());
		}
		else {
			result.push_back(rightProject[0]);
			rightProject.erase(rightProject.begin());
		}
	}
	while (leftProject.size() != 0) {
		result.push_back(leftProject[0]);
		leftProject.erase(leftProject.begin());
	}
	while (rightProject.size() != 0) {
		result.push_back(rightProject[0]);
		rightProject.erase(rightProject.begin());
	}
	return result;
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
