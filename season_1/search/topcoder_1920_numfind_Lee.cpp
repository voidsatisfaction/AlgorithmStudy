#include <iostream>
#include <vector>

using namespace std;

/*�Է� ����
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
	vector<int> A; //Ž���� ����
	vector<int> B; //Ž���Ϸ��ϴ� ���� ����

	//�Է�
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
	//A�� B�� ������������ �����Ѵ�.
	//�̶� A�� �׳� �����ϵ�, B�� ������ �Է¼����� �˱����ؼ� ���� �۾��� �Ѵ�.
	vector<int> BOrder;//B_order : B�� �������Ŀ��� ���� ������ �˱� ���ؼ� ������ �����صδ� �迭 
	BOrder.resize(m);

	for(int i =0; i<m;i++){ //B_order �ʱ�ȭ
		BOrder[i] = i;
	}

	quicksort(A, 0, n-1);
	quicksort(B, BOrder, 0, m-1);
	//����, B[0]�� A�� ������ ���Һ��� ū��쿣 B�� A�� ���Ұ� �ϳ��� ���� ������ ���� 0�� ����ϰ� ���α׷��� �����Ų��
	if(B[0] > A[n-1]){
		for(int i=0;i<m;i++){
			cout<<"0 ";
		}
		return 0;
	}
	//A�� ����������(�ִ밪) ������ B�� �����߿� ���� ū���� ��°���� mMax��� �Ѵ�
	//B[mMax]������ ���ҵ��� A�� ��������� ���� ������ �ʿ���� ������ ���̱� ���� ���ϴ� ��
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

	//B[0]����B[mMax]������ �˻��Ѵ�
	//�켱 B�� ���� ���� ���� ������ vector<bool> Bexist[]�� �����ϰ� ��� false�� �ʱ�ȭ�Ѵ�
	//���� B[i]�� A[j]�� �־����� Bexist[i]�� true�� �ٲٰ�, B[i+1]�� �ٽ� A[j]���� �˻��Ѵ�

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

	//Bexist�� Borigin���� Bresult�� �����
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