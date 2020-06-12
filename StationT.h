#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
using namespace std;
class Train
{
	int number;
	string destination;
	int time[1][2];
public:
	friend ostream& operator<<(ostream& fout, Train& train);
	friend ifstream& operator>>(ifstream& fin, Train& train);
	Train() {}
	void TrainAdd();
	void SetTime();
	int SetNumber();
	int GetNumber();
	string SetFollowing();
	string GetFollowing();
	void ShowTrain();
	~Train() {}
};
class Station :private Train
{
	vector<Train> dBase;
public:
	Station() {}
	void AddTrain();
	void Show();
	void SearchNumber();
	void SearchFollowing();
	void SaveBase();
	void TrainLoad();

};
