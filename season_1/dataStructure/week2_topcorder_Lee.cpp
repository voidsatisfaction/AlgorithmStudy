  	
//class:	alienandhamburgers
//method:	getnumber
//parameters:	int[], int[]
//returns:	int
//method signature:	int getnumber(int[] type, int[] taste)
//(be sure your method is public)

#include <iostream>
#include <vector>

using namespace std;

#define HAMBURGER 3// �ܹ����� ���� �� == type,taste�� ���Ҽ�

class AlienAndHamburgers{
public:
	static int getnumber(int type[], int taste[]){
		//step1. type�� taste�� �����ϱ� ���ϰ� �����Ѵ�
		quicksort(type, taste, 0, (HAMBURGER) -1);

		//step2. type�� �ߺ��� ���� �ĳ���, �ʿ��� taste���� ���ؼ� ����� ziptaste�� �����
		vector<int> ziptaste; //������ ������ ���� �𸣰�, �ڿ��� �ϳ��� �������� ����̹Ƿ� vector
		zip(type, taste, ziptaste); 

		//step3. ziptaste�� ó������ ������ �Ⱦ 
		//       case1: ����� ������ positastenum(int, ��0)�� 1���ϰ� positasteadd(int, ��0)�� �� �����ŭ ���Ѵ�
		//		 case2: 0�̳� ������ ������ �װ��� negataste(����)�� push�Ѵ�
		int positastenum = 0, positasteadd = 0;
		vector<int> negataste;
		cout<<"ziptaste size :"<<ziptaste.size()<<endl;
		judgetaste(ziptaste, &positastenum, &positasteadd, negataste);

		//step4. �켱 negataste�� ������������ �����Ѵ� ex(-1, -2, -40, -60)
		//		 positastenum �� tasteadd�� ���� result�� �����Ѵ�
		//		 negataste�� �տ��� i�� ���Ѱ��� negatasteadd��� �ϰ�
		//		 (positastenum + i) * (positasteadd + negatasteadd) �� result���� ũ�� �̸� result�� �����Ѵ�
		//		 ���� �װ��� result���� �۾����� break
		//		 �̿Ͱ��� ������ ������ �ִ��� result�� ���ϰ�, �̸� �����Ѵ�
		int result = positastenum * positasteadd;
		if(negataste.size()>0){
			dessort(negataste, 0, (int)negataste.size() -1 );
		}
		calcresult(negataste, positastenum, positasteadd, &result);

		return result;
	}
private:
	/*
	������ ���� ���� �޼���
	*/
	static void swap(int* a, int* b){
		if(a != b){
			*a = *b - *a;
			*b = *b - *a;
			*a = *a + *b;
		}
	}
	/*
	�־��� �迭 arr�� ������������ �����ϰ�, arr2�� arr�� �Բ� ������ �ٲ۴�
	��,			0 1 2 3 ��° ����
		 array1 2 1 6 5
		 array2 0 2 7 1 �̶�� array1�� ��������

				1 0 3 2
		 array1 1 2 5 6
		 array2 2 0 1 7 �� �ٲٴ� �۾�

	����Ʈ�ʹ� swap������ ���� �ٸ���
	*/
	static void quicksort(int arr[], int arr2[], int left, int right){ //�̺κп� static�� ���� ������ ������ ����
		int i = left, j = right;
		int pivot = arr[(i+j)/2];

		while(i <= j){
			while(arr[i] < pivot)
				i++;
			while(arr[j] > pivot)
				j--;
			if(i <= j){ //swap arr[i] <-> arr[j], arr2[i] <-> arr2[j]
				
				swap(&arr[i], &arr[j]);
				swap(&arr2[i], &arr2[j]);

				i++, j--;
			}
		}
		if(left < j)
			quicksort(arr, arr2, left, j);
		if(i < right)
			quicksort(arr, arr2, i, right);
	}
	/*
	������ ������ type�� taste�� �ʿ��� ������ �̾� �����Ų��
	���� ���� type���� taste�� ���� 0���϶�� ���� ���� ū �� �ϳ����� �̾Ƴ���
	�׷��� �ʰ� type���� taste�� ��� �Ѱ��� ����� �ִٸ� ��� ����� ���ؼ� �̾Ƴ���
	�̾Ƴ� type�� taste�� ���ο� �迭�� ���� �ִ´�

	��,  type{1,2,2, 3,3,3, 4, 4}
		taste{0,1,7,-1,2,5,-1,-5}���

		 ziptype{1,  2,  3, 4} (�߰�: �̰� �ʿ����)
		ziptaste{0,1+7,2+5,-1} �� �����Ѵ�
	*/
	static void zip(int type[], int taste[], vector<int>& ziptaste){
		for(int i=0; i < HAMBURGER ; i++){
			if(type[i] != type[i-1] || i ==0){ // i�� 0�̰ų�, type�� ���ο� ���ڷ� �ٲ��
				ziptaste.push_back(taste[i]);  // ����� ���� �ϴ� ziptaste�� ����ִ´�
			}else{
				if(taste[i]>0){
					if(ziptaste.back()>0){
						ziptaste.back() += taste[i];
					}else{
						ziptaste.back() = taste[i];
					}
				}else{
					if(ziptaste.back() < taste[i]){
						ziptaste.back() = taste[i];
					}
				}
			}
		}
	}
	/*
	ziptaste�� �տ��� ���� �Ⱦ ����� ������ positastenum++, positasteadd + �׾��
	������ 0�� ������ negataste�� push

	������?!@$!@$
	*/
	static void judgetaste(vector<int>& ziptaste, int *positastenum, int *positasteadd, vector<int>& negataste){
		for(int i=0;i<(int)ziptaste.size();i++){
			if(ziptaste[i]>0){
				*positastenum += 1; //�̺κ��� positastenum++�� �ϸ� �۵����� �ʴ´�
				*positasteadd += ziptaste[i];
			}else{
				negataste.push_back(ziptaste[i]);
			}
		}
	}
	/*
	negataste�� ������������ ��Ʈ
	*/
	static void dessort(vector<int>& negataste, int left, int right){
		int i = left, j = right;
		int pivot = negataste[(i+j)/2];

		while(i <= j){
			while(negataste[i] > pivot)
				i++;
			while(negataste[j] < pivot)
				j--;
			if(i <= j){ 
				swap(&negataste[i], &negataste[j]);
				i++, j--;
			}
		}
		if(left < j)
			dessort(negataste, left, j);
		if(i < right)
			dessort(negataste, i, right);
	}
	/*
	negataste�� �տ��� i�� ���Ѱ��� negatasteadd��� �Ҷ�
	(positastenum + i) * (positasteadd + negatasteadd) �� result���� ũ�� �� ���� result�� ����
	�ƴϸ� break
	*/
	static void calcresult(vector<int> negataste, int positastenum, int positasteadd, int* result){
		int a = positastenum,
			b = positasteadd,
			negatastesum = 0,
			temp = 0;
		if(negataste.size() > 0){
			for(int i=0; i<(int)negataste.size(); i++){
				cout<<i<<endl;
				negatastesum += negataste[i];
				temp = (a + i + 1) * (b + negatastesum);
				if(*result < temp){
					*result = temp;
				}else{
					break;
				}
			}
		}
	}
};
int main(void){
	int type[HAMBURGER] = {30,20,10}; //�Է��� �ڵ忡. type�� taste�� ���Ҽ��� ������. �ִ� 50��, 1~100
	int	taste[HAMBURGER] = {100000,-100000, 100000};//�ִ� 50��, -100,000 ~ 100,000
	
	cout<<sizeof(type)/sizeof(int)<<endl;

	AlienAndHamburgers a;
	int b = a.getnumber(type, taste);
	cout<<b<<endl;

}