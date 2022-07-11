#include <iostream>
#include <string>
#include <vector>

using namespace std;

void recursion(int num, int cnt) {
	string temp = "____";

	for (int i = 0; i < cnt; i++)
		cout << temp;
	cout << "\"����Լ��� ������?\" " << "\n";

	if (num == 0) {
		for (int i = 0; i < cnt; i++)
			cout << temp;
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		for (int i = 0; i < cnt; i++)
			cout << temp;
		cout << "��� �亯�Ͽ���." << "\n";
		return;
	}
	
	for (int i = 0; i < cnt; i++)
		cout << temp;
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
	for (int i = 0; i < cnt; i++)
		cout << temp;
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
	for (int i = 0; i < cnt; i++)
		cout << temp;
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
	
	recursion(num - 1, cnt + 1);

	for (int i = 0; i < cnt; i++)
		cout << temp;
	cout << "��� �亯�Ͽ���." << "\n";
}

int main() {
	//�Է�
	int num;
	cin >> num;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";

	recursion(num, 0);
	return 0;
}

