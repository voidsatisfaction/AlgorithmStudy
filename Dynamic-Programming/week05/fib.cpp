#include <iostream>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

unsigned long long fib1(unsigned long long  n){
	if(n <= 2) return 1;
	else return fib1(n-1)+fib1(n-2);
}

unsigned long long  fib2(unsigned long long  n){
	unsigned long long  num1 = 0,
						num2 = 1,
						temp = 1;

	for(int i=1; i<n; i++){
		temp = num1 + num2;
		num1 = num2;
		num2 = temp;
	}
	return temp;
}

typedef unsigned long long ull;

ull* mul(ull a[], ull b[]){ 
	ull* retu = new ull[4];
	retu[0] = a[0]*b[0] + a[1]*b[2];
	retu[1] = a[0]*b[1] + a[1]*b[3];
	retu[2] = a[2]*b[0] + a[3]*b[2];
	retu[3] = a[2]*b[1] + a[3]*b[3];
	return retu;
}

ull pow(ull a[], int n){
	ull *b = new ull[4] ;
	b[0] = 1;b[1]=0;b[2]=0;b[3]=1;


	while(n>0){
		if(n&1){  
			b = mul(a, b);
		}
		a = mul(a,a);
		n >>= 1;
	}
	ull result = b[3];

	delete [] b;
	return result;
}

ull  fib(int n){
	ull a[4] = {1,1,1,0};
	return pow(a,n+1);
}

int infib(long double n){
	double phi = (sqrt(5.0) + 1)/2.0;
	return floor(log(n*sqrt(5.0)) / log(phi) + 0.5);
}
void calc(int n){
	DWORD beg, end;

	beg = timeGetTime();
	cout<<"fib1("<<n<<") : "<<fib1(n)<<endl;
	end = timeGetTime();
	cout<<"spend time: "<<((double)(end-beg)/1000)<<"ms"<<endl;

	beg = timeGetTime();
	cout<<"fib2("<<n<<") : "<<fib2(n)<<endl;
	end = timeGetTime();
	cout<<"spend time: "<<((double)(end-beg)/1000)<<"ms"<<endl;

	beg = timeGetTime();
	cout<<"fib3("<<n<<") : "<<fib(n)<<endl;
	end = timeGetTime();
	cout<<"spend time: "<<((double)(end-beg)/1000)<<"ms"<<endl;
}

 int main(void){
	calc(30);
	return 0;
}
