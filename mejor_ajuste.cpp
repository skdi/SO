#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

typedef pair<float,int> par;//proceso
struct proceso{
    string nombre;
    float size;
    int duracion;
    int t_llegada;
    proceso(string name,float si,int dur,int t){
        this->nombre=name;
        this->size=si;
        this->duracion=dur;
        this->t_llegada=t;
    }
};

typedef vector<proceso> cola_proceso;//cola de procesos

int ajustar(proceso pro,vector<float> memo){
    for(int i=0;i<3;i++)
        if(memo[i]>=pro.size)
            return i;

    return 0;
}

vector<proceso> mejor_ajuste(cola_proceso &cola,float memoria){
    vector<float> memo;

    memo.push_back(0.25*memoria);
    memo.push_back(0.35*memoria);
    memo.push_back(0.4*memoria);
    int n_particion;
    int time=0;
    for(int i=0;i<cola.size();i++){
        n_particion=ajustar(cola[i],memo);

        if(time>=cola[i].t_llegada){
            for(int j=0;j<cola[i].duracion;j++){
                time++;
                cout<<cola[i].nombre<<"   -   "<<n_particion<<"   -   "<<(cola[i].duracion-j)<<endl;
            }
        }

    }
}


int main(){

    cola_proceso cola;
    cola.push_back(proceso("T1",30,4,0));
    cola.push_back(proceso("T2",12,6,3));
    cola.push_back(proceso("T3",3,1,7));
    cola.push_back(proceso("T4",18,3,9));
    cola.push_back(proceso("T5",40,12,10));
    cola.push_back(proceso("T6",27,5,12));
    cout<<"nombre"<<"-"<<"n_particion"<<"-"<<"duracion"<<endl;
    mejor_ajuste(cola,100);

    return 0;
}
