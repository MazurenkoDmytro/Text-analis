#include <QChar>
#ifndef SYMBOL_H
#define SYMBOL_H


class Symbol
{
private:
   QChar data;
   int count;
   double Pn;
   static int total_symbols;
public:
    Symbol();
    Symbol(QChar&);
    static void setTotal_symbols(int total);
    static int getTotal_symbols();
    QChar getData();
    int getCount();
    double getPn();
    friend  bool  operator== (const Symbol &s, const QChar &c);
    Symbol&  operator++(int);
     friend bool operator < (const Symbol &s, const QChar &c);
     friend bool operator <(const Symbol &s1, const Symbol &s2);
     friend bool operator < (const Symbol &s, const int &i);
     friend bool operator < (const int &i,const Symbol &s);
     friend bool operator > (const int &i,const Symbol &s);
     friend bool operator > (const Symbol &s, const int &i);
     friend bool operator > (const Symbol &s, const QChar &c);
     friend bool operator >(const Symbol &s1, const Symbol &s2);

     friend bool operator >(const Symbol &s, const double &d);
     friend bool operator >(const double &d, const Symbol &s);
     friend bool operator <(const Symbol &s, const double &d);
     friend bool operator <(const double &d, const Symbol &s);


};
#endif // SYMBOL_H
