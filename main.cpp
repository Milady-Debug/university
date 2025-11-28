#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "¬ведите количество чисел: ";
    int length;
    cin >> length;
    ofstream file("1.txt");
    cout << "¬ведите вещественные числа:" << endl;
    for (int i = 0; i < length; i++) {
        double num;
        cin >> num;
        file << num << endl;
    }
    file.close();
    ifstream readFile("1.txt");
    double numbers[length];
    int kol = 0;
    double number;
    while (readFile >> number && kol < length) {
        numbers[kol] = number;
        kol++;
    }
    readFile.close();
    int maxi = 0, k = 0;
   int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < length; ++i) {
        if (numbers[i] > numbers[i - 1]) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            currentLength = 1;
        }
    }
    cout<<endl;
    cout<<maxLength;
    return 0;
}
