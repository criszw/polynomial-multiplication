#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string> 
#include <iostream>

using namespace std;


int * getCoeff(int n) {
	int * coeff = new int[n];
	for(int i =0; i<n; i++) {
		int x;
		cin >> x;
		coeff[i]=x;
	}
	return coeff;
}

void printPoly(int * array, int len){
	for(int i = 0; i < len; i++) {
		if (i == 0) {
			cout << "(" << array[i] << ")";
		}
		else {
			cout<< " + (" << array[i] << ")" << "x^" << i;
		}
		
	}
	cout <<  endl;
}

int * computePoly(int * x, int m, int * y, int n) {
	int * result = new int[m+n-1];
	for(int i =0; i<m+n-1; i++) {
		result[i]=0;
	}
	
	for(int i =0; i<m; i++) {
		for(int j =0; j<n; j++) {
			result[i+j] += x[i] * y[j];
		}
	}
	
	delete [] x; 
	delete [] y;
	return result;
	
		
}
	
	

int main() {

int n1,n2;
cout << "How many coefficients are in the first polynomial? ";
cin >> n1;
cout << "What are the coefficients (lowest power first)? ";
int *poly1 = getCoeff(n1);
cout << "How many coefficients are in the second polynomial? ";
cin >> n2;
cout << "What are the coefficients (lowest power first)? ";
int * poly2= getCoeff(n2);
printPoly(poly1, n1);
cout << "times" << endl;
printPoly(poly2, n2);
cout << "-----" << endl;
printPoly(computePoly(poly1,n1, poly2, n2), n1+n2-1);

}
