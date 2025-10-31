#include <iostream>

using namespace std;

int value_func(int y) {                // y will be a copy of the caller's variable x
	cout << "Address of y is " << &y << endl;
	y = 1;
	return y;                    // Copy y into the function's return value
}
void reference_func(int& y)
{
	cout << "Address of y is " << &y << endl;
	y = 1;
}
void address_func(int* y)
{
	cout << "Address of y is " << &y << endl;
	*y = 1;
}
int main() {
	int x = 2;
	cout << "Address of x is " << &x << endl;
	//int z = value_func(x);
	reference_func(x);
	//address_func(&x);
	//cout << "Address of z is " << &z << endl;
	cout << "After calling func(), x = " << x << endl;
}