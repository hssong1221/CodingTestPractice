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
	else cout << "casting failed" << endl; // 부모에 부모를 넣는다

	p = dynamic_cast<Parent*>(&child);
	if (p) p->print();
	else cout << "casting failed" << endl; // 자식을 부모에 넣는다 업캐스팅

	//c = dynamic_cast<Child*>(&parent);
	//if (c) c->print();
	//else cout << "casting failed" << endl; // 부모를 자식에 넣는다 다운 캐스팅

	//c = dynamic_cast<Child*>(p);
	//if (c) c->print();
	//else cout << "casting failed" << endl; // 부모를 자식에 넣는건데 p는 위에서 업캐스팅 당해서 자식을 가르키게 된거라 어쨌든 됨

	return 0;
}

