#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"commande.h"
#include<QMessageBox>
#include "connection.h"
#include<QIntValidator>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(C.afficher("",0));
    ui->lineEdit_5->setText("");
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->order->setText("décrementé");
    ord=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_2_clicked()
{
       ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_buttonAjout_clicked()
{   int id_c=ui->le_id->text().toInt();
    int prix=ui->le_Prix->text().toInt();
    int quantite=ui->le_Quantite->text().toInt();
    QString DateC=ui->le_Date->text();

    Commande C(id_c,prix,quantite,DateC);
     ui->le_id->setValidator(new QIntValidator(0,999999999,this));
     ui->le_Prix->setValidator(new QIntValidator(0,999999999,this));
     ui->le_Quantite->setValidator(new QIntValidator(0,999999999,this));
    bool test=C.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tableView->setModel(C.afficher("",ord));
   ui->lineEdit_5->setText("");

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not okay"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}







void MainWindow::on_button_supprimer_clicked()
{  ui->le_id_supp->setValidator(new QIntValidator(0,999999999,this));
    int id_c= ui->le_id_supp->text().toInt();

    bool test=C.supprimer(id_c);

    if (test)


    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tableView->setModel(C.afficher("",ord));
   ui->lineEdit_5->setText("");
}
    else
        QMessageBox::critical(nullptr, QObject::tr("not okay"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_buttonAfficher_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_8_clicked()
{

}

void MainWindow::on_Menu_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_13_clicked()
{

      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ButtonModifier_clicked()
{ Commande C;
    ui->le_id_modif->setValidator(new QIntValidator(0,999999999,this));
    ui->le_prix_modif->setValidator(new QIntValidator(0,999999999,this));
    ui->le_quantite_modif->setValidator(new QIntValidator(0,999999999,this));

 int id_c=ui->le_id_modif->text().toInt();
C.setPrix(ui->le_prix_modif->text().toInt());
C.setQuantite(ui->le_quantite_modif->text().toInt());
C.setDateC(ui->le_date_modif->text());

   bool test = C.modifier(id_c) ;

       if (test)


       {   ui->setupUi(this);
           ui->tableView->setModel(C.afficher("",ord));
            ui->lineEdit_5->setText("");

           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("update successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not okay"),
                       QObject::tr("update failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
   }





void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_21_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
     ui->tableView->setModel(C.afficher(arg1,ord));
}

void MainWindow::on_order_clicked()
{       if(ord==0){
        ui->order->setText("incrementé");
        ord=1;}else {ui->order->setText("décrementé");
        ord=0;}
         ui->tableView->setModel(C.afficher(ui->lineEdit_5->text(),ord));

}
