//Знайти в списку (масиву) найбільшу послідовність непарних чисел
#include <iostream>
#include <ctime>
using namespace std;
#define N 10
#define M 1

class list{
public:
    int x;
    list *next;
    list *prev;
};

void add(int n, list **lst) {
    list *t = new list;
    t->x = n;
    t->prev = NULL;
    t->next = (*lst);
    if ((*lst) != NULL){
       (*lst)->prev = t;
    }
    (*lst) = t;
}

void show(list *lst){
    while (lst != NULL){
        cout << lst->x << " ";
        lst = lst->next;
    }
    cout << endl;
}

void fun_list(list *lst) {
    int max = 0, i = 0;
    while (lst != NULL) {
        if (lst->x % 2 == 1) {
            i++;
        }
        else {
            i = 0;
        }
        if (i > max) {
            max = i;
        }
        lst = lst->next;
    }
    cout << max << endl;
}

void fun_arr(int *arr) {
    int max = 0, i = 0;
    for (int s = 0; s < N; s++) {
        if (arr[s] % 2 == 1){
            i++;
        }
        else {
            i = 0;
        }
        if (i > max) {
            max = i;
        }
    }
    cout << max << endl;
}

int main(){
    int arr[N];
    list *lst = NULL;
    clock_t start, end;

    for (int i = 0; i < N; i++) {
        arr[i] =  rand() % 101;
        add(arr[i], &lst);
    }

    start = clock();
    for (int i = 0; i < M; i++) {
      fun_arr(arr);
    }
    end = clock();
    cout << "Время работы с массивом: " << (end - start) << endl;
    show(lst);
    start = clock();
    for (int i = 0; i < M; i++) {
        fun_list(lst);
    }
    end = clock();
    cout << "Время работы с DLL: " << (end - start) << endl;

    return 0;
}