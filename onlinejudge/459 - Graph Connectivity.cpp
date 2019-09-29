#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi visitados; //-1 = UNVISITED, 1 = VISITED
vector <vi> AdjList;

void dfs(int u) {
    
    visitados[u] = 1;
    for(int i=0; i<(int)AdjList[u].size(); i++) {
        int v = AdjList[u][i];
        if (visitados[v] == -1){
            dfs(v);
        }
    }
}

int convertir(char a){
    return (int)a-64;
}

int main() {
    //459 - Graph Connectivity
    
    int N;
    cin >> N;
    bool flag = false;
    
    for(int rep=0; rep<N; rep++){
        
        if(flag==true){
            cout << endl;
        }
        
        //cin
        char aux;
        cin >> aux;
        getchar();
        int cantidadNodos = convertir(aux);
        //setup vectores
        visitados.clear();
        visitados.assign(cantidadNodos, -1);
        
        AdjList.clear();
        AdjList.assign(cantidadNodos, vi());
        //
        string linea;
        getline(cin,linea);
        
        while(!linea.empty()){

            char a,b;
            a = linea[0];
            b = linea[1];
            int n1, n2;
            n1 = convertir(a) - 1;
            n2 = convertir(b) - 1;
            AdjList[n1].push_back(n2);
            AdjList[n2].push_back(n1);
            
            
            getline(cin,linea);
        }
        
        int contador = 0;
        for(int i=0; i<visitados.size(); i++){
            if(visitados[i] == -1){
                contador++;
                dfs(i);
            }
        }
        
        flag = true;
        
        cout << contador << endl;
    }
    
    return 0;
}