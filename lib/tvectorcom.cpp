#include "tvectorcom.h"

bool es_null(TComplejo *v){
    bool n=false;
    if(v==NULL){
        n=true;
    }
    return n;
}


TVectorCom::TVectorCom(int tam){
	if(tam > 0){
        c = new TComplejo [tam];
		tamano = tam;
		
	}
	else{
		tamano = 0;
		c = NULL;
	}
}

TVectorCom::TVectorCom(const TVectorCom &v){

	if(es_null(v.c)==true){	
        c = NULL;	
		tamano = 0;
		
	}
	else{
		if(es_null(v.c)==false){	
			int i=0;
			tamano = v.tamano;
			c = new TComplejo [v.tamano];
			while( i < tamano){
				c[i] = v.c[i];
				i++;
			}
		}
	}
}

TVectorCom::TVectorCom(){
	tamano = 0;
	c = NULL;
}



TVectorCom &TVectorCom::operator=(const TVectorCom &de){
	
	if(this != &de){
		if (c== NULL){

		}else{

			
		if(true==(c != NULL)){		
			delete [] c;
			c = NULL;
			tamano = 0;
		}}
		if (de.c==NULL){

		}else{
			if(de.c != NULL){
				int i=0;
				int t2=de.tamano;
				tamano = t2;
				c = new TComplejo [tamano];
				while( i < tamano){
					c[i] = de.c[i];
					i++;
				}
			}
		}
	}
	TVectorCom *a=new TVectorCom(*this);
	return *a; 	
}
TVectorCom::~TVectorCom(){
	if(es_null(c)==false){
        tamano = 0;
		delete [] c;
		c = NULL;
		
	}
}


bool TVectorCom::operator!=(const TVectorCom &de) const{
	return !(*this == de);
}



TComplejo &TVectorCom::operator[](int i){
	if(i<1||i> tamano){
		return error;
	}else{
		return c[i - 1];
	}
	
}


TComplejo TVectorCom::operator[](int i) const{
	if(i<1 || i> tamano){
		return TComplejo(0,0);
	}else{
		return c[i - 1];
	}
	
}

bool TVectorCom::operator==(const TVectorCom &de) const{
	bool sam = false;
	if(tamano != de.tamano){
		sam=false;
	}else{
		if(tamano == de.tamano && (tamano != de.tamano)==false){
			int i = 0;
			sam= true;
			while( i < tamano && sam){
				if((c[i] != de.c[i])==true){ 
					sam = false;
				}
				i++;
			}
		}
	}
	return sam;
}

ostream &operator<<(ostream &o, const TVectorCom &t){
	o << "[";
	if(t.c && t.tamano > 0){
		for (int i = 0; i < t.tamano; i++){
			o << "(" << i + 1 << ") " << t.c[i];
			if(i < t.tamano-1){
				o << ", ";
			}
		}
	}
	o << "]";
	return o;
}
bool TVectorCom::Redimensionar(int tam){
	bool redimensionado = false;
	TComplejo *nu;
	bool t;
	int i=0;
	if(tam <0 && tam==tamano){

	}else{
		if(tam > i && tam != tamano){
			
			nu = new TComplejo [tam];
			while(i < tam && i < tamano){
				nu[i] = c[i];
				i++;
			}

			if(c != NULL==true){
				delete [] c;
			}
			
			tamano = tam;
			redimensionado = true;
			c = nu;
		}
	}
	return redimensionado;
}


int TVectorCom::Tamano() const{
	return tamano;
}




bool TVectorCom::ExisteCom(const TComplejo &com) const{
	
	int i=0;
	bool v=true;
	while(i < tamano){
		if(c[i] == com){
			return v;
		}
		i++;
	}
	v=false;
	return v;
}
int TVectorCom::Ocupadas() const{
	int i = 0;
	int in = i;
	while( i < tamano){
		TComplejo a = c[i];
		if((!(a == TComplejo()))==true){
			in++;
		}
		i++;
	}
	return in;
}
void TVectorCom::MostrarComplejos(double re) const{
	
	cout << "[";
	int i=0;
	bool fi = true;
	while( i < tamano){
		if(c[i].Re() >= re){
			if(fi!=true && fi==false){
				cout << ", ";
			}

			cout << c[i];
			fi = false;
			
		}
		i++;
	}
	cout << "]";
}






