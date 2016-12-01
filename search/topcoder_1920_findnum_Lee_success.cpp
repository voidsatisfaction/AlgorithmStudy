#include <algorithm>

using namespace std;

void search(int data[], int n, int findnum){ //n개의 원소를 가지는 data배열에서 findnum이 있으면 true, 없으면 false
	int left = 0,
		right = n-1,
		here = (left + right) / 2;
	while(true){
		if(data[here] == findnum || data[here + 1] == findnum){
			printf("1 ");
			break;
		}else if(left == here){
			printf("0 ");
			break;
		}else if(data[here] < findnum){
			left = here;
			here = (left + right) /2;
		}else{
			right = here;
			here = (left + right) /2;
		}
	}
}

int main(){
	int n=0,m=0,temp=0;

	scanf(" %d",&n);
	int* A = new int[n];
	for(int i=0;i<n;i++){
		scanf(" %d", &temp);
		A[i] = temp;
	}

	sort(A, A+n);

	scanf(" %d", &m);
	for(int i=0;i<m;i++){
		scanf(" %d",&temp);
		search(A, n, temp);
	}

	delete A;
	return 0;
}