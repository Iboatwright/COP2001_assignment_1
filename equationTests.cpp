// test driver for quadratic equation program
// TODO:  Still need to test with negative values.
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

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

/*  The coef arrays have a good range of values for a, b, and c.  The
 *  first pass results are all based on positive inputs.  If I had time
 *  I'd try to code this in vector format. I think that might be faster
 *  and more efficient.
 */
void equationTests(){
	ofstream outs;
	outs.open(outfile);
	
	array<double, 95> coefA {100,100,100,100,100,100,100,100,100,100,100,
				             100,100,100,100,100,100,100,100,100,100,100,
				             100,100,100,99,99,99,99,99,99,99,99,99,99,99,
				             99,99,99,99,99,99,99,99,99,99,99,99,99,99,50,
				             50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
				             50,50,50,50,50,50,50,50,50,1,1,1,1,1,1,1,1,1,
				             1,1,1,1,1,1,1,1,1,1,1};
	array<double, 95> coefB {0,0,0,0,0,1,1,1,1,1,50,50,50,50,50,99,99,99,
                             99,99,100,100,100,100,100,0,0,0,0,0,1,1,1,1,1,
                             50,50,50,50,50,99,99,99,99,99,100,100,100,100,
                             100,0,0,0,0,0,1,1,1,1,1,50,50,50,50,50,99,99,
                             99,99,99,100,100,100,100,100,0,0,0,0,0,1,1,1,
                             1,1,50,50,50,50,50,99,99,99,99,99};
	array<double, 95> coefC {0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,
                             50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,
                             99,100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,
                             100,0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,
                             0,1,50,99,100,0,1,50,99,100,0,1,50,99,100,0,1,
                             50,99,100,0,1,50,99,100,0,1,50,99,100};
	string results[95];

	double tmpDisc, tmpRoot1, tmpRoot2;
	int i = 0;
	
	for (auto& e : coefA) {
		tmpDisc = discr(coefA[i], coefB[i], coefC[i]);
		if (tmpDisc > -1){ // real roots exist
			tmpRoot1 = (-coefB[i] + sqrt(tmpDisc))/(2*coefA[i]);
			tmpRoot2 = (-coefB[i] - sqrt(tmpDisc))/(2*coefA[i]);
			if (tmpRoot1 == tmpRoot2){ // equal roots
				//results[i] = (expected[i] == 1)?"passed ":"failed ";
				results[i] += "- roots: " + to_string(tmpRoot1);
			} else { // two different real roots
				//results[i] = (expected[i] == 3)?"passed ":"failed ";
				results[i] +=  "+ root1: " + to_string(tmpRoot1) +
					", root2: " + to_string(tmpRoot2);
			}
		} else { // imaginary roots
			//results[i] = (expected[i] == 2)?"passed ":"failed ";
			results[i] += "~ discriminant: " + to_string(tmpDisc);
		}
		i++;
	}
	i=0;
	for (auto& r : results) {
		outs << "[" <<setw(2)<<right << (i+1) << "]" <<setw(14)<<right 
			<< "(a, b, c): (" <<setw(3)<<right << coefA[i] << ", "
			<<setw(3)<<right << coefB[i] << ", " <<setw(3)<<right
			<< coefC[i] << ") " << r << endl;
		i++;
	}
	outs.close();
	return;
	
}
