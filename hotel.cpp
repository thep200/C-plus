#include<iostream>
using namespace std;

void hotel(int n){
    for(int i = 1; i <= (n/3) + 1; i++){
        if((n - 2*i)%3 == 0){
            cout << i << " " << (n - 2*i)/3 ;
            return;
        }
    }
}
int main(){
    int n;
    cout << "N = ";cin >> n;
    hotel(n);
}

