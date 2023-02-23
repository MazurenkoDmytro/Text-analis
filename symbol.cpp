#include "symbol.h"

int Symbol::total_symbols=0;
Symbol::Symbol()
{

}
void Symbol::setData(QChar newData)
   {
    data = newData;
}

void Symbol::setData(char newData)
{
    data = newData;
}
void Symbol::setCount(int newCount)
   {
       count = newCount;
   }
void Symbol::setPn(double newPn)
   {
       Pn = newPn;
   }
void Symbol::setTotal_symbols(int total){
    Symbol::total_symbols = total;
}

int Symbol::getTotal_symbols()
{
  return Symbol::total_symbols;
}
QChar Symbol::getData(){
    return data;
}
int Symbol::getCount(){
    return count;
};

double Symbol::getPn(){
   return Pn;
}

Symbol::Symbol(QChar &c){
    data = c;
    count = 1;
    Pn = (double)count/Symbol::total_symbols;
}

Symbol& Symbol::operator++(int){
    count++;
    Pn = (double)count/Symbol::total_symbols;
    return *this;
}

bool operator >(const Symbol &s, const double &d){
    return s.Pn>d;
}
 bool operator >(const double &d, const Symbol &s){
     return d>s.Pn;
 }
 bool operator <(const Symbol &s, const double &d){
     return s.Pn<d;
 }
 bool operator <(const double &d, const Symbol &s){
    return d<s.Pn;
 }

bool operator==  (const Symbol &s, const QChar &c){
    return (s.data==c);
}
bool operator > (const Symbol &s, const QChar &c)
{
    return s.data > c;
}
bool operator >(const Symbol &s1, const Symbol &s2){
 return s1.data>s2.data;
};
bool operator > (const Symbol &s, const int &c){
   return s.count>c;
}
bool operator > (const int &c,const Symbol &s){
 return c>s.count;
}

bool operator < (const Symbol &s, const int &c){
     return s.count<c;
}
bool operator <(const Symbol &s1, const Symbol &s2){

    return s1.data<s2.data;
};
bool operator < (const int &c,const Symbol &s){
 return c<s.count;
}
bool operator < (const Symbol &s, const QChar &c)
{
    return s.data < c;
}
