#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define CASES 2 // 테스트 케이스의 개수

string decode(string* strx);
void inputTst(vector<string>& testcase);

int main(){

	//미리 코드에서 testcase를 입력받는 방법
	//string testcase[CASES];
	//testcase[0] = "<<BP<A>>Cd-"; //BPAC
	//testcase[1] = "<><><><><><><><dd-f-ggg-<<<34"; //34dgg

	//string password[CASES]; // 테스트케이스를 가공해서 집어넣는 문자열의 배열

	//for(int i=0; i<CASES; i++){
	//	password[i] = decode(&testcase[i]);//testcase[i]를 해석해서 password[i]에 집어넣는다
	//	cout<<"testcase["<<i<<"] :"<<testcase[i]<<endl;
	//	cout<<"password["<<i<<"] :"<<password[i]<<endl;
	//}
	vector<string> testcase;
	inputTst(testcase);//cases의 개수

	for(int i = 0; i<(int)testcase.size(); i++){
		cout<<"testcase["<<i<<"] : "<<testcase[i]<<endl;
		cout<<"password : "<<decode(&testcase[i])<<endl;
	}
}

void inputTst(vector<string>& testcase){
	cout<<"Input only A BLANK(space) to end input process"<<endl<<endl;
	while(1){
		string temp;
		getline(cin, temp); //문자열을 입력받는 방법.
		if(temp == " ") break;
		testcase.push_back(temp);
	}
}

string decode(string* str){ //str을 올바른 형태로 바꾸어 리턴한다

	//cout<<str<<endl; str이 저장된 메모리주소
	//cout<<*str<<endl; str의 값
	//cout<<*str[0]<<endl; str의 첫번째값(str은 문자로 이루어진 배열이므로) ??간접 참조가 잘못되었습니다??

	int corsor = 0; //커서의 위치. 맨왼쪽이 0. n번째 글자의 오른쪽이 n번째 커서
	string result; //새로 만들 해석된 str
	string a = *str;

	for(unsigned int i=0;i<a.length();i++){
		switch(a[i]){
		case 60 : // < == 60
			if(corsor != 0){
				corsor--;
			}
			break;
		case 62 : // > == 62 
			if(corsor != result.length()){
				corsor++;
			}
			break;
		case 45 : // - == 45
			if(corsor != 0){
				result.erase(corsor-1,1);
				corsor--;
			}
			break;
		default : // 그외의 문자
			string temp = a.substr(i,1);//insert함수는 문자열을 받는다
			result.insert(corsor, temp);
			corsor++;
			break;
		}
	}
	return result;
}

