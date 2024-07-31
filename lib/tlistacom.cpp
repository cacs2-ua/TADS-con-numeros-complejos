#include "tlistacom.h"

TListaPos::TListaPos(){
	pos = NULL;
}

TListaPos::TListaPos(const TListaPos &posi){
	pos = posi.pos;
}

TListaPos::~TListaPos(){
	pos = NULL;
}

TListaPos &TListaPos::operator=(const TListaPos &posi){
	pos = posi.pos;
	return *this;
}

bool TListaPos::operator==(const TListaPos &lista) const{
	if(pos == lista.pos){
        return true;
    }else{
        return false;
    }
}

bool TListaPos::operator!=(const TListaPos &lista) const{
	if(pos != lista.pos){
        return true;
    }else{
        return false;
    }
    
}


TListaPos TListaPos::Anterior() const{
	TListaPos nuevisima;
	
	if((NULL!=pos)==true){
		nuevisima.pos = pos->anterior;
	}	
	return nuevisima;
}

TListaPos TListaPos::Siguiente() const{
	TListaPos nuevisima;
	
	if((NULL!=pos)==true){
		nuevisima.pos = pos->siguiente;
	}	
	return nuevisima;
}
bool TListaCom::EsVacia() const {
	if(this->Longitud()==0){
		return true;
	}else{
		return false;
	}
}
bool TListaPos::EsVacia() const{
    if(pos==NULL){
        return true;
    }
	return false;
}

bool TListaCom::InsertarI( const TComplejo &compe,const TListaPos &poss){
	bool insertado = false;
	insertado=true;

	TListaNodo *ptn, *pta;
	if(poss.pos != NULL){
		insertado = true;
		pta = poss.pos->anterior;
		ptn = new TListaNodo(compe);
		
		ptn->siguiente = poss.pos;
		ptn->anterior = pta;
		
		if(pta != NULL){
			pta->siguiente = ptn;
		}
		else{
			primero = ptn;
		}
		poss.pos->anterior = ptn;
	}
	return insertado;
}

bool TListaCom::InsertarD( const TComplejo &c,const TListaPos &p){
	bool insertado = false;
	TListaNodo *ptn, *pts;
	if(p.pos != NULL){
		insertado = true;
		ptn = new TListaNodo(c);
		pts = p.pos->siguiente;
		
		ptn->anterior = p.pos;
		ptn->siguiente = pts;
		
		p.pos->siguiente = ptn;
		if(pts){
			pts->anterior = ptn;
		}
		else{
			ultimo = ptn;
		}
	}
	return insertado;
}



bool TListaCom::Borrar(TListaPos &p){
	bool encontrado;
	TListaNodo *ptl, *pta;

	ptl = primero;
	encontrado = false;
	while(ptl && !encontrado){
		if(ptl == p.pos){
			encontrado = true;
		}
		else{
			ptl = ptl->siguiente;
		}
	}
	if(encontrado){
		pta = ptl->anterior;
		if(pta){
			pta->siguiente = ptl->siguiente;
		}
		else{
			primero = ptl->siguiente;
		}
		if(ptl->siguiente){
			ptl->siguiente->anterior = pta;
		}
		else{
			ultimo = pta;
		}
		delete ptl;
		
		p.pos = NULL;	
	}
	return encontrado;		
}




bool TListaCom::BorrarTodos(const TComplejo &c){
	bool borrado;
	if(Buscar(c) == true){
		borrado = true;
		while(Buscar(c)){
			Borrar(c);	
	    }   
    }
	else{
		borrado=false;
	}
	return borrado;
}




void TListaCom::Borrar(){
	TListaNodo *ptb, *ptl;
	if(primero){ 
		ptl = primero;
		while(ptl){
			ptb = ptl;
			ptl = ptl->siguiente;
			delete ptl;		
		}
		primero = ultimo = NULL;
	}	
}

TListaPos TListaCom::Ultima() const{
	TListaPos p;
	p.pos = ultimo;
	return p;
}

TListaPos TListaCom::Primera() const{
	TListaPos p;
	p.pos = primero;
	return p;
}

TComplejo TListaCom::Obtener(const TListaPos &de) const{
	TComplejo com;
	if(de.pos != NULL){ 
		com = de.pos->e;
		
	}
	return com;
}


TListaCom::TListaCom(const TListaCom &lista){
	primero = ultimo = NULL;
	*this = lista;	

}
TListaCom &TListaCom::operator=(const TListaCom &de){
	TListaNodo *ptn, *ptl;
	if(this != &de){	
		Borrar();	
				
		ptl = de.primero;
		while(ptl){
			ptn = new TListaNodo(ptl->e);
			if(primero == NULL){ 
				primero = ultimo = ptn;
			}
			else{
				ptn->anterior = ultimo;
				ultimo->siguiente = ptn;
				ultimo = ptn;
			}
			ptl = ptl->siguiente;
		}
	}
	return *this;		
}

TListaCom::TListaCom(){
	primero = ultimo = NULL;
}


TListaCom::~TListaCom(){
	Borrar();
/*
	while(primero){
		ptb = primero;
		primero = primero->siguiente;
		delete ptb;
	}
	utlimo = NULL;
*/
}

bool TListaCom::InsCabeza(const TComplejo &c){
	bool insertado=true;
	TListaNodo *pn;
	
	insertado = false;
	pn = new TListaNodo(c);
	
	if(pn != NULL){
		insertado = true;
		if(primero == NULL){
			primero = ultimo = pn;
		}
		else{
			pn->siguiente = primero;
			primero->anterior = pn;
			primero = pn;
		}
	}
	return insertado;
}


bool TListaCom::operator==(const TListaCom &de) const{
	bool iguales = false;
	TListaNodo *ptl1, *ptl2;
	

	if(primero == NULL && de.primero == NULL){
		iguales = true;
	}
	else{
		
		if(primero && de.primero){
			iguales = true; 
			ptl1 = primero;		
			ptl2 = de.primero;
			while(ptl1 && ptl2 && iguales){
				if(ptl1->e == ptl2->e){
					ptl1 = ptl1->siguiente;
					ptl2 = ptl2->siguiente;
				}
				else{
					iguales = false;		
				}
			}
			
			if(ptl1 || ptl2){
				iguales = false;
			}
		}
	}

	return iguales;
}

bool TListaCom::operator!=(const TListaCom &de) const{
	return !(*this == de);
	// return !(this->operator==(de));
	//	TListaCom == TListaCom
}


/*
bool TListaCom::iguales(const TListaCom &de){
	TListaNodo *ptl1 = primero, *ptl2 = de.primero;	
	// warning !! shortcut
	while(ptl1 && ptl2 && ptl1->e == ptl2->e){
		ptl1 = ptl1->siguiente;
		ptl2 = ptl2->siguiente;
	}	
	return !ptl1 && !ptl2;
} 
*/


bool TListaCom::Buscar(const TComplejo &c) const{
	bool encontrado;
	TListaNodo *ptl;
	
	ptl = primero;
	encontrado = false;
	while(ptl && !encontrado){
		if(ptl->e == c){
			encontrado = true;
		}
		else{
			ptl = ptl->siguiente;
		}
	}
	return encontrado;
}

/*
bool TListaCom::Buscar(const TComplejo &c) const{
	bool encontrado;
	TListaNodo *ptl;

	ptl = primero;
	while(ptl && ptl->e != c){
		ptl = ptl->siguiente;
	}
	if(ptl == NULL){
		encontrado = false;
	}
	else{
		encontrado = true;
	}
	return econtrado;
}
*/

bool TListaCom::Borrar(const TComplejo &c){
	bool encontrado;
	TListaNodo *ptl, *pta;

	ptl = primero;
	encontrado = false;
	while(ptl && !encontrado){
		if(ptl->e == c){
			encontrado = true;
		}
		else{
			ptl = ptl->siguiente;
		}
	}
	if(encontrado){ 
		
		if(ptl->anterior == NULL && ptl->siguiente == NULL){
			primero = ultimo = NULL;
			delete ptl;
		}
		else{
			if(primero == ptl){
				primero = primero->siguiente;
				primero->anterior = NULL;
				delete ptl;	
			}
			else{
				if(ultimo == ptl){
					ultimo = ultimo->anterior;
					ultimo->siguiente = NULL;
					delete ptl;
				}
				else{
					ptl->anterior->siguiente = ptl->siguiente;
					ptl->siguiente->anterior = ptl->anterior;
					delete ptl;
				}
			}
		}
	}
	/*
	if(encontrado){
		pta = ptl->anterior;
		if(pta){
			pta->siguiente = ptl->siguiente;
		}
		else{
			primero = ptl->siguiente;
		}
		if(ptl->siguiente){
			ptl->siguiente->anterior = pta;
		}
		else{
			ultimo = pta;
		}
		delete ptl;
	}*/
	return encontrado;	
}

int TListaCom::Longitud() const{
	int cont;
	TListaNodo *ptl;
	ptl = primero;
	cont = 0;
	while(ptl){
		ptl = ptl->siguiente;
		cont++;
	}
	return cont;
}

TListaNodo::TListaNodo(){
	
	anterior = siguiente = NULL;
}

TListaNodo::TListaNodo(const TComplejo &c){
	e = c;
	anterior = siguiente = NULL;
}

ostream &operator<<(ostream &os, const TListaCom &li){
	TListaNodo *ptl;
	
	os << "{";
	ptl = li.primero;
	while(ptl){
		os << ptl->e;
		if(ptl->siguiente != NULL){
			os << " ";
		}
		ptl = ptl->siguiente;
	}
/*
	while(ptl){
		os << ptl->e;
		ptl = ptl->siguiente;
		if(ptl){
			os << " ";
		}
	}
*/

	os << "}";
	return os;
}

TListaCom TListaCom::operator+(const TListaCom &l) const {
    TListaCom l3(*this);

    TListaPos p = l.Primera();

    while(!p.EsVacia()) {
        TComplejo aux2(l.Obtener(p));
        l3.InsertarD(aux2, l3.Ultima());
        p = p.Siguiente();
    }

    return l3;
}


TListaCom TListaCom::operator-(const TListaCom &lista) const{
    TListaCom nl(*this);
	TListaNodo *nodo=lista.primero;
    
    while(nodo!=NULL){
        nl.Borrar(nodo->e);
		nodo=nodo->siguiente;
    }
	
    return nl;
}