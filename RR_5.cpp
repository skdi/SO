#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct proceso{

	int t_llegada;
	string nombre;
	int duracion;

	proceso(){
		nombre="";
	}

	proceso(string a,int llegada,int Dura){
		nombre=a;
		t_llegada=llegada;
		duracion=Dura;
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
void sortDuracion(cola &v){
    for(double i=0;i<v.size();i++)
    {
        for(double j=i-1;j>=0;j--)
        {
            if(v[j].duracion<=v[j+1].duracion)
                break;
            swap(v[j],v[j+1]);
        }
    }
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
			if(temp.duracion>0){
				temporizador++;
				temp.duracion--;
				cout<<temp.nombre<<": "<<temp.duracion<<endl;
			}
			else
				break;
		}
		while(pro[cont].t_llegada<=temporizador && cont<pro.size()){

			aux.push(pro[cont]);
			cont++;
		}
		if(temp.duracion>0)
			aux.push(temp);
		
	}
}

int main(){

	proceso T1("T1",0,3);
	proceso T2("T2",2,6);
	proceso T3("T3",4,4);
	proceso T4("T4",6,5);
	proceso T5("T5",8,2);

	cola pro;
	
	pro.push_back(T1);
	pro.push_back(T2);
	pro.push_back(T3);
	pro.push_back(T4);
	pro.push_back(T5);
	Round_Robin(v,3);

	return 0;
}
