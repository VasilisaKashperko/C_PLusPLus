#include <iostream>
int main()
{
	float x = 1.1; int b = 40; double a = 5E-6, w, v;
	w = (a + b) * tan(x) / (x + 1);
	v = 1/2 * b - sqrt(w - a * b);
	std::cout << "w=" << w;
	std::cout << "v=" << v;
}