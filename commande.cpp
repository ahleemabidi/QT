#include "commande.h"
#include<QSqlQuery>
#include<QtDebug>
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <QDebug>

Commande::Commande()
{   id_c=0 ;
    prix=0 ;
    quantite=0 ;
}
 Commande::Commande (int id_c,int prix,int quantite ,QString DateC)
 {   this->id_c=id_c ;
     this->prix=prix;
     this->quantite=quantite;
     this->DateC=DateC;
 }


     void Commande::setId(int id_c){this->id_c=id_c;}
     void Commande::setPrix(int prix){this->prix=prix;}
     void Commande::setQuantite(int quantite){this->quantite=quantite;}
     void Commande::setDateC(QString DateC){this->DateC=DateC;}

     bool Commande::ajouter()
     {      QSqlQuery query;
            query.prepare(" INSERT INTO COMMANDE(ID_C,PRIX,QUANTITE,DATEC)" "VALUES(:id_c,:prix,:quantite,:DateC)");
            query.bindValue(":id_c",getId());
            query.bindValue(":prix",getPrix());
            query.bindValue(":quantite",getQuantite());
            query.bindValue(":DateC",getDateC());

            return query.exec();
     }

     QSqlQueryModel* Commande::afficher(QString recherche,int order)
     {  QSqlQueryModel* model=new QSqlQueryModel();
         if(recherche!="")if(order==1)
         model->setQuery("SELECT* FROM COMMANDE where id_c like '%"+recherche+"%' order by prix");
else
         model->setQuery("SELECT* FROM COMMANDE where id_c like '%"+recherche+"%' order by prix desc");
else    if(order==1)
        model->setQuery("SELECT* FROM COMMANDE order by prix ");
else
        model->setQuery("SELECT* FROM COMMANDE order by prix desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEC"));
        return model;
     }

     bool Commande::supprimer(int id1)
     {     QSqlQuery query;
           QString identifiant=QString::number(id1);
           query.prepare(" DELETE  From COMMANDE  WHERE ID_C= :id1");
           query.bindValue(":id1",identifiant);
           return query.exec(); }

     bool Commande::modifier(int id_modif)
      {
        QSqlQuery query;
        QString identifiant=QString::number(id_modif);
        QString le_prix=QString::number(prix);
        QString la_quantitee=QString::number(quantite);

     query.prepare("UPDATE COMMANDE SET  prix= :prix ,quantite= :quantite , DateC= :DateC WHERE ID_C= :id_modif ");
     query.bindValue(":id_modif",identifiant);
     query.bindValue(":prix",le_prix);
     query.bindValue(":quantite",la_quantitee);
     query.bindValue(":DateC",DateC);

     return query.exec();
      }

     void Commande::RechercherCommandes(int id_cherch)
     {   QSqlQuery query2;
         query2.prepare ("SELECT * FROM COMMANDE WHERE ID_C= '"+QString::number(id_cherch)+"'");
         query2.exec();

              while(query2.next()){
              id_c= query2.value(0).toInt();
              prix= query2.value(1).toInt();
              quantite= query2.value(2).toInt();
              DateC=query2.value(3).toInt();
           }
     }
