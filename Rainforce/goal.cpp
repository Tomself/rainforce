#include "stdafx.h"
#include "goal.h"
#include "rrandom.h"

goal::goal()
{
	_mx = 0;
	_my = 0;

	_fieldNum = 0;

	_fx = 0;
	_fy = 0;

}

goal::goal(int fn) {

	_fieldNum = fn;

}

goal::~goal()
{
}

int goal::random() {

	int n;

	n = rrandom(_fieldNum);

	return n;

}

void goal::setMyRocation() {

	_mx = random();
	_my = random();
}

void goal::resetMyRocation() {

	_mx = _fx;
	_my = _fy;

}

void goal::setFirstRocation() {

	_fx = _mx;
	_fy = _my;

}

void goal::getMyRocation(int* ret) {

	ret[0] = _mx;
	ret[1] = _my;

}