#include "facto.h"
#include "fibo.h"
#include "prime.h"

#include <iostream>

int main( int argc, char** argv ) {
	
	std::cout << Fact<10>::val << std::endl; // 3628800

	std::cout << Fibo<10>::val << std::endl; //
	std::cout << FiboN<10>::val << std::endl; //


	std::cout << IS_PRIME(131) << std::endl;


	return 0;
}