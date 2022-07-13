//15649 n과m (백트래킹 - DFS를 재귀로 구현)

#include <stdio.h>
#include <stdbool.h>

void Backtraking(int a);

int n, m;
int save[9];							// 전역으로 해놔서 재귀 돌면서 값 저장 하게 해놨음
bool visit[10];							// 전역으로 해놔서 재귀 돌면서 했던건지 안했던건지 구별

int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);
	
	Backtraking(0); // 맨 처음 위치
	return 0;
}

void Backtraking(int a) {
	if (a == m) {						// 맨 아래쪽 노드까지 도착
		for (int i = 0; i < m; i++) {
			printf("%d ", save[i]);		// 저장된 순서 출력 m개임
		}
		printf("\n");
	}
	else {								// 아직 탐색중
		for (int i = 1; i <= n; i++) {	// 자연수라서 1부터 시작임
			if (!visit[i]) {			// 처음왔음
				visit[i] = true;		// 왔다고 표시
				save[a] = i;			// 그리고 값 저장
				Backtraking(a + 1);		// 그 다음 노드로 들어감
				visit[i] = false;		// 다시 초기화 
			}	
		}	
	}
}