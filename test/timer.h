#ifndef _TIMER_H_
#define _TIMER_H_

#include <ctime>
#include <iostream>

class timer {
	std::string tag;
	std::clock_t begin;
	
public:
	timer(const std::string &tag=std::string()) : tag(tag),begin(std::clock()) {}
	~timer() {
		std::cout<<tag<<": "<<elapse()*1000<<"ms"<<std::endl;
	}
	
	double elapse() const {
		return double(std::clock()-begin)/CLOCKS_PER_SEC;
	}
	
	void reset() {
		begin=std::clock();
	}
};

#endif

