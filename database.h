#ifndef DATABASE_H
#define DATABASE_H

#include "qsqldatabase.h"
#include "symbol.h"
#include <QString>



class DataBase
{
private:
    QString database_name_;
    QSqlDatabase dbase_;
public:
    bool SaveToDB( QVector<Symbol>& symbols);
       DataBase(const QString& database_name);
       ~DataBase();
       void LoadFromDB(QVector<Symbol>& symbols);
};

#endif // DATABASE_H
