//2606 ���̷��� (DFS)
#include <stdio.h>

void dfs(int n);

int graph[101][101];	//��ǻ�� ���� ���� ������ķ� ǥ��
int visit[101];			// �湮 ����
int connect;
int com;
int count;

int main(void) {
	scanf("%d", &com);						// ��ǻ�� ����
	scanf("%d", &connect);					// ���� ����

	for (int i = 0; i < connect; i++) {		//������� �����
		int a, b;							
		scanf("%d", &a);
		scanf("%d", &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(1);									// 1�� ��ǻ�� ���̷��� 
	printf("%d", count);
	return 0;
}

void dfs(int n) {
	if (visit[n])							// ���� �Ӵ� ���� �ǳʶ�
		return;
		
	visit[n] = 1;							// ó�� ������ ǥ��
	for (int i = 1; i <= com; i++) {
		if (graph[n][i] == 1 && visit[i] == 0) {	// ����� �ִ� ��� �߿��� �湮 ���Ѱ� ã��
			count++;								// ã����
			dfs(i);									// ã������ �ű�� �Ѿ
		}
	}
	return;
}