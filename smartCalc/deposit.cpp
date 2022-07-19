#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);

}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}


void Deposit::on_pushButton_2_clicked()
{



    if (ui->checkBox_kapitolization_persent->isChecked()){
        double sum_invest = ui->lineEdit_sum_invest->text().toDouble();
        double placement_period = ui->lineEdit_placement_period->text().toDouble();
        double percent = sum_invest * ui->lineEdit_percent->text().toDouble() * 0.01;
        double nalog = sum_invest * ui->lineEdit_nalog->text().toDouble() * 0.01;

        double result = sum_invest + percent * placement_period - nalog;

        QString percent_string =  QString::number(percent, 'g', 15);
        ui->label_nachislennie_persent->setText("Начисленные проценты " + percent_string + " руб");

        QString nalog_string =  QString::number(nalog, 'g', 15);
        ui->label_sum_nalog_2->setText("Сумма налога " + nalog_string + " руб");

        QString result_string =  QString::number(result, 'g', 15);
        QString year = QString::number((placement_period + 2021), 'g', 15);
        ui->label_sum_k_konzu_sroka_2->setText("Сумма на вкладе к концу срока " + result_string + " руб к " + year + "году");
    } else {

        double sum_invest = ui->lineEdit_sum_invest->text().toDouble();
        double placement_period = ui->lineEdit_placement_period->text().toDouble();
        double percent = sum_invest * ui->lineEdit_percent->text().toDouble() * 0.01;
        double nalog = sum_invest * ui->lineEdit_nalog->text().toDouble() * 0.01;

        double result = sum_invest + percent * placement_period - nalog;
        result = int(result * 0.95);

        QString percent_string =  QString::number(percent, 'g', 15);
        ui->label_nachislennie_persent->setText("Начисленные проценты " + percent_string + " руб");

        QString nalog_string =  QString::number(nalog, 'g', 15);
        ui->label_sum_nalog_2->setText("Сумма налога " + nalog_string + " руб");

        QString result_string =  QString::number(result, 'g', 15);
        QString year = QString::number((placement_period + 2021), 'g', 15);
        ui->label_sum_k_konzu_sroka_2->setText("Сумма на вкладе к концу срока " + result_string + " руб к " + year + "году");
    }
}


