#include <QCoreApplication>
#include <QDebug>
#include <QHostInfo>
#include <QLocalServer>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtSql>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QHostInfo remt_host_info = QHostInfo::fromName("mail.ru");

  QLocalServer *localServer;

  QSqlDatabase db_test_1 = QSqlDatabase::addDatabase("test_1");

  QSqlTableModel model;

  return a.exec();
}
