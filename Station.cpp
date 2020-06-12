#include "StationT.h"

bool Symbol(const string& Symbols, const char& ch)
{
	for (int i = 0; i < Symbols.size(); i++)
		if (ch == Symbols[i])
			return true;
	return false;
}
void Station::AddTrain()
{
	Train temp;
	temp.TrainAdd();
	dBase.push_back(temp);
}
void Station::Show()
{
	if (dBase.empty())
		cout << "Load base of supplies !"<<endl;
	for (int i = 0; i < dBase.size(); i++)
		dBase[i].ShowTrain();
}
void Station::SearchNumber()
{
	int n;
	cout << "Enter number Train : "; cin >> n;
	for (int i = 0; i < dBase.size(); i++)
		if (n == dBase[i].GetNumber())
			dBase[i].ShowTrain();
}
void Station::SearchFollowing()
{
	string str, str2;
	cout << "\nEnter destination train : "; cin >> str;
	for (size_t i = 0; i < dBase.size(); i++)
		if (dBase[i].GetFollowing() == str)
			dBase[i].ShowTrain();
}
void Station::SaveBase()
{
	ofstream fout;
	fout.open("out_database.txt");
	for (int i = 0; i < dBase.size(); i++)
		fout << dBase[i];
	fout.close();
}
void Station::TrainLoad()
{
	ifstream fin("out_database.txt");
	if (!fin.is_open())
		cout << "Error, not opened file!" << endl;
	while (true)
	{
		Train temp;
		fin >> temp;
		dBase.push_back(temp);
		if (fin.eof())
			break;
	}
}
ifstream& operator>>(ifstream& fin, Train& train)
{
	string Symbols = "1234567890";
	string str;
	getline(fin, str);
	int num = 0;
	for (int i = 0;i < str.size(); i++)
		if (Symbol(Symbols, str[i]))
		{
			num *= 10;
			num += str[i]-48;
		}
	train.number = num;
	getline(fin, str);
	int pos = str.find(":")+2;
	train.destination.append(str, pos);
	getline(fin, str);
	pos = str.find_last_of(":");
	if (Symbol(Symbols, str[pos-2]) && Symbol(Symbols, str[pos-1]))
		train.time[0][0] = ((str[pos-2] - 48) * 10) + (str[pos-1] - 48);
	else if (Symbol(Symbols, str[pos-1]) && !Symbol(Symbols, str[pos-2]))
		train.time[0][0] = (str[pos-1] - 48);
	if (Symbol(Symbols, str[pos +1]) && Symbol(Symbols, str[pos+2]))
		train.time[0][1] = ((str[pos +1] - 48) * 10) + (str[pos+2] - 48);
	else if (Symbol(Symbols, str[pos+1]) && !Symbol(Symbols, str[pos + 2]))
		train.time[0][1] = (str[pos+1] - 48);
	return fin;
}
ostream& operator<<(ostream& fout, Train& train)
{
	fout <<"¹ :"<< train.number<<endl;
	fout <<"\nFollowing : "<< train.destination;
	fout <<"\nDeparture : "<<train.time[0][0] << ":" << train.time[0][1];
	return fout;
}
