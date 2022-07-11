//9663 N-Queen (백트래킹)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Backtracking(int row);
bool Pruning(int row);

int n;
int col[16];
int temp = 0;


int main(void) {
	scanf("%d", &n);								// 체스판 크기

	for (int i = 0; i < n; i++) {					//(0,0),(0,1)...(0,15)
		col[0] = i;									// 퀸의 시작점 - 행
		Backtracking(1);							// 탐색시작 
	}
	printf("%d", temp);
	return 0;
}

void Backtracking(int row) {	
	if (row < n) {									
		for (int i = 0; i < n; i++) {				// 열 돌리기
			col[row] = i;							// 좌표일단 저장 i = 행 row = 열

			if (Pruning(row)) {						// 유망한 노드는 다음거 탐색
				Backtracking(row + 1);
			}
			else {									// 짤렸으면 다시 초기화
				col[row] = 0;
			}
		}
	}
	else {											// 체스판 크기 넘어가면 노드탐색 완료 된거니까 경우의수 +1
		temp++;										
	}
	
}
		
bool Pruning(int row) {							// 유망하지 않은 노드 가지치기
	for (int i = 0; i < row; i++) {
		if (col[i] == col[row])					// 열 검사
			return false;
		if (abs(col[i] - col[row]) == abs(i - row))  // 대각선 검사 - 가로 세로 차이의 절대값이 같으면 대각선임 
			return false;
	}
	return true;
}