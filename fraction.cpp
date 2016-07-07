#include <iostream>
#include<cmath>
#include<cstdlib>

 using namespace std;
 
 class Fraction{
   private:
     int numerator, denominator;
 
   public:
   Fraction();
     Fraction(int n, int d); 
     void print();
   
   friend ostream& operator<<(ostream&, Fraction&);
   friend istream& operator>>(istream&, Fraction&);
   friend bool operator ==(const Fraction&, const Fraction&);
   friend bool operator >(const Fraction&, const Fraction&);
   friend bool operator <(const Fraction&, const Fraction&);
   friend Fraction operator *(const Fraction&, const Fraction&);
   friend Fraction operator /(const Fraction&, const Fraction&);
   friend Fraction operator +(const Fraction&, const Fraction&);
   friend Fraction operator -(const Fraction&, const Fraction&);
 };
 

 
 int main(){
   Fraction f1,f2, sum, diff, equal;
   cout<<"enter your fractions"<<endl;
   cin>>f1>>f2;
   
   sum = f1 + f2;
   diff = f1 - f2;
   equal=f1 == f2;
   cout<<"The two fractions are: "<<f1<<" and "<<f2<<endl;
   cout<<"Their sum is: "<<sum<<endl;
   cout<<"Their difference is: "<<diff<<endl;
   cout<<equal<<endl;
  
  
 
  
   return 0;
 }
 Fraction::Fraction(int n, int d)
 {
	 numerator=n;
	 denominator=d;
 }

ostream& operator<<(ostream& out, Fraction& f){
   out << f.numerator << '/' << f.denominator;
   return out;
 }
 istream& operator>>(istream& in, Fraction& f)
 {
	 in>>f.numerator>>f.denominator;
	 return in;
 }
 Fraction::Fraction()
 {
	 numerator=0;
	 denominator=0;
 }
 bool operator ==(const Fraction& f, const Fraction& f1)
 {
	 return (f.numerator * f1.denominator) == (f1.numerator * f.denominator);
 }
 bool operator <(const Fraction& f, const Fraction& f1)
 {
	 return (f.numerator * f1.denominator) < (f1.numerator *f.denominator);
	 
  }
  bool operator >(const Fraction& f, const Fraction& f1)
  {
       return (f.numerator * f1.denominator) > (f1.numerator *f.denominator);
  }
  //Fraction operator *(const Fraction& f, const Fraction& f1)
  //{
   //    return (f.numerator * f1.numerator) / (f.denominator * f1.denominator);
 // }
  //Fraction operator /(const Fraction& f, const Fraction& f1)
  //{
       //return (f.numerator / f1.numerator) / (f.denominator / f1.denominator);
  //}
  Fraction operator +(const Fraction& f, const Fraction& f1)
  {
	  Fraction r;        

   
   r.numerator = (f.numerator * f1.denominator)
                  + (f1.numerator * f.denominator);

  
   r.denominator = f.denominator * f1.denominator;

   return r;         // return the result Fraction
}
Fraction operator -(const Fraction& f, const Fraction& f1)
{
	Fraction r;
	r.numerator = (f.numerator*f1.denominator)
				-(f1.numerator * f.denominator);
				
	r.denominator = f.denominator * f1.denominator;
	
	return r;
}

  
