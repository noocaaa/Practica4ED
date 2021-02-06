#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * @brief Tipo elemento que define el diccionario.
 * @param T, es el tipo de dato asociado a una clave queno se repite (DNI p.ej.)
 * @param list<U> es una lista de datos (string p.ej) asociados a la clave de tipo T. 
 * @note El diccionario está ordenado de menor a mayor clave.
 */

/*template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;
 };*/


/**
 * @brief Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T.
 * @param const data &d1, el dato que se supone que tiene una clave menor
 * @param const data <T,U>&d2, el dato que se supone que tiene una clave mayor
 * @return devuelve true si d1 < d2, false si d2 < d1.
 * @note Puede usarse como un funtor.
 */

/*template <class T, class U>
bool operator< (const data &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}*/	   

/**
 * @class Diccionario
 * @brief Un diccionario es una lista de datos de los definidos anteriormente. 
 * @warning Cuidado porque se manejan listas de listas. 
 */

template <class T,class U>
class Diccionario{
	private:

		/**
		 * @brief Tipo elemento que define el diccionario.
		 * @param T, es el tipo de dato asociado a una clave queno se repite (DNI p.ej.)
		 * @param list<U> es una lista de datos (string p.ej) asociados a la clave de tipo T. 
		 * @note El diccionario está ordenado de menor a mayor clave.
		 */
       		  		
		struct data{
		     T clave;
		     list<U> info_asoci;
		     
		     	/**
			 * @brief Construcotor por defecto
			 */
			data() {}

			/**
			 * @brief Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T.
			 * @param const data &d1, el dato que se supone que tiene una clave menor
			 * @param const data <T,U>&d2, el dato que se supone que tiene una clave mayor
			 * @return devuelve true si d1 < d2, false si d2 < d1.
			 * @note Puede usarse como un funtor.
			 */
			bool operator<(const data &d2)	{
				bool resultado = (clave[0] < d2.clave[0]) ? true : false;
				return resultado;
			}
		};


		list<data> datos;

		/**
		 * @brief Funcion que copia el diccionario pasado al actual. 
		 * @param const Diccionario<T,U>& D, diccionario que se va a copiar
		 */
		void Copiar(const Diccionario<T,U>& D){
			/*typename list<data >::const_iterator it_d;
			typename list<data >::iterator it=this->datos.begin();*/

			datos.assign(D.datos.begin(),D.datos.end());
			/*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
			     this->datos.insert(it,*it_d);
			     
			}*/
		}

		/**
		 * @brief Funcion que borra todos los datos que hay en datos.
		 */
		void Borrar() {
			this->datos.erase(datos.begin(),datos.end());
		}	      
			   
			       
	public:
		 /**
		  * @brief Constructor por defecto
		  */
		 Diccionario():datos(list<data >()){}
		 
		 /**
		  * @brief Constructor de copias
		  */
		 Diccionario(const Diccionario<T,U> &D){
			   Copiar(D);
		 }
		 
		 /**
		  * @brief Destructor.
		  */
		 ~Diccionario(){}
		 
		 /**
		  * @brief Operador de asignación
		  */
		 Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
			   if (this!=&D){
				     Borrar();
				     Copiar(D);
			   }
			   return *this;
		 }
		 

		 /**
		  * @brief Inserta un nuevo registro en el diccionario. Lo hace a través de la clave e inserta la lista con toda la información asociada a esa clave.
		  * @param const T& clave, la clave que identifica a la lista, en este caso, el nombre de una palabra.
		  * @param const list<U> &info, lista que contiene la descripción de la clave.
		  */
		 void Insertar(const T& clave,const list<U> &info){
			   
		     typename list<data >::iterator it;
		     
		     if (!Esta_Clave(clave,it)){
			       data p;
			       p.clave = clave;
			       p.info_asoci=info;
			 
			       datos.insert(it,p);
			      	 
		     }
		     
		 }
		 
		 /**
		  * @brief Añade una nueva informacion asocida a una clave que está en el diccionario.
		  * @param const U &s, el significado a añadir
		  * @param const T &p, clave de la palabra
		  */
		 void AddSignificado_Palabra(const U & s ,const T &p){
			   typename list<data >::iterator it;
			   
			   if (!Esta_Clave(p,it)){
				    datos.insert(it,p);
			   }	    
			   
			    //Insertamos el siginificado al final
		           (*it).info_asoci.insert((*it).info_asoci.end(),s);
		 }

		 /**
		  * @briefevuelve la información (una lista) asociada a una clave p. 
		  * @param const T &p, clave de la que se pide su información asociada
		  * @return devuelve la información asociada a la clave si existe, sino una lista vacía.
		  */
		  list<U>  getInfo_Asoc(const T & p) {
			   typename list<data >::iterator it;
			   
			   if (!Esta_Clave(p,it)){
				return list<U>();
			   }
			   else{
				return (*it).info_asoci;
			   }
		 }	   
				
		 /**
		  * @brief Devuelve el tamaño del diccionario
		  */
		 int size()const{
			   return datos.size();
		 }

		 /**
		  * @brief  Busca la clave p en el diccionario.
		  * @param const T &p, la clave que se quiere buscar en datos
		  * @param typename  list<data >::iterator &it_out, el iterador con el que buscaremos la clave
		  * @return Si está devuelve un iterador a dónde está clave. Si no está, devuelve end() y deja el iterador de salida apuntando al sitio dónde debería estar la clave
		  */		
		bool Esta_Clave(const T &p, typename  list<data >::iterator &it_out){
			  
			  if (datos.size()>0){
				    
			      typename list<data >::iterator it;
			      
			      for (it=datos.begin(); it!=datos.end() ;++it){
					if ((*it).clave==p) {
						  it_out=it;
						  return true;
					}
					else if ((*it).clave>p){
						  it_out=it;
						  return false;
					}	  
					   
			      }
			      
			      it_out=it;
			      return false;
			  }
			  else {	
				    it_out=datos.end();
				    return false;
			  }	    
		 }
		
// ............................................................................................ MIS MÉTODOS AÑADIDOS ....................................................................................
		 /**
		  * @brief Método que borra un elemento de datos
		  * @param const T &clave, elemento que se quiere borrar
		  * @return devuelve true si la clave esta y se ha borrado, false si la clave introducida no ha sido encontrada en datos.
		  */	
		bool borrar_elemento (const T &clave) {
			bool esta = false;

			typename list<data >::iterator it;

			//buscamos si esta la clave
			if (Esta_Clave(clave, it)) {
				datos.erase(it);
				esta = true;
			} 

			return esta;	  
		}   

		 /**
		  * @brief Operador +, es decir, el operador de unión. 
		  * @param const Diccionario &dos, diccionario que contiene palabras que le vamos a unir al nuesto
		  * @return devuelve el diccionario resultante de la union
		  */    
		Diccionario<T, U> operator+(Diccionario<T, U> &D) {

		   	Diccionario dic(*this);
		    	typename list<data>::iterator it, it2;

			for (it = D.datos.begin(); it != D.datos.end(); ++it){ 
				// Si no hay un elemento con esa clave lo insertamos
				if (!Esta_Clave((*it).clave, it2))
					dic.Insertar((*it).clave, (*it).info_asoci);
			}
		    	return dic;
		}

		 /**
		  * @brief Operador -, es decir, el operador de diferencia. 
		  * @param const Diccionario &dos, diccionario que contiene palabras que determinaran con que palabras nos quedamos
		  * @return devuelve el diccionario resultante de la diferencia
		  */    
		Diccionario<T, U> operator-(Diccionario<T, U> &D) {
			
			Diccionario aux; //creamos un diccionario auxiliar que contendra todos los elementos del nuestro diccionario.

			typename list<data>::iterator it, ita;
			

			for (it = datos.begin(); it != datos.end(); it++) {
				if (!D.Esta_Clave((*it).clave, ita)) {
					aux.Insertar((*it).clave, (*it).info_asoci);
				}
			}

			return aux;
		}


		 /**
		  * @brief Método que une nuestro diccionario con el pasado por parametros
		  * @param const Diccionario &dos, diccionario con el que queremos unir el nuestro.
		  * @return devuelve el diccionario resultante de la union
		  * @note NO se ha querido implementar el operator+, sino el método. Dependiendo de cómo se llame saldrá un resultado diferente.
		  */
		Diccionario<T,U> rango(const T &clave1, const T &clave2) {

			typename list<data >::iterator it, ita;

			Diccionario<T,U>  aux; //diccionario a devolver

			//nos cercioramos de que el rango sea correcto
			
			if (Esta_Clave(clave1, it) && Esta_Clave(clave2, ita)) {
				ita++;
				for (; it != ita; ++it) {
					aux.Insertar((*it).clave, (*it).info_asoci);
				}
			}

			return aux;
		}


		/**
		 * @class Iterator
		 */		
		class iterator {
			private:
				 typename list<data > :: iterator it;

			public:

				/**
				 * @brief Constructor de la clase iterator
				 */
				iterator(){}

				/**
				 * @brief Operador de incremento
				 * @return devuelve el puntero a iterador que contiene el valor incrementado en uno
				 */
				iterator & operator++() {
					++it;
					return *this;
					//this es un puntero a iterador
					//*this es un objeto de tipo iterador
					//this->it es un objeto de tipo list<data> :: iterador
				}

				/**
				 * @brief Operador de decremento
				 * @return devuelve el puntero a iterador que contiene el valor decrementado en uno
				 */		
				iterator & operator--() {
					--it;
					return *this;
					//this es un puntero a iterador
					//*this es un objeto de tipo iterador
					//this->it es un objeto de tipo list<data> :: iterador
				}

				/**
				 * @brief Operador de intersección
				 * @return devuelve el puntero a iterador que contiene la intersección 
				 */
				const data & operator*() {
					return *it;
				}

				/**
				 * @brief Operador de igualdad
				 * @return devuelve true si son iguales, false si son diferentes
				 */
				bool operator==(const iterator &i) const{
					return it==i.it;
				}

				/**
				 * @brief Operador de no igualdad
				 * @return devuelve true si son diferentes, false si son iguales
				 */
				bool operator!=(const iterator &i) const{
					return it!=i.it;
					//return !(*this == i);
				}

				friend class Diccionario;
		};

		/**
		 * @class Const_iterator
		 */
		class const_iterator {
			private:
				typename list<data > :: const_iterator it;

			public:

				/**
				 * @brief Constructor de la clase const iterator
				 */
				const_iterator(){}

				/**
				 * @brief Operador de incremento
				 * @return devuelve el puntero a iterador que contiene el valor incrementado en uno
				 */
				const_iterator & operator++() {
					++it;
					return *this;
					//this es un puntero a iterador
					//*this es un objeto de tipo iterador
					//this->it es un objeto de tipo list<data> :: iterador
				}
			
				/**
				 * @brief Operador de decremento
				 * @return devuelve el puntero a iterador que contiene el valor decrementado en uno
				 */	
				const_iterator & operator--() {
					--it;
					return *this;
					//this es un puntero a iterador
					//*this es un objeto de tipo iterador
					//this->it es un objeto de tipo list<data> :: iterador
				}

				/**
				 * @brief Operador de intersección
				 * @return devuelve el puntero a iterador que contiene la intersección 
				 */
				const data & operator*(){
					return *it;
				}

				/**
				 * @brief Operador de igualdad
				 * @return devuelve true si son iguales, false si son diferentes
				 */
				bool operator==(const const_iterator &i) const{
					return it==i.it;
				}

				/**
				 * @brief Operador de no igualdad
				 * @return devuelve true si son diferentes, false si son iguales
				 */
				bool operator!=(const const_iterator &i) const{
					//return it!=i.it;
					return !(*this == i);
				}

				friend class Diccionario;

		};
		 
		 /*Funciones begin y end asociadas al diccionario*/

		/**
		 * @brief iterator del inicio 
		 * @return devuelve un puntero que apunta a la posición inicial de datos
		 */
		iterator begin() {
			iterator i;
			i.it = datos.begin();
			return i;
		}		

		/**
		 * @brief iterator del final 
		 * @return devuelve un puntero que apunta a la posición final de datos
		 */
		iterator end() {
			iterator i;
			i.it = datos.end();
			return i;
		}

		/**
		 * @brief Const iterator de inicio 
		 * @return devuelve un puntero que apunta a la posición inicial de datos
		 */
		const_iterator begin() const{
			const_iterator i;
			i.it = datos.begin();
			return i;
		}	

		/**
		 * @brief Const iterator del final 
		 * @return devuelve un puntero que apunta a la posición final de datos
		 */
		const_iterator end() const{
			const_iterator i;
			i.it = datos.end();
			return i;
		}

// ......................................................................................FIN DE MIS MÉTODOS AÑADIDOS ....................................................................................
		 	
};

#endif
	 
	  

	  
