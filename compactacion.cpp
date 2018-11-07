#include <iostream>
#include <vector>
#include <utility>

using namespace std;
struct proceso
{
	string nombre;
	int t_memoria;
	int size;
	bool flag;
	proceso(string n,int Tiem,int size)
	{
		this->nombre=n;
		this->t_memoria=Tiem;
		this->size=size;
		this->flag=false;
	}
};
typedef vector<proceso> cola;

struct particiones
{
	string nombre;
	int size;
	int tiempo;
	bool estado;
};

typedef vector<particiones> memoria_p;
struct memoria
{
	int tamMax;
	memoria_p particion;
	memoria(int t)
	{
		this->tamMax=t;
	}
};
bool huecos(memoria_p &A)
{
	for(int i=0;i<A.size()-1;i++)
	{
		if(A[i].nombre==" ")
		{
			return true;
		}
	}
	return false;
}
int compactar(memoria_p &A)
{
	int ncompactados=0;
	while(huecos(A))
	{
		for(int i=0;i<A.size();i++)
		{
			if(A[i].nombre==" " && A[i].estado==false)
			{
				ncompactados++;
				A.erase(A.begin()+i);
			}
		}
	}
	return ncompactados;
}
int EspacioLibre(memoria &A)
{
	int es=0;
	for(int i=0;i<A.particion.size();i++)
	{
		es+=A.particion[i].size;
	}
	return A.tamMax-es;
}
void borrarproceso(string a,cola &B)
{
	for(int i=0;i<B.size();i++)
	{
		if(B[i].nombre==a)
		{
			B.erase(B.begin()+i);
			break;
		}
	}
}


void imprimir_memo(memoria &Memo)
{
	for(int i=0;i<Memo.particion.size();i++)
	{
		cout<<"|nombre: "<<Memo.particion[i].nombre<<
		" 	|tiempo: "<<Memo.particion[i].tiempo<<" 	|size:"<<Memo.particion[i].size<<endl;
	}
	cout<<"memoria disponible:"<<EspacioLibre(Memo)<<endl;
	
	cout<<""<<endl;
}

void Procesar(cola &A,int mem)
{
	memoria Memo(mem);
	Memo.tamMax=mem;
	int tem=0;
	particiones auxP;
	while(!A.empty())
	{
		for(int i=0;i<A.size();i++)
		{
			if(Memo.particion.empty())
			{
				if(A[i].size<EspacioLibre(Memo) && A[i].flag==false)
				{
					A[i].flag=true;
					auxP.nombre=A[i].nombre;
					auxP.size=A[i].size;
					auxP.tiempo=A[i].t_memoria;
					auxP.estado=true;
					Memo.particion.push_back(auxP);
				}
			}
			else
			{	
				for(int j=0;j<Memo.particion.size();j++)
				{
					if(Memo.particion[j].estado==false && Memo.particion[j].size>=A[i].size)
					{
						Memo.particion[j].nombre=A[i].nombre;
						Memo.particion[j].tiempo=A[i].t_memoria;
						Memo.particion[j].estado=true;
						A[i].flag=true;
						break;
					}
				}
				if(A[i].size<EspacioLibre(Memo) && A[i].flag==false)
				{
					A[i].flag=true;
					auxP.nombre=A[i].nombre;
					auxP.size=A[i].size;
					auxP.tiempo=A[i].t_memoria;
					auxP.estado=true;
					Memo.particion.push_back(auxP);
				}
				
			}
		}
		
		tem++;
		for(int i=0;i<Memo.particion.size();i++)
		{
			if(Memo.particion[i].tiempo==0)
			{
				for(int j=0;j<Memo.particion.size();j++)
				{
					if(Memo.particion[j].tiempo==0)
					{
						borrarproceso(Memo.particion[j].nombre,A);
						Memo.particion[j].nombre=" ";
						Memo.particion[j].estado=false;
					}	
				}		
				int n=compactar(Memo.particion);
				for(int j=i;j<Memo.particion.size();j++)
				{
					Memo.particion[j].tiempo-=1;
				}
				cout<<"1:: "<<endl;
				imprimir_memo(Memo);
				break;
			}
			else
				Memo.particion[i].tiempo-=1;
			
			cout<<"2:: "<<endl;
			imprimir_memo(Memo);
		}
	}
}


int main()
{
	cola colita;
	proceso aux("T1",3,30);
	colita.push_back(aux);
	proceso aux1("T2",1,50);
	colita.push_back(aux1);
	proceso aux2("T3",2,40);
	colita.push_back(aux2);

	Procesar(colita,124);
	return 0;
}
