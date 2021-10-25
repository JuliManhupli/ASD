//Вивести символи першого слова , яке починається на “a”.
#include <iostream>
#include <stdio.h>
using namespace std;
#define N 2061144
#define M 1

void iter(char l[]) {
    int k = 1;
    int i;
    for (i = 0; i < N && k!=0; i++) {
        if (l[i] == 'a' && k == 1) {
            for (; k; ++i) {
                cout << l[i];
                if (l[i] == ' ' || l[i] == '\n') {
                    k = 0;
                }
            }
        }
        else if (l[i] == ' ') {
            k = 1;
        }
        else {
            k = 2;
        }
    }
}

void rec(char l[], int k, int i) {
    if (i < N && k!=0) {
        if (l[i] == 'a' && k == 1) {
            for (; k; ++i) {
                cout<<l[i];
                if (l[i] == ' ' || l[i] == '\n') {
                    k = 0;
                }
            }
        }
        else if (l[i] == ' ') {
            k = 1;
        }
        else {
            k = 2;
        }
        i++;
        rec(l, k, i);
    }
}

int main() {
    char l[N];
    clock_t start, end;

    for (int s = 0; s < N; s++) {
        if (s % 5 == 0) {
            l[s] = ' ';
        }
        else {
            l[s] = 96 + rand() % 27;
        }
    }
/*
    cout<<"Итерационный алгоритм: \n";
    start = clock();
    for (int i = 0; i < M; i++) {
        iter(l);
    }
    end = clock();
    cout << "\nВремя итерационного алгоритма: " << (end - start) << endl;
*/
   cout<<"Рекурсивный алгоритм: \n";
    start = clock();
    for (int i = 0; i < M; i++) {
        rec(l, 1, 0);
    }
    end = clock();
    cout << "\nВремя рекурсивного алгоритма: " << (end - start) << endl;

    return 0;
}


