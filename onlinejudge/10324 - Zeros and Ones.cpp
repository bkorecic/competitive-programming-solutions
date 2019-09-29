#include <iostream>
#include <cstring>
using namespace std;

int main() {
    //10324 - Zeros and Ones
    string str;
    int K, a, b, i, j, aux;
    int caso = 1;
    getline(cin,str);
    while(str[0] == '1' || (str[0] == '0' && (str[1] == '1' || str[1] == '0'))){
        cin >> K;
        cout << "Case " << caso << ":" << endl;
        for(int rep=0; rep<K; rep++){
            cin >> a >> b;
            i = min(a,b);
            j = max(a,b);
            aux = str[i];
            for(int n=0; n<(j-i+1); n++){
                if(str[i+n] != aux){
                    n = j-i+1;
                    cout << "No" << endl;
                }
                else if(str[i+n] == aux && n == j-i){
                    cout << "Yes" << endl;
                }
            }
        }
        caso++;
        getchar();
        getline(cin,str);
    }
    return 0;
}