#include <iostream>
#include <algorithm> //std::sort
#include <vector>
#include <stdlib.h> //rand()
#include <time.h> //time(NULL)
#include <Windows.h> //calc time spend
#pragma comment(lib, "winmm.lib") //calc time spend

using namespace std;

#define UNIT 5

//�Լ� ����
int order(vector<int>& A, int k);//A���� k��°�� �������� ����
int order_new(vector<int>& A, int k);//������ ���

//�Լ� ����
int main(){
	int n=500000, k=0;
	cin>>k;

	vector<int> A;
	A.resize(n);

	//1���� 5�鸸������ ������ ���Ҹ� ���� ����
	srand((unsigned int)time(NULL));
	for(int i = 0;i<n;i++){
		A[i] = (double)rand() / RAND_MAX * 5000000;
	}

	DWORD beg, end;

	//��Ʈ�� �̿��� ���
	vector<int> temp(A);

	beg = timeGetTime();
		sort(temp.begin(), temp.end());
		cout<<temp[k-1];
	end = timeGetTime();

	cout<<"spend time: "<<((double)(end-beg)/1000)<<"s"<<endl;

	//���� ���
	beg = timeGetTime();
		cout<<order(A, k);
	end = timeGetTime();

	cout<<"spend time: "<<((double)(end-beg)/1000)<<"s"<<endl;

	//������ ���
	beg = timeGetTime();
		cout<<order_new(A, k);
	end = timeGetTime();

	cout<<"spend time: "<<((double)(end-beg)/1000)<<"s"<<endl;
	
	return 0;
}

/*
case 1. A�� ũ�Ⱑ UNIT(=5)���� �۰ų� ������
		A�� ��Ʈ�ؼ� ����ã�´�
		����ð����� �ذ� ����

case2. A�� ũ�Ⱑ UNIT���� ũ��
		������ ������� A�� �߾�ġ�� �ٻ�ġm�� ã��
		
		A�� ������ m���� ������(S1), ������(S2), ū��(S3)�� �з��ؼ�
		
		S1�� ���Ҽ��� k���� ũ�� �ٽ� order(S1, k)
		S1�ǿ��Ҽ� <= k S1�� ���Ҽ�+S2�� ���Ҽ��� m�� ����
		�׷����� ������ �ٽ� order(S3, k-(S1�ǿ��Ҽ� + S2�ǿ��Ҽ�)
*/

int order(vector<int>& A, int k){
	int n = A.size();

	if(n <= UNIT){
		vector<int> temp(A);
		sort(temp.begin(), temp.end());
		return temp[k-1];
	}else{
		vector<int> T; //m�� �ɸ��� ������ �����Ѵ�
		T.resize(n/UNIT);

		vector<int> temp; //T�� ����� ���� �ӽ� ����
		temp.resize(UNIT);

		for(int i=0; i<(n/UNIT); i++){
			for(int j=0; j<UNIT; j++){
				temp[j] = A[i*UNIT + j];
			}
			T[i] = order(temp, 3);
		}

		int m = order(T, (n+5)/10);

		vector<int> S1, S2, S3; //S1 : A�� ������ m���� ������ S2 : A�� ������ m�� ������ S3 : A�� ������ m���� ū��
		int nS1=0, nS2=0, nS3=0;//nS1 = S1�� ���� ���Ҽ�

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
������ ���

m�� ������ A�� �߾�ġ�� ��´�
å������ �� ����� �־�O(n^2)�� �����ٰ� ������
���� ������ �ξ� ������
*/

int order_new(vector<int>& A, int k){
	int n = A.size();

	if(n <= UNIT){
		vector<int> temp(A);
		sort(temp.begin(), temp.end());
		return temp[k-1];
	}else{
		int m = A[(n-1)/2];

		vector<int> S1, S2, S3; //S1 : A�� ������ m���� ������ S2 : A�� ������ m�� ������ S3 : A�� ������ m���� ū��
		int nS1=0, nS2=0, nS3=0;//nS1 = S1�� ���� ���Ҽ�

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
