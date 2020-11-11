#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
int tab[10][10];
struct seat {
	char row;
	int column;
};
void maketable(vector<seat> tb) {
	system("cls");
	for (int i = 0; i < tb.size(); i++) {
		tab[tb[i].row - 97][tb[i].column - 1] = 1;
	}
	for (int j = 0; j < 1; j++) cout << "   ";
	for (int j = 0; j < 9; j++) cout << j + 1 << " ";
	cout << endl;
	for (int j = 0; j < 1; j++) cout << "  ";
	for (int j = 0; j < 9; j++) cout << "--";
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << char(65 + i) << " |";
		for (int j = 0; j < 9; j++) {
			if (tab[i][j]) cout << "x|";
			else cout << " |";
		}
		cout << endl;
		for (int j = 0; j < 1; j++) cout << "  ";
		for (int j = 0; j < 9; j++) cout << "--";
		cout << endl;
	}
}
int main() {
	vector<seat> tb;
	maketable(tb);

	while (1)
	{
		char d;
		char emp[2];
		seat Temp;
		cout << "Do you want to reserve a seat? (y/n) ";
		cin >> d;
		if (d == 'y') {

			cout << "Enter your seat(Example 7e) : ";
			cin >> emp;
			Temp.row = emp[1];
			Temp.column = emp[0] - 48;
			if (!tab[Temp.row - 97][Temp.column - 1]) {
				tb.push_back(Temp);
				maketable(tb);
			}
			else cout << "Error or your seat is reserved." << endl;
		}
		else if (d == 'n') {
			cout << "thank you, please come back again." << endl;
			cout << "------------------------------------" << endl;
		}
		else cout << "Error : invalid value, please try again" << endl;
	}
	return 0;
}
