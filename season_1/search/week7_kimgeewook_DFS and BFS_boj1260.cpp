#include <cstdio>	
#include <queue>
#include <cstring>
using namespace std;
int n,m,v,tmp1,tmp2,linked[1001][1001]={{0}},visited[1001]={0};
queue<int> q;
void DFS(int v){
	visited[v] = 1;
	for(int i  = 1;i <= n;i++){
		if(linked[v][i] && !visited[i]){
			printf("%d ",i); 
			DFS(i);
		};
	};
};
void BFS(int v){
	visited[v] = 1;
	q.push(v);
	while(!q.empty()){
		tmp1 = q.front();
		q.pop();
		for(int i  = 1;i <= n;i++){
			if(linked[tmp1][i] && !visited[i]){
				visited[i] = 1;
				printf("%d ",i); 
				q.push(i);
			};
		};
	};
};
int main(){
	scanf("%d %d %d",&n,&m,&v); 
	for(int i = 1;i <= m;i++){
		scanf("%d %d",&tmp1,&tmp2); 
		linked[tmp1][tmp2] = linked[tmp2][tmp1] = 1;
	};
	printf("%d ",v); 
	DFS(v);
	printf("\n");    
	memset(visited,0,sizeof(visited));
	printf("%d ",v);
	BFS(v);
	return 0;
}