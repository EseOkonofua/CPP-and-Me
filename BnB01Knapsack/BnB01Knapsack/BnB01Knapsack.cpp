// BnB01Knapsack.cpp : Defines the entry point for the console application.
//Name: Ese OKonofua   SN: 10107285

#include "BnB01Knapsack.h"
#include <fstream>
#include <iostream>


int main()
{
	Knapsack testPack = Knapsack("DataSet/B+B 2015 Data 20151124 1226  Size 30.txt");

	cout << testPack.getName() << endl;
	cout << "Optimal Value: " << testPack.getOptimalValue() << endl;
	cout << "Optimal Value Identifiers: ";
	for (auto& i : testPack.getOptimalItems())
		cout << i.getId() << ", ";
	cout << endl;
	cout << "Partial solutions generated: " << testPack.getSolutionGeneratedCount() << endl << endl;

	return 0;
}

Item::Item(const int & id, const int & value, const int & mass) : id(id), value(value), mass(mass)
{
	vm = (float)value / (float)mass;
}

int Item::getId() const
{
	return id;
}

int Item::getValue() const
{
	return value;
}

int Item::getMass() const
{
	return mass;
}

float Item::getVm() const
{
	return vm;
}

ostream& operator<<(ostream& out, const Item& item) {
	out << "Item ID: " << item.getId() << "\tItem Value: " << item.getValue() << "\t Item mass: " << item.getMass() << "\t Item V/M: " << item.getVm() << endl;
	return out;
}

bool operator<(const Item& lItem, const Item& rItem) {
	if (lItem.getVm() < rItem.getVm())
		return true;
	else
		return false;
}

Solution::Solution()
{
}

/*
	Solution 1 With using Weaker LowerBound Function and Weaker UpperBound Function
	Cost so far = Cost of things we have decided not to take
	Guaranteed future cost = Cost of things that individually will not fit in knapsack
	Feasible future cost = Cost of things left out after running a greedy heuristic on the remaining objects.

	LowerBound = Cost so far + Guaranteed future cost
	UpperBound = Cost so far + Feasible future cost
*/

Solution::Solution(const int & index, const int & choice, const int & capacity, const int& mass, const int& costSoFar, const vector<Item>& solutionSoFar, const vector<Item>& items) :index(index), capacity(capacity), costSoFar(costSoFar), mass(mass)
{
	if (choice == 0) { //Don't take the item 
		this->costSoFar += items[index].getValue();

		this->mass += 0;

		int GFC = 0;
		for (int i = index + 1; i < items.size(); i++) {
			if ((items[i].getMass() + this->mass) > capacity)
				GFC += items[i].getValue();
		}
		guaranteedFutureCost = GFC;

		vector<Item> remainingItems(items.begin() + 1, items.end());
		int remainingItemTotalValue(0);
		for (auto& i : remainingItems)
			remainingItemTotalValue += i.getValue();
		int greedyValue = greedyHeuristic(this->mass, capacity, remainingItems);
		feasibleFutureCost = remainingItemTotalValue - greedyValue;

		upperBound = this->costSoFar + feasibleFutureCost;
		lowerBound = this->costSoFar + guaranteedFutureCost;

		solution = solutionSoFar;
	}
	else if (choice == 1) { //Take the item
		this->costSoFar += 0;

		this->mass += items[index].getMass();

		int GFC = 0;
		for (int i = index + 1; i < items.size(); i++) {
			if ((items[i].getMass() + this->mass) > capacity)
				GFC += items[i].getValue();
		}
		guaranteedFutureCost = GFC;

		vector<Item> remainingItems(items.begin() + 1, items.end());
		int remainingItemTotalValue(0);

		for (auto& i : remainingItems)
			remainingItemTotalValue += i.getValue();


		int greedyValue = greedyHeuristic(this->mass, capacity, remainingItems);
		feasibleFutureCost = remainingItemTotalValue - greedyValue;

		upperBound = costSoFar + feasibleFutureCost;
		lowerBound = costSoFar + guaranteedFutureCost;

		solution = solutionSoFar;
		solution.push_back(items[index]);
	}
}



/*
Solution 2 With using Stronger LowerBound Function and "Different" UpperBound Function
Cost so far = Cost of things we have decided not to take
Guaranteed future cost = Eliminate all objects that won't fit, then put remaining objects in groups that cannot all go in.
Also improving on algorithm by expanding objects with more solutions first.

Feasible future cost = Cost of things left out after running a greedy heuristic on the remaining objects.

LowerBound = Cost so far + Guaranteed future cost
UpperBound = Cost so far + Feasible future cost

!!!!!!COULD NOT FULLY GET THIS IMPLEMENTATION TO WORK NOT ENOUGH TIME !!!!!!!!


Solution::Solution(const int & index, const int & choice, const int & capacity, const int& mass, const int& costSoFar, const vector<Item>& solutionSoFar, const vector<Item>& items) :index(index), capacity(capacity), costSoFar(costSoFar), mass(mass)
{
	if (choice == 0) { //Don't take the item
		this->costSoFar += items[index].getValue();

		this->mass += 0;

		int GFC = 0;
		vector<int> indices;
		vector<Item> tempItems(items.begin() + 1,items.end());
		for (int i = index + 1; i < items.size(); i++) {
			if ((items[i].getMass() + this->mass) > capacity) {
				GFC += items[i].getValue();
				indices.push_back(i);
			}
		}
		int shiftCompensate(0);
		for(auto& i : indices) {
			tempItems.erase(tempItems.begin() + (i - shiftCompensate));
			shiftCompensate = 1;
		}

		int masses(0);
		int minValue = INT32_MAX;
		for (auto& i : tempItems) {
			masses += i.getMass();
			if (minValue > i.getValue())
				minValue = i.getValue();
			if (((this->mass) + masses) > capacity) {
				GFC += minValue;
				masses = 0;
				minValue = INT32_MAX;
			}
		}


		guaranteedFutureCost = GFC;

		vector<Item> remainingItems(items.begin() + 1, items.end());
		int remainingItemTotalValue(0);
		for (auto& i : remainingItems)
			remainingItemTotalValue += i.getValue();
		int greedyValue = greedyHeuristic(this->mass, capacity, remainingItems);
		feasibleFutureCost = remainingItemTotalValue - greedyValue;

		upperBound = this->costSoFar + feasibleFutureCost;
		lowerBound = this->costSoFar + guaranteedFutureCost;

		solution = solutionSoFar;
	}
	else if (choice == 1) { //Take the item
		this->costSoFar += 0;

		this->mass += items[index].getMass();

		int GFC = 0;
		for (int i = index + 1; i < items.size(); i++) {
			if ((items[i].getMass() + this->mass) > capacity)
				GFC += items[i].getValue();
		}
		guaranteedFutureCost = GFC;

		vector<Item> remainingItems(items.begin() + 1, items.end());
		int remainingItemTotalValue(0);

		for (auto& i : remainingItems)
			remainingItemTotalValue += i.getValue();


		int greedyValue = greedyHeuristic(this->mass, capacity, remainingItems);
		feasibleFutureCost = remainingItemTotalValue - greedyValue;

		upperBound = costSoFar + feasibleFutureCost;
		lowerBound = costSoFar + guaranteedFutureCost;

		solution = solutionSoFar;
		solution.push_back(items[index]);
	}
}
*/

vector<Solution> Solution::expandSolution(vector<Item> items)
{
	vector<Solution> returnedSolution;

	Solution solution1 = Solution(this->index + 1, 1, this->capacity, this->mass, this->costSoFar, this->solution, items);
	Solution solution0 = Solution(this->index + 1, 0, this->capacity, this->mass, this->costSoFar, this->solution, items);

	if (solution0.mass <= capacity)
		returnedSolution.push_back(solution0);
	if (solution1.mass <= capacity)
		returnedSolution.push_back(solution1);

	return returnedSolution;
}

int Solution::getUpperBound() const
{
	return upperBound;
}

int Solution::getLowerBound() const
{
	return lowerBound;
}

int Solution::getIndex()
{
	return index;
}

vector<Item> Solution::getSolution()
{
	return solution;
}

SolutionMinHeap::SolutionMinHeap()
{
}

void SolutionMinHeap::insertSolution(vector<Solution>& minHeap, const Solution & targetSolution)
{
	int heapSize = minHeap.size();
	minHeap.push_back(targetSolution);
	int position = heapSize;
	if (heapSize > 1) { //check if not inserting into head
		while (minHeap[position].getLowerBound() <= minHeap[position / 2].getLowerBound() && position != 1) {

			if (minHeap[position].getLowerBound() == minHeap[position / 2].getLowerBound()) { //Now accounting for index
				if (minHeap[position].getIndex() > minHeap[position / 2].getIndex()) {
					Solution lastSolution = minHeap[position];
					Solution upperSolution = minHeap[position / 2];

					minHeap[position / 2] = lastSolution;
					minHeap[position] = upperSolution;

					position = position / 2;
					break;
				}
				break;
			}
			else {
				Solution lastSolution = minHeap[position];
				Solution upperSolution = minHeap[position / 2];

				minHeap[position / 2] = lastSolution;
				minHeap[position] = upperSolution;

				position = position / 2;
			}

		}

	}

}

Solution SolutionMinHeap::getMinSolution(vector<Solution>& minHeap)
{
	Solution minSolution = minHeap[1];

	Solution minHeapBack = minHeap[minHeap.size() - 1];

	minHeap[1] = minHeapBack;
	minHeap.pop_back();

	if (minHeap.size() > 2)
		moveDown(1, minHeap);
	return minSolution;
}

void SolutionMinHeap::moveDown(const int & nodeIndex, vector<Solution>& minHeap)
{
	int leftChildIndex = nodeIndex * 2;
	int rightChildIndex = nodeIndex * 2 + 1;
	int minIndex;

	if (rightChildIndex >= minHeap.size()) {
		if (leftChildIndex >= minHeap.size())
			return;
		else
			minIndex = leftChildIndex;

	}
	else {
		if (minHeap[leftChildIndex].getLowerBound() <= minHeap[rightChildIndex].getLowerBound())
			minIndex = leftChildIndex;
		else
			minIndex = rightChildIndex;
	}
	if (minHeap[nodeIndex].getLowerBound() > minHeap[minIndex].getLowerBound()) {
		Solution temp = minHeap[minIndex];
		minHeap[minIndex] = minHeap[nodeIndex];
		minHeap[nodeIndex] = temp;
		moveDown(minIndex, minHeap);
	}
	else if (minHeap[nodeIndex].getLowerBound() == minHeap[minIndex].getLowerBound()) {
		if (minHeap[nodeIndex].getIndex() < minHeap[minIndex].getIndex()) {
			Solution temp = minHeap[minIndex];
			minHeap[minIndex] = minHeap[nodeIndex];
			minHeap[nodeIndex] = temp;
			moveDown(minIndex, minHeap);
		}
	}
}


Knapsack::Knapsack(const string & document)
{
	string line;
	ifstream myFile(document);
	if (myFile.fail())
		cerr << "File not read!" << endl;
	else if (myFile.is_open()) {
		getline(myFile, line);
		name = line;

		getline(myFile, line);
		vector<int> array = getCapacityItemCount(line);

		capacity = array[0];
		itemCount = array[1];


		while (getline(myFile, line)) {
			items.push_back(getItem(line));
		}
		myFile.close();

	}
	sort(items.rbegin(), items.rend()); //sort in descending order :D
	int totalValue(0);
	for (auto& i : items) {
		totalValue += i.getValue();
	}
	initialUpperBound = totalValue - greedyHeuristic(0, capacity, items);

	bnbGetOptimalSolution();

	for (auto& i : optimalItems)
		optimalValue += i.getValue();
}


vector<int> Knapsack::getCapacityItemCount(string & line)
{
	vector<int> array;
	int Pos(line.find("\t"));
	string capacity = line.substr(0, Pos);
	line = line.substr(Pos + 1);

	string itemCount = line;

	array.push_back(atoi(capacity.c_str()));
	array.push_back(atoi(itemCount.c_str()));

	return array;

	return vector<int>();
}

Item Knapsack::getItem(string & line)
{
	int pos(line.find("\t"));
	int id = atoi(line.substr(0, pos).c_str());

	line = line.substr(pos + 1);

	pos = line.find("\t");
	int value = atoi(line.substr(0, pos).c_str());

	line = line.substr(pos + 1);
	int mass = atoi(line.c_str());


	return Item(id, value, mass);
}

void Knapsack::bnbGetOptimalSolution()
{
	int upperBound = initialUpperBound;
	vector<Item> solutionSoFar;//Empty Vector

	Solution solution0 = Solution(0, 0, this->capacity, 0, 0, solutionSoFar, this->items);
	Solution solution1 = Solution(0, 1, this->capacity, 0, 0, solutionSoFar, this->items);

	Solution placeHolderSolution;
	vector<Solution> minHeap;
	minHeap.push_back(placeHolderSolution);

	SolutionMinHeap heaper = SolutionMinHeap();

	heaper.insertSolution(minHeap, solution0);
	heaper.insertSolution(minHeap, solution1);
	solutionGeneratedCount = 2;
	while (true) {
		Solution minSolution = heaper.getMinSolution(minHeap);
		if (minSolution.getIndex() == (itemCount - 1)) {
			optimalSolution = minSolution;
			optimalItems = minSolution.getSolution();

			break;
		}
		else {
			vector<Solution> expandedSolutions = minSolution.expandSolution(this->items);
			solutionGeneratedCount += 2;
			for (auto& i : expandedSolutions) {
				if (i.getLowerBound() <= upperBound)
					heaper.insertSolution(minHeap, i);
				if (i.getUpperBound() < upperBound)
					upperBound = i.getUpperBound();
			}

		}
	}

}//ERROR WAS VECTOR OUT OF RANGE



string Knapsack::getName() const
{
	return name;
}

vector<Item> Knapsack::getItems() const
{
	return items;
}

int Knapsack::getInitialUpperBound() const
{
	return initialUpperBound;
}

vector<Item> Knapsack::getOptimalItems() const
{
	return optimalItems;
}

Solution Knapsack::getOptimalSolution() const
{
	return optimalSolution;
}

int Knapsack::getSolutionGeneratedCount() const
{
	return solutionGeneratedCount;
}

int Knapsack::getOptimalValue() const
{
	return optimalValue;
}


int greedyHeuristic(const int& mass, const int& capacity, const vector<Item>& items) {

	int upperBound(0);
	int ms(mass);
	for (auto& i : items) {
		if (ms + i.getMass() <= capacity) {
			upperBound += i.getValue();
			ms += i.getMass();
		}

	}
	return upperBound;
}


