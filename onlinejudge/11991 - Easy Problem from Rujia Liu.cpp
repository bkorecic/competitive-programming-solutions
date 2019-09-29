#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 11991 - Easy Problem from Rujia Liu?
    int n,m; //n cantidad de números, m queries
    while(cin >> n >> m) {
        int a;
        vector <vector<int>> lista;
        lista.assign(1000000,vector<int>());

        for(int i=0; i<n; i++) {
            cin >> a;
            lista[a].push_back(i+1);
        }
        int pos,num; //Posición a buscar y número a buscar
        for(int i=0; i<m; i++){
            cin >> pos >> num;
            if(pos<=lista[num].size()){
                cout << lista[num][pos-1] << endl;
            }
            else{
                cout << "0" << endl;
            }
        }
    }
    
    return 0;
}