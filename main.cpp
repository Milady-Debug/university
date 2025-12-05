#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int costOfBase=0;
    int costOfBlade=0;
    int maxCostOfSpinner=0,totalNumberOfBlade = 0;
    cout<<"Введите стоимость основания, стоимость одной лопасти спиннера"<< endl;
    cin>> costOfBase;
    cin>> costOfBlade;
    cout<<"Введите максимальную стоимость одного спиннера "<<endl;
    cin>>maxCostOfSpinner;
    totalNumberOfBlade = (maxCostOfSpinner - costOfBase)/costOfBlade;
    cout<<totalNumberOfBlade;
    return 0;
}
