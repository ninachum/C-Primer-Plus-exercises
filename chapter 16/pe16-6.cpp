#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime()	const { return processtime; }
};

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

const int MIN_PER_HR = 60;


bool newcustomer(double x);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ios_base;
	using std::queue;

	std::srand(std::time(0));

	cout << "Case study : Heather Bank ATM\n";
	cout << "Max Queue length?: ";
	int queue_max_size;
	cin >> queue_max_size;
	typedef Customer Item;
	queue<Item> line;

	cout << "enter simulation times: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "enter average customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (line.size() == queue_max_size)	// if line is full
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		if (wait_time <= 0 && !line.empty()) {
			temp = line.front();
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}

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