#include <iostream>
#include <cstring>
using namespace std;
int main() {
    //621 - Secret Research
    int K;
    string str;
    cin >> K;
    getchar();
    for(int rep=0; rep<K; rep++){
        getline(cin,str);
        if(str == "1" || str == "4" || str == "78") {
            cout << "+" << endl;
        }
        else if(str[str.length()-2] == '3' && str[str.length()-1] == '5') {
            cout << "-" << endl;
        }
        else if(str[0] == '9' && str[str.length()-1] == '4'){
            cout << "*" << endl;
        } 
        else{
            cout << "?" << endl;
        }
    }
    return 0;
}