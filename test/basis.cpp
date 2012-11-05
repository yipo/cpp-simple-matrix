#include "../matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
void fill(matrix<T> &mat,T from) {
	for (int i=0;i<mat.get_m();i++) {
		for (int j=0;j<mat.get_n();j++) {
			mat.at(i,j)=from++;
		}
	}
}

template <typename T>
void print(const char *prompt,const matrix<T> &mat) {
	cout<<prompt<<endl;
	for (int i=0;i<mat.get_m();i++) {
		for (int j=0;j<mat.get_n();j++) {
			cout<<setw(4)<<mat.at(i,j);
		}
		cout<<endl;
	}
}

int main() {
	matrix<int> a(2,6);
	fill(a,100);
	print("a:",a);
	
	matrix<int> b(a);
	print("b:",b);
	
	fill(a,200);
	print("a:",a);
	print("b:",b);
	
	a=a;
	print("a:",a);
	
	return 0;
}

