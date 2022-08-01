#include <iostream>

using namespace std;

class Parent {
public:
	virtual void print() { cout << "PARENT" << endl; }
};



class Child : public Parent {
public:
	void print() { cout << "CHILD" << endl; }
};

int main() {
	Parent parent, * p;
	Child child, * c;

	p = dynamic_cast<Parent*>(&parent);
	if (p) p->print();
	else cout << "casting failed" << endl; // �θ� �θ� �ִ´�

	p = dynamic_cast<Parent*>(&child);
	if (p) p->print();
	else cout << "casting failed" << endl; // �ڽ��� �θ� �ִ´� ��ĳ����

	//c = dynamic_cast<Child*>(&parent);
	//if (c) c->print();
	//else cout << "casting failed" << endl; // �θ� �ڽĿ� �ִ´� �ٿ� ĳ����

	//c = dynamic_cast<Child*>(p);
	//if (c) c->print();
	//else cout << "casting failed" << endl; // �θ� �ڽĿ� �ִ°ǵ� p�� ������ ��ĳ���� ���ؼ� �ڽ��� ����Ű�� �ȰŶ� ��·�� ��

	return 0;
}

