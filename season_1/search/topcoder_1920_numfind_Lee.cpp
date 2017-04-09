#include <iostream>
#include <vector>

using namespace std;

/*입력 예제
5
4 1 5 2 3
5 
1 3 7 9 6
*/
void swap(int* a, int* b){
	if(a != b){
		*a = *b - *a;
		*b = *b - *a;
		*a = *a + *b;
	}
} // ok
void quicksort(vector<int>& vec, int left, int right){ 
		int i = left, j = right;
		int pivot = vec[(i+j)/2];
		while(i <= j){
			while(vec[i] < pivot)
				i++;
			while(vec[j] > pivot)
				j--;
			if(i <= j){ 
				swap(&vec[i], &vec[j]);
				i++, j--;
			}
		}
		if(left < j)
			quicksort(vec, left, j);
		if(i < right)
			quicksort(vec, i, right);
	}
void quicksort(vector<int>& vec, vector<int>& ori, int left, int right){ 
		int i = left, j = right;
		int pivot = vec[(i+j)/2];
		while(i <= j){
			while(vec[i] < pivot)
				i++;
			while(vec[j] > pivot)
				j--;
			if(i <= j){ 
				swap(&vec[i], &vec[j]);
				swap(&ori[i], &ori[j]);
				i++, j--;
			}
		}
		if(left < j)
			quicksort(vec, ori, left, j);
		if(i < right)
			quicksort(vec, ori, i, right);
	}
int main(){
	int n=0,m=0;
	vector<int> A; //탐색할 벡터
	vector<int> B; //탐색하려하는 수의 벡터

	//입력
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		A.push_back(temp);
	}

	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		B.push_back(temp);
	}
	//A와 B를 오름차순으로 정리한다.
	//이때 A는 그냥 정렬하되, B는 본래의 입력순서를 알기위해서 따로 작업을 한다.
	vector<int> BOrder;//B_order : B를 정렬한후에도 원래 순서를 알기 위해서 순서를 저장해두는 배열 
	BOrder.resize(m);

	for(int i =0; i<m;i++){ //B_order 초기화
		BOrder[i] = i;
	}

	quicksort(A, 0, n-1);
	quicksort(B, BOrder, 0, m-1);
	//만약, B[0]가 A의 마지막 원소보다 큰경우엔 B에 A의 원소가 하나도 없기 때문에 전부 0을 출력하고 프로그램을 종료시킨다
	if(B[0] > A[n-1]){
		for(int i=0;i<m;i++){
			cout<<"0 ";
		}
		return 0;
	}
	//A의 마지막원소(최대값) 이하의 B의 원소중에 가장 큰것의 번째수를 mMax라고 한다
	//B[mMax]이후의 원소들은 A에 들어있을수 없기 때문에 필요없는 연산을 줄이기 위해 구하는 것
	int mMax = 0;

	if(B[m-1] <= A[n-1]){
		mMax = m-1;
	}else{
		int left = 0,
			right =(m-1),
			result = (left + right)/2;

		while(!((B[result]<=A[n-1])&&(B[result+1]>A[n-1]))){
			if(B[result] <= A[n-1]){
				left = result;
				result = (left + right)/2;
			}else{
				right = result;
				result = (left + right)/2;
			}
		}

		mMax = result;
	}

	//B[0]부터B[mMax]까지를 검사한다
	//우선 B와 같은 원소 수를 가지는 vector<bool> Bexist[]를 생성하고 모두 false로 초기화한다
	//만약 B[i]가 A[j]에 있었으면 Bexist[i]를 true로 바꾸고, B[i+1]을 다시 A[j]부터 검사한다

	vector<bool> Bexist;
	Bexist.resize(m);

	for(int i =0;i<m;i++){
		Bexist[i] = false;
	}

	int j =0;
	for(int i =0;i<=mMax;i++){
		while(1){
			if(B[i] == A[j]){
				Bexist[i] = true;
				break;
			}else if(B[i] < A[j]){
				//Bexist[i] = false;
				break;
			}else{
				j++;
			}
		}
	}

	//Bexist와 Borigin으로 Bresult를 만든다
	vector<bool> Bresult;
	Bresult.resize(m);

	for(int i=0; i<m; i++){
		int temp = BOrder[i];
		Bresult[temp] = Bexist[i];
	}

	for(int i=0; i<m;i++){
		if(Bresult[i]) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}

	return 0;
}