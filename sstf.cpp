#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

struct proceso{
	string nombre;
	int n_cilindro;
	int t_llegada;
	proceso (string name,int a,int b){
		this->nombre=name;
		this->n_cilindro=a;
		this->t_llegada=b;
	}
	proceso(){
		this->nombre=" ";
	}

};
typedef vector<proceso> cola;
typedef pair<int,int> par;

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

bool llego(proceso task,int t){
	if(task.t_llegada<=t)
		return true;
	else return false;
}

par mas_cercano(cola pro,int cili){
	int min=9999;
	int cont=0;
	par pare;
	for(int i=0;i<pro.size();i++){
		if(abs(cili-pro[i].n_cilindro)<min){
			min=abs(cili-pro[i].n_cilindro);
			cont=i;
		}
	}
	pare.first=cont;
	pare.second=min;
	return pare;
}

void imprimir ( cola pro){
	for (int i = 0; i < pro.size(); i++)
	{
		cout<<pro[i].nombre<<endl;
	}
}

void sstf(cola &pro,int cilindro,float lag){
	sort_llegada(pro);
	float t_actual=0;
	int cili=cilindro;
	cola aux;par pare;
	proceso p_aux("inicial",cilindro,0);
	int d_total=0;
	cout<<p_aux.nombre<<"|"<<p_aux.n_cilindro<<"|"<<p_aux.t_llegada<<endl;
	while(!pro.empty()){
		//cout<<endl;
		//copia de los procesos que ya llegaron
		cout<<"t_actual:"<<t_actual<<endl;
		for(int i=0;i<pro.size();i++){
			if(llego(pro[i],t_actual)){
				aux.push_back(pro[i]);
				pro.erase(pro.begin()+i);
			}
		}
		if(aux.empty())
			t_actual+=1;
		else{
			//ejecucion de los procesos 
			for (int i = 0; i < aux.size(); i++){

				pare=mas_cercano(aux,cili);
				cili=aux[pare.first].n_cilindro;
				//cout<<aux[pare.first].nombre<<"|"<<aux[pare.first].n_cilindro<<"|"<<aux[pare.first].t_llegada<<endl;
				d_total+=pare.second;
				aux.erase(aux.begin()+pare.first);
				t_actual+=lag;
			}
		}
		imprimir(pro);

	}

	cout<<"d_total:"<<d_total<<endl;
	


}

int main(){
	cola colita;
	proceso p1("P1",8,1);
	proceso p2("P2",25,2);
	proceso p3("P3",48,3);
	proceso p4("P4",76,4);
	proceso p5("P5",32,5);
	proceso p6("P6",11,6);
	colita.push_back(p1);
	colita.push_back(p2);
	colita.push_back(p3);
	colita.push_back(p4);
	colita.push_back(p5);
	//colita.push_back(p6);
	sstf(colita,40,2);
	return 0;
}
