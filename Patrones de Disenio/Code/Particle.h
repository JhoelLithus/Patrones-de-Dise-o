#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Turtle.h"
#include <vector>
using namespace std;

/**

* @file Particle.h
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Particle.h
	
*/

/**Class Color es de tipo Bridge, por consiguiente es un patron de diseño.*/
class Colorsn :public Colors
{
	public:
		virtual void Paint()=0;
};

/**Class ColorRed Dibuja de Color Rojo.*/
class ColorReds :public Colorsn
{
	public:
		void Paint()
		{
			R=255;
		    G=0;
		    B=0;
		}			
};

/**Class ColorBlue Dibuja de Color Blue.*/
class ColorBlues :public Colorsn
{
	public:
		void Paint()
		{
			R=0;
		    G=0;
		    B=255;
		}	
};

/**Class ColorBlue Dibuja de Color Green.*/
class ColorGreens :public Colorsn
{
	public:
		void Paint()
		{
			R=0;
		    G=255;
		    B=0;
		}	
};


/** 
Declaracion de la Clase Flyweight: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Flyweight, "Es un patron de diseño", la tiene dos tipos especificos de datos,
INTRINSECO: Son los datos que conpartes los objetos, son las caracteristicas que tienen en comun.
EXTRINSECO: Son los datos que estan fuera del Flyweight, son los datos con caracteristicas unicas.
*/
//Class Flyweight
class Flyweight 
{
	private:
		int cant;
		Flyweight()
    	{
    		cant=5;
		}
    	
	public:
		static Flyweight* instance;
	
		static Flyweight* getinstance()
		{
			if(instance==0)
			{
				instance=new Flyweight();
			}
			return instance;
		}
		void setCant(int pcant)
		{
			cant=pcant;
		}
		
		int getCant()
		{
			return cant;		
		}		
};
Flyweight* Flyweight::instance = 0;

/** 
Declaracion de la Clase Particle: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a lo largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Snow te permite dibujar un copo de nieve.
*/

//Class Particle
class Particle 
{
	private:
		float x;
		float y;
		float tamanio;
		Flyweight* snows;
	
	public:
		/** Snow(float ptamanio) -> es el contructor de la clase Snow */
		/** @brief Declaracion de variables */
		Particle( float px, float py, float ptamanio) 
	   	{
	   		snows=Flyweight::getinstance();
	   		x=px;
	   		y=py;
	   		tamanio=ptamanio;
	  	}
	  	
	  	/** 
		La funcion Draw de la clase Snow dibuja un copo de nieve. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
		/** @param x -> señala la posicion en el eje de las "X" en el plano cartesiano, es decir de manera horizontal */
		/** @param y -> señala la posicion en el eje de las "Y" en el plano cartesiano, es decir de manera Vertical */
		/** @param tamanio -> señala el tamaño de las aristas de la particula */
		void Draw(Turtle t) 
		{
			t.reset();
   			t.positionini(x,y);
   			t.setvalue(0.0);
		    int grados = 0;
		    
	       	for(int x=1; x<40; x++)
	       	{
	       		for(int x=0; x<4; x++)
	       		{
	       			t.forward(tamanio);
			        t.left(90);
				}
			
				t.left(grados + 10);
			}  
		}
};

/** 
Declaracion de la Clase Snow: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Snow dibuja un cantidad determinada de particulas.
*/
//Class Snow
class Snow//: public Shape
{
	protected:
		Colorsn * colorimpl;	
	private:
	    vector <Particle> vec;
	    int cant;
	 
	public:
		Snow(int c)
		{
			colorimpl=new ColorReds();
			cant=c;
			for(int i=0; i<cant ;i++)
			{
				Particle p1= Particle(0.2,0.4,0.05);
				Particle p2= Particle(0.4,0.2,0.04);
				Particle p3= Particle(0.6,0.4,0.07);
				Particle p4= Particle(0.8,0.2,0.1);
				Particle p5= Particle(-0.8,0.2,0.05);
				Particle p6= Particle(-0.6,0.6,0.04);
				Particle p7= Particle(-0.4,0.0,0.05);
				Particle p8= Particle(-0.7,0.4,0.08);
				Particle p9= Particle(0.2,0.7,0.07);
				Particle p10= Particle(0.0,0.4,0.08);
				
				vec.push_back(p1);
				vec.push_back(p2);
				vec.push_back(p3);
				vec.push_back(p4);
				vec.push_back(p5);
				vec.push_back(p6);
				vec.push_back(p7);
				vec.push_back(p8);
				vec.push_back(p9);
				vec.push_back(p10);	
			}	
		}
			
	    virtual void Draw(Turtle t)
	    {
	    	t.setColor(colorimpl->R, colorimpl->G, colorimpl->B);
	        for(int j=0; j<cant; j++)
	        {
	        	//cout <<"Smow"<<endl;
	        	vec[j].Draw(t);
			}
	    }
	    
	    void setCant(float pcant)
	    {
	    	cant=pcant;
		}
		
		void Paintx(char color)
        {
	        if(color=='B')
			{
		        colorimpl=new ColorBlues();
		        colorimpl->Paint();
		    }
		    else if(color=='R')
			{
		        colorimpl=new ColorReds();
		        colorimpl->Paint();
		    }
		    else if(color=='G')
			{
		        colorimpl=new ColorGreens();
		        colorimpl->Paint();
		    }
		}	
};
#endif
