//Створити стек цілих чисел. Видалити максимальний елемент серед від’ємних чисел.

#include<iostream>
using namespace std;
#define SIZE 10
class stack {
	int stck[SIZE];
	int tos;
public:
	stack() { tos = 0; }
	void push(int i);
	int pop();
};

void stack::push(int i) {
	if (tos == SIZE) {
		cout << "Stack is full\n";
	}
	else {
		stck[tos] = i;
		tos++;
	}
}

int stack::pop() {
	if (tos == 0) {
		cout << "Stack is empty\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

void print(stack obj) {
	for (int i = 0; i < SIZE; i++) {
		cout << obj.pop() << " ";
	}
	cout << endl;
}

int main() {
	srand(time(0));
	int a, b, max = -51;
	stack obj1, obj2;

	for (int i = 0; i < SIZE; i++) {
		a = rand() % 100 - 50;
		obj1.push(a);
	}
	print(obj1);

	for (int i = 0; i < SIZE; i++) {
		a = obj1.pop();
		if (a<0 && a>max) {
			b = i;
			max = a;
		}
		obj2.push(a);
	}
	for (int i = 0; i < SIZE; i++) {
		a = obj2.pop();
		if (i != SIZE - b - 1) {
			obj1.push(a);
		}
	}

	print(obj1);
	return 0;
}