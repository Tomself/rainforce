#include "stdafx.h"
#include "drawing.h"

using namespace std;

drawing::drawing()
{
}


drawing::~drawing()
{
}

void drawing::drawMap(int fieldNum, int* rocs, int* arrow) {




	for (int i = 0; i < fieldNum; i++) {

		cout << endl;

		for (int j = 0; j < fieldNum; j++) {

			int a = arrow[i*fieldNum + j];
			int b = arrow[i*fieldNum + j + 1];
			int c = arrow[i*fieldNum + j + 2];
			int d = arrow[i*fieldNum + j + 3];

			if (((rocs[0]-1 == j) && ( rocs[1]-1 == i))) {

				cout << " R";
			}
			else if (((rocs[2] -1 == j) && (rocs[3] -1 == i))) {

				cout << " G";
			}
			else if (a ==b && a==c && a==d && b==c && b==d && c==d){
					cout << "–";
				
			}
			else {
				int l = 0;
				for (int k = 1; k < 4; k++) {
					if (arrow[i*fieldNum + j + k - 1]  < arrow[i*fieldNum + j + k]) {
						l = k;
					}
				}

				switch (l) {
				case 0:
					cout << "ª";
					break;
				case 1:
					cout << "¨";
					break;
				case 2:
					cout << "«";
					break;
				case 3:
					cout << "©";
					break;
				}
			}

		}

	}
	cout << endl <<"-------------------------" << endl;

}
