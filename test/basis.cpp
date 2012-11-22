#include "../matrix.h"
#include <cassert>
#include <iostream>
using namespace std;

const int BASE=10;

template <typename T>
void fill(matrix<T> &mat,T from) {
	for (int i=0;i<mat.get_m();i++) {
		for (int j=0;j<mat.get_n();j++) {
			mat.at(i,j)=from+i*BASE+j;
		}
	}
}

template <typename T>
void check(const matrix<T> &mat,T from) {
	for (int i=0;i<mat.get_m();i++) {
		for (int j=0;j<mat.get_n();j++) {
			assert(mat.at(i,j)==from+i*BASE+j);
		}
	}
}

int main() {
	matrix<int> a(2,6);
	fill(a,100);
	check(a,100);
	
	matrix<int> b(a);
	check(b,100);
	
	fill(a,200);
	check(a,200);
	check(b,100);
	
	b=b;
	check(b,100);
	
	matrix<int> c(4,3);
	fill(c,500);
	a=c;
	check(a,500);
	
	cout<<"OK"<<endl;
	return 0;
}

