//Вивести перше входження літер у текст, зберігаючи їх взаємний порядок.
#include <iostream>
#include <ctype.h>
using namespace std;
#define N 100
#define M 26

void task(char a[], char b[]){
	int j=0;
	bool p;
	b[j]='\0';
	for (int i=0; a[i]!='\0'; i++){
		p = true;
		for (int k=0; b[k]!= '\0'; k++){
			if (a[i]==b[k] || a[i]==b[k]-32 || a[i]==b[k]+32){
				p=false;
			}
		}
		if(p && isalpha(a[i])){
			b[j]=a[i];
			j++;
			b[j]='\0';
		}
	}
	cout<<"Ответ: "<<b;
}

int main(){
	char a[N], b[M];
	cout<<"Введите массив: ";
	cin.get(a, N);
	task(a, b);
	return 0;
}