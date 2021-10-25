//Створити стек цілих чисел. Видалити максимальний елемент серед від’ємних чисел.

#include<iostream>
using namespace std;
#define SIZE 10
class list {
public:
	int x;
	list *next;
};

class stack {
	list *tos;
public:
	stack(){ tos = NULL; }
	void push(int i);
	int pop();
	friend void print(stack obj);
};

void stack::push(int i){
	list *p = new list;
	p->x = i;
	p->next = tos;
	tos = p;
}

int stack::pop() {
	if (tos == NULL) {
		cout << "Stack is empty\n";
		return 0;
	}
	list *p = tos;
	int n = tos->x;
	tos = tos->next;
	delete p;
	return n;
}

void print(stack obj){
	list *p = obj.tos;
	while (p!=NULL){
		cout << p->x << " ";
		p = p->next;
	}
	cout << endl;
}

int main(){
	srand(time(0));
	stack lst1, lst2;
	int a, b, max = -51;

	for (int i = 0; i < SIZE; i++) {
		a = rand() % 100 - 50;
		lst1.push(a);
	}
	print(lst1);

	for (int i = 0; i < SIZE; i++) {
		a = lst1.pop();
		if (a<0 && a>max) {
			b = i;
			max = a;
		}
		lst2.push(a);
	}
	for (int i = 0; i < SIZE; i++) {
		a = lst2.pop();
		if (i != SIZE - b - 1) {
			lst1.push(a);
		}
	}

	print(lst1);
	return 0;
}