#include <iostream>
using namespace std;

int main() {
    //11942 - Lumberjack Sequencing
    int n;
    int arr[10];
    cin >> n;
    cout << "Lumberjacks:" << endl;
    for (int i=0; i<n; i++) {
        //Escribir array
        for (int a=0; a<10; a++) {
            cin >> arr[a];
        }
        
        if(arr[0] > arr[1]) {
            for(int b=0; b<9; b++){
                if(arr[b] < arr[b+1]){
                    b=10;
                    cout << "Unordered" << endl;
                }
                if(b==8 && arr[b] > arr[b+1]){
                    cout << "Ordered" << endl;
                }
            }
        }
        
        else {
            for(int b=0; b<9; b++){
                if(arr[b] > arr[b+1]){
                    b=10;
                    cout << "Unordered" << endl;
                }
                if(b==8 && arr[b] < arr[b+1]){
                    cout << "Ordered" << endl;
                }
            }
        }
        
    }
    return 0;
}