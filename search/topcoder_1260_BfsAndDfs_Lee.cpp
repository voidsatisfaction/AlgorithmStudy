#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
4 5 1
1 2
1 3
1 4
2 4
3 4

6 8 1
1 2
1 3
2 4
2 5
4 5
4 6
5 6
6 3
*/

int nodes, //노드의 개수
	lines; //간선의 개수
vector<int> gra[1001]; //인접 리스트를 저장할 벡터배열. gra[a]엔 a의 값을가진 노드가 연결된 노드의 값들이 저장됨. gra[0]은 자연적으로 빔
bool visited[1001] = {false};//dfs시 방문한 점을 저장하는 배열. visit[a]를 방문 했다면 true, 아니면 false;

void dfs(int here){
	visited[here] = true;
	cout<<here<<" ";

	for(int i=0;i<gra[here].size();i++){
		int next=gra[here][i];
		if(!visited[next]){
			dfs(next);
		}
	}
};

void bfs(int start){
	int* q = new int[nodes+1];
	int head=0,tail=0;

	visited[start] = true;
	q[tail++] = start;
	while(head<tail){
		for(int i=head;i<tail;i++){
			for(int j=0; j<gra[i+1].size();j++){
				if(!(visited[gra[i+1][j]])){
					visited[gra[i+1][j]] = true;
					q[tail++]=gra[i+1][j];
				}
			}
			cout<<q[head++]<<" ";
		}
	}

	delete[] q;
};

int main(){
	int start;//탐색을 시작하는 노드

	scanf("%d%d%d", &nodes,&lines,&start);

	//인접리스트 생성
    for (int i = 0; i<lines; i++) { 
        int node1, node2;
        scanf("%d %d", &node1, &node2);
		if(find(gra[node1].begin(), gra[node1].end(), node2) == gra[node1].end()){ //중복된 간선이 입력되었을때 이를 거르는 조건식
			gra[node1].push_back(node2); 
			gra[node2].push_back(node1);
		}
	}

	//인접 리스트 생성 체크
	//for(int i=0;i<=nodes;i++){
	//	vector<int>::iterator a;
	//	cout<<"gra["<<i<<"] 의 원소: ";
	//	for(a = gra[i].begin() ; a != gra[i].end() ; ++a){
	//		cout<<*a<<" ";
	//	}
	//	cout<<endl;
	//}

	dfs(start);

	cout<<endl;

	for(int i=0;i<=nodes;i++){
		if(visited[i] ==true) visited[i] = false;
	}

	bfs(start);

	return 0;
}