#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct proceso
{
	int Tamano;
	string nombre;
	proceso()
	{
		nombre="";
	}
	proceso(string a,int Ta)
	{
		this->nombre=a;
		this->Tamano=Ta;
	}
};

typedef vector<proceso> cola;

struct memoria{

	int marco;
	bool m_llena;
	memoria(int a, bool b)
	{
		this->marco=a;
		this->m_llena=b;
	}
};

bool m_llena(vector<memoria> &A){
	for(int i=0;i<A.size();i++)
		if(A[i].m_llena==true)
			return false;
	
	return true;
}
void GestionMemoria(cola &A,int n,int memory_size)
{
	int marco=memory_size/n;
	vector<memoria> M;
	cout<<"marco size= "<<marco<<endl;

	//la memoria se separa en marcos
	for(int i=0;i<A.size();i++){
		memoria aux(marco,true);
		M.push_back(aux);
	}
	int c=0;
	//por cada proceso
	for(int i=0;i<A.size();i++){
		if(m_llena(M))
			break;
		else{
			if(A[i].Tamano>marco){
				cout<<"Numero de marco:	"<<c+1<<"	proceso actual:	"<<A[i].nombre<<"-"<<A[i].Tamano<<endl;
				A[i].Tamano-=marco;
				i--;
				M[c].m_llena=false;
				c++;
			}
			else if(A[i].Tamano<=marco){
			
				cout<<"Numero de marco:	"<<c+1<<"	proceso actual:	"<<A[i].nombre<<"-"<<A[i].Tamano<<endl;
				M[c].m_llena=false;
				c++;
			}
	}	
}}

int main()
{
	cola colita;
	proceso p1("P1",4);
	proceso p2("P2",2);
	proceso p3("P3",7);
	proceso p4("P4",1);
	proceso p5("P5",11);
	colita.push_back(p1);
	colita.push_back(p2);
	colita.push_back(p3);
	colita.push_back(p4);
	colita.push_back(p5);
	GestionMemoria(colita,4,21);
	return 1;
}
