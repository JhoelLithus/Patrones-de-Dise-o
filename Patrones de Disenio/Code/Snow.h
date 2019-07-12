#ifndef SNOW_H_
#define SNOW_H_

#include "Turtle.h"
#include <vector>
#include <string>
using namespace std;

/**
* @file Snow.h
* @version 1.0
* @date 09/07/2019
* @autor Jhoel Huallpar Dorado
* @title Class Particle.h
*/

/** 
Declaracion de la Clase SFlyweight: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Flyweight, "Es un patron de diseño", la tiene dos tipos especificos de datos,
INTRINSECO: Son los datos que conpartes los objetos, son las caracteristicas que tienen en comun.
EXTRINSECO: Son los datos que estan fuera del Flyweight, son los datos con caracteristicas unicas.
*/
class SFlyweight 
{
	private:
		float tam;
		SFlyweight()
    	{
    		tam=0.02;
		}
    	
	public:
		static SFlyweight* instance;
	
		static SFlyweight* getinstance()
		{
			if(instance==0)
			{
				instance=new SFlyweight();
			}
			return instance;
		}
		
		void settam(float ptam)
		{
			tam=ptam;
		}
		
		float gettam()
		{
			return tam;		
		}		
};
SFlyweight* SFlyweight::instance = 0;

/** 
Declaracion de la Clase Particles: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a lo largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Snow te permite dibujar un copo de nieve.
*/
class particles
{
	private:
	    float tam;
	    SFlyweight *fsnow;
	    float x,y;
	    
	public:
		/** Snow(float ptamanio) -> es el contructor de la clase Snow */
		/** @brief Declaracion de variables */
		particles(float _tam)
		{
		    fsnow=SFlyweight::getinstance();
		    fsnow->settam(_tam);
		    tam=_tam;
		}
		~particles(){}
		void set_tam(float tam)
		{
		    fsnow->settam(0.02);
		}
		void setxy(float px,float py)
		{
		    x=px;
		    y=py;
		}
		/** 
		La funcion Draw de la clase Snow dibuja un copo de nieve. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
		/** @param x -> señala la posicion en el eje de las "X" en el plano cartesiano, es decir de manera horizontal */
		/** @param y -> señala la posicion en el eje de las "Y" en el plano cartesiano, es decir de manera Vertical */
		/** @param tamanio -> señala el tamaño de las aristas de la particula */
		void drawn(Turtle t)
		{
		    t.reset();
	   		t.positionini(x,y);
	   		t.setvalue(0.0);
		    int grados = 0;
	       	for(int x=1; x<30; x++)
	       	{
	       		for(int x=0; x<3; x++)
	       		{
	       			t.forward(fsnow->gettam());
			        t.left(90);
				}
			
				t.left(grados + 10);
			}  
		}
};

/** 
Declaracion de la Clase nieve: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Snow dibuja un cantidad determinada de particulas.
*/
class nieve 
{
	private:
	    int cant;
	public:
		vector<particles> v;
		nieve(int cantidad= 5, float tamano=0.02)
		{
	    
		    for(int i=0;i<cantidad;i++)
		        this->add_copo(tamano);
		}
		~nieve()	{}
		void drawn(Turtle t)
		{
		    t.setColor(0.0, 1.0, 0.0);
		    float tam=v.size();
		    for(int i=0;i<tam;i++)
			{
		        v[i].drawn(t);
		    }
		    glutPostRedisplay();
		}
		void set_cantidad(int _cant)
		{
		    cant=_cant;
		}
		void add_copo(float tam)
		{
		    particles tmp=particles(tam);
		    v.push_back(tmp);
		}	
};
#endif
