#ifndef _TComplejo_
#define _TComplejo_
#include <iostream>
#include<cmath>
using namespace std;

class TComplejo
{
private:
	double re;
	double im;
public:
	

	TComplejo(double a,double b);
	TComplejo();
	TComplejo(double raw);
	TComplejo(const TComplejo &);
	
	~TComplejo();
	
	
	TComplejo operator*(const TComplejo &) const;
	TComplejo operator+(const TComplejo &) const;
	TComplejo operator-(const TComplejo &) const;
	TComplejo operator+(double)const;
	TComplejo operator-(double)const;
	TComplejo operator*(double)const;
	friend TComplejo operator-(double,const TComplejo &);
	friend TComplejo operator*(double,const TComplejo &);
	
	friend TComplejo operator+(double,const TComplejo &);
	
	TComplejo& operator=(const TComplejo &);
	bool operator==(const TComplejo &) const;
	bool operator<(const TComplejo &tcoom) const;
	bool operator>(const TComplejo &tcoom) const;
	
	bool operator!=(const TComplejo &) const;

	
	
	double Re() const;
	void Re(double);
	double Mod(void) const;
	double Arg(void) const;
	double Im() const;
	void Im(double);
	
	
	
	friend ostream& operator<<(ostream &,const TComplejo &);
};


#endif
