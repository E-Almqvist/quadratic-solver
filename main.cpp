#include <cmath>
#include <string>
#include <iostream>
#include <array>

void print( std::string txt ) {
	std::cout << txt << std::endl;
}

double input( std::string prefix ) {
	double returnVal;
	std::cout << prefix;
	std::cin >> returnVal;

	return returnVal;
}

std::array<double, 3> pqFormel( double a, double b, double c ) {
	double p = b/a;
	double q = c/a;

	double base = -(p/2);
	double rotDiff = abs( pow(base, 2) - q );
	double rot = sqrt( rotDiff );

	double isComplex = 0.0;
	if( pow(base, 2) - q < 0 ) {
		isComplex = 1.0;
	}

	return { base, rot, isComplex };
}

std::string stringResult( std::array<double, 3> res ) {
	std::string endStr = "";
	if( res[2] == 1.0 ) {
		endStr = "i";
	}

	return std::to_string(res[0]) + " ± " + std::to_string(res[1]) + endStr;
}

class Equation {
	private:
		double a = 1;
		double b = 0;
		double c = 0;
	public:
		std::array<double, 3> solution;
		std::string solutionStr = "Not solved";
		Equation( double A, double B, double C ) {
			a = A;
			b = B;
			c = C;
		}

		void solve() {
			std::array<double, 3> res = pqFormel( a, b, c );
			solutionStr = stringResult(res);
		}
};

int main() {
	print( "A(x^2) + Bx + C = 0" );
	print( "Input your equation" );

	double A = input("A: ");
	if( A == 0 ) {
		print("That is no quadratic function!");
		return 1;
	}

	double B = input("B (p): ");
	double C = input("C (q): ");

	Equation ekv( A, B, C );
	ekv.solve();
	print( "\nResult: " + ekv.solutionStr );
	return 0;
}