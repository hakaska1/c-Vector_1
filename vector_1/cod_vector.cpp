#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	//	setlocale(CL_ALL," ");
	srand(time(NULL));
	int x = 11;
	int y = 11;
	vector <vector <int>> Vec(x, vector<int>(y));

	int sum_global = 0;
	int sum_up = 0;
	int sum_down = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			Vec[i][j] = -50 + rand() % +101;
			if (i == j) {
				sum_global += Vec[i][j];
			}
			else if (i < j) {
				sum_up += Vec[i][j];
			}
			else if (i > j) {
				sum_down += Vec[i][j];
			}
			cout << Vec[i][j] << " ";
		}
		cout << endl;
	}

	cout << "===============================" << endl;
	cout << "sum_global: " << sum_global << endl;
	cout << "sum_up: " << sum_up << endl;
	cout << "sum_down: " << sum_down << endl;
	cout << "===============================" << endl;

	if (sum_global > sum_up + sum_down) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (sum_up % 2 == 0 && sum_down % 2 == 0) {
					if (i != j) {
						Vec[i][j] = 0;
					}
				}
				else if (sum_up % 2 == 0) {
					if (i < j) {
						Vec[i][j] = 0;
					}
				}
				else if (sum_down % 2 == 0) {
					if (i > j) {
						Vec[i][j] = 0;
					}
				}
			}
		}
	}

	if (sum_global < sum_up + sum_down) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (sum_up % 2 == 1 && sum_down % 2 == 1) {
					if (i != j) {
						Vec[i][j] = 0;
					}
				}
				else if (sum_up % 2 == 1) {
					if (i < j) {
						Vec[i][j] = 0;
					}
				}
				else if (sum_down % 2 == 1) {
					if (i > j) {
						Vec[i][j] = 0;
					}
				}
			}
		}
	}
	cout << "===============================" << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << Vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << "===============================" << endl;
	_getch();
}