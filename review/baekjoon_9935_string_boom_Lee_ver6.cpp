#include <iostream>
#include <string>

using namespace std;

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
			bool temp = true;//pop�� ����. �ϴ� true�� �ʱ�ȭ �ϰ�, �Ʒ��� for������ boom�� ��ġ���� ������ �Ǹ�Ǹ� false

			for(int i=0; i<boom_length;i++){
				if(stack_str[stack_str.length() - boom_length + i] != boom[i]){
					temp = false;
					break;
				}
			}

			if(temp){
				for(int i=0; i<boom_length;i++){ //boom_length�� pop�ϸ�ȴ�
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