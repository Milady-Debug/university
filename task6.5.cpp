#include <iostream>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    // Инициализация: levelA - длина, levelB - другая длина (если есть)
    // cntA - количество отрезков длины levelA, cntB - количество отрезков длины levelB
    // levelB = levelA - 1, если levelA > 0 и нужно.
    // На первом уровне только один отрезок длины N.
    long long levelA = N, levelB = N - 1;
    long long cntA = 1, cntB = 0;
    // Приведение: если levelA == levelB+1, то возможно объединение
    // Но на старте levelB мнимый.

    // Текущий номер школьника, с которого начинается уровень
    long long curStart = 1; // первый школьник на уровне 1
    long long curTotal = 1; // сколько школьников на текущем уровне

    while (K > curStart + curTotal - 1) {
        // Переходим на следующий уровень
        long long nextCntA = 0, nextCntB = 0;
        long long nextA = -1, nextB = -1;

        // Обрабатываем все отрезки длины levelA
        if (cntA > 0) {
            // Разбиваем отрезок длины levelA
            if (levelA % 2 == 1) { // нечётный
                long long half = (levelA - 1) / 2;
                // Два отрезка длины half
                if (nextA == -1) {
                    nextA = half;
                    nextCntA += 2 * cntA;
                } else if (nextA == half) {
                    nextCntA += 2 * cntA;
                } else if (nextB == half) {
                    nextCntB += 2 * cntA;
                } else {
                    nextB = half;
                    nextCntB += 2 * cntA;
                }
            } else { // чётный
                long long left = levelA / 2 - 1;
                long long right = levelA / 2;
                // left и right
                // left может быть right-1
                if (nextA == -1) {
                    nextA = right;
                    nextCntA += cntA;
                } else if (nextA == right) {
                    nextCntA += cntA;
                } else if (nextB == right) {
                    nextCntB += cntA;
                } else {
                    nextB = right;
                    nextCntB += cntA;
                }

                if (left == right) {
                    nextCntA += cntA; // но это невозможно при чётном levelA, left = right-1
                } else {
                    if (nextA == left) {
                        nextCntA += cntA;
                    } else if (nextB == left) {
                        nextCntB += cntA;
                    } else if (nextA == -1) {
                        nextA = left;
                        nextCntA += cntA;
                    } else {
                        nextB = left;
                        nextCntB += cntA;
                    }
                }
            }
        }

        // Обрабатываем все отрезки длины levelB
        if (cntB > 0 && levelB >= 0) {
            if (levelB % 2 == 1) { // нечётный
                long long half = (levelB - 1) / 2;
                if (nextA == half) {
                    nextCntA += 2 * cntB;
                } else if (nextB == half) {
                    nextCntB += 2 * cntB;
                } else if (nextA == -1) {
                    nextA = half;
                    nextCntA += 2 * cntB;
                } else {
                    nextB = half;
                    nextCntB += 2 * cntB;
                }
            } else { // чётный
                long long left = levelB / 2 - 1;
                long long right = levelB / 2;
                if (nextA == right) {
                    nextCntA += cntB;
                } else if (nextB == right) {
                    nextCntB += cntB;
                } else if (nextA == -1) {
                    nextA = right;
                    nextCntA += cntB;
                } else {
                    nextB = right;
                    nextCntB += cntB;
                }

                if (left == right) {
                    nextCntA += cntB;
                } else {
                    if (nextA == left) {
                        nextCntA += cntB;
                    } else if (nextB == left) {
                        nextCntB += cntB;
                    } else if (nextA == -1) {
                        nextA = left;
                        nextCntA += cntB;
                    } else {
                        nextB = left;
                        nextCntB += cntB;
                    }
                }
            }
        }

        // Переход на следующий уровень
        levelA = nextA;
        levelB = nextB;
        cntA = nextCntA;
        cntB = nextCntB;

        // Обновляем curStart и curTotal
        curStart += curTotal;
        curTotal = cntA + cntB;
    }

    // Теперь K-й школьник находится на текущем уровне
    // Номер внутри уровня: pos = K - curStart
    // Нужно определить, в отрезок какой длины он попал
    long long pos = K - curStart; // от 0 до curTotal-1
    long long len; // длина интервала, в который сядет K-й школьник
    if (pos < cntA) {
        len = levelA;
    } else {
        len = levelB;
    }

    // Вычисляем L и R после посадки
    long long L, R;
    if (len % 2 == 1) {
        L = R = (len - 1) / 2;
    } else {
        L = len / 2 - 1;
        R = len / 2;
    }

    if (L > R) swap(L, R);
    cout << L << " " << R << endl;

    return 0;
}
