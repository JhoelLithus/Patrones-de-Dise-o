#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include "Turtle.h"
#include "Snow.h"
/**
* @file Observer.cpp
* @version 1.0
* @date 09/07/2019
* @autor Jhoel Huallpar Dorado
* @title SHAPE	
*/
using namespace std;
/** Declaracion de la clase Puntos, en donde daremos las posiciones en la interfaz grafica de las nieves*/
class Puntos 
{
	/** @brief La varialble "X" acepta valores enteros y tambien valores decimales.
		La "X" señala la posicion en el eje de las "X" en el plano cartesiano, es decir de manera horizontal */
    float x;
    /** La varialble "Y" acepta valores enteros y tambien valores decimales.
		La "Y" señala la posicion en el eje de las "Y" en el plano cartesiano, es decir de manera Vertical */
    float y;
    
  public:
    Puntos(float px=0.0,float py=0.0)
	{
        x=px;
        y=py;
    }
    void setXYp(float px, float py) 
	{
        x = px;
        y=py;
    
    }
    void setXp(float px) 
	{
        x = px;
    }
    void setYp(float py) 
	{
        y=py;
    }
    float getx() 
	{
      return x;
    }
    float gety()
	{
      return y;
    }
    void notify();
};
/** declaracion de la clase tabla en donde utilizamos la clase puntos para poder utilizarlos y meterlos a un vertor y poder accerder de esta manera a la ubicacion de cada nieve. */
class Tabla 
{  
    vector < class Observer * > obser;
    vector <Puntos> punt;
    
  public:
    Tabla(float px=0.0, float py=0.0)
	{
        addpoint(px,py);
    }
    void attach(Observer *obs) 
	{
        obser.push_back(obs);
    }
    void setXY(float px,float py,int i) 
	{
        punt[i].setXYp(px,py);
        //notify();
    }
    void setX(float px,int i) 
	{
        punt[i].setXp(px);
        //notify();
    }
    void setY(float py,int i) 
	{
        punt[i].setYp(py);
        //notify();
    }
    void addpoint(float px,float py) 
	{
        Puntos a(px,py);
        punt.push_back(a);
        //notify();
    }
    vector <Puntos> getpoints() 
	{
      return punt;
    }
    void notify();
};
/** La clase observer permite utilizar el patron de diseño Observer, para asi poder observar el comportamiento de las funciones de las clases cunado se modifica una de ellas. */
class Observer 
{
	protected:
    	Tabla *tab;
  	public:
		    Observer(Tabla *mod) 
			{
		        tab = mod;
		    }
		    virtual void update() = 0;
		    virtual void drawn(Turtle t)=0;
};

/**La clase nieve1 permite crear un grupo de nieves y utilizar el patron de diseño Observer en los elementos del grupo de particulas.*/
class nieve1: public Observer 
{
	private:
    	nieve *aux;
    	
  	public:
	    nieve1(Tabla* tab): Observer(tab)
		{
	        aux = new nieve(5,0.02);
	    }
	    void update()
		{
	
	       vector<Puntos> x = (tab->getpoints());
	       for (unsigned int i = 0; i < x.size(); ++i)
	       {
	        aux->v[i].setxy(x[i].getx()-0.25,x[i].gety());
	       }
	    }
	    void drawn(Turtle t)
		{
	        aux->drawn(t);
	    }
};

/**La clase nieve1 permite crear un grupo de nieves y utilizar el patron de diseño Observer en los elementos del grupo de particulas.*/
class nieve2: public Observer
{
	private:
    	nieve *aux;
    	
  	public:
	    nieve2(Tabla* tab): Observer(tab)
		{
	        aux = new nieve(5,0.02);
	    }
	    void update()
		{
	
	       vector<Puntos> x = (tab->getpoints());
	       for (unsigned int i = 0; i < x.size(); ++i)
	       {
	        aux->v[i].setxy(x[i].getx()+0.05,x[i].gety());
	       }
	    }
	    void drawn(Turtle t)
		{
	        aux->drawn(t);
	    }
};

/**La clase nieve1 permite crear un grupo de nieves y utilizar el patron de diseño Observer en los elementos del grupo de particulas.*/
class nieve3: public Observer 
{
	private:
    	nieve *aux;
    	
  	public:
	    nieve3(Tabla* tab): Observer(tab)
		{
	        aux = new nieve(5,0.02);
	    }
	    void update()
		{
	
	       vector<Puntos> x = (tab->getpoints());
	       for (unsigned int i = 0; i < x.size(); ++i)
	       {
	        aux->v[i].setxy(x[i].getx()+0.30,x[i].gety());
	       }
	    }
	    void drawn(Turtle t)
	    {
	        aux->drawn(t);
	    }
};
/**Creacion de la funcion notify de la clase Tabla, es esta funcion quizas la mas importante de todas, porque nos perminte ver comportamiento de las demas clases cuando una de ellas cambia.*/
void Tabla::notify()
{
  for (unsigned int i = 0; i < obser.size(); i++)
  {
      obser[i]->update();
  }
}
#endif 
