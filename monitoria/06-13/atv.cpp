#include <iostream>
#include <cmath>
using namespace std;

int msp(char A[], int i, int j) {
	if(i == j) return 1;	
	else {
		if(i + 1 == j && A[i] == A[j]) return 2;
		else {
			if(A[i] == A[j]) return msp (A, i + 1, j - 1) + 2;	
			else return max (msp (A, i + 1, j), msp (A, i, j - 1));
		}	
	}
}



int main() {
	char pali[10] = "BBABCBCAB";

	cout << msp (pali, 0, 8);
	return 0;
}