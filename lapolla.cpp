#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <queue>
#include <stdlib.h>
#include <vector>
using namespace std;
struct pares
{
    int first;
    string second;
};
typedef vector<pares> vpar;
struct node
{
	int Tllegada;
	char* nombre;
	int duracion;
	int x;
	int y;
	node()
	{
		nombre="";
	}
	node(char* a,int TLL,int Dura)
	{
		this->nombre=a;
		this->Tllegada=TLL;
		this->duracion=Dura;
	}
};
typedef vector<node> vnodo;

void sortLLegada(vnodo &v){
    for(double i=0;i<v.size();i++)
    {
        for(double j=i-1;j>=0;j--)
        {
            if(v[j].Tllegada<=v[j+1].Tllegada)
                break;
            swap(v[j],v[j+1]);
        }
    }
}
void sortDuracion(vnodo &v){
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

vpar Politica1(vnodo A){
	vpar res;
	sortLLegada(A);
	pares r;
    while(!A.empty()){
        for(int i=0;i<A[0].duracion;i++){
        	r.first=1;
        	r.second=A[0].nombre;
        	res.push_back(r);
        }
        A.erase(A.begin());
    }
    return res;
}

vpar Politica2(vnodo A){
	vpar res;
	sortDuracion(A);
	pares r;
    while(!A.empty()){
        for(int i=0;i<A[0].duracion;i++){
        	r.first=1;
        	r.second=A[0].nombre;
        	res.push_back(r);
        }
        A.erase(A.begin());
    }
    return res;
}

vpar Politica3(vnodo v)
{
	sortLLegada(v);
	vpar res;
	pares r;
	int temporizador=0,cont=0;
	vnodo aux;
	aux.push_back(v[cont]);
	cont++;
	while(!aux.empty())
	{
		temporizador++;
		aux[0].duracion--;
		///cout<<aux[0].nombre<<" "<<aux[0].duracion<<endl;
		r.first=1;
		r.second=aux[0].nombre;
		res.push_back(r);
		while(v[cont].Tllegada<=temporizador && cont<v.size())
		{
			aux.push_back(v[cont]);
			cont++;
			sortDuracion(aux);
		}
		if(aux[0].duracion==0)
		{
			aux.erase(aux.begin());
		}
	}
	return res;
}

vpar Politica5(vnodo pro,int quantum=2){
	sortLLegada(pro);
	vpar res;
	pares r;
	int temporizador=0,cont=0;
	queue<node> aux;
	aux.push(pro[cont]);
	cont++;
	node temp;
	while(!aux.empty()){
		temp=aux.front();
		aux.pop();
		for(int i=0;i<quantum;i++){
			if(temp.duracion>0){
				temporizador++;
				temp.duracion--;
				r.first=1;
				r.second=temp.nombre;
				//cout<<temp.nombre<<": "<<temp.duracion<<endl;
				res.push_back(r);
			}
			else
				break;
		}
		while(pro[cont].Tllegada<=temporizador && cont<pro.size()){

			aux.push(pro[cont]);
			cont++;
		}
		if(temp.duracion>0)
			aux.push(temp);

	}
	return res;
}


const char* tostr (int x)
{
    stringstream str;
    str << x;
    return str.str().c_str();
}

void pantalla_Inicio(int x,int y,char* nombre)
{
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    setcolor(WHITE);
    outtextxy(275+x,0+y,nombre);
    const char* cha;
    setlinestyle(SOLID_LINE,4,3);
    line(100+x,420+y,100+x,60+y);
    line(100+x,420+y,600+x,420+y);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    for(int i=0;i<=40;i+=5){
        cha=tostr(i);
    	outtextxy(100+x,430+y,cha);
    	x+=50;
    }
    //Flechas
    /**line(90+x,70+y,100+x,60+y);
    line(110+x,70+y,100+x,60+y);
    line(590+x,410+y,600+x,420+y);
    line(590+x,430+y,600+x,420+y);*/

}
void mostrar_politica(int x,int y,vnodo v,vpar vv)
{
    pantalla_Inicio(x,y,"SJF");

    int Ax,Ay,c=0,actual=x+100;
    for(int i=0;i<v.size();i++)
    {
        outtextxy(70+x,380+y-(i*100),v[i].nombre);
        //v[i].x=70+x;
        v[i].y=380+y-(i*100);
    }
    for(int i=0;i<vv.size();i++)
    {
        while(v[c].nombre!=vv[i].second)
        {
            c++;
        }
        Ay=v[c].y+10;
        c=0;
        //setlinestyle(SOLID_LINE,20,20);
        line(actual,Ay,actual+10,Ay);
        actual+=10;
    }
}

int main()
{
    initwindow(1800,1000,"SO",0,0);

    vpar poli1,poli2,poli3,poli5;
    node a("P1",0,15);
	node b("P2",2,12);
	node c("P3",3,5);
	node d("P4",3,2);
	vnodo v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	poli1=Politica1(v);
	poli2=Politica2(v);
	poli3=Politica3(v);
	poli5=Politica5(v);

    mostrar_politica(0,0,v,poli1,"FIFO");
    mostrar_politica(450,0,v,poli2,"STF");
    mostrar_politica(0,450,v,poli3,"SJF");
    mostrar_politica(450,450,v,poli5,"ROUND ROBIN");


    getch();
    return 0;
}

