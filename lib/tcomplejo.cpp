#include "tcomplejo.h"





TComplejo::TComplejo(double real,double imaginaria){
	re = real;
	im = imaginaria;
}

TComplejo::TComplejo(){
	re = im = 0;
}
TComplejo::TComplejo(const TComplejo &c){
	re=c.re;
	im = c.im;
}


TComplejo::~TComplejo()
{

im=0;
re=0-0;
}











TComplejo TComplejo::operator*(const TComplejo &c) const{
	TComplejo ucto;
	double mul1;
	mul1=(re*c.re)-(im*c.im);
	ucto.re = mul1;
	double mul2=(re*c.im)+(im*c.re);
	ucto.im = mul2;
	return ucto;

	
}


TComplejo TComplejo::operator+(double sum) const  {
	TComplejo sumaaaa;
	double s1,s2;
	s1=re+sum;

	sumaaaa.re=s1;
	s2=im;
	sumaaaa.im=s2;
	return sumaaaa;
	
}


TComplejo TComplejo::operator-(double res) const{
	TComplejo esta;
	double r1,r2;
	r1=re - res;
	r2=im;
	esta.re = r1;
	esta.im = r2;
	return esta;
}

bool TComplejo::operator>(const TComplejo &tcoom) const{
	return ((Mod() > tcoom.Mod() )|| 
	(Mod() == tcoom.Mod() && Re() >tcoom.Re()) || 
	(Mod() == tcoom.Mod() && Re() == tcoom.Re() && Im() > tcoom.Im()));
}
TComplejo TComplejo::operator*(double perreo) const{
	TComplejo ucto;
	double pr1,pr2;
	pr1=re*perreo;
	pr2=im*perreo;
	ucto.re = pr1;
	ucto.im = pr2;
	return ucto;
}
TComplejo TComplejo::operator+(const TComplejo &c) const{
double a=re+c.re;
TComplejo sumador;

sumador.re=a;
double b=im+c.im;
sumador.im=b;

return sumador;

}

TComplejo operator+(double d,const TComplejo &c){
	TComplejo sumadorium;
	double s1,s2;
	s1=d + c.re;
	s2=c.im;
	sumadorium.re = s1;
	sumadorium.im = s2;
	return sumadorium;
}

bool TComplejo::operator==(const TComplejo &c) const
{
	bool seem=false;

	if(((re==c.re)==true) && ((im==c.im)==true)){
		
		seem=true;
	}

	return seem;
}


TComplejo operator-(double d,const TComplejo &c)
{

TComplejo restadorium;
double r1=d-c.re;
double r2=-c.im;

restadorium.re=r1;
restadorium.im=r2;

return restadorium;
}


TComplejo operator*(double d,const TComplejo &c)
{

TComplejo ucto;
double p1=d*c.re;
double p2=c.im*d;
ucto.re=p1;
ucto.im=p2;

return ucto;
}


TComplejo::TComplejo(double real){
	re = real;
	im = 0;
}

TComplejo& TComplejo::operator=(const TComplejo &c)
{
re=c.re;
im=c.im;
return *this;

}




ostream &operator<<(ostream &o,const TComplejo &c){
	o<<"("<<c.re<<" "<<c.im<<")";
	return o;
}
bool TComplejo::operator!=(const TComplejo &c) const
{
bool perreo=false;

	if(((re!=c.re)==true)||((im!=c.im)==true)){
		perreo=true;
	}
	return perreo;
}


double TComplejo::Re() const
{
return re;
}


void TComplejo::Re(double rial)
{
re=rial;
}

double TComplejo::Arg(void) const
{
	double arcotangente;
	if(((re==0)==true) && ((im==0)==true)){
		arcotangente=0;
	}
	else{
		arcotangente= atan2(im, re);
	}

	return arcotangente;
}

double TComplejo::Im() const
{
return im;
}


void TComplejo::Im(double imaginarium)
{
im=imaginarium;
}


double TComplejo::Mod(void) const
{
	double a1=pow(re,2.0);
	double a2=pow(im,2.0);
	double raiz=sqrt(a1+a2);
	return raiz;
}






bool TComplejo::operator<(const TComplejo &tcoom) const{
	return *this != tcoom && !(*this > tcoom);
}



TComplejo TComplejo::operator-(const TComplejo &c) const 
{
double a=re-c.re;
TComplejo restador;

restador.re=a;
double b=im-c.im;
restador.im=b;

return restador;

}

