#include <iostream>
using namespace std;

int main() {
    //Nlogonia
    int K; //Queries
    int N; //Coordenada X de punto de división
    int M; //Coordenada Y de punto de división
    int X; //Coordenada X casa
    int Y; //Coordenada Y casa
    cin >> K;
    while (K>0) {
        cin >> N;
        cin >> M;
        for(int i=0; i<K; i++) {
            cin >> X;
            cin >> Y;
            if(X-N == 0 || Y-M == 0) {
                cout << "divisa" << endl;
            }
            if(X-N > 0 && Y-M > 0) {
                cout << "NE" << endl;
            }
            if(X-N < 0 && Y-M > 0) {
                cout << "NO" << endl;
            }
            if(X-N > 0 && Y-M < 0) {
                cout << "SE" << endl;
            }
            
            if(X-N < 0 && Y-M < 0) {
                cout << "SO" << endl;
            }
        }
        cin >> K;
    }
    return 0;
}