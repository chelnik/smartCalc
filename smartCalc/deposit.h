#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
