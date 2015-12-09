//前方宣言時にはcppにヘッダを置く

#include "stdafx.h"
#include "field.h"
#include "robot.h"
#include "goal.h"

#include "rrandom.h"

using namespace std;

field::field() {


}

field::field(int fn, int stn, float pym, int lnn) {

	Robot = new robot(fn, stn, lnn);
	Goal = new goal(fn);

	Payment = pym;
	fieldNum = fn;
	stepNum = stn;
	learnNum = lnn;

	startRocation = new int[2];
	goalRocation = new int[2];

	gridArrow = new int[fieldNum*fieldNum*4];

	for (int i = 0; i < fieldNum*fieldNum * 4; i++) {
		gridArrow[i] = 1000;
	}

}


field::~field()
{
}

int field::decArrow() {

	int all = 0;
	int dec = 1, decn = 0;
	int* roc = new int[2];
	bool ok = true;

	field::Robot->getMyRocation(roc);

	while (ok) {

		all = gridArrow[((roc[1] - 1)*fieldNum + roc[0] - 1)] + gridArrow[((roc[1] - 1)*fieldNum + roc[0] -1) +1] + gridArrow[((roc[1] - 1)*fieldNum + roc[0] -1) + 2] + gridArrow[((roc[1] - 1)*fieldNum -1) + roc[0] +3];

		dec = rrandom(all);

		int decbuf = dec;

		decn = 0;

		while (1) {
			decbuf = decbuf - gridArrow[((roc[1] - 1)*fieldNum + roc[0] -1) + decn];
			if (decbuf <= 0) {
				break;
			}
			decn++;
		}
		switch (decn) {
		case 0:
			if (roc[1] - 1 > 0 && roc[0] <= fieldNum) {
				ok = false;
			}
			break;
		case 1:
			if (roc[0] + 1 <= fieldNum && roc[1] > 0 ) {
				ok = false;
			}
			break;
		case 2:
			if (roc[1] + 1 <= fieldNum && roc[0] > 0) {
				ok = false;
			}
			break;
		case 3:
			if (roc[0] - 1 > 0) {
				ok = false;
			}
			break;
		}
	}
	delete roc;
	return decn;
}

void field::payArrow(int dec, int num, int stp, int ls) {

	gridArrow[(num - 1) + dec] = gridArrow[(num - 1) + dec] + (Payment*(ls - (ls-stp) + 1) / ls)*10;

}

void field::confisArrow(int dec, int num, int stp, int ls) {

	if ((gridArrow[(num - 1) + dec] - (Payment*(ls - (ls - stp) + 1) / ls)) > 10) {
		gridArrow[(num - 1) + dec] = gridArrow[(num - 1) + dec] - (Payment*(ls - (ls - stp) + 1) / ls);
	}
	else {
		gridArrow[(num - 1) + dec] = 10;
	}
}


void field::outArrow(int* arr) {

	for (int i = 0; i < fieldNum*fieldNum * 4; i++) {
		arr[i] = gridArrow[i];
	}
}

void field::roboMove() {

	Robot->setPastRocation();
	Robot->moveStep(this->decArrow());
	Robot->progNowStep();
	Robot->memNowStep(Robot->getNowDirection(), learnNum);

}

int field::comRocation() {

	int* rob = new int[2];
	int* gol = new int[2];

	Robot->getMyRocation(rob);
	Goal->getMyRocation(gol);

	if ((rob[0] == gol[0]) &&  (rob[1] == gol[1])) {
		delete rob;
		delete gol;
		return 1;
	}
	else {
		delete rob;
		delete gol;
		return 0;
	}


}

void field::setNumbers(int fn) {

	fieldNum = fn;

	Robot->setMyRocation();
	Goal->setMyRocation();

	Robot->setFirstRocation();
	Goal->setFirstRocation();

	int* getRobot = new int[2];
	int* getGoal = new int[2];


	Robot->getMyRocation(getRobot);
	Goal->getMyRocation(getGoal);

	while (1) {
		if ((getRobot[0] != getGoal[0]) && (getRobot[1] != getGoal[1])) {
			break;

		}
		Goal->setMyRocation();
		Goal->getMyRocation(getGoal);
		Robot->setFirstRocation();
		Goal->setFirstRocation();
	}
	delete getRobot;
	delete getGoal;
}

void field::resetNumbers() {

	Robot->resetMyRocation();
	Robot->resetNowStep();
	Goal->resetMyRocation();

}

void field::getNumbers(int* nums) {

	int* ge = new int[2];
	Robot->getMyRocation(ge);
	nums[0] = ge[0];
	nums[1] = ge[1];
	int* ne = new int[2];
	Goal->getMyRocation(ne);
	nums[2] = ne[0];
	nums[3] = ne[1];
	delete ge;
	delete ne;
}

void field::setFieldNum(int fn) {

	fieldNum = fn;
}

int field::getFieldNum() {

	return fieldNum;
}

void field::setLearnNum(int learn) {

	learnNum = learn;
}

void field::setArrowNum(int num, int value) {

	gridArrow[num] = value;
}

int field::getArrowNum(int num) {

	return gridArrow[num];
}

void field::setPayment(float pay) {

	Payment = pay;
}

void field::goV(int l) {

	int step = Robot->getNowStep();
	int t = 0;

	int* rec = new int[2];

	for (int i = step; i > 0; i--) {
		Robot->getAllSteps(rec, i, l);
		confisArrow(rec[0], rec[1], i, step);
	}
}

void field::matchV(int l) {

	int step = Robot->getNowStep();
	int t = 0;
	
	int* rec = new int[2];

	for (int i = step; i > 0; i--) {
		Robot->getAllSteps(rec, i, l);
		payArrow( rec[0], rec[1], i, step);
	}
}

void field::tryV(int l) {


}