#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstring>

template <typename T>
class matrix {
	int m,n;
	T *buf;
	
public:
	matrix() : m(0),n(0),buf(new T[0]) {}
	matrix(int m,int n) : m(m),n(n),buf(new T[m*n]) {}
	matrix(const matrix &mat) : m(mat.m),n(mat.n),buf(new T[m*n]) {
		std::memcpy(buf,mat.buf,m*n*sizeof(T));
	}
	
	~matrix() {
		delete [] buf;
	}
	
	matrix &operator =(const matrix &mat) {
		if (this!=&mat) {
			delete [] buf;
			m=mat.m,n=mat.n;
			buf=new T[m*n];
			std::memcpy(buf,mat.buf,m*n*sizeof(T));
		}
		return *this;
	}
	
	/*
	* Get the size of this matrix.
	*/
	int get_m() const {
		return m;
	}
	int get_n() const {
		return n;
	}
	
	/*
	* Access the element via the `at' member function.
	*/
	T &at(int i,int j) {
		return buf[i*n+j];
	}
	const T &at(int i,int j) const {
		return buf[i*n+j];
	}
	
	/*
	* Access the element by the way of functor.
	*/
	T &operator ()(int i,int j) {
		return buf[i*n+j];
	}
	const T &operator ()(int i,int j) const {
		return buf[i*n+j];
	}
	
	/*
	* Access the element via the [] operator.
	*/
private:
	class row {
		T *buf;
		
	private:
		row(T *buf) : buf(buf) {}
		
	public:
		T &operator [](int j) {
			return buf[j];
		}
		const T &operator [](int j) const {
			return buf[j];
		}
		
		friend class matrix;
		// So that only the matrix class can create a row object.
	};
	
public:
	row operator [](int i) {
		return row(buf+i*n);
	}
	const row operator [](int i) const {
		return row(buf+i*n);
	}
};

#endif

