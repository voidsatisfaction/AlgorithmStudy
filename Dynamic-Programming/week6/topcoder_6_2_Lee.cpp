#include <iostream>

using namespace std;

int main(){
	//�߸��� �Է¹��? 
	//int secret[5001] = {0,}; //5000���� ��ȣ�� �͵� 5001��° �ڸ��� \0�� ���� �ϱ⶧���� 5001��
	//int result[5000] = {0,}; //result[n] : secret[0]����[n]������ �̷���� secret�� �κ������� �ؼ������� ������
	//char c;
	//int len=0; 
	//while((c=getchar()) != '\n'){
	//	secret[len] = c - 48;
	//	len++;
	//}

	//�Է�
	char secret[5001];
	int secret2[5001];
	int result[5000];
	cin>>secret;
	int len = 0;
	while(secret[len] != '\0'){
		secret2[len] = secret[len] - '0';
		len++;
	}
	
	// ���
	result[0] = 1;

	int temp1 = secret2[0]*10 + secret2[1];
	if(temp1 <= 26){
		if(secret2[1] == 0) result[1] = 1;
		else result[1] = 2;
	}else  result[1] = 1;

	for(int i=2;i<len;i++){
		int temp2 = secret2[i-1] *10 + secret2[i];
		if(temp2 <= 26 && temp2 >= 10){
			if(secret2[i] == 0) result[i] = result[i-2];
			else result[i] = result[i-2] + result[i-1];
		}else result[i] = result[i-1];

		if(result[i]>1000000) result[i] = result[i]%1000000;
	}
	
	//���
	cout<<result[len-1];
	return 0;
}