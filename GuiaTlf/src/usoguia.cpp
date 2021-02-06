#include "../include/guiatlf.h"
#include <fstream>

int main(int argc , char * argv[]){
	  if (argc!=2){
	      cout<<"Dime el nombre del fichero con la guia"<<endl;
	      return 0;
	  }
	  ifstream f(argv[1]);

	  if (!f){
	      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
	      return 0;
	  }
  
 	 Guia_Tlf g;
	 
	 f>>g;
	 cout<<"La guia insertada " << endl <<g<<endl;
	 cin.clear();

	 /*cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
	 string n;

	 while (getline(cin,n)){
		   cout<<"Buscando "<<n<<"...."<<endl;
		   string tlf = g.gettelefono(n);
		   if (tlf==""){
			     cout<<"No existe ese nombre en la guia"<<endl;
		   }
		   else 
		    cout<<"El telefono es "<<tlf<<endl;
		   cout<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
	 }	
	 cin.clear();

	 cout<<"Dime el nombre que quieres borrar"<<endl;
	 
	 while (getline(cin,n)){
		   g.borrar(n);
		   cout<<"Ahora la guia es:"<<endl;
		   cout<<g<<endl;
		   cout<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar"<<endl;
	 }
	 
	 cin.clear();

	 Guia_Tlf otraguia;
	 cout<<"Introduce otra guia ([Pulse CTRL+D para finalizar])"<<endl;
	 cin>>otraguia;
	 cin.clear();

	 Guia_Tlf un = g+otraguia;
	 Guia_Tlf dif = g-otraguia;


	 cout << endl << "La union de las dos guias: "<< un <<endl;
	 
	 cout << endl <<"La diferencia de las dos guias:"<< dif <<endl;

	 cout << endl <<"Dime un nombre para establecer los previos"<<endl;
	
	cin>>n;
	 string tlf= g.gettelefono(n);
	 Guia_Tlf p = g.previos(n,tlf);
	 cout<<endl<<"Los nombre previos: "<<p<<endl;
	 
	 
	 cout<<"Listando la guia con iteradores:"<<endl;
	 Guia_Tlf::iterator it;
	 for (it=g.begin(); it!=g.end(); ++it)
	     cout<<*it<<endl;

	it=g.begin();
	it=it+5;

	cout << "Cinco posiciones más alla " << *it << endl;*/

	//.....................................................................PRUEBA DE MIS METODOS AÑADIDOS................................................................................

//PRUEBA DEL MÉTODO QUE DEVUELVE LAS PERSONAS QUE EMPIEZAN POR UNA LETRA --------------------------------------------------------------------------------------------------------------------

	/*char letra;

	cout << "Dime la inicial de los nombres que quieres buscar" << endl;
	cin >> letra;

	Guia_Tlf dev = g.devolver_con(letra);

	cout << endl << endl << "La guia con los nombres que empiezan con " << letra << " es: " << endl << dev << endl;*/

//PRUEBA DEL MÉTODO INTERSECCIÓN -------------------------------------------------------------------------------------------------------------------------------------------------------------	
	
	/*Guia_Tlf otraguia;

	cout << "Introduce otra guia ([Pulse CTRL+D para finalizar] [Entre nombre y numero de telefono se ha de tabular])" << endl;
	cin >> otraguia;
	cin.clear();

	Guia_Tlf inter = g*otraguia;

	cout << endl << "La intersección de las dos guias es: " << endl << inter << endl;*/

//PRUEBA DEL MÉTODO MOSTRAR ENTRE DOS RANGOS -------------------------------------------------------------------------------------------------------------------------------------------------

	/*string nombre1, nombre2;

	cout << "Vamos a buscar los nombre que hay entre dos personas. " << endl << "Por favor, introduzca el primer nombre: " << endl;
	getline (cin, nombre1);

	cout << "Introduzca el segundo nombre: " << endl;
	getline (cin, nombre2);


	Guia_Tlf rango = g.entre(nombre1, nombre2);

	cout << endl << "Los miembros que estan en el rango son: " << endl << rango << endl;*/

//PRUEBA DEL MÉTODO QUE MODIFICA UN TELEFONO A UNA PERSONA EXISTENTE ---------------------------------------------------------------------------------------------------------------------------

	/*string nombre;
	string numtel;

	cout << "Introduzca el nombre de la persona a la que se quiere modificar el telefono: " << endl;
	getline(cin, nombre);

	cout << "Introduzca los digitos del nuevo telefono: " << endl;
	getline(cin, numtel);

	g.modificar_telefono(nombre, numtel);

	cout << endl << "Estamos modificando el telefono ..." << endl << endl << "La guia con el telefono modificado es " << endl << g;*/
	
	//............................................................FIN DE LA PRUEBA DE MIS METODOS AÑADIDOS................................................................................
}
