#include "rrandom.h"

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <random>



int rrandom(int range){

	int r = 0;

	std::random_device rdm;
	std::mt19937 mt(rdm());

	std::uniform_int_distribution<int> field(1, range);

	r = field(mt);

	return r;
}
