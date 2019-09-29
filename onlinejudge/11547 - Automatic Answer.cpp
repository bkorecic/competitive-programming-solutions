#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //Automatic Answer
    int K;
    int n;
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> n;
        int resultado = abs(315*n + 36962);
        int length = log10(resultado) + 1;
        int digitos[length];
        string num = to_string(resultado);
        cout << num.at(length-2) << endl;
    }
    return 0;
}