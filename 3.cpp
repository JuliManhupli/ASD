#include <iostream>
#include <ctime>
using namespace std;
#define N 5000
#define M 500

void mergesort(int a[], int left, int right);
void merge(int a[], int left, int m, int right);

/*void radixsort(int a[], int num);
int getmax(int a[], int num);
void countsort(int a[], int num, int place);*/

int main() {
	clock_t start, end;
	int arr[N];

	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}
	start = clock();
	for (int i = 0; i < M; i++) {
		mergesort(arr, 0, N - 1);
		//radixsort(arr, N);
	}
	end = clock();
	cout << "Отсортированый по возрастанию: " << (end - start) << endl;

	for (int i = 0; i < N; i++) {
		arr[i] = N - i - 1;
	}
	start = clock();
	for (int i = 0; i < M; i++) {
		mergesort(arr, 0, N - 1);
		//radixsort(arr, N);
	}
	end = clock();
	cout << "Отсортированый по убыванию: " << (end - start) << endl;

	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}
	start = clock();
	for (int i = 0; i < M; i++) {
		mergesort(arr, 0, N - 1);
		//radixsort(arr, N);
	}
	end = clock();
	cout << "Случайный набор данных: " << (end - start) << endl;

	return 0;
}

//Сортировка слиянием
void mergesort(int a[], int left, int right) {
	if (left >= right) {
		return;
	}
	int m = left + (right - left) / 2;
	mergesort(a, left, m);
	mergesort(a, m + 1, right);
	merge(a, left, m, right);
}

void merge(int a[], int left, int m, int right) {
	int n1 = m - left + 1;
	int n2 = right - m;
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = a[m + 1 + j];
	}

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}


/*
//Поразрядная сортировка
void radixsort(int a[], int num) {
	int max = getmax(a, num);
	for (int place = 1; max / place > 0; place *= 10){
		countsort(a, num, place);
	}
}

int getmax(int a[], int num) {
	int max = a[0];
	for (int i = 1; i < num; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}


void countsort(int a[], int num, int place) {
	const int max = 10;
	int b[num];
	int c[max];
	for (int i = 0; i < max; ++i) {
		c[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		c[(a[i] / place) % 10]++;
	}
	for (int i = 1; i < max; i++) {
		c[i] += c[i - 1];
	}
	for (int i = num - 1; i >= 0; i--) {
		b[c[(a[i] / place) % 10] - 1] = a[i];
		c[(a[i] / place) % 10]--;
	}
	for (int i = 0; i < num; i++) {
		a[i] = b[i];
	}
}*/

