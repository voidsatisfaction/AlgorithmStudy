#include <stdio.h>
//ī���� ��-Ʈ
int main(){

	int n = 0, // �Է¹޴� ���� ����
		input = 0, //�Ź� �Է¹޴� ��
		max = 0; //�Է¹��� �� �߿� ���� ū��
	int count[10001] = {0}; //count[i] : i�� �Է¹��� Ƚ��

    scanf(" %d", &n);

	for(int i=0; i<n; i++){
		scanf(" %d",&input);
		count[input]++;

		if(input>max) max = input;
	}

	for(int i=1; i<=max; i++){
		for(int j =0; j<count[i] ; j++){
			printf("%d\n", i);
		}
	}

	return 0;
}