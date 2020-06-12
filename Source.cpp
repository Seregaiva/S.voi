#include "StationT.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Station St;
	int key;
	while (true)
	{
		system("cls");
		cout << "\n1.Add Train"<<endl;
		cout << "2.Show all Train" << endl;
		cout << "3.Search train number" << endl;
		cout << "4.Search train following" << endl;
		cout << "5.Load base of supplies" << endl;
		cout << "6.Save base of supplies" << endl;
		cout << "Other  Exit" << endl;
		cin >> key;
		if (key == 1)St.AddTrain();
		else if (key == 2)St.Show();
		else if (key == 3)St.SearchNumber();
		else if (key == 4)St.SearchFollowing();
		else if (key == 5)St.TrainLoad();
		else if (key == 6)St.SaveBase();
		else break;
		system("pause");
	}
	
}