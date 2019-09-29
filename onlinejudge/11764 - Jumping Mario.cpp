#include <iostream>
using namespace std;

int main() {
    //11764 - Jumping Mario
    int K;
    int N;
    int high;
    int low;
    cin >> K;
    
    for(int rep=0; rep<K; rep++){
        cin >> N;
        high = 0;
        low = 0;
        int H[N];
        for(int i=0; i<N; i++){
            cin >> H[i];
        }
        for(int i=0; i<N-1; i++){
            if(H[i]>H[i+1]){
                low++;
            }
            else if(H[i]==H[i+1]){
            }
            else{
                high++;
            }
        }
        cout << "Case " << rep+1 << ": " << high << " " << low << endl;
    }
    return 0;
}