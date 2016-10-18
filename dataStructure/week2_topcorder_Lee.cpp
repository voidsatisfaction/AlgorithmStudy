  	
//class:	alienandhamburgers
//method:	getnumber
//parameters:	int[], int[]
//returns:	int
//method signature:	int getnumber(int[] type, int[] taste)
//(be sure your method is public)

#include <iostream>
#include <vector>

using namespace std;

#define HAMBURGER 3// 햄버거의 종류 수 == type,taste의 원소수

class AlienAndHamburgers{
public:
	static int getnumber(int type[], int taste[]){
		//step1. type와 taste를 가공하기 편하게 정렬한다
		quicksort(type, taste, 0, (HAMBURGER) -1);

		//step2. type의 중복된 값을 쳐내고, 필요한 taste만을 더해서 압축된 ziptaste를 만든다
		vector<int> ziptaste; //원소의 개수를 아직 모르고, 뒤에서 하나씩 더해지는 방식이므로 vector
		zip(type, taste, ziptaste); 

		//step3. ziptaste를 처음부터 끝까지 훑어서 
		//       case1: 양수가 나오면 positastenum(int, 초0)를 1더하고 positasteadd(int, 초0)를 그 양수만큼 더한다
		//		 case2: 0이나 음수가 나오면 그값을 negataste(벡터)에 push한다
		int positastenum = 0, positasteadd = 0;
		vector<int> negataste;
		cout<<"ziptaste size :"<<ziptaste.size()<<endl;
		judgetaste(ziptaste, &positastenum, &positasteadd, negataste);

		//step4. 우선 negataste를 내림차순으로 정렬한다 ex(-1, -2, -40, -60)
		//		 positastenum 과 tasteadd의 곱을 result로 저장한다
		//		 negataste를 앞에서 i개 더한것을 negatasteadd라고 하고
		//		 (positastenum + i) * (positasteadd + negatasteadd) 가 result보다 크면 이를 result에 저장한다
		//		 만일 그것이 result보다 작아지면 break
		//		 이와같은 루프를 돌려서 최대의 result를 구하고, 이를 리턴한다
		int result = positastenum * positasteadd;
		if(negataste.size()>0){
			dessort(negataste, 0, (int)negataste.size() -1 );
		}
		calcresult(negataste, positastenum, positasteadd, &result);

		return result;
	}
private:
	/*
	정렬을 위한 스왑 메서드
	*/
	static void swap(int* a, int* b){
		if(a != b){
			*a = *b - *a;
			*b = *b - *a;
			*a = *a + *b;
		}
	}
	/*
	주어진 배열 arr를 오름차순으로 정렬하고, arr2는 arr와 함께 순서를 바꾼다
	즉,			0 1 2 3 번째 원소
		 array1 2 1 6 5
		 array2 0 2 7 1 이라면 array1을 정렬한후

				1 0 3 2
		 array1 1 2 5 6
		 array2 2 0 1 7 로 바꾸는 작업

	퀵소트와는 swap과정이 조금 다르다
	*/
	static void quicksort(int arr[], int arr2[], int left, int right){ //이부분에 static을 때면 위에서 에러가 난다
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
	위에서 정렬한 type와 taste를 필요한 정보만 뽑아 압축시킨다
	만일 같은 type안의 taste가 전부 0이하라면 그중 가장 큰 수 하나만을 뽑아낸다
	그렇지 않고 type안의 taste에 적어도 한개의 양수가 있다면 모든 양수를 더해서 뽑아낸다
	뽑아낸 type와 taste를 새로운 배열에 집어 넣는다

	즉,  type{1,2,2, 3,3,3, 4, 4}
		taste{0,1,7,-1,2,5,-1,-5}라면

		 ziptype{1,  2,  3, 4} (추가: 이건 필요없다)
		ziptaste{0,1+7,2+5,-1} 로 저장한다
	*/
	static void zip(int type[], int taste[], vector<int>& ziptaste){
		for(int i=0; i < HAMBURGER ; i++){
			if(type[i] != type[i-1] || i ==0){ // i가 0이거나, type가 새로운 숫자로 바뀌면
				ziptaste.push_back(taste[i]);  // 어떤수가 오던 일단 ziptaste에 집어넣는다
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
	ziptaste를 앞에서 부터 훑어서 양수가 나오면 positastenum++, positasteadd + 그양수
	음수나 0이 나오면 negataste에 push

	에러남?!@$!@$
	*/
	static void judgetaste(vector<int>& ziptaste, int *positastenum, int *positasteadd, vector<int>& negataste){
		for(int i=0;i<(int)ziptaste.size();i++){
			if(ziptaste[i]>0){
				*positastenum += 1; //이부분을 positastenum++로 하면 작동하지 않는다
				*positasteadd += ziptaste[i];
			}else{
				negataste.push_back(ziptaste[i]);
			}
		}
	}
	/*
	negataste를 내림차순으로 소트
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
	negataste를 앞에서 i개 더한것을 negatasteadd라고 할때
	(positastenum + i) * (positasteadd + negatasteadd) 가 result보다 크면 그 값을 result에 저장
	아니면 break
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
	int type[HAMBURGER] = {30,20,10}; //입력은 코드에. type와 taste의 원소수는 같도록. 최대 50개, 1~100
	int	taste[HAMBURGER] = {100000,-100000, 100000};//최대 50개, -100,000 ~ 100,000
	
	cout<<sizeof(type)/sizeof(int)<<endl;

	AlienAndHamburgers a;
	int b = a.getnumber(type, taste);
	cout<<b<<endl;

}