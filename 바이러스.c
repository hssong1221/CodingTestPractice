//2606 바이러스 (DFS)
#include <stdio.h>

void dfs(int n);

int graph[101][101];	//컴퓨터 연결 상태 인접행렬로 표시
int visit[101];			// 방문 여부
int connect;
int com;
int count;

int main(void) {
	scanf("%d", &com);						// 컴퓨터 갯수
	scanf("%d", &connect);					// 간선 갯수

	for (int i = 0; i < connect; i++) {		//인접행렬 만들기
		int a, b;							
		scanf("%d", &a);
		scanf("%d", &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(1);									// 1번 컴퓨터 바이러스 
	printf("%d", count);
	return 0;
}

void dfs(int n) {
	if (visit[n])							// 전에 왓던 노드면 건너뜀
		return;
		
	visit[n] = 1;							// 처음 왔으면 표시
	for (int i = 1; i <= com; i++) {
		if (graph[n][i] == 1 && visit[i] == 0) {	// 연결되 있는 노드 중에서 방문 안한곳 찾기
			count++;								// 찾았음
			dfs(i);									// 찾았으면 거기로 넘어감
		}
	}
	return;
}