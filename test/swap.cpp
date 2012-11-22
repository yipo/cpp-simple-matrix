#include "../matrix.h"
#include "timer.h"
#include <algorithm> // for swap()
#include <cassert>
using namespace std;

void test() {
	matrix<int> a(1,1),b(1,1);
	a.at(0,0)=3;
	b.at(0,0)=5;
	swap(a,b);
	assert(a.at(0,0)==5);
	assert(b.at(0,0)==3);
}

const int AMOUNT=1000000;

void benchmark() {
	matrix<int> a(1,1),b(1,1);
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) swap(a,b);
}

int main() {
	test();
	for (int i=0;i<5;i++) benchmark();
	return 0;
}

