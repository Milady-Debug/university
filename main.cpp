#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int amountOfBlades=0, amountOfThree;
    int remaining;

    cout<<"Введите количество лопастей"<< endl;
    cin>> amountOfBlades;
    for(int i = 0; (i * 4) <= amountOfBlades; i++){
        remaining = amountOfBlades - (i*4);
        if(remaining %3 ==0){
            amountOfThree = remaining/3;
            cout<<amountOfThree<< endl<< i<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl<<"0";
    return 0;

}
