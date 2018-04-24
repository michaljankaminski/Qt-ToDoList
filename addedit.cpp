#include "addedit.h"
#include "mainwindow.h"
#include "ui_addedit.h"
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QDate>
#include <QWidget>
AddEdit::AddEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEdit)
{

    ui->setupUi(this);
}
AddEdit::AddEdit(QModelIndex index,QPushButton *TaskSave,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEdit)
{
    ui->setupUi(this);
    QDate date = date.fromString(index.sibling(index.row(),0).data().toString(),"yyyy-MM-dd");
    ui->title->setText(index.sibling(index.row(),1).data().toString());
    ui->description->setText(index.sibling(index.row(),3).data().toString());
    ui->date->setDate(date);
    ui->slider->setValue(index.sibling(index.row(),2).data().toInt());
//    MainWindow *w = qobject_cast<MainWindow*>(parent);
//    qDebug() << w->list[0]->getComplete();
 //   TaskSave=ui->pushButton;
}

AddEdit::~AddEdit()
{
    delete ui;
}

void AddEdit::on_pushButton_clicked()
{

}
void AddEdit::SetItems(QModelIndex index)
{
 //  qDebug() <<  index.row();

}
Task* AddEdit::setTask()
{
    Task* task = new Task(ui->date->date(),"ui->title->text()",2,"abc");
   // Task* task = new Task(ui->date->date(),ui->slider->value(),ui->title->text(),"abc");
    return task;
}
