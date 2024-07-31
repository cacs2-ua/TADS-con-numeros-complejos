#ifndef TABBAVL_H
#define TABBAVL_H
#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tavlcom.h"
class TNodoAVL;
class TAVLCom{
	friend ostream &operator<<(ostream &os, const TAVLCom &ab);
	friend class TNodoAVL;
	private:
		TNodoAVL *raiz;		
		void InordenAux(TVectorCom &v, int &pos) const;
		void PostordenAux(TVectorCom &v, int &pos) const;
		void PreordenAux(TVectorCom &v, int &pos) const;
		TComplejo BuscarMayor();

		// la funcion ahora tambien devuelve si despues de la insercion
		// el arbol ha crecido en altura.
		bool Insertar(const TComplejo &c, bool &crece); // aqui se implementa la insercion
		bool Borrar(const TComplejo &c, bool &decrece);
		void DD();
		void DI();
		void ID();
		void II();	
	public:
		TAVLCom();
		TAVLCom(const TAVLCom &a);
		~TAVLCom();
		TAVLCom &operator=(const TAVLCom &de);
		bool Insertar(const TComplejo &c);	// llama al de arriba que implementa la insercion.
		int Nodos() const;
		TVectorCom Inorden() const;
		TVectorCom Postorden() const;
		TVectorCom Preorden() const;
		TVectorCom Niveles() const;
		bool operator==(const TAVLCom &ab) const;
		bool operator!=(const TAVLCom &ab) const;
		bool EsVacio() const;
		bool Borrar(const TComplejo &c);
		bool Buscar(const TComplejo &c) const;
		TComplejo Raiz() const;
		int Altura() const;
		int NodosHoja() const;		
};
class TNodoAVL{
	friend class TAVLCom;
	private:
		TComplejo item;
		TAVLCom iz, de;
		int fe;  /// factor de equilibrio del nodo.
	public:
		TNodoAVL();
		TNodoAVL(const TComplejo &c);
		TNodoAVL(const TNodoAVL &n);
		~TNodoAVL();
		TNodoAVL &operator=(const TNodoAVL &de);
};
#endif
