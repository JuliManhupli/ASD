/* Дано послідовність, що містить від 2 до 50 слів, у кожному з яких від 1
до 8 рядкових латинських букв; між сусідніми словами - не менш одного
пробілу, за останнім словом - крапка.
Надрукувати ті слова послідовності, які
відмінні від першого слова й задовольняють наступній властивості:
букви слова впорядковані за алфавітом */

#include <iostream>
#include <ctype.h>
#include <cstring>
using namespace std;
#define N 500

bool f1(char* s, char* f);
bool f2(char* s);
void print(char* s);

int main() {
    char s[N];
    char f[9];
    int i = 0;
    cout << "Введите строку:" << endl;
    cin.get(s, N);

    while (s[i] != ' ') {
        f[i] = s[i];
        i++;
    }
    f[i + 1] = '.';

    while (s[i] != '.') {
        while (s[i] == ' ') {
            i++;
        }
        if (f1(s + i, f) && f2(s + i)) {
            print(s + i);
        }
        while (s[i] != ' ' && s[i] != '.') {
            i++;
        }
    }
    return 0;
}

void print(char* s) {
    int i = 0;
    while (s[i] != ' ' && s[i] != '.') {
        cout << s[i];
        i++;
    }
    cout << ' ';
}

bool f1(char* s, char* f) {
    int i = 0;
    while (*(s + i) == *(f + i) && *(f + i) != '.') {
        i++;
    }
    return (*(f + i) == '.' && *(s + i) == ' ') ? false : true;
}

bool f2(char* s) {
    char p, q;
    int i = 1;
    while (s[i] != ' ' && s[i] != '.') {
        p = isupper(s[i - 1]) ? s[i - 1] + 32 : s[i - 1];
        q = isupper(s[i]) ? s[i] + 32 : s[i];
        if (p > q) {
            return false;
        }
        i++;
    }
    return true;
}