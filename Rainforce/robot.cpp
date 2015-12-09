#include "stdafx.h"
#include "robot.h"
#include "rrandom.h"

#include <random>

using namespace std;

robot::robot()
{
	_mx = 0;
	_my = 0;
	_fieldNum = 0;
	_nowStep = 0;


}

robot::robot(int fn, int stepNum, int learnNum) {

	_mx = 0;
	_my = 0;
	_fieldNum = fn;
	_nowStep = 0;
	_nowDir = 0;
	_px = 0;
	_py = 0;
	_fx = 0;
	_fy = 0;

	_stepMax = stepNum;
	_learnMax = learnNum;

	_stepAll = new int[stepNum * learnNum * 2];

	for (int i = 0; i < stepNum * learnNum; i++) {

		_stepAll[i] = 0;
	}


}


robot::~robot()
{
}

int robot::random() {

	int n;

	n = rrandom(_fieldNum);

	return n;

}

void robot::getMyRocation(int* ret) {

	ret[0] = _mx;
	ret[1] = _my;
}

void robot::setMyRocation() {

	_mx = this->random();
	_my = this->random();

}

void robot::setMyRocation(int ix, int iy) {

	_mx = ix;
	_my = iy;

}

int robot::getNowStep() {

	return _nowStep;

};
void robot::progNowStep(){

	_nowStep++;
};


void robot::memNowStep(int dir, int lrn ){

	_stepAll[(_nowStep -1)*2 + lrn*_stepMax] = dir;
	_stepAll[(_nowStep -1)*2 + lrn*_stepMax +1] = (_py -1)*_fieldNum +_px;
};

void robot::getAllSteps(int* receive, int step, int lrn) {
	receive[0] = _stepAll[(step-1)*2 + lrn*_stepMax];
	receive[1] = _stepAll[(step-1)*2 + lrn*_stepMax+1];

};

void robot::resetNowStep() {
	_nowStep = 0;
};

void robot::setPastRocation() {

	_px = _mx;
	_py = _my;

}


void robot::setFirstRocation() {
	
	_fx = _mx;
	_fy = _my;

}

void robot::resetMyRocation() {

	_mx = _fx;
	_my = _fy;

}

void robot::moveStep(int decision) {

	_nowDir = decision;

	switch (decision) {

	case 0:
		_my -= 1;
		break;
	case 1:
		_mx += 1;
		break;
	case 2:
		_my += 1;
		break;
	case 3:
		_mx -= 1;
	}
}

int robot::getNowDirection() {

	return _nowDir;

}

int robot::getRocationNum() {

	return (_my - 1)*_fieldNum + (_mx);
}