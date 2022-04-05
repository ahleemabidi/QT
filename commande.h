#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <iostream>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTime>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTime>

#include "connection.h"

class Commande
{
private:
    int id_c ;
    int prix ;
    int quantite ;
    QString DateC;
public:
    Commande();
    Commande (int,int,int,QString);


    int getId() {return id_c;}
    int getPrix() {return prix;}
    int getQuantite(){return quantite;}
    QString getDateC(){return DateC;}

    void setId(int);
    void setPrix(int);
    void setQuantite(int);
    void setDateC(QString);

    bool ajouter();
    QSqlQueryModel* afficher(QString recherche,int order);
    bool supprimer (int);
    bool modifier(int);
    void RechercherCommandes(int id_chech);
    QSqlQueryModel* statistiques();
    void notifcation();






};

#endif // COMMANDE_H
