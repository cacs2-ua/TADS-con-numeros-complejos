#ifndef TABBCOM_H
#define TABBCOM_H

#include "tvectorcom.h"


// forward declartion
class TNodoABB;

class TABBCom{
	friend ostream &operator<<(ostream &os, const TABBCom &ab);
	friend class TNodoABB;
	private:
		TNodoABB *nodo;		
		void InordenAux(TVectorCom &v, int &pos) const;
		void PostordenAux(TVectorCom &v, int &pos) const;
		void PreordenAux(TVectorCom &v, int &pos) const;
		TComplejo BuscarMayor() ;
	public:
		TABBCom();
		TABBCom(const TABBCom &a);
		~TABBCom();
		TABBCom &operator=(const TABBCom &de);
		bool Insertar(const TComplejo &c);
		int Nodos() const;
		TVectorCom Inorden() const;
		TVectorCom Postorden() const;
		TVectorCom Preorden() const;
		TVectorCom Niveles() const;
		bool operator==(const TABBCom &ab) const;
		bool EsVacio() const;
		bool Borrar(const TComplejo &c);
		bool Buscar(const TComplejo &c) const;
		TComplejo Raiz() const;
		int Altura() const;
		int NodosHoja() const;
		
};

class TNodoABB{
	friend class TABBCom;
	private:
		TComplejo item;
		TABBCom iz, de;
	public:
		TNodoABB();
		TNodoABB(const TComplejo &c);
		TNodoABB(const TNodoABB &n);
		~TNodoABB();
		TNodoABB &operator=(const TNodoABB &de);
		

};



#endif
