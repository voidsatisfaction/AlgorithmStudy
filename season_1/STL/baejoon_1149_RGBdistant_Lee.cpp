#include<iostream>

using namespace std;

/*
3
26 40 83
49 60 57
13 89 99
*/
int main(){
	int R=0, G=0, B=0, //���� �ܰ迡�� ����, �ʷ�, �Ķ��� ĥ�Ұ�� �ּҺ��
		tempR=0, tempG=0, tempB =0, //���� �Է¹޴� ��ĥ ���, �ٲ� R�� ������ ���� �ο����� ����Ѵ�
		result = 0, //��
		n = 0; //���� ����

	cin>>n;

	for(int i=0; i<n; i++){
		cin>>tempR>>tempG>>tempB;

		tempR += (G<B) ? G : B;
		tempG += (R<B) ? R : B;
		tempB += (R<G) ? R : G;

		R = tempR;
		G = tempG;
		B = tempB;
	}

	result = (R<G) ? R : G;
	if(B < result) result = B;

	cout<<result;

	return 0;
}