#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace chrono;

// Selection sort (with time measurement inside)
void selectionSort(int* a, int n, long long& cmp, long long& mov, double& elapsed) {
    auto start = high_resolution_clock::now();
    cmp = 0;
    mov = 0;
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            cmp++;
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = tmp;
            mov+=3;
        }
    }
    auto end = high_resolution_clock::now();
    elapsed = duration<double, milli>(end - start).count();
}

// Bubble sort (with time measurement inside)
void bubbleSort(int* a, int n, long long& cmp, long long& mov, double& elapsed) {
    auto start = high_resolution_clock::now();
    cmp = 0;
    mov = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            cmp++;
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                mov+=3;
            }
        }
    }
    auto end = high_resolution_clock::now();
    elapsed = duration<double, milli>(end - start).count();
}

// Array generators
/* Fills the array with random numbers from 0 to 999.
   This corresponds to the average case for sorting algorithms,
   as the data has no particular structure. */
int* generateRandom(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = rand() % 1000;
    return arr;
}

/* Fills the array with ascending numbers (0, 1, 2, ..., n-1).
   This is the best case for sorting algorithms,
   because the array is already sorted. */
int* generateAscending(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = i;
    return arr;
}

/* Fills the array with descending numbers (n, n-1, ..., 1).
   This is the worst case for most simple sorting algorithms,
   as the elements are in reverse order, requiring the maximum
   number of swaps and comparisons. */
int* generateDescending(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = n - i;
    return arr;
}

// Copy array
int* copyArray(int* src, int n) {
    int* dest = new int[n];
    for (int i = 0; i < n; ++i) dest[i] = src[i];
    return dest;
}

// Main testing function
void runSortingTests() {
    srand(time(nullptr));

    int sizes[] = {100, 200, 500, 1000, 2000, 5000, 10000,
                   100000, 200000, 500000, 1000000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    cout << fixed << setprecision(6);
    cout << "Comparison of Selection sort and Bubble sort\n";

    for (int i = 0; i < numSizes; ++i) {
        int n = sizes[i];
        cout << "Array size: " << n;

        int* randArr = generateRandom(n);
        int* ascArr = generateAscending(n);
        int* descArr = generateDescending(n);

        int* a = nullptr;
        long long cmp, mov;
        double elapsed;

        // Selection sort: average case
        a = copyArray(randArr, n);
        selectionSort(a, n, cmp, mov, elapsed);
        cout << "Selection, average: n=" << n
             << ", time=" << elapsed << " ms"
             << ", cmp=" << cmp << ", mov=" << mov
             << ", total=" << (cmp + mov) << endl;
        delete[] a;

        // Selection sort: best case
        a = copyArray(ascArr, n);
        selectionSort(a, n, cmp, mov, elapsed);
        cout << "Selection, best:    n=" << n
             << ", time=" << elapsed << " ms"
             << ", cmp=" << cmp << ", mov=" << mov
             << ", total=" << (cmp + mov) << endl;
        delete[] a;

        // Selection sort: worst case
        a = copyArray(descArr, n);
        selectionSort(a, n, cmp, mov, elapsed);
        cout << "Selection, worst:   n=" << n
             << ", time=" << elapsed << " ms"
             << ", cmp=" << cmp << ", mov=" << mov
             << ", total=" << (cmp + mov) << endl;
        delete[] a;

        // Bubble sort: average case
        a = copyArray(randArr, n);
        bubbleSort(a, n, cmp, mov, elapsed);
        cout << "Bubble,    average: n=" << n
             << ", time=" << elapsed << " ms"
             << ", cmp=" << cmp << ", mov=" << mov
             << ", total=" << (cmp + mov) << endl;
        delete[] a;

        // Bubble sort: best case
        a = copyArray(ascArr, n);
        bubbleSort(a, n, cmp, mov, elapsed);
        cout << "Bubble,    best:    n=" << n
             << ", time=" << elapsed << " ms"
             << ", cmp=" << cmp << ", mov=" << mov
             << ", total=" << (cmp + mov) << endl;
        delete[] a;

        // Bubble sort: worst case
        a = copyArray(descArr, n);
        bubbleSort(a, n, cmp, mov, elapsed);
        cout << "Bubble,    worst:   n=" << n
             << ", time=" << elapsed << " ms"
             << ", cmp=" << cmp << ", mov=" << mov
             << ", total=" << (cmp + mov) << endl;
        delete[] a;

        delete[] randArr;
        delete[] ascArr;
        delete[] descArr;
    }
}

int main() {
    // setlocale(LC_ALL, "rus");  // Not needed for English output
    runSortingTests();
    return 0;
}
