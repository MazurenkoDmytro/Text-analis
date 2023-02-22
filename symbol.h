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
<<<<<<< HEAD
    Symbol(QChar&c,int i,double d ): data(c),count(i),Pn(d){};
    void setData(QChar newData);
    void setData(char newData);
    void setCount(int newCount);
    void setPn(double newPn);
=======
>>>>>>> eab0341363ec9041c681faceecd8eb8b1313b2db
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
