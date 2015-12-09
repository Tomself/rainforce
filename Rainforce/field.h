#pragma once

//‘O•ûéŒ¾I

class robot;
class goal;


class field
{

private:

	robot * Robot;
	goal * Goal;

	int fieldNum;
	int * gridArrow;
	float Payment;
	int stepNum;
	int learnNum;

	int* startRocation;
	int* goalRocation;




public:
	field();
	field(int, int, float, int);
	~field();
	int decArrow();
	void payArrow(int, int, int, int);
	void confisArrow(int, int, int, int);
	void outArrow(int*);
	void roboMove();
	int comRocation();


	void goV(int);
	void matchV(int);
	void tryV(int);

	void setNumbers(int);
	void getNumbers(int*);
	void setFieldNum(int);
	int getFieldNum();
	void setLearnNum(int);
	void setArrowNum(int,int);
	int getArrowNum(int);
	void setPayment(float);

	void resetNumbers();
};

