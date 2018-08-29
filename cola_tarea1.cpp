#include <iostream>
#include <queue>
#include <utility>      // std::pair
using namespace std;
typedef pair<string,int> par;
typedef queue<par> proceso;
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
	proceso tarea1;
	par t1,t2,t3,t4;
	t1.first="t1";
	t1.second=5;
	t2.first="t2";
	t2.second=3;
	t3.first="t3";
	t3.second=6;
	t4.first="t4";
	t4.second=4;
	tarea1.push(t1);
	tarea1.push(t2);
	tarea1.push(t3);
	tarea1.push(t4);
	procesador(tarea1);
	return 0;


}
