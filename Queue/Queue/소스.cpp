#define Q_MAX 3
#include <iostream>

using namespace std;


enum MyEnum
{
	YES = 222222, NO = 444444
};

int q[Q_MAX];
int q_head = 0;
int q_tail = -1;
int q_size = 0;


int inQ(int input)
{
	if (q_size == Q_MAX)
		return NO;

	q_tail = (q_tail + 1) % Q_MAX;
	q[q_tail] = input;
	q_size++;

	return YES;
}

int DeQ()
{
	int output;
	if (q_size == 0)
		return NO;

	output = q[q_head];
	q_head = (q_head + 1) % Q_MAX;
	q_size--;

	return output;
}

int main()
{
	inQ(7);
	inQ(77);
	cout << DeQ() << endl;
	cout << DeQ() << endl;
	inQ(777);
	inQ(7777);
	inQ(77777);
	cout << DeQ() << endl;
	cout << DeQ() << endl;
	cout << DeQ() << endl;
	cout << DeQ() << endl;



	return 0;
}