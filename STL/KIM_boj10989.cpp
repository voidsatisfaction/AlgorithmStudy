#include <cstdio>
int main(){
	int n, tmp, tail = 0,array[10001] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf(" %d",&tmp);
		array[tmp]++;
		tail = (tail < tmp) ? tmp : tail;
	}
	for(int i = 1; i <= tail; i++){
		for(int j = 0; j < array[i]; j++){
			printf("%d\n", i);
		}
	}
	return 0;
}
