/*
 *	��ǥ ��� ��� �ð��� 1 (���������� : ACCEPTABLE_ERROR_RANGE) �϶�,  �ð��� ��� �� ��(perhour)�� ���ϴ� ���α׷�.
 *	1. �ð��� ��� �� ���� �ʱⰪ���� ��� ��� �ð��� ���غ�
 *	2. ��ǥ ��� ���ð� ���� ���� �� ���, ������ ���߰� ��� ���
 *	3. ���� ���� ���, �ð��� ��� �� ���� �����ϸ� ��ǥ ��� ��� �ð��� �����ϴ� ���� �ݺ�.
 *  
 *  ���� �� : �ʱ� �ð��� ��� �� ���� 30. -> ��� ��� �ð��� 1���� ŭ ->
 *  		  ��� �� �� 15�� ����-> (15 - 30 = -15)�� �ʱ� ��ȭ�� ���� ->
 *			  ��� ���ð��� 1���� ������ ŭ -> ��ȭ���� (-15 / 2 = -7.5)�� ����->
 *			  ��� ��ýð��� 1���� ���� -> ��ȭ���� (-7.5 / 2 * (-1) = 3.75)�� ����....
 *			  .....-> ������ �� -> ��� ��� �� ����
 *  !!!! �����ϰ� �Ϸ��� SIMPLEX ALGORITHM���� �� �� !!!!
 *	!!!! �� ���α׷��� �����ս��� Ȯ�����̹Ƿ� �ſ� ����(customer class�� randomness ����)�� ����!!!!
 *  !!!! �� ������ �������� ���� �� �� ����. !!!!
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "queue.h"

const int MIN_PER_HR = 60;
const double ACCEPTABLE_ERROR_RANGE = 0.01;

bool newcustomer(double x);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case study : Heather Bank ATM\n";
	cout << "Max Queue length?: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "enter simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	double perhour = 60; // initial value.
	double last_perhour;
	double last_change;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;
	double testval;

	Item temp;
	long turnaways;
	long customers;
	long served;
	long sum_line;
	int wait_time;
	long line_wait;
	bool is_initial = true;
	int tracker = 0;
	do {
		if (!is_initial) {
			if (testval > 1.0 + ACCEPTABLE_ERROR_RANGE) {
				if (last_change < 0) {
					perhour += last_change;
					if (perhour < 0)
						perhour = 0;
					min_per_cust = MIN_PER_HR / perhour;
				}
				else {
					last_change *= -1;
					last_change /= 2;
					perhour += last_change;
					min_per_cust = MIN_PER_HR / perhour;
				}
			}
			else if (1.0 - ACCEPTABLE_ERROR_RANGE > testval) {
				if (last_change < 0) {
					last_change *= -1;
					last_change /= 2;
					perhour += last_change;
					min_per_cust = MIN_PER_HR / perhour;
				}
				else {
					perhour += last_change;
					min_per_cust = MIN_PER_HR / perhour;
				}
			}
		}
		turnaways = 0;
		customers = 0;
		served = 0;
		sum_line = 0;
		wait_time = 0;
		line_wait = 0;
		for (int cycle = 0; cycle < cyclelimit; cycle++) {
			if (newcustomer(min_per_cust)) {
				if (line.isfull())
					turnaways++;
				else {
					customers++;
					temp.set(cycle);
					line.enqueue(temp);
				}
			}
			if (wait_time <= 0 && !line.isempty()) {
				line.dequeue(temp);
				wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
		testval = (double)line_wait / served;
		if (is_initial) {
			is_initial = false;
			if (testval > 1.0 + ACCEPTABLE_ERROR_RANGE) {
				last_perhour = perhour;
				perhour /= 2;
				last_change = perhour - last_perhour;
				min_per_cust = MIN_PER_HR / perhour;				
			}
			else if (testval < 1.0 - ACCEPTABLE_ERROR_RANGE) {
				last_perhour = perhour;
				perhour *= 2;
				last_change = perhour - last_perhour;
				min_per_cust = MIN_PER_HR / perhour;
			}

		}
		tracker++;
	} while (!(1.0 - ACCEPTABLE_ERROR_RANGE <= testval && testval <= 1.0 + ACCEPTABLE_ERROR_RANGE));
	
	if (customers > 0) {
		cout << "       customers lined in queue : " << customers << endl;
		cout << "customers completed transaction : " << served << endl;
		cout << "          customers turned away : " << turnaways << endl;
		cout << "           average queue length : ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "           average waiting time : " << (double)line_wait / served << "minute\n";
		cout << "target value-customers per hour : " << perhour << endl;
		cout << "total count for approx.         : " << tracker << endl;
	}
	else
		cout << "there's no customer!\n";
	cout << "completed!\n";
	cin.get();
	cin.get();
	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}