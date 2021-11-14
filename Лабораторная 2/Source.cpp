#include <iostream>
int main()
{
	int t = 6; float y = -1.2, p, q; double x = 0.4E6;
	p = 2.6 * t + cos(y / (3 * x + y));
		q = sin(t) / cos(t);
		std::cout << "V resultate rasscheta po formule p=" << p;
		std::cout << "V resultate rasscheta po formule q=" << q;
}