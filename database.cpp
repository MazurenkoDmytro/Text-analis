
#include "database.h"
#include "qsqlquery.h"

#include <QSqlQuery>
#include <QSqlError>


   DataBase::DataBase(const QString& database_name) : database_name_(database_name) {
        dbase_ = QSqlDatabase::addDatabase("QSQLITE");
        dbase_.setDatabaseName(database_name_);
        if (!dbase_.open()) {
        } else {
            QSqlQuery query;
            QString str = "CREATE TABLE IF NOT EXISTS Symbol ("
                          "symbol VARCHAR(3) PRIMARY KEY NOT NULL, "
                          "count INTEGER, "
                          "frequency DOUBLE"
                          ")";
            query.exec(str);

        }
    }

   DataBase::~DataBase() {

        dbase_.close();
    }

    bool DataBase::SaveToDB( QVector<Symbol>& symbols) {

        bool success = true;
        QSqlQuery query;
        dbase_.transaction();
        query.exec("DELETE FROM Symbol");
        for (auto symbol : symbols) {
            query.prepare("INSERT INTO Symbol (symbol, count, frequency) VALUES (:symbol, :count, :frequency)");
            query.bindValue(":symbol", QString(symbol.getData()));
            query.bindValue(":count", symbol.getCount());
            query.bindValue(":frequency", symbol.getPn());
            if (!query.exec()) {
                qDebug() <<5   << symbol.getData() << "in db: " << query.lastError().text();
                success = false;
                break;
            }
        }
        if (success) {
            dbase_.commit();
        } else {
            dbase_.rollback();
        }
        return success;
    }

   void DataBase::LoadFromDB(QVector<Symbol>& symbols) {
           symbols.clear();
           QSqlQuery query("SELECT * FROM Symbol");
           while (query.next()) {
                      Symbol s;
                      s.setData(query.value(0).toString().at(0)) ;
                      s.setCount(query.value(1).toInt());
                      s.setPn( query.value(2).toDouble());
                      symbols.push_back(s);
           }

       }


