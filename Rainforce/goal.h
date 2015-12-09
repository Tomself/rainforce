#pragma once

#include "rrandom.h"

class goal
{
private:

	int _mx;
	int _my;
	int _fx;
	int _fy;
	int _fieldNum;

	int random();

	int** steps;

public:
	goal();
	goal(int);
	~goal();

	void getMyRocation(int*);
	void setMyRocation();
	void setFirstRocation();
	void resetMyRocation();
};

