#include <iostream>
using namespace std;

int whatCompartment(int place) {
    if (place <= 36) {
        return (place - 1) / 4;
    } else {
        return 8 - ((place - 37) / 2);
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    int compartment[9]{};
    int amount;
    int place;
    cout<<"Введите количество свободных мест"<<endl;
    cin >> amount;
    cout<<"Введите номера свободных мест"<<endl;
    for (int i = 0; i < amount; i++) {
        cin >> place;
        compartment[whatCompartment(place)]++;
    }
    int freeCompartment = 0;
    int notInPlaceYet = 0;
    for (int i = 0; i < 9; i++) {
        if (compartment[i] == 6) {
           notInPlaceYet++;
            if (notInPlaceYet > freeCompartment) {
                freeCompartment = notInPlaceYet;
            }
        } else {
            notInPlaceYet = 0;
        }
    }
    cout<<"Количество свободных купе, идущих подряд "<<endl;
    cout << freeCompartment;

    return 0;
}
