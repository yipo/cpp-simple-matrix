#include "../matrix.h"
#include "timer.h"
#include <iostream>

const int AMOUNT=100000000;

// Control Group: Doing nothing but looping.

void test_ctrlgrp() {
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++);
}

// A: Accessing the element by mat.at(i,j).

template <typename T>
void test_a_set(matrix<T> &mat) {
	T value;
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) mat.at(0,0)=value;
}

template <typename T>
void test_a_get(matrix<T> &mat) {
	T value;
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) value=mat.at(0,0);
}

// B: Accessing the element by mat(i,j).

template <typename T>
void test_b_set(matrix<T> &mat) {
	T value;
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) mat(0,0)=value;
}

template <typename T>
void test_b_get(matrix<T> &mat) {
	T value;
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) value=mat(0,0);
}

// C: Accessing the element by mat[i][j].

template <typename T>
void test_c_set(matrix<T> &mat) {
	T value;
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) mat[0][0]=value;
}

template <typename T>
void test_c_get(matrix<T> &mat) {
	T value;
	timer t(__func__);
	for (int i=0;i<AMOUNT;i++) value=mat[0][0];
}

// Run all the test cases with different type.

template <typename T>
void test_benchmark(matrix<T> &mat) {
	test_ctrlgrp();
	test_a_set(mat);
	test_a_get(mat);
	test_b_set(mat);
	test_b_get(mat);
	test_c_set(mat);
	test_c_get(mat);
}

int main() {
	using namespace std;
	
	cout<<"- matrix<int>"<<endl;
	matrix<int> mi(1,1);
	test_benchmark(mi);
	
	cout<<"- matrix<double>"<<endl;
	matrix<double> md(1,1);
	test_benchmark(md);
	
	return 0;
}

