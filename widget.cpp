#include "widget.h"
#include "ui_widget.h"
#include "ui_result.h"
#include <QFileDialog>
#include <QUrl>
#include <QDebug>
#include "FileReader.hpp"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_selectFileButton_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File");
    ui->selectFileButton->hide();
    FileReader file(m_fileName.toUtf8().constData());
    QString str = QString::fromUtf8(file.show().c_str());
    this->setStyleSheet("background-color:#dfc8ca");
    ui->label->setStyleSheet("color:#d3394c");
    ui->label->setText(str);
}
