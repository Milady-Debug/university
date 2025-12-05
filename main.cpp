#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int rows=0,collumns =0;
    cout<<"Введите количество столбцов и строк"<<endl;
    cin>>rows>>collumns;
    cout<<"Количество прямоугольников, которых можно вырезать"<<endl;
    cout<<(rows*(rows+1)/2)*(collumns*(collumns+1)/2);
    return 0;
}
