#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "symbol.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fillTable(QVector<Symbol>&);


private slots:
    void on_pushButton_clicked();
    void sectionClicked(int idx);
    void on_BuildGraph_clicked();
     void on_SaveToDB_clicked();
     void on_LoadFromDB_clicked();

private:

    QVector<Symbol> symbols ;
    Ui::MainWindow *ui;
    DataBase *DB = new DataBase ("SymbolDataBase");

};
#endif // MAINWINDOW_H
