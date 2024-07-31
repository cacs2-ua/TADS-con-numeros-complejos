#include "tavlcom.h"
#include <queue>
//Raúl Luján Domenech 50590584Z

//si
TAVLCom::TAVLCom(const TAVLCom &a){
	if((a.raiz != NULL)==true){
		
		raiz = new TNodoAVL(*(a.raiz));
	}
	else{
		raiz = NULL;
	}
}



TNodoAVL &TNodoAVL::operator=(const TNodoAVL &n){
	item = n.item;
	iz = n.iz;
	de = n.de;
	fe = n.fe; 
	return *this;
}


TNodoAVL::TNodoAVL(const TNodoAVL &n):item(n.item), iz(n.iz), de(n.de), fe(n.fe){

}

//si
TAVLCom::~TAVLCom(){
	if((raiz == NULL)==false){
		delete raiz; 
		raiz = NULL;	
	}
}

TNodoAVL::~TNodoAVL(){
	
}

void TAVLCom::PreordenAux(TVectorCom &vc, int &posic) const{
	if((raiz == NULL)==false){
		vc[posic] = raiz->item;
		posic++;
		raiz->iz.PreordenAux(vc, posic);
		raiz->de.PreordenAux(vc, posic);
	}
}
TVectorCom TAVLCom::Postorden() const{
	TVectorCom vc(Nodos());
	int posic = 0;	
	posic++;
	PostordenAux(vc, posic);
	return vc;
}

void TAVLCom::PostordenAux(TVectorCom &vc, int &posic) const{
	if((raiz == NULL)==false){
		raiz->iz.PostordenAux(vc, posic);
		raiz->de.PostordenAux(vc, posic);
		int p=posic;
		vc[p] = raiz->item;
		posic++;
	}
}
void TAVLCom::InordenAux(TVectorCom &vc, int &posic) const{
	if((raiz == NULL)==false){
		raiz->iz.InordenAux(vc, posic);
		vc[posic] = raiz->item;
		posic--;
		posic=posic +2;
		raiz->de.InordenAux(vc, posic);
	}
}

TVectorCom TAVLCom::Preorden() const{
	TVectorCom v(Nodos());
	int pos = 0;
	pos++;	
	PreordenAux(v, pos);
	return v;
}



TVectorCom TAVLCom::Inorden() const{
	TVectorCom vc(Nodos());
	int posic = 0;
	posic++;	
	InordenAux(vc, posic);
	return vc;
}




TAVLCom::TAVLCom(){
	raiz = NULL;	
}

//si
void TAVLCom::DD() {
	if (raiz != nullptr && raiz->de.raiz != nullptr) {
		TNodoAVL* auxRight = raiz;
		TNodoAVL* auxRD = raiz->de.raiz;
		TNodoAVL* auxRDiz = auxRD->iz.raiz;

		raiz = auxRD;
		auxRight->de.raiz = auxRDiz;
		raiz->iz.raiz = auxRight;

		auxRight->fe = 0;
		auxRD->fe = 0;
	}
}

//si
void TAVLCom::II() {
	if (raiz != nullptr && raiz->iz.raiz != nullptr) {
		TNodoAVL* auxRight = raiz;
		TNodoAVL* auxRI = raiz->iz.raiz;
		TNodoAVL* auxRIde = auxRI->de.raiz;

		raiz = auxRI;
		auxRight->iz.raiz = auxRIde;
		raiz->de.raiz = auxRight;

		auxRight->fe = 0;
		auxRI->fe = 0;
	}
}

bool TAVLCom::Insertar(const TComplejo &c, bool &crece){
	bool ins, ci, cD;

	ins = false;
	ci = false;
	cD = false;	
	if(raiz == NULL){
		raiz = new TNodoAVL(c);
		crece = true;	// este arbol crece.
	}
	else{
		if(c < raiz->item){
			ins = raiz->iz.Insertar(c, ci);
			cD = false;		
		}
		else{
			if(c > raiz->item){
				ins = raiz->de.Insertar(c, cD);
				ci = false;			
			}
			else{
				ci = cD = false;
				ins = false;
				crece = false;	
			}		
		} 
	}
	if(ci){
		raiz->fe--;
		switch(raiz->fe){
			case 0:
				crece = false;
				break;
			case -1:
				crece = true;
				break;
			case -2:
				switch(raiz->iz.raiz->fe){
					case -1:
						II();
						crece = false;
					break;
					case 1:		
						ID();
						crece = false;
					break;
				}
		}
		
	}
	if(cD){
		raiz->fe++;
		switch(raiz->fe){
			case 0:
				crece = false;
				break;
			case 1:
				crece = true;
				break;
			case 2:
				switch(raiz->de.raiz->fe){
					case 1:
						DD();
						crece = false;
						break;
					case -1:
						crece = false;
						DI();
						break;
				}
		}
	}
	return ins;
}


TAVLCom& TAVLCom::operator=(const TAVLCom& de) {
	if (this != &de) {
		TAVLCom temp(de);  
		std::swap(raiz, temp.raiz); 
	}
	return *this;
}
void TAVLCom::ID() {
	if (raiz == nullptr || raiz->iz.raiz == nullptr) {
		return; // No se puede realizar la rotación
	}

	TNodoAVL* auxRight = raiz;
	TNodoAVL* auxLeft = raiz->iz.raiz;
	TNodoAVL* auxDerech = raiz->iz.raiz->de.raiz;

	raiz = auxLeft->de.raiz;
	auxLeft->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = auxLeft;
	auxRight->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = auxRight;

	// Actualizar factores de equilibrio
	if ((raiz->fe != 0)==false) {
		raiz->fe = raiz->iz.raiz->fe = raiz->de.raiz->fe = 0;
	}
	else if ((raiz->fe != -1)==false) {
		raiz->fe = 0;
		raiz->iz.raiz->fe = 0;
		raiz->de.raiz->fe = 1;
	}
	else {
		raiz->fe = 0;
		raiz->iz.raiz->fe = -1;
		raiz->de.raiz->fe = 0;
	}
}


//n
bool TAVLCom::Insertar(const TComplejo &c){
	bool crece, ins;
	ins = Insertar(c, crece); 
	return crece;
}

TNodoAVL::TNodoAVL(){
	
	fe = 0;
}


TNodoAVL::TNodoAVL(const TComplejo &c):item(c){
	fe = 0;
}
//si
void TAVLCom::DI() {
	if (raiz == nullptr || raiz->de.raiz == nullptr) {
		return; // No se puede realizar la rotación
	}

	TNodoAVL* auxRight = raiz;
	TNodoAVL* auxDerech = raiz->de.raiz;
	TNodoAVL* auxLeft = raiz->de.raiz->iz.raiz;

	raiz = auxDerech->iz.raiz;
	auxDerech->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = auxDerech;
	auxRight->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = auxRight;

	// Actualizar factores de equilibrio
	if ((raiz->fe != 0)==false) {
		raiz->fe = raiz->iz.raiz->fe = raiz->de.raiz->fe = 0;
	}
	else if ((raiz->fe != -1)==false) {
		raiz->fe = 0;
		raiz->iz.raiz->fe = 0;
		raiz->de.raiz->fe = 1;
	}
	else {
		raiz->fe = 0;
		raiz->iz.raiz->fe = -1;
		raiz->de.raiz->fe = 0;
	}
}



//si
int TAVLCom::Nodos() const {
	if (raiz == nullptr) {
		return 0;
	}

	int n = 1;
	if (raiz->iz.raiz != nullptr) {
		n += raiz->iz.Nodos();
	}
	if (raiz->de.raiz != nullptr) {
		n += raiz->de.Nodos();
	}

	return n;
}

//si
TVectorCom TAVLCom::Niveles() const {
	TVectorCom v(Nodos());
	int pos = 1;

	if (raiz == nullptr) {
		return v;
	}

	queue<TNodoAVL*> teil;
	teil.push(raiz);

	while (!teil.empty()) {
		TNodoAVL* act = teil.front();
		teil.pop();
		v[pos] = act->item;
		pos++;

		if (act->iz.raiz != nullptr) {
			teil.push(act->iz.raiz);
		}
		if (act->de.raiz != nullptr) {
			teil.push(act->de.raiz);
		}
	}

	return v;
}


//si
bool TAVLCom::operator==(const TAVLCom &yiyi) const{
	
	TVectorCom orin2 = yiyi.Inorden();
	TVectorCom orin1 = Inorden();
	if(orin2==orin1){
		return true;
	}else{
	return false;
	}
	

}

//no
bool TAVLCom::Borrar(const TComplejo &cucu){
	bool deleteado;
	bool downgrading;
	deleteado = Borrar(cucu, downgrading);
	return deleteado;
}
//si
TComplejo TAVLCom::BuscarMayor() {
	if (raiz == nullptr) {
		
		return TComplejo();
	}

	TNodoAVL *nodoActual = raiz;
	while (nodoActual->de.raiz != nullptr) {
		nodoActual = nodoActual->de.raiz;
	}

	return nodoActual->item;
}



//si
int TAVLCom::NodosHoja() const {
	if (raiz == nullptr) {
		return 0; // El árbol está vacío, no hay nodos hoja
	}

	if (raiz->iz.raiz == nullptr && raiz->de.raiz == nullptr) {
		return 1; // El nodo raíz es un nodo hoja
	}

	int hojasIzq = TAVLCom(raiz->iz).NodosHoja(); // Nodos hoja en el subárbol izquierdo
	int hojasDer = TAVLCom(raiz->de).NodosHoja(); // Nodos hoja en el subárbol derecho

	return hojasIzq + hojasDer; // Total de nodos hoja en el árbol
}
//no
bool TAVLCom::Borrar(const TComplejo &cucu, bool &downgrading){
	bool founded = false;
	bool downLeft = false;
	bool downRight = false;
	TNodoAVL *ptb;
	if(raiz != NULL){
		if((cucu< raiz->item)==true){
			founded = raiz->iz.Borrar(cucu, downLeft);
		}
		else{
			if((cucu > raiz->item)==true){
				founded = raiz->de.Borrar(cucu, downRight);
			}
			else{
				
				if(raiz->iz.raiz == NULL && raiz->de.raiz == NULL){
					delete raiz;
					raiz = NULL;
					founded = true;
					downgrading = true;
				}
				else{
					
					if(raiz->iz.raiz != NULL && raiz->de.raiz == NULL){
						ptb = raiz;
						raiz = raiz->iz.raiz;
						ptb->iz.raiz = NULL; 
						delete ptb;
						founded = true;
						downgrading = true;
					}
					else{
						
						if(raiz->iz.raiz == NULL && raiz->de.raiz != NULL){
							ptb = raiz;
							raiz = raiz->de.raiz;
							ptb->de.raiz = NULL;
							delete ptb;
							founded = true;
							downgrading = true;	
						}
						else{	
							TComplejo cmayor = raiz->iz.BuscarMayor();
							raiz->item = cmayor;
							raiz->iz.Borrar(cmayor, downLeft);
							founded = true;
						}
					}
				}
			}
		}
		if(downLeft){
			raiz->fe++;
			switch(raiz->fe){
				case 0:
					downgrading = true;
					break;
				case 1:
					downgrading = false;	
					break;
				case 2:
					switch(raiz->de.raiz->fe)
					{
						case -1:
							DI();
							downgrading = true;	
						break;
						case 0: 
							DD();
							downgrading = false;
						break;
						case 1:
							DD();
							downgrading = true;
						break;
					}
				break;
	
			}
		}
		else{
			if(downRight){
				raiz->fe--;
				switch(raiz->fe){
					case 0:
						downgrading = true;
						break;
					case -1:
						downgrading = false;
						break;
					case -2:
						switch(raiz->iz.raiz->fe){
							case -1:
								II();
								downgrading = true;
								break;
							case 0:
								II();
								downgrading = false;
								break;
							case 1:
								ID();
								downgrading = true;
								break;
						}
				}
			}
		}
	}
	return founded;
}
//si

//si
TComplejo TAVLCom::Raiz() const {
	if (raiz != nullptr) {
		return raiz->item;
	}
	
	
	return TComplejo();
}

//si
int TAVLCom::Altura() const {
	if (raiz == nullptr) {
		return 0; // El árbol está vacío, la altura es cero
	}

	int alturaIzq = raiz->iz.Altura(); // Altura del subárbol izquierdo
	int alturaDer = raiz->de.Altura(); // Altura del subárbol derecho

	return 1 + ((alturaIzq > alturaDer) ? alturaIzq : alturaDer); // Altura es 1 más la altura máxima entre los subárboles izquierdo y derecho
}



bool TAVLCom::Buscar(const TComplejo &c) const{
	bool founded = false;
	if(raiz==NULL){
		return false;
	}
	if(raiz != NULL){
		if((c != raiz->item)==false){
			founded = true;
		}
		else{
			if((c < raiz->item)==true){
				founded = raiz->iz.Buscar(c);
			}
			else{
				if((c < raiz->item)==false)
				founded = raiz->de.Buscar(c);
			}
		}
	}
	return founded;
}


ostream &operator<<(ostream &os, const TAVLCom &ab){
	TVectorCom niveles = ab.Niveles();
	os << niveles;
	return os;
}
//no
bool TAVLCom::operator!=(const TAVLCom &ab) const{
	return !(*this == ab);
}
//si
bool TAVLCom::EsVacio() const{
	if(raiz==NULL){
		return true;
	}else{

	return false;
	}

}




