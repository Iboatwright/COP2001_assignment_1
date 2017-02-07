/* This program solves a single quadratic equation of the form:
 *		a*x^2 + b*x + c = 0
 */

#include <iostream>
#include <cmath>

using namespace std;

// global variables
double root1, root2;

// reads coefficients from keyboard and returns to main
double readCoeffs();

// solves the equation and writes solution to globals
bool equSolver(double, double, double);

// test if (b^2 - 4ac) is negative, if so roots do not exist
double disc(double, double, double);

// prints the results to stdout
void outResults(double, double, double, bool);


int main() {
	// coefficient vars
	double a, b, c;
	bool ind;
	
	// have operator enter values for variables
	a = readCoeffs();
	b = readCoeffs();
	c = readCoeffs();
	
	// solve the equation
	ind = equSolver(a, b, c);
	
	outResults(a, b, c, ind);
	return 0;
}

double readCoeffs(){
	double temp;
	cout << "Enter coefficient: " << endl << endl; 
	cin >> temp;
	return temp;
}

double discr(double a, double b, double c){
	return (b*b-4*a*c);
}

bool equSolver(double a, double b, double c){
	double compDisc = discr(a, b, c);
	
	if (compDisc > -1 && a){
		root1 = (-b + sqrt(compDisc))/(2*a);
		root2 = (-b - sqrt(compDisc))/(2*a);
	}
	
	return (compDisc > -1)?1:0;
}

void outResults(double a, double b, double c,bool ind){
	if (ind){
		cout << "Quadratic equation with the following coefficients:" << endl;
		cout << "a: " << a << "; b: " << b << "; c: " << c << endl;
		cout << "has the following roots" << endl;
		cout << "Root1: " << root1 << "; Root2: " << root2 << ";" << endl << endl;
	} else {
		cout << "Quadratic equation with the following coefficients:" << endl;
		cout << "a: " << a << "; b: " << b << "; c: " << c << endl;
		cout << "has no roots in the real domain." << endl << endl;
	}
	return;
}
