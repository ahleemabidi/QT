#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connection.h"
#include "commande.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_buttonAjout_clicked();



    void on_button_supprimer_clicked();

    void on_buttonAfficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_Menu_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_ButtonModifier_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_21_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_order_clicked();

private:
    Ui::MainWindow *ui;
    Commande C;
    int ord;
};

#endif // MAINWINDOW_H
