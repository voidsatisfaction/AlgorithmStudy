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

unsigned long long * mul(unsigned long long a[], unsigned long long b[]){
	static unsigned long long c[4] = {0,0,0,0};
	c[0] = a[0]*b[0] + a[1]*b[2];
	c[1] = a[0]*b[1] + a[1]*b[3];
	c[2] = a[2]*b[0] + a[3]*b[2];
	c[3] = a[2]*b[1] + a[3]*b[3];
	return c;
}

unsigned long long * pow(unsigned long long a[], int n){
	static unsigned long long b[4] = {1,0,0,1};
	unsigned long long *pb, *pa;
	while(n>0){
		if(n&1){  
			pb = mul(a, b);
			for(int i=0; i<4;i++){
				b[i] = pb[i];
			}
		}
		pa = mul(a,a);
		for(int i=0; i<4;i++){
			a[i] = pa[i];
		}
		n >>= 1;
	}
	return b;
}

unsigned long long  fib3(int n){
	unsigned long long a[4] = {1,1,1,0};
	unsigned long long *pa;
	pa = pow(a, n+1);

	return pa[3];
}

void calc(int n){
	DWORD beg, end;

	/*beg = clock();
	cout<<"fib1("<<n<<") : "<<fib1(n)<<endl;
	end = clock();
	cout<<"spend time: "<<((end-beg)/CLOCKS_PER_SEC)<<endl;*/

	beg = timeGetTime();
	cout<<"fib2("<<n<<") : "<<fib2(n)<<endl;
	end = timeGetTime();
	cout<<"spend time: "<<((double)(end-beg)/1000)<<"ms"<<endl;

	beg = timeGetTime();
	cout<<"fib3("<<n<<") : "<<fib3(n)<<endl;
	end = timeGetTime();
	cout<<"spend time: "<<((double)(end-beg)/1000)<<"ms"<<endl;
}

 int main(void){
	calc(100000000);
	//fib1 = uncountable
	//fib2 = 0.98ms
	//fib3 = 0ms(uncountable alse)
	return 0;
}
