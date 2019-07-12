#include <sstream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "Abstract.h"
#include "Observer.h"
#include "Snow.h"
/**
* @file Shape.cpp
* @version 1.0
* @date 09/07/2019
* @autor Jhoel Huallpar Dorado
* @title SHAPE	
*/
using namespace std;
/** Declaracion de las Variable "Turtle t" esto es para poder utilizar las funciones de la clase Turtle  */
Turtle t;
/**Declaracion de las variables px y py las cuales son del tipo float */
float px;
float py;

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{	
		case 27:             // ESCAPE key
			exit (0);
		break;	
	}
	
}

//Bridge
void setPrim(int value)
{
	/**Funciones para poder dibujar las diferentes partes del un bosque nevado, como Arbol, Flor y Nieve; pudiendo ser estas de tres distindos colores como son el rojo, azul y verde; ademas de ello puedes dar la ubicacion del arbol y de la flor. */
	//Draw Patron de diseño Bridge
	static AbstractSimple* abst =new PaintElaborado01();
	static Tree* tr = abst->getTree();
	static Flower* f = abst->getFlower();
	static Snow* n = abst->getSnow();
	/** Funciones para poder utilizar el Patron de diseño Observer y ver que cuando cambias un posicion de un determinado gropo de nieve, cambias tambien de los demas grupos el elemento que elegiste de una posicion determinada.*/
	//Patron de Diseño Obderver
	Tabla subj;
	nieve1 *n1=new nieve1(&subj);
    nieve2 *n2=new nieve2(&subj);
    nieve3 *n3=new nieve3(&subj);
    subj.attach(n1);
    subj.attach(n2);
    subj.attach(n3);
    subj.addpoint(0.017,0.02);
	subj.addpoint(0.05,0.02);
	subj.addpoint(0.035,0.02);
	
	/**Menu para poder interactuar con la interfaz de una manera mas dinamica*/    
    switch(value)
    {
    case 1:
    	cout<<"ingresa coordenadas del Arbol : "<<endl;
	  	cin>>px>>py;
	  	t.clear();
        tr->Paintx('R');
		tr->Draw(t, px, py);
        break;
    case 2:
    	cout<<"ingresa coordenadas del Arbol : "<<endl;
	  	cin>>px>>py;
	  	t.clear();
        tr->Paintx('B');
		tr->Draw(t, px, py);
        break;
    case 3:
    	cout<<"ingresa coordenadas del Arbol : "<<endl;
	  	cin>>px>>py;
	  	t.clear();
        tr->Paintx('G');
		tr->Draw(t, px, py);
        break;
    case 4:
    	cout<<"ingresa coordenadas de la Flor : "<<endl;
	  	cin>>px>>py;
	  	t.clear();
        f->Paintx('R');
		f->Draw(t, px, py);
		
        break;
    case 5:
    	cout<<"ingresa coordenadas de la Flor : "<<endl;
	  	cin>>px>>py;
	  	t.clear();
        f->Paintx('B');
		f->Draw(t, px, py);
		
        break;
    case 6:
    	cout<<"ingresa coordenadas de la Flor : "<<endl;
	  	cin>>px>>py;
	  	t.clear();
        f->Paintx('G');
		f->Draw(t, px, py);
		
        break;
    case 7:
    	t.clear();
        n->Paintx('R');
		n->Draw(t);
        break;
    case 8:
    	t.clear();
        n->Paintx('B');
		n->Draw(t);
        break;
    case 9:
    	t.clear();
        n->Paintx('G');
		n->Draw(t);
        break;
    case 10:
    	float xx; //0.15
		float yy; //-0.4
		int i;//1
		cout<<" Type Float Ingrese las cordenas en el eje X: ";
		cin>>xx;
		cout<<" Type Float Ingrese las cordenas en el eje Y: ";
		cin>>yy;
		cout<<" Type int Ingrese que numero de nieve quiere cambiar ";
		cin>>i;
	
		subj.setXY(xx,yy,i);
	    subj.notify();
    	t.clear();
	    n1->drawn(t);
	    n2->drawn(t);
	    n3->drawn(t);
        break;
    case 11:    
        
        break;
    case 12:
        t.clear();
        break;
    case 13:    
        exit (0);
        break;
    default:
        break;
    }
}

//CreateMenu
void CreateSMenu(void)
{
	int rojo;
    rojo=glutCreateMenu(setPrim);
    glutAddMenuEntry("Arbol Rojo",1);
    glutAddMenuEntry("Flor Rojo",4);
    glutAddMenuEntry("Nieve Rojo",7);
    
    int azul;
    azul=glutCreateMenu(setPrim);
    glutAddMenuEntry("Arbol Azul",6);
    glutAddMenuEntry("Flor Azul",5);
    glutAddMenuEntry("Nieve Azul",8);
    
    int verde;
    verde=glutCreateMenu(setPrim);
    glutAddMenuEntry("Arbol Verde",3);
    glutAddMenuEntry("Flor Verde",6);
    glutAddMenuEntry("Nieve Verde",9);
    
    int bridge;
    bridge=glutCreateMenu(setPrim);
    glutAddSubMenu("Arbol",rojo);
    glutAddSubMenu("Flor",azul);
    glutAddSubMenu("Nieve",verde);
    
    //menú con el click derecho
    glutCreateMenu(setPrim);
    glutAddSubMenu("Bridge", bridge);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
	glutAddMenuEntry("Observer", 10);
    glutAddMenuEntry("Memento", 11);
    glutAddMenuEntry("Clear", 12);
    glutAddMenuEntry("Salir", 13);
		
}
//Mouse
void myMouse(int btn, int state, int x, int y)
{
    glutPostRedisplay();
}

/** " printbitmap() " esta funcion esta relacionada a la libreria opengl, la cual nos permite colocar texto a la interfaz */
void printbitmap(const string msg, double x, double y)
{
   glRasterPos2d(x, y);
   for (string::const_iterator ii = msg.begin(); ii != msg.end(); ++ii)
    	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);
}
/** " display() " esta funcion esta relacionada a la libreria opengl, la cual nos permite dibujar diferentes objetos */
void display()
{
   	glLineWidth(0.2);  //Grosor de linea
   	glColor3d(0.5, 0.0, 0.9); //Color del dibujo

	    printbitmap("Salir = ESC", -0.9, 0.9);
	    printbitmap("Hacer Click Derecho para acceder a las funciones", -0.85, 0.7);
	glFlush();
}

/** " main() " El main es la ventana principal, la función main se encarga de dirigir el algoritmo que da solución al mismo. */
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   	glutInitWindowSize(600, 600);  //tamaño de la pantalla
   	glutInitWindowPosition(50, 50);
   	glutCreateWindow("Turtle C++");
	  
   	glutDisplayFunc(display); // Pantalla de Graficos
   	glutKeyboardFunc(*keyboard);
   	glutMouseFunc(myMouse);
	glClearColor(1.0, 2.0, 1.0, 0.0);  //Fondo
	glColor3f(0.5, 0.5, 0.9); //Color del dibujo
	CreateSMenu();
	/*
	tabla subj;
	
    nieve1 *n1=new nieve1(&subj);
    nieve2 *n2=new nieve2(&subj);
    nieve3 *n3=new nieve3(&subj);
    subj.attach(n1);
    subj.attach(n2);
    subj.attach(n3);
    subj.addpoint(0.017,0.02);
	subj.addpoint(0.05,0.02);
	subj.addpoint(0.035,0.02);

	subj.setXY(0.15,-0.4, 1);
    subj.notify();
    n1->drawn(t);
    n2->drawn(t);
    n3->drawn(t);
	*/
	glFlush();
   	glutMainLoop();

    return 0;
}

