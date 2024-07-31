#ifndef _TLISTACOM_
#define _TLISTACOM_
#include "tcomplejo.h"
#include <iostream>
using namespace std;



class TListaNodo;



class TListaPos{
	friend class TListaCom;
	private:
		TListaNodo *pos;
	public:
		TListaPos();
		TListaPos(const TListaPos &p);
		~TListaPos();
		TListaPos &operator=(const TListaPos &);
		bool operator==(const TListaPos &de) const;
		bool operator!=(const TListaPos &de) const;
		// devuelve una lista pos nueva no la modifican!!
		TListaPos Anterior() const;
		TListaPos Siguiente() const;
		bool EsVacia() const;

};

class TListaCom{
	
	friend ostream &operator<<(ostream &os, const TListaCom &lista);
	friend class TListaPos;
	private:
		void Borrar();
		TListaNodo *primero, *ultimo;
	public:
		TListaCom();
		~TListaCom();
		TListaCom(const TListaCom &lista);
		TListaCom &operator=(const TListaCom &de);
		
		bool Buscar(const TComplejo &c) const;
		bool Borrar(const TComplejo &c);
		bool InsCabeza(const TComplejo &c);
		bool operator==(const TListaCom &de) const;
		bool operator!=(const TListaCom &de) const;
		int Longitud() const;
		bool BorrarTodos(const TComplejo &);
		
		
		bool EsVacia() const ;
		TListaCom operator+(const TListaCom &de) const;
		TListaCom operator-(const TListaCom &de) const;
		
		TListaPos Primera() const;
		
		
		bool InsertarI(const TComplejo &c,const TListaPos &p );
		TComplejo Obtener(const TListaPos &de) const;
		TListaPos Ultima() const;
		bool InsertarD(const TComplejo &c,const TListaPos &p);
		bool Borrar(TListaPos &p);
};

class TListaNodo{
		
	
	
	friend class TListaPos;
	friend ostream &operator<<(ostream &os, const TListaCom &lista);
	
	friend class TListaCom;
	public:
		TListaNodo();
		TListaNodo(const TComplejo &e);
	private:
		TComplejo e;
		TListaNodo *anterior, *siguiente;
	
};

#endif
