#ifndef ABSTRACT_H_
#define ABSTRACT_H_

#include "Tree.h"
#include "Flower.h"
#include "Particle.h"
/**
* @file Shape.h
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Shape.h
*/

/** 
Declaracion de la Clase AbstractSimple: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
*/


class AbstractSimple
{
	public:
		/**
		los datos publicos de la clase Abstract Hace referencia a la clase Tree, Flower y Particle,
		ademas de estos deben ser de tipo virtual.
		virtual Tree* getTree()=0 -> Hace referencia a getTree de la clase Tree
		virtual Flower* getFlower()=0 -> Hace referencia a getFlower de la clase Flower
		virtual Particle* getSnow()=0 -> Hace referencia a getParticle de la clase Particle
		*/

		AbstractSimple() {}
		virtual Tree* getTree()=0;
		virtual Flower* getFlower()=0;
		virtual Snow* getSnow()=0;
};

/** 
La Clase PaintElaborado, hace referencia a las librerias Tree, Flower y Particle, con sus respectivas clases, metodos y funciones.
*/
class PaintElaborado01 :public AbstractSimple
{		
	public:
		PaintElaborado01() {}
		~PaintElaborado01() {}
		/** 
		Tree* getTree() -> realiza las funciones establecidad en la libreria Tree.h
		*/
		Tree* getTree()
		{
			Tree* tree;
		    TDirector Tdirector;
		    tree = Tdirector.getBuilder();
		
		    return tree;
		}
		/** 
		Flower* getFlower() -> realiza las funciones establecidad en la libreria Flower.h
		*/
		Flower* getFlower()
		{
			Flower* flower;
			Director director;
			flower=director.getBuilder();
			
			return flower;
		}
		/** 
		Particle* getSnow() -> realiza las funciones establecidad en la libreria Particle.h
		*/
		Snow* getSnow()
		{
			Snow *snw = new Snow(10);
	
			return snw;
		}	
};

class PaintElaborado02 :public AbstractSimple
{		
	public:
		PaintElaborado02() {}
		~PaintElaborado02() {}
		/** 
		Tree* getTree() -> realiza las funciones establecidad en la libreria Tree.h
		*/
		Tree* getTree()
		{
			Tree* tree;
		    TDirector Tdirector;
		    tree = Tdirector.getBuilder();
		
		    return tree;
		}
		/** 
		Flower* getFlower() -> realiza las funciones establecidad en la libreria Flower.h
		*/
		Flower* getFlower()
		{
			Flower* flower;
			Director director;
			flower=director.getBuilder();
			
			return flower;
		}
		/** 
		Particle* getSnow() -> realiza las funciones establecidad en la libreria Particle.h
		*/
		Snow* getSnow()
		{
			Snow *snw = new Snow(5);
	
			return snw;
		}	
};
#endif
