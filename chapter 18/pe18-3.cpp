
template <typename T>
long double sum_value(const T& num)
{
	return num;
}


template <typename T, typename... Args>
long double sum_value(const T& num, const Args&... args)
{
	return num + sum_value(args...);
}

int main()
{
	long double x = sum_value(3, 2, 'A');
}