#include "StationT.h"
void Train::TrainAdd()
{
	this->number = SetNumber();
	SetTime();
	this->destination = SetFollowing();
}
void Train::SetTime()
{
	int h, min;
	while (true) {
		cout << "Clock departure time(Hours) : ";
		if (!(cin >> h))
		{
			cout << "Please enter numbers only." << endl;
			cin.clear();
			cin.ignore(50, '\n');
			h = -1;
		}
		if (h >= 0 && h < 24)
			break;
	}
	while (true) {

		cout << "Clock departure time(Minut) : ";
		if (!(cin >> min))
		{
			cout << "Please enter numbers only." << endl;
			cin.clear();
			cin.ignore(50, '\n');
			min = -1;
		}
		if (min >= 0 && min < 60)
			break;
	}
	this->time[0][0] = h;
	this->time[0][1] = min;
}
int Train::SetNumber()
{
	int n;
	while (true)
	{
		cout << "\nEnter number Train : ";
		if (!(cin >> n))
		{
			cout << "Please enter numbers only." << endl;
			cin.clear();
			cin.ignore(50, '\n');
		}
		else break;
	}
	return n;
}
int Train::GetNumber() { return number; }
string Train::SetFollowing()
{
	string str;
	cout << "\nEnter train following : "; cin >> str;
	return str;
}
string Train::GetFollowing() { return destination; }
void Train::ShowTrain()
{
	cout << "Number Train ¹ " << number << endl;
	cout << "Arrival station " << destination << endl;
	if (time[0][1] >= 10)
		cout << "Departure time " << time[0][0] << ":" << time[0][1] << endl << endl;
	else
		cout << "Departure time " << time[0][0] << ":0" << time[0][1] << endl << endl;
}