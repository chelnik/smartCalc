#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <credit.h>
#include <deposit.h>
#include <QVector>


extern "C" {
//#include "../C7_SmartCalc_v1.0-0/src/underfile.h"
#include "../src/underfile.h"
}



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

signals:
    void firstWindow();
private:
    Ui::MainWindow *ui;
    Credit *creditWindow;
    Deposit *depositWindow;
    double xBegin, xEnd, h, X;
    int N;
    QVector<double> x,y;
private slots:
    void digits_numbers() ;
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_AC_clicked();
    void math_operations();
    void on_pushButton_equal_clicked();
    void caller_function();
    void on_pushButton_credit_clicked();
    void on_pushButton_deposit_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_graph_clicked();
};
#endif // MAINWINDOW_H
