#include <iostream>
using namespace std;

int main() {
    //Packing for Holiday
    int K;
    int a;
    int b;
    int c;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> a;
        cin >> b;
        cin >> c;
        if (a<= 20 && b<=20 && c<=20) {
            cout << "Case " << i+1 << ": " << "good" << endl;
        }
        else {
            cout << "Case " << i+1 << ": " << "bad" << endl;
        }
    }
    return 0;
}