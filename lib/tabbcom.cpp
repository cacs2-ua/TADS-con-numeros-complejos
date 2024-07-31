#include "tabbcom.h"
#include <queue>



TABBCom& TABBCom::operator=(const TABBCom &objTab){
    if (this != &objTab) {
        TNodoABB *aux;
        if (objTab.nodo != NULL) {
            aux = new TNodoABB();
            *aux = *(objTab.nodo);
        }
        else {
            aux = NULL;
        }
        delete nodo;
        nodo = aux;
    }
    return *this;
}




TABBCom::TABBCom(const TABBCom &objTab) {
    
    if ((objTab.nodo != NULL)==true) {
        nodo = new TNodoABB();
        *(nodo) = *(objTab.nodo); 
        int n=-1;
    }
    else {
        nodo = NULL;
    }
}



TNodoABB::TNodoABB(const TNodoABB &n):item(n.item), iz(n.iz), de(n.de){

}



TNodoABB& TNodoABB::operator=(const TNodoABB &objTab) {
    if (this != &objTab) {
        
        
        item = objTab.item;
        if ((objTab.iz.nodo != NULL)==true) {
            iz.nodo = new TNodoABB();
            *(iz.nodo) = *(objTab.iz.nodo);
        }
        else {
            iz.nodo = NULL;
        }
        if (objTab.de.nodo != NULL) {
            de.nodo = new TNodoABB();
            *(de.nodo) = *(objTab.de.nodo);
        }
        else {
            de.nodo = NULL;
        }
    }
    return *this;
}

TNodoABB::~TNodoABB(){
	
}




void TABBCom::PostordenAux(TVectorCom &v, int &pos) const{
    if(nodo != NULL){
        
        nodo->iz.PostordenAux(v, pos);
        nodo->de.PostordenAux(v, pos);
       
        v[pos] = nodo->item;
        pos++;
    }
}
TVectorCom TABBCom::Postorden() const{
    TVectorCom v(Nodos());
    int pos = 1; 
    PostordenAux(v, pos);
    return v;
}


TVectorCom TABBCom::Preorden() const{
    TVectorCom vt(Nodos());
    int p = 1;
    PreordenAux(vt, p);

    return vt;
}



TABBCom::~TABBCom(){
	if(nodo != NULL){
		delete nodo; 
		nodo = NULL;	
	}
}

TVectorCom TABBCom::Inorden() const {
    int pos = 1;

    TVectorCom vector(Nodos());
    InordenAux(vector, pos);
    return vector;
}
void TABBCom::InordenAux(TVectorCom &vector, int &pos) const {
    if (!this->EsVacio()) {
        this->nodo->iz.InordenAux(vector, pos);
        vector[pos] = this->nodo->item;
        pos++;
        this->nodo->de.InordenAux(vector, pos);
    }
}

void TABBCom::PreordenAux(TVectorCom &vt, int &p) const{
    if(nodo == NULL){

    }else{
        vt[p] = nodo->item;
        p++;
        nodo->iz.PreordenAux(vt, p);
        nodo->de.PreordenAux(vt, p);
    }
}



bool TABBCom::Insertar(const TComplejo &c){
    TNodoABB *padre = NULL;
    TNodoABB *actual = nodo;
    while(actual != NULL){
        if(c == actual->item){
            return false; 
        }
        padre = actual;
        if(c < actual->item){
            actual = actual->iz.nodo;
        }
        else{
            actual = actual->de.nodo;
        }
    }
    TNodoABB *nuevo_nodo = new TNodoABB(c);
    if(padre == NULL){
        nodo = nuevo_nodo; 
    }
    else{
        if(c < padre->item){
            padre->iz.nodo = nuevo_nodo;
        }
        else{
            padre->de.nodo = nuevo_nodo;
        }
    }
    return true; 
}



TNodoABB::TNodoABB(){
	
}

TNodoABB::TNodoABB(const TComplejo &c):item(c){
}
TABBCom::TABBCom(){
	nodo = NULL;	
}
//si
int TABBCom::Nodos() const {
    if ((nodo != NULL)==true) {
         return 1 + nodo->iz.Nodos() + nodo->de.Nodos();
    } else {
       return 0;
    }
}




//si

//si


bool TABBCom::operator==(const TABBCom &objTab) const{
	
	TVectorCom ino2 = objTab.Inorden();
	TVectorCom ino1 = Inorden();
	if(ino1 == ino2){
		return true;
	}
	return false;
	

}
//si
bool TABBCom::EsVacio() const{
	if(nodo==NULL){
		return true;
	}
	return false;
}
TVectorCom TABBCom::Niveles() const{
	int pos = 1;
	
	queue<TNodoABB *> teil;
	TNodoABB *contacto;
	TVectorCom v(Nodos());
	

	teil.push(nodo);
	while((!teil.empty())==true){
		contacto = teil.front();
		teil.pop();
		if((contacto != NULL)==true){
			v[pos] = contacto->item;
			pos++;
			teil.push(contacto->iz.nodo);
			teil.push(contacto->de.nodo);
		}
	}
	return v;	
}
//s


//si
bool TABBCom::Borrar(const TComplejo &c){
	bool enc = false;
	TNodoABB *ptb;
	if(nodo != NULL){
		if(c < nodo->item){
			enc = nodo->iz.Borrar(c);
		}
		else{
			if(c > nodo->item){
				enc = nodo->de.Borrar(c);
			}
			else{
				
				if(nodo->iz.nodo == NULL && nodo->de.nodo == NULL){
					delete nodo;
					nodo = NULL;
					enc = true;
				}
				else{
					
					if(nodo->iz.nodo != NULL && nodo->de.nodo == NULL){
						ptb = nodo;
						nodo = nodo->iz.nodo;
						ptb->iz.nodo = NULL; 
						delete ptb;
						enc = true;
					}
					else{
						
						if(nodo->iz.nodo == NULL && nodo->de.nodo != NULL){
							ptb = nodo;
							nodo = nodo->de.nodo;
							ptb->de.nodo = NULL;
							delete ptb;
							enc = true;	
						}
						else{	
							TComplejo cmayor = nodo->iz.BuscarMayor();
							nodo->item = cmayor;
							nodo->iz.Borrar(cmayor);
							enc = true;
						}
					}
				}
			}
		}
	}
	return enc;
}


bool TABBCom::Buscar(const TComplejo &c) const{
    TNodoABB *actual = nodo;
    bool encontrado = false;

    while(actual != NULL && !encontrado) {
        if(c == actual->item) {
            encontrado = true;
        }
        else if(c < actual->item) {
            actual = actual->iz.nodo;
        }
        else {
            actual = actual->de.nodo;
        }
    }

    return encontrado;
}

TComplejo TABBCom::BuscarMayor()  {
    if (nodo == NULL) {
        return TComplejo();
    } else if (nodo->de.nodo == NULL) {
        return nodo->item;
    } else {
        return nodo->de.BuscarMayor();
    }
}


int TABBCom::Altura() const{
    if(nodo == NULL){
        return 0;
    }
    int h = 0;
    queue<TNodoABB*> q;
    q.push(nodo);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TNodoABB* current = q.front();
            q.pop();
            if(current->iz.nodo){
                q.push(current->iz.nodo);
            }
            if(current->de.nodo){
                q.push(current->de.nodo);
            }
        }
        h++;
    }
    return h;
}


int TABBCom::NodosHoja() const {
    int hojas = 0;
    if (nodo != NULL) {
        if (nodo->iz.nodo == NULL && nodo->de.nodo == NULL) {
            hojas = 1;
        }
        hojas += nodo->iz.NodosHoja() + nodo->de.NodosHoja();
    }
    return hojas;
}


TComplejo TABBCom::Raiz() const{
	TComplejo c;
	if(nodo != NULL){
		c = nodo->item;
	}
	return c;
}

ostream &operator<<(ostream &os, const TABBCom &ab){
	TVectorCom niveles = ab.Niveles();
	os << niveles;
	return os;
}





