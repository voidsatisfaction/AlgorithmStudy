#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int sum[301] = {0,};//A[n]:nĭ ���� ������ �ִ� ���� 
	int pt[300] = {0,};//pt[n]: n+1��° ĭ�� ����
	int n;//����� �� �ܼ�

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pt[i];
	}
	//sum[0] = 0 ���� �ʱ�ȭ �Ǿ�����
	sum[1] = pt[0];
	sum[2] = pt[0] + pt[1];

	for(int i=3;i<n+1;i++){//sum[3]���� sum[n]������ ä���
		sum[i] = max(sum[i-2]+pt[i-1],sum[i-3]+pt[i-2]+pt[i-1]);
	}

	cout<<sum[n];
	return 0;
}