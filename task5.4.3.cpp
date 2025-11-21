// Задание 48 сортировка строк по убыванию среднего арифметического
#include <iostream>
using namespace std;

double average(double sum, int numberOfElements) {
    double average;
    average = sum / numberOfElements;
    return average;
}

int main() {
    setlocale(LC_ALL, "rus");
    int rows, columns;
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> columns;

    int arr[rows][columns];
    cout << "Введите двумерный массив: " << endl;
    for(int i = 0; i < rows; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }

    int summa = 0;
    double arrSumma[rows];
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            summa += arr[i][j];
        }
        arrSumma[i] = average(summa, columns);
        summa = 0;
    }


    for(int i = 0; i < rows - 1; i++) {
        for(int j = 0; j < rows - i - 1; j++) {
            if(arrSumma[j] < arrSumma[j + 1]) {
                double tempAvg = arrSumma[j];
                arrSumma[j] = arrSumma[j + 1];
                arrSumma[j + 1] = tempAvg;
                for(int k = 0; k < columns; k++) {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }

    cout << "Отсортированный массив по убыванию средних арифметических строк:" << endl;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << arrSumma[i] << endl;
    }

    return 0;
}
