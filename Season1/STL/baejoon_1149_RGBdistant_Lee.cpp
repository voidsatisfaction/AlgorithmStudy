#include<iostream>

using namespace std;

/*
3
26 40 83
49 60 57
13 89 99
*/
int main(){
	int R=0, G=0, B=0, //현재 단계에서 빨강, 초록, 파랑을 칠할경우 최소비용
		tempR=0, tempG=0, tempB =0, //현재 입력받는 색칠 비용, 바뀔 R을 저장할 변수 두역할을 담당한다
		result = 0, //답
		n = 0; //집의 개수

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