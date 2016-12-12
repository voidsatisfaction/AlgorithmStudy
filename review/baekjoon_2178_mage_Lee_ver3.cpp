#include <iostream>
#include <queue>

using namespace std;

int mage[100][100] = {{0}},
	width = 0,
	height = 0,
	answer = 0;
queue<int> que; //저장된 int를 100으로 나눈 몫을 i, 나머지를 j라고하면, 이는 mage[i][j]를 의미한다

int main(void){

	cin>>height>>width;

	for(int i =0;i<height;i++){
		for(int j=0;j<width;j++){
			do{
				mage[i][j] = getchar() - '0';
			}while(mage[i][j] == -38);
		}
	}

	//일단 큐에 mage[0][0]을 집어넣기. 실제로는 (0*100 + 0) = 0의 형태로 집어넣는다
	que.push(0);
	mage[0][0] = 0;

	bool breakloop = false; //true가 되면 아래의 while는 더이상 돌지 않는다 
	while(!(que.empty()) && (!breakloop)){ //que가 빌때까지 bfs OR 마지막점에 도달했을때
		answer ++;
		int qsize = que.size();

		for(int i=0; i<qsize; i++){
			int y = que.front() / 100,
				x = que.front() % 100;

			if((y == height -1)&&(x == width-1)){
				breakloop = true;
				break;
			}
			//위를 체크
				if((y>0)&&(mage[y-1][x] ==1)){
					que.push((y-1)*100 + x);
					mage[y-1][x] = 0;
				}
			//아래를 체크
				if((y<height-1)&&(mage[y+1][x] ==1)){
					que.push((y+1)*100 + x);
					mage[y+1][x] = 0;
				}
			//왼쪽을 체크
				if((x>0)&&(mage[y][x-1] ==1)){
					que.push(y*100 + (x-1));
					mage[y][x-1] = 0;
				}
			//오른쪽을 체크
				if((x<width-1)&&(mage[y][x+1] ==1)){
					que.push(y*100 + (x+1));
					mage[y][x+1] = 0;				
				}
			que.pop();
		}
	}

	cout<<answer;

	return 0;
}
