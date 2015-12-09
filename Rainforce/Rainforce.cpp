// Rainforce.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "robot.h"
#include "field.h"
#include "drawing.h"
#include "goal.h"

#include "windows.h"

using namespace std;

int main()
{

	int fn, pym, stn, lnn;

	cout << "Please input a field number : ";

	cin >> fn;

	cout << "Please input a payment : ";

	cin >> pym;

	cout << "Please input a maximum step number : ";

	cin >> stn;

	cout << "Please input a learning number : ";

	cin >> lnn;

	field* Field = new field(fn, stn, pym, lnn);
	drawing* Draw = new drawing();

	Field->setNumbers(fn);

	cout << "Drawing Map.";

	int* nums = new int[4];

	cout << endl << "Draw" << endl;

	bool end = true;
	bool wpay = true;

	int* arrow = new int[fn*fn*4+4];

	for (int i = 0; i < fn*fn*4; i++) {
		arrow[i] = 0;
	}

	while (end) {
		for (int i = 0; i < lnn; i++) {

			Field->resetNumbers();
			Field->setLearnNum(i);

			cout << "get" << endl;

			if (i == 0) {
				Field->getNumbers(nums);
				Field->outArrow(arrow);
				Draw->drawMap(Field->getFieldNum(), nums, arrow);
			}

			for (int j = 0; j < stn; j++) {

				

				Field->roboMove();

				Field->getNumbers(nums);
				Field->outArrow(arrow);
				Draw->drawMap(Field->getFieldNum(), nums, arrow);

				Sleep(20);

				cout << "Learning" << i << " Step" << j << endl;
				

				switch (Field->comRocation())
				{
				case 0:
					char ab;
					wpay = false;
					break;

				case 1:
					char a;
					Field->matchV(i);
					cout << "Match!";
					Sleep(500);
					j = stn;
					wpay = true;
					
				}
				
				Field->getNumbers(nums);
				
			}
			if (wpay == false) {
				//Field->goV(i);
			}
			Sleep(500);
		}
	}

	cout << "Use" << endl;
	while (end) {
		for (int i = 0; i < lnn; i++) {

			Field->resetNumbers();
			Field->setLearnNum(i);

			cout << "get" << endl;

			if (i == 0) {
				Field->getNumbers(nums);
				Field->outArrow(arrow);
				Draw->drawMap(Field->getFieldNum(), nums, arrow);
			}

			for (int j = 0; j < stn; j++) {



				Field->roboMove();

				Field->getNumbers(nums);
				Field->outArrow(arrow);
				Draw->drawMap(Field->getFieldNum(), nums, arrow);

				Sleep(200);

				cout << "Learning" << i << " Step" << j << endl;


				switch (Field->comRocation())
				{
				case 0:
					char ab;
					wpay = false;
					break;

				case 1:
					char a;
					cout << "Goal!";
					Sleep(500);
					j = stn;
					wpay = true;

				}

				Field->getNumbers(nums);

			}
			if (wpay == false) {
				cout << "Fault!" << endl;
			}
			Sleep(500);
		}
	}

	return 0;
}
