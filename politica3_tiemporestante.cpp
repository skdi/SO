#include <iostream>
#include <queue>
#include <vector>
#include <utility>      // std::pair
#define INF 999999
using namespace std;
typedef pair<string,int> par;
typedef queue<par> proceso;
typedef pair<string,pair<int,int>> part;//nombre,tiempo de llegada ,tamaño proc
typedef queue<part> proceso2;
typedef vector<part> proceso3;


void sort_llegada(proceso3 &v){
	for(double i=0;i<v.size();i++){
		for(double j=i-1;j>=0;j--){
			if(v[j].second.first<=v[j+1].second.first)
				break;
			swap(v[j],v[j+1]);
		}
	}
}
void sort_size(proceso3 &v){
	for(double i=0;i<v.size();i++){
		for(double j=i-1;j>=0;j--){
			if(v[j].second.second<=v[j+1].second.second)
				break;
			swap(v[j],v[j+1]);
		}
	}
}
void politica3(proceso3 A){
	sort_llegada(A);
	unsigned timer=0;
	while(!A.empty()){
		timer++;
		if(A[0].second.first<=timer){
			if(A[0].second.second>0){
				A[0].second.second-=1;
				cout<<A[0].first<<" size:"<<A[0].second.second<<endl;
				sort_size(A);
			}
			else A.erase(A.begin());
		}
	}

	
}
void procesador(proceso A);
bool usado(vector<par> A){
	bool flag;
	for(int i=0;i<A.size();i++){
		if(A[i].second==INF)
			flag=1;
		else {flag=0;
			return flag;
		}
	}
	return flag;

}
void insertsort(vector<par> &v){
	for(double i=0;i<v.size();i++){
		for(double j=i-1;j>=0;j--){
			if(v[j].second<=v[j+1].second)
				break;
			swap(v[j],v[j+1]);
		}
	}
}

vector<par> ordenar_pormenor(proceso A){
	par menor;
	vector<par> copy;
	menor=A.front();
	//paso de cola a vector
	while(!A.empty()){
		copy.push_back(A.front());
		A.pop();
	}
	insertsort(copy);
	for(int i=0;i<copy.size();i++){
		A.push(copy[i]);
	}
	procesador(A);
}



void procesador(proceso A){
	while(!A.empty()){
		for(int i=0;i<A.front().second;i++){
			cout<<A.front().first<<" ";
		}
		A.pop();
		cout<<endl;
	}

	return;
}

int main(){
	proceso3 tarea1;
	part t1,t2,t3,t4;
	t1.first="t1";
	t1.second.first=1;
	t1.second.second=5;
	t2.first="t2";
	t2.second.first=2;
	t2.second.second=3;
	t3.first="t3";
	t3.second.first=3;
	t3.second.second=2;
	t4.first="t4";
	t4.second.first=4;
	t4.second.second=4;
	tarea1.push_back(t1);
	tarea1.push_back(t2);
	tarea1.push_back(t3);
	tarea1.push_back(t4);
	politica3(tarea1);
	return 0;


}
