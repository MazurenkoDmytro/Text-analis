#include "mainwindow.h"
#include "qtablewidget.h"
#include "ui_mainwindow.h"
#include "symbol.h"

#include <QVector>
#include <QtCore>

void QuickSort (QVector<Symbol>& , unsigned int N, int L, int R, bool direction, QChar x);
void QuickSort (QVector<Symbol>& symbols, unsigned int N, int L, int R, bool direction, int x);
void QuickSort (QVector<Symbol>& symbols, unsigned int N, int L, int R, bool direction, double x);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sectionClicked(int)));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_BuildGraph_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD


 void MainWindow::on_LoadFromDB_clicked(){
     DB->LoadFromDB(symbols);
       fillTable(symbols);
}
void MainWindow::on_SaveToDB_clicked()
{
  DB->SaveToDB(symbols);

}

=======
>>>>>>> eab0341363ec9041c681faceecd8eb8b1313b2db
void MainWindow::on_BuildGraph_clicked()
{
    ui->widget->clearPlottables();
    //Колір позаду гістограми
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->widget->setBackground(QBrush(gradient));

    // створення порожніх гістограм:
    QCPBars *histogram = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    histogram->setAntialiased(false);
    histogram->setStackingGap(1);
    histogram->setPen(QPen(QColor(68,121,212).lighter(130)));
    histogram->setBrush(QColor(68,121,212));
    // Налаштування відображення та заповнення даними
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> histogramData;
    if (!symbols.empty()){
        auto temp = symbols;
        if (ui->rbPn->isChecked()){
            QuickSort(temp, temp.length(), 0, temp.length()-1,0,temp[0].getPn()); //відсортована копія щоб отримати перший (і максимальний елемент) для зручного відображення графіку по Y
            ui->widget->yAxis->setRange(0, temp[0].getPn());
            for (int i = 0; i < symbols.length(); ++i) {
                ticks << i ;
                labels << symbols[i].getData();
                histogramData <<  symbols[i].getPn();
            }
        }
        else {
            ui->rbCount->setChecked(true);
            QuickSort(temp, temp.length(), 0, temp.length()-1,0,temp[0].getCount()); //відсортована копія щоб отримати перший (і максимальний елемент) для зручного відображення графіку по Y
            int percent = qCeil(temp[0].getCount()/100.0*10.0); // зум від найбільшої гістограми +10%
            ui->widget->yAxis->setRange(-percent, temp[0].getCount()+percent);
            for (int i = 0; i < symbols.length(); ++i) {
                ticks << i ;
                labels << symbols[i].getData();
                histogramData <<  symbols[i].getCount();
            }
        }
    }
    //Вісь Х
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(textTicker);
    ui->widget->xAxis->setSubTicks(false);
    ui->widget->xAxis->setTickLength(0, 1);
    ui->widget->xAxis->setRange(-2, symbols.length()+2);
    ui->widget->xAxis->setBasePen(QPen(Qt::white));
    ui->widget->xAxis->setTickPen(QPen(Qt::white));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setLabelColor(Qt::white);

    // Вісь Y:

    ui->widget->yAxis->setPadding(5);
    ui->widget->yAxis->setLabel("Text analis");
    ui->widget->yAxis->setBasePen(QPen(Qt::white));
    ui->widget->yAxis->setTickPen(QPen(Qt::white));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    histogram->setData(ticks, histogramData);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->widget->replot();
}

void MainWindow::fillTable(QVector<Symbol>& symbols){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(symbols.length());
    for (int i = 0; i < symbols.length(); ++i) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(symbols[i].getData()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(symbols[i].getCount())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(symbols[i].getPn())));



    }
}

void MainWindow::on_pushButton_clicked()
{
    symbols.clear();
    QString text;

    text = ui->textInput->toPlainText().simplified().remove(" ");
    Symbol::setTotal_symbols(text.length());

    for (int i = 0; i < text.length(); ++i) {
        if (!symbols.contains(text[i])){
            symbols.append(text[i]);
        }
        else for (int j = 0; j < symbols.length(); ++j) {
            if(symbols[j]==text[i]){
                symbols[j]++;
                break;
            }
        }
    }

    fillTable(symbols);
}

void QuickSort (QVector<Symbol>& symbols, unsigned int N, int L, int R, bool direction, QChar x){

    int iter = L ,
    jter = R ;

    int middle = (R+L)/2 ;
    x = symbols [middle].getData().toUpper() ;
    Symbol temp ;

    do
    {
        if (!direction){
            while (symbols[iter].getData().toUpper()>x)
            { iter ++ ; }

            while (x>symbols[jter].getData().toUpper())
            { jter -- ; }
        }
        else if (direction){
            while (symbols[iter].getData().toUpper()<x)
            { iter ++ ; }

            while (x<symbols[jter].getData().toUpper())
            { jter -- ; }
        }

        if (iter<=jter)
        {
            temp = symbols [iter];
            symbols [iter] = symbols [jter] ;
            symbols [jter] = temp ;

            iter ++ ;
            jter -- ;
        }
    }
    while (iter<jter) ;

    if (L<jter)
    { QuickSort  (symbols, N, L, jter,direction,x); }

    if (iter<R)
    { QuickSort  (symbols, N, iter, R,direction,x) ; }
}
void QuickSort (QVector<Symbol>& symbols, unsigned int N, int L, int R, bool direction, int x){
    int iter = L ,
     jter = R ;

    int middle = (R+L)/2 ;

    x = symbols [middle].getCount() ;//
    Symbol temp ;

    do
    {
        if (!direction){
            while (symbols[iter]>x)
            { iter ++ ; }

            while (x>symbols[jter])
            { jter -- ; }
        }
        else if (direction){
            while (symbols[iter]<x)
            { iter ++ ; }

            while (x<symbols[jter])
            { jter -- ; }
        }

        if (iter<=jter)
        {
            temp = symbols [iter];
            symbols [iter] = symbols [jter] ;
            symbols [jter] = temp ;

            iter ++ ;
            jter -- ;
        }
    }
    while (iter<jter) ;

    if (L<jter)
    { QuickSort (symbols, N, L, jter,direction,x) ; }

    if (iter<R)
    { QuickSort (symbols, N, iter, R,direction,x) ; }

}
void QuickSort (QVector<Symbol>& symbols, unsigned int N, int L, int R, bool direction, double x){
    int iter = L ,
            jter = R ;

    int middle = (R+L)/2 ;

    x = symbols [middle].getPn() ;
    Symbol temp ;

    do
    {
        if (!direction){
            while (symbols[iter]>x)
            { iter ++ ; }

            while (x>symbols[jter])
            { jter -- ; }
        }
        else if (direction){
            while (symbols[iter]<x)
            { iter ++ ; }

            while (x<symbols[jter])
            { jter -- ; }
        }

        if (iter<=jter)
        {
            temp = symbols [iter];
            symbols [iter] = symbols [jter] ;
            symbols [jter] = temp ;

            iter ++ ;
            jter -- ;
        }
    }
    while (iter<jter) ;

    if (L<jter)
    { QuickSort (symbols, N, L, jter,direction,x) ; }

    if (iter<R)
    { QuickSort (symbols, N, iter, R,direction,x) ; }
}

void MainWindow::sectionClicked(int idx)
{

    static bool symbol_direction=true; //напрямок сортування
    static bool count_direction=true;
    static bool pn_direction=true;
    if(!symbols.empty()){
        switch (idx) {
        case 0:
            if (symbol_direction){

                QuickSort(symbols, symbols.length(), 0, symbols.length()-1,symbol_direction,symbols[0].getData()) ;
                symbol_direction=false;
            }
            else if (!symbol_direction){
                QuickSort(symbols, symbols.length(), 0, symbols.length()-1,symbol_direction,symbols[0].getData()) ;
                symbol_direction=true;
            }

            fillTable(symbols);
            break;
        case 1:
            if (count_direction ){
                QuickSort(symbols, symbols.length(), 0, symbols.length()-1,count_direction,symbols[0].getCount()) ;
                count_direction=false;
            }
            else if(!count_direction){
                QuickSort(symbols, symbols.length(), 0, symbols.length()-1,count_direction,symbols[0].getCount()) ;
                count_direction=true;
            }
             fillTable(symbols);
            break;
        case 2:
            if (pn_direction){
                QuickSort(symbols, symbols.length(), 0, symbols.length()-1,pn_direction,symbols[0].getPn() ) ;
                pn_direction=false;
            }
            else if(!pn_direction){
                QuickSort(symbols, symbols.length(), 0, symbols.length()-1,pn_direction,symbols[0].getPn()) ;
                pn_direction=true;
            }

            fillTable(symbols);
            break;
        default:
            break;
        }

    }
}

//Test text
//C++ (pronounced "C plus plus") is a high-level general-purpose programming language created by Danish computer scientist Bjarne Stroustrup as an extension of the C programming language, or "C with Classes". The language has expanded significantly over time, and modern C++ now has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM, so it is available on many platforms. C++ was designed with systems programming and embedded, resource-constrained software and large systems in mind, with performance, efficiency, and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, video games, servers (e.g. e-commerce, web search, or databases), and performance-critical applications (e.g. telephone switches or space probes). C++ is standardized by the International Organization for Standardization (ISO), with the latest standard version ratified and published by ISO in December 2020 as ISO/IEC 14882:2020 (informally known as C++20). The C++ programming language was initially standardized in 1998 as ISO/IEC 14882:1998, which was then amended by the C++03, C++11, C++14, and C++17 standards. The current C++20 standard supersedes these with new features and an enlarged standard library. Before the initial standardization in 1998, C++ was developed by Stroustrup at Bell Labs since 1979 as an extension of the C language; he wanted an efficient and flexible language similar to C that also provided high-level features for program organization. Since 2012, C++ has been on a three-year release schedule with C++23 as the next planned standard.

<<<<<<< HEAD





=======
>>>>>>> eab0341363ec9041c681faceecd8eb8b1313b2db
