#include "../matrix.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main() {
	const int M=50,N=60;
	matrix<double> mat1(M,N),mat2(M,N),mat3(M,N);
	
	double value=0.0;
	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++) {
			mat1.at(i,j)=value;
			mat2(i,j)=value;
			mat3[i][j]=value;
			value+=1.0;
		}
	}
	
	double check=0.0;
	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++) {
			assert(check==mat1.at(i,j));
			assert(check==mat2(i,j));
			assert(check==mat3[i][j]);
			check+=1.0;
		}
	}
	
	cout<<"OK"<<endl;
	return 0;
}

