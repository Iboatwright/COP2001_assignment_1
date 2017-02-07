// developing an equation test driver
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

#define outfile "test_results.txt"

using namespace std;

// test if (b^2 - 4ac) is negative, if so roots do not exist
double disc(double, double, double);

// runs the code to test against test values and outputs the results
void equationTests();

int main(){
	equationTests();
}

double discr(double a, double b, double c){
	return (b*b-4*a*c);
}

void equationTests(){
	ofstream outs;
	outs.open(outfile);
	// 1 = equal roots, 2 = imaginary roots, 3 = real roots
	std::array<int, 95> expected {1,2,2,2,2,3,2,2,2,2,3,3,2,2,2,3,3,2,2,2,3,3,2,2,2,1,2,2,2,2,3,2,2,2,2,3,3,2,2,2,3,3,2,2,2,3,3,2,2,2,1,2,2,2,2,3,2,2,2,2,3,3,2,2,2,3,3,2,2,2,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3};
	std::array<double, 95> coefA {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	std::array<double, 95> coefB {0,0,0,0,0,1,1,1,1,1,50,50,50,50,50,99,99,99,99,99,100,100,100,100,100,0,0,0,0,0,1,1,1,1,1,50,50,50,50,50,99,99,99,99,99,100,100,100,100,100,0,0,0,0,0,1,1,1,1,1,50,50,50,50,50,99,99,99,99,99,100,100,100,100,100,0,0,0,0,0,1,1,1,1,1,50,50,50,50,50,99,99,99,99,99};
	std::array<double, 95> coefC {0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100};
	std::string results[95];
	double tmpDisc, tmpRoot1, tmpRoot2;
	int i = 0;
	
	for (auto& e : expected) {
		tmpDisc = discr(coefA[i], coefB[i], coefC[i]);
		if (tmpDisc > -1){ // real roots exist
			tmpRoot1 = (-coefB[i] + sqrt(tmpDisc))/(2*coefA[i]);
			tmpRoot2 = (-coefB[i] - sqrt(tmpDisc))/(2*coefA[i]);
			if (tmpRoot1 == tmpRoot2){ // equal roots
				results[i] = (expected[i] == 1)?"passed":"failed - roots: " + std::to_string(tmpRoot1);
			} else { // two different real roots
				results[i] = (expected[i] == 3)?"passed":"failed root1: " + std::to_string(tmpRoot1) + ", root2: " + std::to_string(tmpRoot2);
			}
		} else { // imaginary roots
			results[i] = (expected[i] == 2)?"passed":"failed - discriminant: " + std::to_string(tmpDisc);
		}
		i++;
	}
	i=1;
	for (auto& r : results) {
		outs << "test[" << i << "] " << r << endl;
	}
	outs.close();
	return;
	
}