/*
 *	목표 평균 대기 시간이 1 (허용오차범위 : ACCEPTABLE_ERROR_RANGE) 일때,  시간당 평균 고객 수(perhour)를 구하는 프로그램.
 *	1. 시간당 평균 고객 수의 초기값으로 평균 대기 시간을 구해봄
 *	2. 목표 평균 대기시간 범위 내에 들 경우, 시행을 멈추고 결과 출력
 *	3. 범위 밖인 경우, 시간당 평균 고객 수를 조정하며 목표 평균 대기 시간을 산출하는 것을 반복.
 *  
 *  실행 예 : 초기 시간당 평균 고객 수가 30. -> 평균 대기 시간이 1보다 큼 ->
 *  		  평균 고객 수 15로 조정-> (15 - 30 = -15)로 초기 변화값 설정 ->
 *			  평균 대기시간이 1보다 여전히 큼 -> 변화값을 (-15 / 2 = -7.5)로 수정->
 *			  평균 대시시간이 1보다 작음 -> 변화값을 (-7.5 / 2 * (-1) = 3.75)로 수정....
 *			  .....-> 범위에 듦 -> 결과 출력 후 종료
 *  !!!! 진지하게 하려면 SIMPLEX ALGORITHM으로 할 것 !!!!
 *	!!!! 이 프로그램의 퍼포먼스는 확률적이므로 매우 느릴(customer class의 randomness 때문)수 있음!!!!
 *  !!!! 정 느리면 오차범위 조정 할 수 있음. !!!!
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