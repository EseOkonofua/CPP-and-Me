//Name : Ese OKonofua  SN:10107285
#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef bnb_13eio_H
#define bnb_13eio_H




class Item {
	int id;
	int value;
	int mass;
	float vm; // Value/Mass
public:

	Item(const int& id, const int& value, const int& mass);
	int getId() const;
	int getValue() const;
 	int getMass() const;
	float getVm() const;
	friend  ostream& operator<<(ostream& out, const Item& item);
	friend bool operator < (const Item& lItem, const Item& rItem);
};


class Solution {
	int upperBound;
	int lowerBound;
	int index;
	vector<Item> solution;
	int mass;
	int capacity;

	int costSoFar; //Cost of things decided not to take;
	int guaranteedFutureCost; // cost of things that individually will not fit in napsack;
	int feasibleFutureCost; // cost of things left after greedy heuristic 
public:
	Solution();
	Solution(const int& index,const int& choice,const int& capacity, const int& mass,const int& costSoFar, const vector<Item>& solutionSoFar, const vector<Item>& items);
	vector<Solution> expandSolution(vector<Item> items);

	int getUpperBound() const;
	int getLowerBound() const;

	int getIndex();
	vector<Item> getSolution();
};


class SolutionMinHeap { //MinHeap implementation
	void moveDown(const int& nodeIndex, vector<Solution>& minHeap);
public:
	SolutionMinHeap();
	void insertSolution(vector<Solution>& minHeap,const Solution& targetSolution);
	Solution getMinSolution(vector<Solution>& minHeap);
};


class Knapsack {
	string name;
	int capacity;
	int itemCount;
	vector<Item> items;

	int initialUpperBound;

	Solution optimalSolution;

	vector<Item> optimalItems;
	int optimalValue;

	int solutionGeneratedCount;

	//Reading file data functions
	vector<int> getCapacityItemCount(string& line);
	Item getItem(string& line);

	//B&B ALgorithm
	void bnbGetOptimalSolution();


public:
	Knapsack(const string& document);
	string getName() const;
	vector<Item> getItems() const;
	int getInitialUpperBound() const;
	
	vector<Item> getOptimalItems() const;
	Solution getOptimalSolution() const;

	int getSolutionGeneratedCount() const;
	int getOptimalValue() const;

};


int greedyHeuristic(const int& mass,const int& capacity,const vector<Item>& items);//Greedy Heuristic





#endif