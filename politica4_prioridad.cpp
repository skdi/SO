#include <iostream>
#include <queue>
#include <vector>
#include <utility>      // std::pair
using namespace std;
unsigned procesado=0;
struct proceso{
	string nombre;
	unsigned prioridad;
	unsigned t_servicio;
	proceso(string nom,unsigned prio,unsigned t_ser){
		if(prio>0&&prio<10){
			prioridad=prio;
			t_servicio=t_ser;
			nombre=nom;
		}
		else cout<<"Error de prioridad"<<endl;		
	}
};

typedef vector<proceso> cola_proceso;

void sort_prioridad(cola_proceso &v){
	for(double i=0;i<v.size();i++){
		for(double j=i-1;j>=0;j--){
			if(v[j].prioridad<=v[j+1].prioridad)
				break;
			swap(v[j],v[j+1]);
		}
	}
}
void sort_servicio(cola_proceso &v){
	for(double i=0;i<v.size();i++){
		for(double j=i-1;j>=0;j--){
			if(v[j].t_servicio<=v[j+1].t_servicio)
				break;
			swap(v[j],v[j+1]);
		}
	}
}
void procesar(cola_proceso &A){
	procesado++;
	if(procesado==5){
		procesado=0;
		for(unsigned i=1;i<A.size();i++){
			A[i].prioridad--;
		}
	}
	sort_prioridad(A);
	if(A[0].t_servicio<=0){
		A.erase(A.begin());
	}else{
		A[0].t_servicio--;
		cout<<A[0].nombre<<"-"<<A[0].t_servicio<<"|"<<endl;
	}
}

void politica4(cola_proceso &A){
	unsigned timer=0;
	char x;proceso p_nulo("NULL",9,1);
	string nombre;unsigned prioridad,t_proceso;
	while(true){
		if(A.empty()){
			A.push_back(p_nulo);
		}
		else{
			cout<<"presione [y] para crear un nuevo proceso,[x] para apagar el procesador y [n] para continuar procesando"<<endl;
			cin>>x;
			if(x=='y'){
				cout<<"ingrese nombre,proridad y tiempo de procesamiento del proceso"<<endl;
				cin>>nombre;cout<<endl;
				cin>>prioridad;cout<<endl;
				cin>>t_proceso;cout<<endl;
				proceso nuevo(nombre,prioridad,t_proceso);
				cout<<"proceso creado"<<endl;
				A.push_back(nuevo);
			}
			else if(x=='x')
				break;

		}
		procesar(A);
	}

	
}


int main(){
	cola_proceso A;
	politica4(A);
	return 0;
}
