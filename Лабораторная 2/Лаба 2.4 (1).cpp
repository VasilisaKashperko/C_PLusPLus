#include <iostream>
int main()
{
	float b = -0.12; int n = 40; double x = 1.3E-4, z, y;
	z = 1 / (x - 1) + sin(x) - sqrt(n);
	y = (exp(-b) + 1) / 2*z;
	std::cout << "z=" << z;
	std::cout << "y=" << y;
}