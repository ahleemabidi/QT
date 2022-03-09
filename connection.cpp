#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("ahlem");//inserer nom de l'utilisateur
db.setPassword("ahlem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

qDebug() << "ERROR" << db.lastError();



    return  test;
}

