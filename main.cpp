#include <cmath>
#include <string>
#include <iostream>
#include <array>

void print( std::string txt ) {
	std::cout << txt << std::endl;
}

float input( std::string prefix ) {
	float returnVal;
	std::cout << prefix;
	std::cin >> returnVal;

	return returnVal;
}

std::array<float, 3> pqFormel( float a, float b, float c ) {
	float p = b/a;
	float q = c/a;

	float base = -(p/2);
	float rotDiff = abs( pow(base, 2) - q );
	float rot = sqrt( rotDiff );

	float isComplex = 0.0;
	if( pow(base, 2) - q < 0 ) {
		isComplex = 1.0;
	}

	return { base, rot, isComplex };
}

std::string stringResult( std::array<float, 3> res ) {
	std::string endStr = "";
	if( res[2] == 1.0 ) {
		endStr = "i";
	}

	return std::to_string(res[0]) + " ± " + std::to_string(res[1]) + endStr;
}

class Equation {
	private:
		float a = 1;
		float b = 0;
		float c = 0;
	public:
		std::array<float, 3> solution;
		std::string solutionStr = "Not solved";
		Equation( float A, float B, float C ) {
			a = A;
			b = B;
			c = C;
		}

		void solve() {
			std::array<float, 3> res = pqFormel( a, b, c );
			solutionStr = stringResult(res);
		}
};

int main() {
	print( "A(x^2) + Bx + C = 0" );
	print( "Input your equation" );

	float A = input("A: ");
	if( A == 0 ) {
		print("That is no quadratic function!");
		return 1;
	}

	float B = input("B (p): ");
	float C = input("C (q): ");

	Equation ekv( A, B, C );
	ekv.solve();
	print( "\nResult: " + ekv.solutionStr );
	return 0;
}