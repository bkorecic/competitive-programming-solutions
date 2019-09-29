#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //Emoogle Balance
    int caso = 1;
    int K;
    int arr[1000];
    int a;
    int b;
    cin >> K;
    while(K !=0){
        a=0;
        b=0;
        for(int i=0; i<K; i++){
            cin >> arr[i];
        }
        for(int i=0; i<K; i++){
            if(arr[i]==0) {
                b++;
            }
            else{
                a++;
            }
        }
        cout << "Case " << caso << ": " << (a-b) << endl;
        caso++;
        cin >> K;
    }
    return 0;
}