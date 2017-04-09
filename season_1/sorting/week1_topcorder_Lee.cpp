//class:	balancedsubstrings
//method:	countsubstrings
//parameters:	string
//returns:	int
//method signature:	int countsubstrings(string s)
//(be sure your method is public)

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class balancedsubstrings{
public:
	string input;
	int result;

	balancedsubstrings(string _input){
		_input = input;
		result = 0;
	}
	void countsubstrings(string s){
		unsigned int sl = s.length(); //여러번 하지 않아도 된다

		for(unsigned int i =1; i<sl+1; i++){//i : length of substring
			for(unsigned int j=0; j<sl-i+1; j++){//j: start point of substring	
				string temp; //s[j] ~ s[j+i-1]
				for(unsigned int k=j; k<j+i; k++){
					char tempchar = s[k];
					temp.push_back(tempchar);
				}
				if(checkbalanced(temp)){result++;}
			}
		}
	}

	bool checkbalanced(string s){
		float one_number = 0.0,//1이 들어있는 칸의 번호의 합
				one_ammount = 0.0;//1의 개수
		for(unsigned int i = 0; i<s.length(); i++){
			if(s[i]=='1'){one_number += i; one_ammount++;}
		}
		return(one_ammount == 0.0||checkint(one_number/one_ammount)) ? true : false;
	}

	bool checkint(float a){
		return (a - (int)a == 0) ? true : false;
	}
};

int main(void){
	clock_t begin, end;
	begin = clock();       //시간설정

	string inputstring = "100110001001"; //input in code 100110001001

	cout<<"inputstring: "<<inputstring<<endl;

	balancedsubstrings b(inputstring);
	b.countsubstrings(inputstring);

	cout<<"result: "<<b.result<<endl;

	end = clock();        // 시간설정
	cout<<"수행시간 : "<<(double(end-begin)/CLOCKS_PER_SEC)<<endl;

	return 0;
}