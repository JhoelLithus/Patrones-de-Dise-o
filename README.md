# Snowy-Forest									  *
c++ code using Design Patterns					  *
***************************************************

 ## Autor: Jhoel Huallpar Dorado ##


						Bosque Nevado

## Documetacion ##

La documentacion esta de forma detallada esta en la carpeta Output 
dentro de esa carpeta debes ingresar a la carpeta html, 
una vez dentro de html ingresas al archivo index.html.

***********************************************************************
## Instalacion Windows ##

******************************************************
Para poder Usar el codigo en Windows deberar instalar necesariamente el mingw, la cual se encuentra en la carpeta "Software necesario".
********************************************************
Una vez instalado el MinGw, nos dirigimos a la ruta de instalacion  #C:\MinGW\mingw32\bin#

En Buscar, busque y seleccione: Sistema (Panel de control)
Haga clic en el enlace Configuración avanzada del sistema.
Haga clic en Variables de entorno. En la sección Variables del sistema, busque la variable de entorno PATH y selecciónela. Haga clic en Editar. Si no existe la variable de entorno PATH, haga clic en Nuevo.
En la ventana Editar la variable del sistema (o Nueva variable del sistema), copianmos los siguiente  C:\MinGW\mingw32\bin   Haga clic en Aceptar.

Para mayor informacion sobre como instalar y configurar MinGW ir al link del video, la cual se encuentra el final de este documento.

********************************************************
Para poder instalar el opengl deberas copiar todo el contenido de la carpeta 
freeglut en la siguiente direccion C:\MinGW\mingw32
 
 ****************************************************************************
## Graficar desde el codigo fuente ##
 
 Para poder compilar, deberas ingresar a la carpeta BosqueNevado, 
 una vez dentro, deberas entrar a la carpeta Shape.cpp,
 dentro del codigo deberas, poder realizar diversos.
 
 **************************************************************************************
 ## Compilacion desde la Consola ##
 
 Para poder compilar el codigo, debereas colocar el comando en la consola el siguiente comando,
 
 Para compilar de manera adecuada compilarlo deberas deberas moverte dentro de la consola a la carpeta 
 donde contiene el codigo fuente.
 
 *****************************************************
 
 g++ -g -Wall Shape.cpp -lopengl32 -lglu32 -lfreeglut

******************************************************
## Instalacion Ubuntu ##
********************************************************
Instalar glut(Ubuntu):

sudo apt install build-essential ubuntu-restricted-extras cimg-dev freeglut3-dev libgles2-mesa-dev
sudo apt install g++
sudo apt-get install freeglut3-dev
********************************************************
##Finalmente ejecute:##
g++ main.cpp plano.cpp -o gl -lGL -lGLU -lglut
./gl

********************************************************
## Para mayor informacion ingresar a los siguientes link ##


https://open.gl/

https://www.youtube.com/watch?v=sXW2VLrQ3Bs   // INSTALACION DEL MinGW

////////////////////// GRACIAS POR SU TIEMPO ///////////////////////////

