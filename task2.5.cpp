#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");
    cout<<"Ââåäèòå ñóììó çàéìà, íà ñêîëüêî ëåò áåðåòå, ïðîöåíò"<<endl;
    double S,p,n,m,r;
    cin>>S>>p>>n;
    r = p/100;
    if ((12*((pow(1+r,n))-1))>0 && r!=-1){
        m = S*r*pow(1+r,n)/(12*((pow(1+r,n))-1));
        cout<<m;
    }
    else{
        cout<<"Error";
    }
}


