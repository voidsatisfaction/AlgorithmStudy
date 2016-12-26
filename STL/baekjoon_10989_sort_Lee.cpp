#include <stdio.h>
//카운팅 소-트
int main(){

	int n = 0, // 입력받는 수의 개수
		input = 0, //매번 입력받는 수
		max = 0; //입력받은 수 중에 가장 큰수
	int count[10001] = {0}; //count[i] : i가 입력받은 횟수

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