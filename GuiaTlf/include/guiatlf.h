/**
 * @file : guiatlf.h
 * @brief: TDA guia de telefonos
 * @authors: Profesores practicas ED & Noelia Carrasco VIalr
 */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>

using namespace std; 

/**
  * @brief Operador de flujo de entrada
  * @param is, flujo de entrada
  * @param const pair<const string,string> &d, par de elementos que queremos mostrar
  */
istream & operator>>(istream &is,pair<string,string> &d){
	  
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}

/**
  * @brief Operador de flujo de salida
  * @param os, flujo de salida
  * @param const pair<const string,string> &d, par de elementos que queremos mostrar
  */
ostream & operator<<(ostream &os,const pair<const string,string> &d){
	  os<<d.first<<'\t'<<d.second<<endl;
	  return os;
}	

/**
  * @class Guia_Tlf
  * @brief T.D.A. Guia_Tlf 
  * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos. 
  */

class Guia_Tlf{
  /**
  * @page repGuia_Tlf Rep del TDA Guia_Tlf
  *
  * @section invGuia_Tlf Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
  *
  * @section faGuia_Tlf Función de abstracción
  *
  * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */
	  private:
		    map<string,string> datos; //si admites que haya nombres repetidos tendrías que usar un
					     //multimap
					     
	  public:
		    
		    /**
		     * @brief Acceso a un elemento
		     * @param nombre: nombre del elemento  elemento acceder
		     * @return devuelve el valor asociado a un nombre, es decir el teléfono
		    */
		    //si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
		    // los telefonos asociados a dicho nombre
		    string & operator[](const string &nombre) {
			      return datos[nombre];
		    }
		    
		    
		    string  gettelefono(const string & nombre){
			      map<string,string>::iterator it=datos.find(nombre);
			      if (it==datos.end()) 
					return string("");
			      else return it->second;
		    }
		     
		    /**
		     * @brief Insert un nuevo telefono 
		     * @param nombre: nombre clave del nuevo telefono
		     * @param tlf: numero de telefono
		     * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
			      o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf){
			      pair<string,string> p (nombre,tlf);
			      pair< map<string,string> ::iterator,bool> ret;

			      ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
			      return ret;     
					
		    }
		    
		    /**
		     * @brief Insert un nuevo telefono 
		     * @param p: pair con el nombre y el telefono asociado
		     
		     * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
			      o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(pair<string,string> p){
			      
			      pair<map<string,string> ::iterator,bool> ret;

			      ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
			      return ret;     
					
		    }
		    
		    
		    
		    /**
		     * @brief Borrar un telefono
		     * @param nombre: nombre que se quiere borrar
		     * @note: en caso de que fuese un multimap borraria todos con ese nombre
		    */
		    void borrar(const string &nombre){
			   map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
			   map<string,string>::iterator itupper = datos.lower_bound(nombre);//el primero que ya no tiene dicho nombre
			   datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
			   //OTRA ALTERNATIVA
			   //pair<map<string,string>::iterator,map<string,string>::iterator>ret;
			   //ret = datos.equal_range(nombre
			   //datos.erase(ret.first,ret.second);   
		    }
		    
		    /**
		      * @brief Borrar un telefono
		      * @param nombre: nombre que se quiere borrar y telefono asociado
		      * @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		     */
		   	 //con map siempre hay uno con multimap puede existir mas de uno
		    void borrar(const string &nombre,const string &tlf){
		           map<string,string>::iterator itlow = datos.lower_bound(nombre);
			   map<string,string>::iterator itupper = datos.upper_bound(nombre);
			   map<string,string>::iterator it;
			   bool salir =false;
			   for (it=itlow; it!=itupper && !salir;++it){
				     if (it->second==tlf){
					datos.erase(it);
					salir = true;
				     }		
			   }		
			   
		    }

		    /**
		      * @brief  Numero de telefonos 
		      * @return el numero de telefonos asociados
		      */
		    int size()const{
			      return datos.size();
		    }	      
		    /**
		      * @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		      * @param nombre: nombre sobre el que queremos consultar
		      * @return numero de telefonos asociados a un nombre
		      */
		    //al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
		    unsigned int contabiliza(const string &nombre){
			      return datos.count(nombre);
		    }
		    
		    /**
		     * @brief Limpia la guia
		     */
		    void clear(){
			      datos.clear();
		    }	      
		    /**
		     * @brief Union de guias de telefonos
		     * @param g: guia que se une
		     * @return: una nueva guia resultado de unir el objeto al que apunta this y g
		    */
		    Guia_Tlf operator+(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string,string>::const_iterator it;
			for (it=g.datos.begin();it!=g.datos.end();++it){
			   aux.insert(it->first,it->second);
			}	  
			return aux;
			
		    }	   
		    	      
		    /**
		     * @brief Diferencia de guias de telefonos
		     * @param g: guia a restar
		     * @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		    */
		    Guia_Tlf operator-(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string,string>::const_iterator it;
			for (it=g.datos.begin();it!=g.datos.end();++it){
			   aux.borrar(it->first,it->second);
			}	  
			return aux;
			
		    }



//.......................................................................................MIS MÉTODOS AÑADIDOS ...........................................................................................
		/**
		  * @brief Operador*, representa la intersección
		  * @param const Guia_Tlf &g, la Guia_Tlf con la que realizaremos la intersección. 
		  * @return devuelve una Guia_Tlf auxiliar que contiene la intersección.
		  */
		Guia_Tlf operator*(const Guia_Tlf & g){
			Guia_Tlf aux;

			map<string,string>::const_iterator it;

			for (it=g.datos.begin();it!=g.datos.end();++it){
			   if (datos.find(it->first) != datos.end())
				aux.insert(*it);
			}
	  
			return aux;
			
		}

		/**
		  * @brief método que devuelve los nombres de las personas que empiezan con cierta letra
		  * @param l, char que es la letra con la que deben empezar las personas que seleccionaremos
		  * @return devuelve una Guia_Tlf auxiliar que contiene la selección de personas que su nombre empieze por la inicial l.
		  */
		Guia_Tlf devolver_con(char &l) {
			Guia_Tlf aux;
			char letra = toupper(l);
			map<string,string>::const_iterator it;

			for (it=datos.begin(); it != datos.end(); ++it){
				if ((*it).first[0] == letra)				
					aux.insert((*it).first, (*it).second);
			}

			return aux;
		}

		/**
		  * @brief Método entre que devuelve los nombres de personas que estan dentro de un rango
		  * @param const String &uno, el segundo nombre que indica el nombre del rango
		  * @param const String &dos, el segundo nombre que indica el fin del rango
		  * @return devuelve una Guia_Tlf auxiliar que contiene solamente las personas que estan dentro de ese rango, estando los dos nombres inclusive
		  */
		Guia_Tlf entre(const string &uno, const string &dos) {

			Guia_Tlf aux;
			bool continuar1, continuar2;
			continuar1 = continuar2 = true;

			map<string,string>::const_iterator it, ita;

			it = datos.begin();

			do {
				if ((*it).first == uno) {
					continuar1 = false;
				}	
				it++;
			} while (it != datos.end() && continuar1);

			ita = it;

			do {
				if ((*ita).first == dos) {
					continuar2 = false;
				}	
				ita++;
			} while (it != datos.end() && continuar2);

			if (!continuar1 && !continuar2) {
				--it;
				for (; it != ita; it++){
					aux.insert((*it).first, (*it).second);
				}
			}

			return aux;

		}

		/**
		  * @brief método que modifica el telefono de una persona que esta en la guia
		  * @param const string &nombre, nombre de la persona a la que queremos modificar el telefono.
		  * @param const string &num, el número de telefono nuevo de la persona. 
		  */
		void modificar_telefono(const string &nombre, const string &num) {
			bool continuar = true;

			map<string,string>::const_iterator it;

			for (it = datos.begin() ;it != datos.end() && continuar; it++){
				if ((*it).first == nombre) {
					if ((*it).second != num) { //si el numero de telefono que le pasamos no es el mismo.
						datos.erase(it);
						insert(nombre, num);
						continuar = false;
					}
				}
			}

		}

//.........................................................................FIN DE MIS MÉTODOS AÑADIDOS ..................................................................................................

		    /**
		     * @brief  Obtiene una guia con los nombre previos a uno dado
		     * @param nombre: nombre delimitador
		     * @param tlf: telefono asociado a nombre
		     * @return nueva guia sin nombres mayores que \a  nombre
		     */
		    Guia_Tlf previos(const string &nombre,const string &tlf){
			map<string,string>::value_compare vc=datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
			Guia_Tlf aux;
			pair<string,string>p(nombre,tlf);
			map<string,string>::iterator it=datos.begin();
			while (vc(*it,p)){
				  aux.insert(*it++);
				  
			}
			return aux;		      
		     }	      
		    
		    
		    /**
		     * @brief Escritura de la guia de telefonos
		     * @param os: flujo de salida. Es MODIFICADO
		     * @param g: guia de telefonos que se escribe
		     * @return el flujo de salida
		     */    
		    friend ostream & operator<<(ostream & os, Guia_Tlf & g){
			      map<string,string>::iterator it;
			      for (it=g.datos.begin(); it!=g.datos.end();++it){
					os<<it->first<<"\t"<<it->second<<endl;
			      }
			      return os;
		    }
		    
		    /**
		     * @brief Lectura de  la guia de telefonos
		     * @param is: flujo de entrada. ES MODIFICADO
		     * @param g: guia de telefonos. ES MODIFICADO
		     * @return el flujo de entrada
		    */
		    friend istream & operator>>(istream & is, Guia_Tlf & g){
			      pair<string,string> p;
			      Guia_Tlf aux;
			      
			      while (is>>p){
				  aux.insert(p);
			      }
			      g=aux;
			      return is;
		    }
		    

		    /**
		     * @brief Clase para iterar sobre la guia
		     */
		    class iterator{
		    	private:
		     		map<string,string>::iterator it, final;
		     	public:
		       		iterator & operator++(){
				    ++it;
		      		}

			       iterator & operator--(){
				   --it;
			       }

			       pair<const string,string> &operator *(){
				  return *it;
			       }

			       bool operator ==(const iterator &i){
				  return i.it==it;
			       }	  
			       
			       bool operator !=(const iterator &i){
				  return i.it!=it;
			       }

				iterator operator=(const iterator &i) {
					it = i.it;
					return *this;
				}

				iterator & operator+(int a) {
					for (int k=0; k < a && it != final; k++) {
						++it;
					}
					return *this;
				}

			       friend class Guia_Tlf;
		    };
		    
		    /**
		     * @brief Clase para iterar sobre la guia
		     */
		    class const_iterator{
		    	private:
		     		map<string,string>::const_iterator it, final;
		     	public:
		       		const_iterator & operator++(){
				    ++it;
		      		}

			       const_iterator & operator--(){
				   --it;
			       }

			       const pair<const string,string> &operator *(){
				  return *it;
			       }

			       bool operator ==(const const_iterator &i){
				  return i.it==it;
			       }	  
			       
			       bool operator !=(const const_iterator &i){
				  return i.it!=it;
			       }

				const_iterator operator=(const const_iterator &i) {
					it = i.it;
					return *this;
				}

				const_iterator & operator+(int a) {
					for (int k=0; k < a && it != final; k++) {
						++it;
					}
					return *this;
				}

			       friend class Guia_Tlf;
		    };

		/**
		 * @brief Inicializa un iterator al comienzo de la guia
		 */
		iterator begin(){
			iterator i;
			i.it=datos.begin();
			i.final = datos.end();
			return i;
		}
	
		/**
		 * @brief Inicializa un iterator al final de la guia
		 */
		iterator end(){
			iterator i;
			i.it=datos.end();
			i.final = datos.end();
			return i;
		}  

		/**
		 * @brief Inicializa un const_iterator al comienzo de la guia
		 */
		const_iterator begin() const{
			const_iterator i;
			i.it=datos.cbegin();
			i.final = datos.cend();
			return i;
		}	

		/**
		 * @brief Inicializa un const_iterator al final de la guia
		 */
		const_iterator end() const{
			const_iterator i;
			i.it=datos.cend();
			i.final = datos.cend();
			return i;
		} 				
      
		    
};

#endif

