#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand( time( 0 ) );
	int per[10], obr[10];
	int iter, jack, tmp, min, num, mainNum;
	bool flag;

	cin >> mainNum;
	for (iter = 0; iter < mainNum; iter++) {
		per[iter] = 1+rand() % 9;
		if(iter == 1 && per[iter] == per[iter-1]){
			iter--;
		}
	}
	while (1) {
		for (int k = 0; k < mainNum; k++) {
			cout << per[k];
		}
		flag = false;
		for (iter = mainNum - 2; iter >= 0; iter--) {
			if (per[iter] < per[iter + 1]) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			break;
		}
		cout << endl;
		num = per[iter + 1];
		for (jack = iter + 1; jack < mainNum; jack++) {
			if (((per[jack] - per[iter]) < num) && (per[iter] < per[jack])) {
				min = jack;
			}
		}
		tmp = per[iter];
		per[iter] = per[min];
		per[min] = tmp;
		for (jack = iter + 1; jack < mainNum; jack++) {
			obr[jack] = per[jack];
		}
		jack = iter + 1;
		for (int k = mainNum - 1; k >= iter + 1; k--) {
			per[jack] = obr[k];
			jack++;
		}
	}
	cout << endl;

	return 0;
}