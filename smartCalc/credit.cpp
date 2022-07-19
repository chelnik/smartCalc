#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}


void Credit::on_pushButton_back_clicked()
{
    this->close();
    emit firstWindow();
}


void Credit::on_pushButton_clicked()
{
    if (ui->pushButton_anuient->isChecked()){
        int monthlypay = ui->lineEdit_sum_credit->text().toDouble() / (ui->lineEdit_time_of_credit->text().toDouble() * 12);
        int accurent_percent = ui->lineEdit_sum_credit->text().toDouble() * 0.05499 * ui->lineEdit_time_of_credit->text().toDouble();
        int creditandpersent = ui->lineEdit_sum_credit->text().toDouble() + accurent_percent;

        QString str_monthlypay =  QString::number(monthlypay, 'g', 15);
        ui->label_monthlypay->setText(str_monthlypay);

        QString str_accurent_percent =  QString::number(accurent_percent, 'g', 15);
        ui->label_accruedpersent->setText(str_accurent_percent);

        QString str_creditandpersent =  QString::number(creditandpersent, 'g', 15);
        ui->label_creditandpersent->setText(str_creditandpersent);
    } else if (ui->radioButton_dif->isChecked()) {

        int monthlypay = ui->lineEdit_sum_credit->text().toDouble() / (ui->lineEdit_time_of_credit->text().toDouble() * 12 * 2);
        int accurent_percent = ui->lineEdit_sum_credit->text().toDouble() * 0.05416 * ui->lineEdit_time_of_credit->text().toDouble();
        int creditandpersent = ui->lineEdit_sum_credit->text().toDouble() + accurent_percent;

        QString str_monthlypay =  QString::number(monthlypay, 'g', 15);
        ui->label_monthlypay->setText(str_monthlypay);

        QString str_accurent_percent =  QString::number(accurent_percent, 'g', 15);
        ui->label_accruedpersent->setText(str_accurent_percent);

        QString str_creditandpersent =  QString::number(creditandpersent, 'g', 15);
        ui->label_creditandpersent->setText(str_creditandpersent);
    }

}

