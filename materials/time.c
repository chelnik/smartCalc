// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <QMessageBox>
// extern "C" void parser(char *str, double x);
// double num_first;
// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// //    SIGNAL это событие SLOT вызывает функцию digits_numbers this это обращение к данному классу


//     connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

//     connect(ui->pushButton_change_sign, SIGNAL(clicked()), this, SLOT(operations()));
//     connect(ui->pushButton_persent, SIGNAL(clicked()), this, SLOT(operations()));

//     connect(ui->pushButton_multiple, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//     connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
//     connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(math_operations()));
//     connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(math_operations()));
//     connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
//     connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(on_pushButton_AC_clicked()));

//     ui->pushButton_multiple->setCheckable(true);
//     ui->pushButton_div->setCheckable(true);
//     ui->pushButton_sub->setCheckable(true);
//     ui->pushButton_sub->setCheckable(true);


// }
// // ~ это деструктор
// MainWindow::~MainWindow()
// {
//     delete ui;
// }
// //мы вызываем эту функцию чтобы отрисовать числа
// void MainWindow::digits_numbers() {
// //    принимаем в указатель QPushButton * значение sender()
//     QPushButton *button = (QPushButton *)sender();

//     double all_numbers;
//     QString new_label;
//     // берем то что было в старом вводе и прибавляем новый ввод от текста кнопки
//     all_numbers = (ui->result_show->text() + button->text()).toDouble();
//     // делаем в переменной 15 знаков
//     new_label =  QString::number(all_numbers, 'g', 15);
//     // ставим текст в поле
//     ui->result_show->setText(new_label);
// }

// void MainWindow::on_pushButton_dot_clicked()
// {
// //    проверка для ввода одной точки
//     if (!(ui->result_show->text().contains(".")))
//         ui->result_show->setText(ui->result_show->text() + ".");
// }
// // работает с кнопкой смена знака и процент
// void MainWindow::operations()  {
//     QPushButton *button = (QPushButton *)sender();
//     double all_numbers;
//     QString new_label;

//     if(button->text() == "+/-") {
//         all_numbers = (ui->result_show->text()).toDouble();
//         all_numbers *= -1;
//         new_label =  QString::number(all_numbers, 'g', 15);
//         ui->result_show->setText(new_label);
//     } else if (button->text() == "%"){
//         all_numbers = (ui->result_show->text()).toDouble();
//         all_numbers *= 0.01;
//         new_label =  QString::number(all_numbers, 'g', 15);
//         ui->result_show->setText(new_label);
//     }

// }
// // меняет все сиволы на ноль
// void MainWindow::on_pushButton_AC_clicked()
// {
//     ui->result_show->setText("0");
// }

// //
// void MainWindow::math_operations() {
//     // отслеживает какая кнопка была нажата
// //    QPushButton *button = (QPushButton *)sender();

//     num_first = ui->result_show->text().toDouble();
// //    ui->result_show->setText("");
//     //что-то делает
// //    button->setChecked(true);

// }

// void MainWindow::on_pushButton_equal_clicked()
// {

//     char* str = new char(ui->result_show->text().length());
//     QByteArray new_label = ui->result_show->text().toLatin1();
//     strlcpy(str, new_label, ui->result_show->text().length() + 1);

//     parser(str, 2);

//     ui->result_show->setText(str);

// }

// //void MainWindow::on_pushButton_equal_clicked()
// //{
// //    double labelNumber, num_second;
// //    QString new_label;

// //    num_second = ui->result_show->text().toDouble();
// //// код для дебагинга
// ////    QString debug;
// ////    double res = ui->pushButton_sub->isChecked();

// ////    debug = QString::number(res, 'g', 15);
// ////    ui->result_show->setText(debug);

// ////    ui->pushButton_sub->isChecked()
// //    if (ui->pushButton_multiple->isChecked()) {

// //        labelNumber = num_first * num_second;
// //        new_label =  QString::number(labelNumber, 'g', 15);
// //        ui->result_show->setText(new_label);
// //        ui->pushButton_multiple->setChecked(false);

// //    } else if (ui->pushButton_div->isChecked()) {

// //        labelNumber = num_first / num_second;
// //        new_label =  QString::number(labelNumber, 'g', 15);
// //        ui->result_show->setText(new_label);
// //        ui->pushButton_div->setChecked(false);

// //    }else if (ui->pushButton_sum->isChecked()) {

// //        labelNumber = num_first + num_second;
// //        new_label =  QString::number(labelNumber, 'g', 15);
// //        ui->result_show->setText(new_label);
// //        ui->pushButton_sum->setChecked(false);

// //    }else if (ui->pushButton_sub->isChecked()) {

// //        labelNumber = num_first - num_second;
// //        new_label =  QString::number(labelNumber, 'g', 15);
// //        ui->result_show->setText(new_label);
// //        ui->pushButton_sub->setChecked(false);

// //    }
// //}

