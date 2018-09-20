#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct proceso{

	int t_llegada;
	string nombre;
	int t_proceso;
	int t_proceso2;
	float entrada_salida;

	proceso(){
		nombre="";
	}

	proceso(string a,int llegada,int dura){
		nombre=a;
		t_llegada=llegada;
		t_proceso=dura;
	}
	proceso(string a,int llegada,int dura,int dura2){
		nombre=a;
		t_llegada=llegada;
		t_proceso=dura;
		t_proceso2=dura2;
	}
	proceso(string a,int llegada,int dura,float es){
		nombre=a;
		t_llegada=llegada;
		t_proceso=dura;
		entrada_salida=es;
	}
	proceso(string a,int llegada,int dura,int dura2,float es){
		nombre=a;
		t_llegada=llegada;
		t_proceso=dura;
		t_proceso2=dura2;
		entrada_salida=es;
	}
};

typedef vector<proceso> cola;

void sort_llegada(cola &v){
    for(double i=0;i<v.size();i++)
    {
        for(double j=i-1;j>=0;j--)
        {
            if(v[j].t_llegada<=v[j+1].t_llegada)
                break;
            swap(v[j],v[j+1]);
        }
    }
}



void poli6(cola usuarios ){
	cola c_usuarios;
	cola c_sistema;
	sort_llegada(c_usuarios);




}

void Round_Robin(cola pro,int quantum){

	sort_llegada(pro);
	int temporizador=0,cont=0;
	queue<proceso> aux;
	aux.push(pro[cont]);
	cont++;
	proceso temp;
	while(!aux.empty()){
		temp=aux.front();
		aux.pop();
		for(int i=0;i<quantum;i++){
			if(temp.t_proceso>0){
				temporizador++;
				temp.t_proceso--;
				cout<<temp.nombre<<": "<<temp.t_proceso<<endl;
			}
			else
				break;
		}
		while(pro[cont].t_llegada<=temporizador && cont<pro.size()){

			aux.push(pro[cont]);
			cont++;
		}
		if(temp.t_proceso>0)
			aux.push(temp);
		
	}
}

int main(){

	/*proceso T1("A",0,3);
	proceso T2("B",2,6);
	proceso T3("C",4,4);
	proceso T4("D",6,5);
	proceso T5("E",8,2);

	cola pro;
	int quantum=2;

	pro.push_back(T1);
	pro.push_back(T2);
	pro.push_back(T3);
	pro.push_back(T4);
	pro.push_back(T5);
	Round_Robin(pro,quantum);*/

	return 0;
}
