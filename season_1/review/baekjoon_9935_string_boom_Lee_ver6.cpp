#include <iostream>
#include <string>

using namespace std;

/*
아이디어
str을 앞에서부터 하나씩 스택에 넣다가
boom의 마지막 문자와 일치하는 문자를 넣으면
뒤에서 boom의 길이만큼의 문자들을 boom의 문자와 하나하나 비교하여 전부 일치할시
그것들을 전부 pop한다 
*/
int main(){
	string str, boom, stack_str;
	cin>>str;
	cin>>boom;

	const int boom_length = boom.length();
	const int str_length = str.length();
	const char boom_last = boom[boom_length - 1];
	
	for(int i=0;i<str_length;i++){
		stack_str.push_back(str[i]);
		
		if(stack_str[stack_str.length()-1] == boom_last && (int)stack_str.length() >= boom_length){
			bool temp = true;//pop의 여부. 일단 true로 초기화 하고, 아래의 for문에서 boom과 일치하지 않음이 판명되면 false

			for(int i=0; i<boom_length;i++){
				if(stack_str[stack_str.length() - boom_length + i] != boom[i]){
					temp = false;
					break;
				}
			}

			if(temp){
				for(int i=0; i<boom_length;i++){ //boom_length번 pop하면된다
					stack_str.pop_back();
				}
			}
		}
	}

	if(stack_str.length()){
		cout<<stack_str<<endl;
	}else{
		cout<<"FRULA";
	}
	
	return 0;
}
