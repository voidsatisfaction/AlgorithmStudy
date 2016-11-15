#Dynamic Programming
Dynamic Programming이란? : 지난주에 함

동적계획법은 메모리 사용량을 증가시키고 계산량을 단축시킨다. 이는 해쉬테이블에서도 살펴본 성질로, ***time-memory trade-off***라고 한다. 동적계획법에는 두 가지 approach가 있다.  

1. top-down with memoization
2. bottom-up method

일반적으로 동적계획법이라 함은 2. bottom-up method를 가르킬 때가 많지만 top-down방식으로도 설계할 수 있다.
###Example (Fibonacci Sequence)
**Source**

```
#include <iostream>
#include <ctime>

#define MAX 1000000

using namespace std;

int fib[10000];

int fibonacciTD(int n){
    if(fib[n] == -1){
        fib[n] = fibonacciTD(n-1)+fibonacciTD(n-2);
        return fib[n] % MAX;
    } else{
        return fib[n] % MAX;
    }
}

int fibonacciBU(int n){
    int a = 0;
    int b = 1;
    for(int i = 0; i < n; i++){
        int tmp = b;
        b = a+b;
        a = tmp;
        a %= MAX;
        b %= MAX;
    }
    return a;
}

int main(){
    memset(fib, -1, 10000*sizeof(int));
    fib[0] = 0;
    fib[1] = 1;
    
    //Top-down방식
    clock_t c1 = clock();
    cout << fibonacciTD(5000) << endl;
    cout << "T1 : " << (double)(clock() - c1)/CLOCKS_PER_SEC << endl;
    
    //Bottom-up방식
    clock_t c2 = clock();
    cout << fibonacciBU(5000) << endl;
    cout << "T2 : " << (double)(clock() - c2)/CLOCKS_PER_SEC << endl;
    return 0;
}

```
**Result**

```
863125
T1 : 0.000204
863125
T2 : 9.9e-05
Program ended with exit code: 0
```
##언제 동적계획법을 써야 하는가?
###계단오르기

###동적계획법의 요소

1. Optimal structure
2. Overlapping subproblems

Optimal structure란, divide-and-conquer에서와 같이 주어진 문제의 해가 그 문제의 부분문제들의 해를 포함하는 것을 말한다.
