#include <iostream>
#include <string>
using namespace std;

int main() {
    //Robot Instructions
    int K;
    int instrucciones;
    string str;
    cin >> K;
    for(int rep=0; rep<K; rep++){
        int index = 0;
        int p = 0;
        cin >> instrucciones;
        int ilog[instrucciones];
        for(int a=0; a<instrucciones; a++){
            ilog[a] == 0;
        } 
        
        for(int i=0; i<instrucciones; i++){
            cin >> str;
            if(str=="RIGHT"){
                p++;
                ilog[i+1] = 1;
            }
            else if(str=="LEFT"){
                p--;
                ilog[i+1] = -1;
            }
            else{
                cin >> str;
                cin >> index;
                p = p + ilog[index];
                ilog[i+1] = ilog[index];
            }
        }
        cout << p << endl;
    }
    return 0;
}