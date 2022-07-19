#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
}

graph::~graph()
{
    delete ui;
}

void graph::on_pushButton_clicked()
{
 this->close();
 emit firstWindow();
}

