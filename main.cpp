#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <memory>
#include <string>
#include <cstring>

using namespace std;
using namespace chrono;

// Функция для преобразования строки в массив символов
unique_ptr<char[]> stringToCharArray(const string& str, int& len) {
    len = str.length();
    unique_ptr<char[]> arr(new char[len]);
    for (int i = 0; i < len; i++) {
        arr[i] = str[i];
    }
    return arr;
}

void dumpChrono() {
    auto begin = chrono::steady_clock::now();
    getchar();
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";
}

void delSecondMethod(unique_ptr<char[]> &x, int &n, char key) {
    auto begin = chrono::steady_clock::now();
    int counterEquels = 0;
    int counterMove = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        counterEquels++;
        counterMove++;
        if (x[i] != key) {
            counterEquels++;
            j++;
        }
    }
    n = j;

    cout << "[Second Algorithm]"<< endl;
    cout << "Movements in second method: " << counterMove << "\nComparisons performed: " << counterEquels << endl;
    auto end = chrono::steady_clock::now();
    auto difference = (end - begin);
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(difference);
    cout << "Execution time of second algorithm (milliseconds): " << elapsed_ms.count() << endl;
}

void delFirstMethod(unique_ptr<char[]> &x, int &n, char key) {
    auto begin = chrono::steady_clock::now();
    int counterEquals = 0, counterMove = 0;
    int i = 0;
    while (i < n) {
        counterEquals++;
        if (x[i] == key) {
            counterEquals++;
            for (int j = i; j < n - 1; j++) {
                counterEquals++;
                counterMove++;
                x[j] = x[j + 1];
            }
            n--;
        } else {
            i++;
        }
    }
    cout << "[First Algorithm]"<< endl;
    cout << "Movements in first method: " << counterMove << "\nComparisons performed: " << counterEquals << endl;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Execution time of first algorithm (milliseconds): " << elapsed_ms.count()<< endl;
}

void printArr(unique_ptr<char[]> &arr, int N, const string& name = "") {
    cout << "Array output " << name << endl;
    cout << "[";
    for(int i(0); i < N; i++) {
        cout << "'" << arr[i] << "'";
        if (i != N-1) cout << ", ";
    }
    cout << "]" << endl;
}

unique_ptr<char[]> copy(unique_ptr<char[]> &arr, int len) {
    std::unique_ptr<char[]> copyResult(new char[len]);
    for (int i = 0; i < len; i++) {
        copyResult[i] = arr[i];
    }
    return copyResult;
}

void executeTask1() {
    srand(time(NULL));

    cout << "Program operation mode:\n";
    cout << ">> 1 - Random filling (digits 0-9)\n";
    cout << ">> 2 - Manual input (string)\n";
    cout << ">> 3 - Fill with single character\n";
    cout << ">> Enter mode ID: ";

    int modeWork;
    cin >> modeWork;
    cin.ignore(); // Очищаем буфер после cin

    string input;
    int N;
    unique_ptr<char[]> arr;

    switch (modeWork) {
        case 1: {
            cout << "Enter array length: ";
            cin >> N;
            cin.ignore();

            arr = unique_ptr<char[]>(new char[N]);
            for(int i = 0; i < N; i++) {
                arr[i] = '0' + (rand() % 10); // Случайные цифры 0-9
            }
            break;
        }

        case 2: {
            cout << "Enter a string (can contain letters, digits, _ ): ";
            getline(cin, input);
            N = input.length();
            arr = stringToCharArray(input, N);
            break;
        }

        case 3: {
            cout << "Enter the character to fill the array with: ";
            char fillChar;
            cin >> fillChar;
            cin.ignore();

            cout << "Enter array length: ";
            cin >> N;
            cin.ignore();

            arr = unique_ptr<char[]>(new char[N]);
            for(int i = 0; i < N; i++) {
                arr[i] = fillChar;
            }
            cout << "Array filled with character: '" << fillChar << "'" << endl;
            break;
        }

        default:
            cout << "Operation mode not found!" << endl;
            return;
    }

    printArr(arr, N, "Initial array");

    cout << "Enter the character to delete:\n>> ";
    char key;
    cin >> key;
    cin.ignore();

    auto arrayFirstAlg = copy(arr, N);
    int nFirst = N;

    delFirstMethod(arrayFirstAlg, nFirst, key);
    printArr(arrayFirstAlg, nFirst, "First algorithm array");

    auto arraySecondAlg = copy(arr, N);
    int nSecond = N;

    delSecondMethod(arraySecondAlg, nSecond, key);
    printArr(arraySecondAlg, nSecond, "Second algorithm array");

    cout << "\nVerification:" << endl;
    cout << "Original array length: " << N << endl;
    cout << "First algorithm result length: " << nFirst << endl;
    cout << "Second algorithm result length: " << nSecond << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    executeTask1();
    return EXIT_SUCCESS;
}
