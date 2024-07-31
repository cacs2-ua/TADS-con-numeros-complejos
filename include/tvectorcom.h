#ifndef _TVECTORCOM_H_
#define _TVECTORCOM_H_
#include "tcomplejo.h"
#include <iostream>
using namespace std;

class TVectorCom{
	friend ostream &operator<<(ostream &os, const TVectorCom &de);
	private:
		
		TComplejo *c;
		
		int tamano;
		TComplejo error;
	public:
		TVectorCom();
		TVectorCom(int tam);
		TVectorCom(const TVectorCom &v);
		~TVectorCom();
		
		bool operator!=(const TVectorCom &de) const;
		TVectorCom &operator=(const TVectorCom &de);

		bool operator==(const TVectorCom &de) const;
		
		bool ExisteCom(const TComplejo &com) const;
		void MostrarComplejos(double re) const;
		TComplejo &operator[](int i);
		TComplejo operator[](int i) const;
		int Tamano() const;
		int Ocupadas() const;
		bool Redimensionar(int tam);
};




#endif
