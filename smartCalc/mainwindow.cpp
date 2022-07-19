#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
//extern "C" int validator(char *str);
//extern "C" int parser(char *str, double x, double *result);
double num_first;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    SIGNAL это событие SLOT вызывает функцию digits_numbers this это обращение к данному классу
//    h = 0.1;
//    xBegin = -3;
//    xEnd = 3 + h;
//    ui->widget->xAxis->setRange(-4, 4);
//     ui->widget->yAxis->setRange(0,9);

////    N = (xEnd - xBegin)/h +2;
//    for (X = xBegin;X < xEnd; X += h){
//         x.push_back(X);
//         y.push_back(X*X);

//    }
//    ui->widget->addGraph();
//    ui->widget->graph(0)->addData(x,y);
//    ui->widget->replot();

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_change_sign, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_persent, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_multiple, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(on_pushButton_AC_clicked()));

    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(caller_function()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(caller_function()));

    ui->pushButton_multiple->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);

    creditWindow = new Credit();
    connect(creditWindow, &Credit::firstWindow, this, &MainWindow::show);

    depositWindow = new Deposit();
    connect(depositWindow, &Deposit::firstWindow, this, &MainWindow::show);


}
// ~ это деструктор
MainWindow::~MainWindow()
{
    delete ui;
}
//Обработчики вызовов новых окон
void MainWindow::on_pushButton_credit_clicked()
{
    creditWindow->show();
    this->close();
}

void MainWindow::on_pushButton_deposit_clicked()
{
    depositWindow->show();
    this->close();
}
void MainWindow::on_pushButton_graph_clicked()
{
    ui->widget->clearGraphs();
    double minx = ui->lineEdit_minx->text().toDouble();
    double maxx = ui->lineEdit_maxx->text().toDouble();
    double miny = ui->lineEdit_miny->text().toDouble();
    double maxy = ui->lineEdit_maxy->text().toDouble();
    h = 0.01;
    xBegin = minx;
    xEnd = maxx + h;
    ui->widget->xAxis->setRange(minx, maxx);
    ui->widget->yAxis->setRange(miny, maxy);
    X = ui->lineEdit_forx->text().toDouble();
    char* str = new char(ui->result_show->text().length());
    QByteArray new_label = ui->result_show->text().toLatin1();
    strlcpy(str, new_label, ui->result_show->text().length() + 1);
    double result = 0;

//    N = (xEnd - xBegin)/h +2;
    if (X!=0){
        for (X = xBegin;X < xEnd; X += h){
             if  (X == 0) continue;
             x.push_back(X);

//            parser(str, X, &result);
//            y.push_back(X*X);
            if (strlen(str) > 0){
             if (validator(str) == 0) {
                 if (parser(str, X, &result) == 0){
                    y.push_back(result);
                 } else {
                     QMessageBox::warning(this, "Ошибка","Невалидный ввод");
                     break;
                 }
             } else {
                 QMessageBox::critical(this, "Ошибка","Невалидный ввод");
                 break;
             }
            }

        }
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x,y);
        ui->widget->replot();
        x.clear();
        y.clear();
    }


}

//мы вызываем эту функцию чтобы отрисовать числа
void MainWindow::digits_numbers() {
//    принимаем в указатель QPushButton * значение sender()
    QPushButton *button = (QPushButton *)sender();

    QString new_label;
    if (ui->result_show->text() == "0"){
        new_label = button->text();
    } else {
         new_label = (ui->result_show->text() + button->text());
    }


    // ставим текст в поле
    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
//    проверка для ввода одной точки
    ui->result_show->setText(ui->result_show->text() + ".");
}

// работает с кнопкой смена знака и процент
void MainWindow::operations()  {
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= -1;
        new_label =  QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    } else if (button->text() == "%"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= 0.01;
        new_label =  QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    }

}
// меняет все сиволы на ноль
void MainWindow::on_pushButton_AC_clicked()
{
    ui->result_show->setText("0");
}

//
void MainWindow::math_operations() {
    // отслеживает какая кнопка была нажата
    QPushButton *button = (QPushButton *)sender();
    QString new_label = NULL;
    if (button->text() == "×") {
        new_label = ui->result_show->text() + "*";
    }else if (button->text() == "÷") {
        new_label = ui->result_show->text() + "/";
    }else {
        new_label = ui->result_show->text() + button->text();
    }

ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_equal_clicked()
{
    double x = ui->lineEdit_forx->text().toDouble();
    char* str = new char(ui->result_show->text().length());
    QByteArray new_label = ui->result_show->text().toLatin1();
    strlcpy(str, new_label, ui->result_show->text().length() + 1);
    double result = 0;

if (strlen(str) > 0){
    if (validator(str) == 0) {
        if (parser(str, x, &result) == 0){
            QString result_string =  QString::number(result, 'g', 15);
            ui->result_show->setText(result_string);
        } else {
            QMessageBox::warning(this, "Ошибка","Невалидный ввод");
        }
    } else {
        QMessageBox::critical(this, "Ошибка","Невалидный ввод");
    }
}




}
void MainWindow::caller_function()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label = NULL;
    if (button->text() == "(") {
        new_label = ui->result_show->text() + "(";
    }else if (button->text() == ")") {
        new_label = ui->result_show->text() + ")";
    }else if (button->text() == "acos") {
        new_label = ui->result_show->text() + "acos";
    }else if (button->text() == "asin") {
        new_label = ui->result_show->text() + "asin";
    }else if (button->text() == "atan") {
        new_label = ui->result_show->text() + "atan";
    }else if (button->text() == "sin") {
        new_label = ui->result_show->text() + "sin";
    }else if (button->text() == "cos") {
        new_label = ui->result_show->text() + "cos";
    }else if (button->text() == "tan") {
        new_label = ui->result_show->text() + "tan";
    }else if (button->text() == "log") {
        new_label = ui->result_show->text() + "log";
    }else if (button->text() == "ln") {
        new_label = ui->result_show->text() + "ln";
    }else if (button->text() == "sqrt") {
        new_label = ui->result_show->text() + "sqrt";
    }else if (button->text() == "^") {
        new_label = ui->result_show->text() + "^";
    }else if (button->text() == "x") {
        new_label = ui->result_show->text() + "x";
    }

ui->result_show->setText(new_label);
}



//qDebug() << "This will output to the spawned console!";
//qDebug() << str;





void MainWindow::on_pushButton_10_clicked()
{
    ui->result_show->setText("(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100");
}


void MainWindow::on_pushButton_11_clicked()
{
        ui->result_show->setText("sin(1)*cos(2)");
}




