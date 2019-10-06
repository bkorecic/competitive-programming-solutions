/*
Solution:
We can merge two segment hashes (i,k) and (k+1,j) by multiplying
the hash of the segment (i,k) by B^(j-k-1) (which is B to the length of the right hash).
We notice that this merge operation is associative, so, we can store, query and update
these hashes in a segment tree.
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll B, P, L, N;
vector <ll> modpow;

struct SegmentTree{
	vector <pll> tree;

	SegmentTree(){ //inicialización
		tree.resize(4*L); // le damos 4*L de espacio a tree
		build(0, 0, L-1); // construimos desde el nodo cero, con rango 0 a N-1 y con el vector A.
	}

	pll merge(pll a, pll b){ // esta es la operación que se
		return make_pair((a.f*modpow[b.s]%P + b.f)%P, a.s + b.s); // hace entre los nodos al combinarlos
	}

	void build(int n, int l, int r){
		//n es el índice de nodo actual en tree
		//l y r es el rango del arreglo original que el nodo actual está mirando
		//A es el vector original
		if(l == r){ // caso hoja
			if(l >= L){
				tree[n] = mp(0, 0);
			}
			else{
				tree[n] = mp(0, 1);
			}
			return;
		}
		int mid = (l+r)/2;
		build(2*n+1, l, mid); // construimos para cada hijo
		build(2*n+2, mid+1, r);
		tree[n] = merge(tree[2*n+1], tree[2*n+2]); // combinamos los hijos
	}

	pll query(int i, int j){ // le pasa el query a la raíz del árbol
		return(query(0, 0, L-1, i, j));
	}

	pll query(int n, int l, int r, int i, int j){
		//n es el índice del nodo actual y l,r el rango que este está viendo
		//i,j son los índices del rango objetivo al que queremos sacarle la respuesta
		if(l>=i && r<=j){ //en este caso, el rango objetivo está totalmente contenido 
			return tree[n]; //en el rango actual y simplemente retornamos lo que está en el nodo
		}
		if(r<i || l>j){ //en este caso, el rango objetivo está afuera del rango actual
			return mp(0, 0); //y retornamos el neutro (en el caso de la suma, es cero)
		}
		int mid = (l+r)/2; //si no se cumplió que está contenido totalmente o fuera,
		pll a = query(2*n+1, l, mid, i, j); //entonces está parcialmente contenido
		pll b = query(2*n+2, mid+1, r, i, j); //y hay que llamar a sus dos hijos
		return merge(a, b);
	}

	void update(int i, ll v){
		update(0, 0, L-1, i, v); //le pasa la actualización al nodo raíz
	}

	void update(int n, int l, int r, int i, ll v){
		if(l == r && r == i){ //caso en el que llegamos al nodo hoja que queremos actualizar
			tree[n].f = v;
			return;
		}
		int mid = (l+r)/2;
		if(i < l || r < i) return; //si estamos fuera del rango ojetivo, cortamos la recursión
		update(2*n+1, l, mid, i, v);
		update(2*n+2, mid+1, r, i, v);
		tree[n] = merge(tree[2*n+1], tree[2*n+2]); //se actualiza a los dos hijos y al nodo actual con ellos
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> B >> P >> L >> N, B != 0){
		modpow.resize(L);
		modpow[0] = 1;
		for(int i=1; i<L; i++){
			modpow[i] = (modpow[i-1]*B)%P;
		}
		SegmentTree ST;
		for(int i=0; i<N; i++){
			char op; cin >> op;
			if(op == 'E'){
				int i; ll val; cin >> i >> val;
				i--;
				ST.update(i, val);
			}
			else{
				int i, j; cin >> i >> j;
				i--; j--;
				cout << ST.query(i,j).f << '\n';
			}
		}
		cout << "-\n";
	}
	return 0;
}