// SpaceStationGreedyPartition.cpp : Defines the entry point for the console application.
//Name: Ese Okonofua SN: 10107285

#include "stdafx.h" //Visual studio standard ignore
#include "GreedyProjects.h"
int main()
{
	ofstream myfile;
	myfile.open("Output.txt", ios::out);
	if (myfile.fail())
		cerr << "File can't be opened" << endl;
	else if (myfile.is_open()) {
		ResearchPeriod period = ResearchPeriod("SpaceStation.txt");
		vector<Project> projects = period.getProjects();
		vector<Project> optimal = period.getOptimalProjects();
		myfile << "All the projects read from the file:" << endl;
		for (auto& i : projects)
			myfile << i;
		myfile << endl;
		myfile << "The selected optimal projects calculated:" << endl;
		for (auto& i : optimal)
			myfile << i;
		myfile << endl;
		myfile << "Group 1 Projects:" << endl;
		for (auto& i : period.getPartition1())
			myfile << i;
		myfile << endl;
		myfile << "Group 2 Projects:" << endl;
		for (auto& i : period.getPartition2())
			myfile << i;
		myfile.close();
	}
	
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

Project::Project(const int & projectNumber, const int & startTime, const int & finishTime) : projectNumber(projectNumber), startTime(startTime), finishTime(finishTime) {
	projectCost = finishTime - startTime;
}

int Project::Si() const { return startTime; }

int Project::Fi() const { return finishTime; }

int Project::PN() const { return projectNumber; }

int Project::ProjectCost() const
{
	return projectCost;
}

ostream& operator<<(ostream& out, const Project& project) {
	out << "Project Number: " << project.projectNumber << "| Start Time: " << project.startTime << "| Finish Time: " << project.finishTime << "| Project Cost: " << project.projectCost << endl;
	return out;
}


ResearchPeriod::ResearchPeriod(const string & document) :document(document)
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
		projects = sortProjectsFinishTime(projects);
		myfile.close();
	}
	optimalProjects = findOptimal();
	optimalProjects = sortProjectCost(optimalProjects);
	partitionProjects();
}

/*FindOptimal() function: Takes a list of projects and finds the Minimum amount of projects that will keep 
the researchers busy at all time. The projects are sorted by Finish time in descending order. The function first decides
what the last project to be picked is by picking the project with the least start time that has a finish time greater than
or equal to the research end time. From then on it goes backwards selecting projects that have the least start time but have 
a finish time >= the start time of the previous project.
*/
vector<Project> ResearchPeriod::findOptimal()
{
	vector<Project> optimalResults;
	Project selectedProject = projects[0]; //Point to first project
	for (auto& i : projects) { //Pick last project in the list
		if (i.Fi() >= researchEndTime && i.Si() <= selectedProject.Si())
			selectedProject = i;
		else if (i.Fi() < researchEndTime) {
			optimalResults.push_back(selectedProject);
			break;
		}
	}

	for (int i = 0; selectedProject.Si() > reasearchStartTime; i++) { //Iterate through picking values 
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

vector<Project> ResearchPeriod::sortProjectCost(vector<Project>& projects)
{
	if (projects.size() <= 1)
		return projects;
	else {
		vector<Project> projectLeft(projects.begin(), projects.begin() + projects.size() / 2);
		vector<Project> projectRight(projects.begin() + projects.size() / 2, projects.end());
		projectLeft = sortProjectCost(projectLeft);
		projectRight = sortProjectCost(projectRight);

		return mergeProjectCost(projectLeft, projectRight);
	}
}

vector<Project> ResearchPeriod::mergeProjectCost(vector<Project>& leftProject, vector<Project>& rightProject)
{
	vector<Project> result;
	while (leftProject.size() != 0 && rightProject.size() != 0) {
		if (leftProject[0].ProjectCost() <= rightProject[0].ProjectCost()) {
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
/*partitionProjects() function: the purpose of this algorithm is to take the list of optimal projects and find
the split them into a list of 2 while minimizing their difference. The algorithm works by taking the initial list of
optimal projects sorted in ascending order and moving values from the initial list into a new list which acts
as the second partition. The while loops stops when the weight of the new list is greater than the initial list
or if there are no more values that will reduce the difference between the 2.*/
void ResearchPeriod::partitionProjects()
{
	vector<Project> projectList = sortProjectCost(optimalProjects);
	vector<Project> newList; 
	while (projectSum(newList) < projectSum(projectList)) {
		int difference = abs(projectSum(projectList) - projectSum(newList));
		int newDifference = abs(projectSum(projectList) - projectSum(newList));
		auto removeValue = projectList.begin();
		for (auto position = projectList.begin(); position != projectList.end(); ++position) {
			if (abs((projectSum(projectList) - position->ProjectCost()) - (projectSum(newList) + position->ProjectCost())) < difference) {
				difference = abs((projectSum(projectList) - position->ProjectCost()) - (projectSum(newList) + position->ProjectCost()));
				removeValue = position;
			}
		}
		if (difference < newDifference) {
			newList.push_back(*removeValue);
			projectList.erase(removeValue);
		}
		else
			break;
	
	}
	
	partition1 = projectList;
	partition2 = newList;
	

}

int ResearchPeriod::projectSum(vector<Project>& list)
{
	int sum(0);
	for (auto& i : list) {
		sum += i.ProjectCost();
	}
	return sum;
}

vector<Project> ResearchPeriod::sortProjectsFinishTime(vector<Project>& projects)
{
	if (projects.size() <= 1)
		return projects;
	else {
		vector<Project> projectLeft(projects.begin(), projects.begin() + projects.size() / 2);
		vector<Project> projectRight(projects.begin() + projects.size() / 2, projects.end());
		projectLeft = sortProjectsFinishTime(projectLeft);
		projectRight = sortProjectsFinishTime(projectRight);

		return mergeFinishTime(projectLeft, projectRight);
	}
}

vector<Project> ResearchPeriod::mergeFinishTime(vector<Project>& leftProject, vector<Project>& rightProject)
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

vector<Project> ResearchPeriod::getOptimalProjects()
{
	return optimalProjects;
}

vector<Project> ResearchPeriod::getPartition1()
{
	return partition1;
}

vector<Project> ResearchPeriod::getPartition2()
{
	return partition2;
}
