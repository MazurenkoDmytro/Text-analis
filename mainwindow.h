#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "database.h"
=======
>>>>>>> eab0341363ec9041c681faceecd8eb8b1313b2db
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
<<<<<<< HEAD
     void on_SaveToDB_clicked();
     void on_LoadFromDB_clicked();

private:

    QVector<Symbol> symbols ;
    Ui::MainWindow *ui;
    DataBase *DB = new DataBase ("SymbolDataBase");

=======

private:
    QVector<Symbol> symbols ;
    Ui::MainWindow *ui;
    int N;
>>>>>>> eab0341363ec9041c681faceecd8eb8b1313b2db
};
#endif // MAINWINDOW_H
