#include <cmath>
#include <string>
#include <iostream>
#include <array>
#include <complex>
#include <cmath>

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

	float base = -(p/2); // middle of the two roots
	float rotDiff = abs( pow(base, 2) - q );
	float rot = sqrt( rotDiff );

	float isComplex = 0.0;
	if( pow(base, 2) - q < 0 ) {
		isComplex = 1.0;
	}

	return { base, rot, isComplex };
}

float getEquationOutput( float a, float b, float c, float input ) {
	return (a*pow(input, 2)) + (b*input) + c;
}

std::array<std::string, 3> stringResult( std::array<float, 3> res ) {
	std::array<std::string, 3> returnArray;

	std::string endStr = "";
	if( res[2] == 1 ) { endStr = "i"; }
	returnArray[0] = std::to_string(res[0]) + " ± " + std::to_string(res[1]) + endStr; // root

	return returnArray;
}

class Equation {
	private:
		float a = 1;
		float b = 0;
		float c = 0;
	public:
		std::array<float, 3> solution;
		float symmetry = 0;
		std::string solutionStr = "Not solved";
		Equation( float A, float B, float C ) {
			a = A;
			b = B;
			c = C;
		}

		void solve() {
			solution = pqFormel( a, b, c );
			symmetry = solution[0];
			// make an array with the solutionos as strings
			std::array<std::string, 3> res_string = stringResult(solution);
			solutionStr = res_string[0];
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
	print( "\nRoot: " + ekv.solutionStr + "\n-----------------------------" );
	print( "Symmetry line: x = " + std::to_string(ekv.symmetry) );
	print( "Vertex: (" + std::to_string(ekv.symmetry) + ", " + std::to_string( getEquationOutput(A,B,C,ekv.symmetry) ) + ")" );
	return 0;
}