#ifndef TURTLE_H_
#define TURTLE_H_
/**

* @file Turtle.h
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Turtle
	
*/
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

using namespace std;
struct Coordenada
{
    int R,G,B;
    
    Coordenada()
	{
        R=255;
		G=255;
        B=0;
    }
};
//Class Turtle
/** 
Declaracion de la Clase Turtle: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a loa largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase turtle te permite realizar diversas figuras que el usuario desea realizar.
*/

class Turtle
{
	/** En el " Private " van todas las variables que el usuario va a utilizar */
	private:
		Coordenada turt;
		
		/** @brief La varialble "X" acepta valores enteros y tambien valores decimales.
		La "X" señala la posicion en el eje de las "X" en el plano cartesiano, es decir de manera horizontal */
		double x;
		
		/** La varialble "Y" acepta valores enteros y tambien valores decimales.
		La "Y" señala la posicion en el eje de las "Y" en el plano cartesiano, es decir de manera Vertical */
		double y;
		
		/** La varialble "Value" acepta valores enteros y tambien valores decimales.
		el "Value" es el tamaño que le designamos para que funcione de manera correcta */
		double value;
		
		/** La varialble "Draw es de tipo booleano, es decir que sus valores son "Verdad" o "Falso". */
		bool draw;
		
	/** En el " Public " van todas las funciones que el usuario va a utilizar */		
	public:
		/** Turtle() -> es el contructor de la clase Turtle */
		Turtle()
		{
			
		}
		
		// Constructor
		/** @brief Ubica el lapiz en un punto incial desde donde se empezara a dibujar */
		/** @param newx -> señala la posicion en el eje de las "X" en el plano cartesiano, es decir de manera horizontal */
		/** @param newy -> señala la posicion en el eje de las "Y" en el plano cartesiano, es decir de manera Vertical */
		void positionini(const double newx, const double newy)
   		{
		   x = newx;
		   y = newy;
		} 
		
		//Funcion Forward
		/** " forward() " Mueva la tortuga hacia adelante en la distancia especificada, en la direccion en que se dirige la tortuga. */
		/** @param dist -> Indica la distancia hacia adelante que debe ser recorrida al momento de graficar */
		void forward(const double dist)
		{
			double pi=3.1415926535897932384626433832795;
		    double newx = x + dist * cos(pi * value / 180.0);
		    double newy = y + dist * sin(pi * value / 180.0);
		    if (draw)
		    {
		        glBegin(GL_LINES);
		        	glVertex2d(x, y);
		        	glVertex2d(newx, newy);
		        glEnd();
		    }
		      x = newx;
		      y = newy;	
			  glFlush();		
		}
		
		//Funcion Backward
		
		/** " backward() " Mueve la tortuga hacia atras por la distancia, opuesta a la direccion en que se dirige la tortuga. No cambies el rumbo de la tortuga. */
		/** @param dist -> Indica la distancia hacia atras que debe ser recorrida al momento de graficar */
		void backward(const double dist)
		{
			forward(-dist);			
		}
				
		//Funcion PenUp
		/** " penup() " Tire de la pluma hacia arriba, sin dibujar al mover. */
		void penup()
		{ 
	   		draw = false;
		}
		
		//Funcion PenDown
			/** " penup() " Tire de la pluma hacia abajo - dibujo al mover. */
		void pendown()
   		{
		   draw = true;
		}
		
		//Left
		/** " left() " Gire la tortuga a la izquierda por unidades de angulo. 
		La orientacion del angulo depende del modo de la tortuga.
		*/
		/** @param angle -> Indica el angulo hacia donde debe ser girado */
		void left(const double angle)    // Gira el angulo en grados
   		{
			value += angle;
		}
		
		//Right
		
		/** " right() " Gire la tortuga a la derecha por unidades de angulo. 
		La orientacion del angulo depende del modo de la tortuga. */
		/** @param angle -> Indica el angulo hacia donde debe ser girado */
   		void right(const double angle)   // Gira el -angulo en grados
   		{ 
			left(-angle);
		}
		
		//Reset
		/** " reset() " Vuelve todos los valores inicial, es decir reinicia todas las configuraciones hechas el momento */
		void reset()                     // Vuelve a su estado inicial
	    {
			x = 0.0;
			y = 0.0;
			value = 0.0; 
			draw = true;
		}
		
		// SetValue
		/** "Setvalue() "Ajusta todos los valores */
		/** @param newvalue -> Indica el nuevo valor que debe ser asignado */
		void setvalue(const double newvalue)
		{ 
			value = newvalue; 
		}
		
		void setColor(double R, double G, double B)
		{
			turt.R=R;
			turt.G=G;
			turt.B=B;
			glColor3f(R,G,B);
		}
		
		void move(const double px, const double py)
		{
			x = px + x;
			y = py + y;
		}
		
		void clear()
		{
			setColor(255,255,255);
    		glClear(GL_COLOR_BUFFER_BIT);
    		const string w="Salir = ESC";
    		glRasterPos2d(300,450);
    		for (string::const_iterator ii = w.begin();ii != w.end();++ii)
			{
            	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*ii);
    		}
    		glFlush();
		}
	
};

class Colors
{
	public:
	    int R;
		int G;
		int B;	
};
#endif
