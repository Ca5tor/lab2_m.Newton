#include <iostream>
#include <vector> 
typedef std::vector<double> dVector; 

double Newton1(int n, dVector y, double a, double h, double z, double E) {
	double p = 0;
	double q = (z - a) / h; 
	if (abs(q) <= 1) { 
		dVector d = y; 
		double t = 1;
		p = d[0]; 
		std::cout << "k" << "\t" << "Pk(x)" << std::endl;
		for (int k = 1; k < n; k++) { 
			for (int i = 0; i != (n - k); i++)
				d[i] = d[i + 1] - d[i]; 
			
			t *= (q - k + 1) / k; 
			double r = d[0] * t; 
			
			if (abs(r) >= E) p += r;
			
			std::cout << k << "\t" << p << std::endl;
		}
	} return p; 
}

int main() {
	double x = 0.47, E = 0.00001;
	dVector X{ 0.45, 0.5, 0.55, 0.6 }; 
	dVector Y{ -3.489, -3.325, -3.1385, -2.928 }; 
	double res = Newton1(4, Y, X[0], 0.05, x, E); 
		std::cout << "\nOtvet:" << res << std::endl << std::endl; 
	system("pause");
	return 0;
}