#include <iostream>
#include "../include/diccionario.h"

using namespace std;

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
	  
	//list<data<string,string> >::const_iterator it;
	Diccionario<string,string>::const_iterator it;
	  
	for (it=D.begin(); it!=D.end(); ++it){
	  
		    list<string>::const_iterator it_s;
		    
		    os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }
	  
	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave); 
		    
		    int ns;
		    is>>ns; 
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
			      
			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);		      
		    
	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){		 
	  list<string>::const_iterator it_s;
	  
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}	

// ...........................................................

void ImprimirAlreves(const Diccionario<string, string> &D) {

	if (D.size() == 0) return;

	Diccionario<string, string> :: const_iterator it=D.end();

	do {	
		--it;
		list<string>::const_iterator it_s;
	    
	    	cout<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;

	    	for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
		      cout<<(*it_s)<<endl;
	    	}

	    	cout<<"**************************************"<<endl;
	} while (it != D.begin());


}

// ...........................................................

/*Lee un diccioario e imprime datos asociados a una clave. 
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
                  ./usodiccionario < data.txt 
*/
int main(){

	string a;
	Diccionario<string,string> D, aux, final;

	cin>>D;
	cout<<D; //imprime el diccionario

	cout<<"Introduce una palabra"<<endl;
	cin>>a;

	list<string>l=D.getInfo_Asoc(a); //coge el significado de la palabra introducida por el usuario

	if (l.size()>0)
		  EscribeSigni(l);  //muestra por pantalla el significado de la palabra introducida por el usuario



// ..................................................................................... PRUEBA DE LOS METODOS ..........................................................................................
	
	//PRUEBA DE MÉTODOS AÑADIDOS


	//PRUEBA DE IMPRIMIRALREVES (ROSA)
	/*cout << endl << "Imprimiendo al revés..." << endl;

	ImprimirAlreves(D);*/


	//PRUEBA MÉTODO BORRAR UN ELEMENTO

	
	/*cout << "Vamos a borrar la palabra Sentencia" << endl;

	D.borrar_elemento("Compilador");

	cout << endl << "--------------------------DICCIONARIO CON LA PALABRA BORRADA--------------------------------" << endl;

	cout << D;*/

	//PRUEBA MÉTODO UNIÓN DICCIONARIO
	
	/*aux = D;
	list<string>laux;
	string s = "Hola caracola";
	laux.insert(laux.end(),s);
 	aux.Insertar("Hola", laux);
	cout << endl << endl << ".......................................... NUEVO DICCIONARIO .............................................." << endl;
	final = D + aux;
	cout << aux;*/

	//PRUEBA MÉTODO DIFERENCIA DICCIONARIO

	/*aux = D;

	list<string>laux;
	string s = "Hola caracola";
	laux.insert(laux.end(),s);
 	aux.Insertar("Hola", laux);

	cout << endl << endl << "............................... NUEVO DICCIONARIO .............................." << endl;

	final = aux - D;

	cout << final; */
	//PRUEBA MÉTODO QUE NOS MUESTRA UN RANGO DE CLAVES.

	/*cout << "....................................... RANGO ............................................." << endl;

	cout << D.rango("Compilador", "Programa");*/

// .......................................................................... FIN DE  PRUEBA DE LOS METODOS .............................................................................................

}

