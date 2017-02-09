/* This program solves a single quadratic equation of the form:
 *		a*x^2 + b*x + c = 0
 */
/***************************************************************************
   This program solves a single quadratic equation of the form:
  		a*x^2 + b*x + c = 0
   Where a, b, and c are entered by the operator when prompted. The results
   are printed to stdout and vary based on the value of the discriminant.
 ***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

// global variables
double root1, root2;

double readCoeffs();

bool equSolver(double, double, double);

// Calculates and returns the discriminant.
// test if (b^2 - 4ac) is negative, if so roots do not exist
double disc(double, double, double);

void outResults(double, double, double, bool);


int main() {
	
	a = readCoeffs();
	b = readCoeffs();
	c = readCoeffs();
	
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
