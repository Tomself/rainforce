#pragma once
#include "rrandom.h"

class robot
{

private:

	int _mx, _my;
	int _fieldNum;
	int _nowStep;
	int _nowDir;
	int _px;
	int _py;
	int _fx;
	int _fy;
	int _stepMax;
	int _learnMax;

	int random();

	int* _stepAll;
	int* stepPast;

public:
	robot();
	robot(int, int, int);
	~robot();

	void getMyRocation(int*);
	void setMyRocation();
	void setMyRocation(int, int);
	int getNowStep();
	void progNowStep();
	void memNowStep(int,int);
	void getAllSteps(int*, int, int);
	void resetNowStep();
	void setPastRocation();
	void setFirstRocation();
	void resetMyRocation();
	void moveStep(int);
	int getNowDirection();
	
	int getRocationNum();
	void setField(int);



};

