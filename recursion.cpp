#include "timer.h"
#include <iostream>
#include <cstdlib>
using namespace std;

unsigned int iterativeFib(unsigned int n);
unsigned int fib(unsigned int n);

int main(int argc, char* argv[]){
	unsigned int v=atoi(argv[1]);
	unsigned int result;
	Timer t1;
	Timer t2;
	t1.start();
	result=iterativeFib(v);
	t1.stop();
	cout << "result is: "  << result << ".  It took " << t1.currtime() << " seconds"<< endl;
	t2.start();
	result=fib(v);
	t2.stop();
	cout << "result is: "  << result << ".  It took " << t2.currtime() << " seconds"<< endl;

}


unsigned int iterativeFib(unsigned int n){
	int first=0;
	int second=1;
	int result;
	if(n>=2){
		while(n>=2){
			result=first+second;
			first=second;
			second = result;		
			n--;
		}
	}
	else{
		result=n;
	}
	return result;

}
unsigned int fib(unsigned int n){
	int result;
	if(n == 0){
		result=0;
	}
	else if(n == 1){
		result=1;
	}
	else{
		result=fib(n-1) + fib(n-2);
	}
	return result;
}

