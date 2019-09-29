#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //One-Two-Three
    int K;
    string str;
    cin >> K;
    for(int rep=0; rep<K+1; rep++){
        getline(cin, str);
        if(str[3] == 'e' || str[4] == 'e') {
            cout << "3" << endl;
        }
        else if(str[0] == 't'  && (str[1] == 'w' || str[2] == 'o')) {
            cout << "2" << endl;
        }
        else if(str[1] == 'w' && (str[0] == 't' || str[2] == 'o')) {
            cout << "2" << endl;
        }
        else if(str[2] == 'o' && (str[0] == 't' || str[1] == 'w')) {
            cout << "2" << endl;
        }
        else if(str[0] == 'o' || str[1] == 'n'){
            cout << "1" << endl;
        }
        else{
        }
        str = "00000";
    }
}