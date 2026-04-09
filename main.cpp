 #include <iostream>
#include <ctime>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace std::chrono;

// Алгоритм 1
void delFirstMetod(char* x, int& n, char key, int& Cn, int& Mn, long long& Tn) {
    int i = 0;
    Cn = 0;
    Mn = 0;

    while (i < n) {
        Cn++; // сравнение i < n
        Cn++; // сравнение x[i] == key
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                Cn++; // сравнение j < n - 1
                x[j] = x[j + 1];
                Mn++; // перемещение
            }
            Cn++; // последнее сравнение j < n - 1
            n--;
        } else {
            i++;
        }
    }
    Tn = Cn + Mn;
}

// Заполнение случайными символами
void r(char* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 'A' + rand() % 26;
    }
}

// Заполнение ключевым значением
void mkey(char* arr, int n, char val) {
    for (int i = 0; i < n; i++) {
        arr[i] = val;
    }
}

// Вывод массива
void m(char* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// функция измерения времени
template<typename Func>
double t(Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    int sizes[] = {100, 200, 500, 1000, 2000, 5000, 10000};
    char keyChar = 'A';

    for (int size : sizes) {
        cout << "\nРазмер массива: " << size << endl;

        // Случай 1: Все элементы должны быть удалены
        char* arr1 = new char[size];
        mkey(arr1, size, keyChar);
        int n1 = size, Cn1 = 0, Mn1 = 0;
        long long Tn1 = 0;

        double time1 = t([&] {
            delFirstMetod(arr1, n1, keyChar, Cn1, Mn1, Tn1);
        });

        cout << "Случай а (все элементы удаляются):" << endl;
        cout << "Cn = " << Cn1 << ", Mn = " << Mn1 << ", Tn = " << Tn1 << endl;
        cout << "Время: " << time1 << " мс" << endl;
        delete[] arr1;

        // Случай 2: Случайное заполнение
        char* arr2 = new char[size];
        r(arr2, size);
        int n2 = size, Cn2 = 0, Mn2 = 0;
        long long Tn2 = 0;

        double time2 = t([&] {
            delFirstMetod(arr2, n2, keyChar, Cn2, Mn2, Tn2);
        });

        cout << "Случай б (случайное заполнение):" << endl;
        cout << "Cn = " << Cn2 << ", Mn = " << Mn2 << ", Tn = " << Tn2 << endl;
        cout << "Время: " << time2 << " мс" << endl;
        delete[] arr2;

        // Случай 3: Ни один элемент не удаляется
        char* arr3 = new char[size];
        r(arr3, size);
        // Убираем ключ
        for (int i = 0; i < size; i++) {
            if (arr3[i] == keyChar) {
                arr3[i] = (keyChar == 'Z') ? 'A' : keyChar + 1;
            }
        }
        int n3 = size, Cn3 = 0, Mn3 = 0;
        long long Tn3 = 0;

        double time3 = t([&] {
            delFirstMetod(arr3, n3, keyChar, Cn3, Mn3, Tn3);
        });

        cout << "Случай в (ни один элемент не удаляется):" << endl;
        cout << "Cn = " << Cn3 << ", Mn = " << Mn3 << ", Tn = " << Tn3 << endl;
        cout << "Время: " << time3 << " мс" << endl;
        delete[] arr3;
    }

    return 0;
}
