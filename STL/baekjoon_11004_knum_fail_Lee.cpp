#include <iostream>
#include <algorithm> //std::sort
#include <vector>
#include <stdlib.h> //rand()
#include <time.h> //time(NULL)
#include <Windows.h> //calc time spend
#pragma comment(lib, "winmm.lib") //calc time spend

using namespace std;

#define UNIT 5

//함수 선언
int order(vector<int>& A, int k);//A에서 k번째로 작은수를 리턴
int order_new(vector<int>& A, int k);//개선된 방법

//함수 구현
int main(){
	int n=500000, k=0;
	cin>>k;

	vector<int> A;
	A.resize(n);

	//1부터 5백만까지의 무작위 원소를 가진 벡터
	srand((unsigned int)time(NULL));
	for(int i = 0;i<n;i++){
		A[i] = (double)rand() / RAND_MAX * 5000000;
	}

	DWORD beg, end;

	//소트를 이용한 방법
	vector<int> temp(A);

	beg = timeGetTime();
		sort(temp.begin(), temp.end());
		cout<<temp[k-1];
	end = timeGetTime();

	cout<<"spend time: "<<((double)(end-beg)/1000)<<"s"<<endl;

	//원래 방법
	beg = timeGetTime();
		cout<<order(A, k);
	end = timeGetTime();

	cout<<"spend time: "<<((double)(end-beg)/1000)<<"s"<<endl;

	//개선된 방법
	beg = timeGetTime();
		cout<<order_new(A, k);
	end = timeGetTime();

	cout<<"spend time: "<<((double)(end-beg)/1000)<<"s"<<endl;
	
	return 0;
}

/*
case 1. A의 크기가 UNIT(=5)보다 작거나 같으면
		A를 소트해서 직접찾는다
		상수시간으로 해결 가능

case2. A의 크기가 UNIT보다 크면
		적절한 방법으로 A의 중앙치의 근사치m을 찾고
		
		A의 원소중 m보다 작은것(S1), 같은것(S2), 큰것(S3)을 분류해서
		
		S1의 원소수가 k보다 크면 다시 order(S1, k)
		S1의원소수 <= k S1의 원소수+S2의 원소수면 m을 리턴
		그렇지도 않으면 다시 order(S3, k-(S1의원소수 + S2의원소수)
*/

int order(vector<int>& A, int k){
	int n = A.size();

	if(n <= UNIT){
		vector<int> temp(A);
		sort(temp.begin(), temp.end());
		return temp[k-1];
	}else{
		vector<int> T; //m이 될만한 값들을 저장한다
		T.resize(n/UNIT);

		vector<int> temp; //T를 만들기 위한 임시 벡터
		temp.resize(UNIT);

		for(int i=0; i<(n/UNIT); i++){
			for(int j=0; j<UNIT; j++){
				temp[j] = A[i*UNIT + j];
			}
			T[i] = order(temp, 3);
		}

		int m = order(T, (n+5)/10);

		vector<int> S1, S2, S3; //S1 : A의 원소중 m보다 작은것 S2 : A의 원소중 m과 같은것 S3 : A의 원소중 m보다 큰것
		int nS1=0, nS2=0, nS3=0;//nS1 = S1의 실제 원소수

		S1.resize(n);
		S2.resize(n);
		S3.resize(n);

		for(int i=0; i<n; i++){
			if(A[i] <m){
				S1[nS1++] = A[i];
			}else if(A[i] == m){
				S2[nS2++] = A[i];
			}else{
				S3[nS3++] = A[i];
			}
		}

		S1.resize(nS1);
		S2.resize(nS2);
		S3.resize(nS3);

		if(k<(int)S1.size()){
			return order(S1, k); 
		}else if(k <= (int)(S1.size() + S2.size())){
			return m;
		}else{
			return order(S3, k-(int)(S1.size() + S2.size()));
		}
	}
}

/*
개선된 방법

m을 적당히 A의 중앙치로 잡는다
책에서는 이 방법이 최악O(n^2)로 느리다고 하지만
실제 측정시 훨씬 빠르다
*/

int order_new(vector<int>& A, int k){
	int n = A.size();

	if(n <= UNIT){
		vector<int> temp(A);
		sort(temp.begin(), temp.end());
		return temp[k-1];
	}else{
		int m = A[(n-1)/2];

		vector<int> S1, S2, S3; //S1 : A의 원소중 m보다 작은것 S2 : A의 원소중 m과 같은것 S3 : A의 원소중 m보다 큰것
		int nS1=0, nS2=0, nS3=0;//nS1 = S1의 실제 원소수

		S1.resize(n);
		S2.resize(n);
		S3.resize(n);

		for(int i=0; i<n; i++){
			if(A[i] <m){
				S1[nS1++] = A[i];
			}else if(A[i] == m){
				S2[nS2++] = A[i];
			}else{
				S3[nS3++] = A[i];
			}
		}

		S1.resize(nS1);
		S2.resize(nS2);
		S3.resize(nS3);

		if(k<(int)S1.size()){
			return order_new(S1, k); 
		}else if(k <= (int)(S1.size() + S2.size())){
			return m;
		}else{
			return order_new(S3, k-(int)(S1.size() + S2.size()));
		}
	}
}
