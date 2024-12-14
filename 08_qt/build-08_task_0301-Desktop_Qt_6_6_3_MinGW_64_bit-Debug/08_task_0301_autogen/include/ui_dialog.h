/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *v_login;
    QLabel *lbl_password;
    QLabel *lbl_DB_name;
    QLabel *lbl_host_name;
    QLabel *lbl_login;
    QLabel *lbl_port_numbr;
    QLineEdit *v_host_name;
    QLineEdit *v_password;
    QSpinBox *v_port_numbr;
    QDialogButtonBox *pb_OK;
    QDialogButtonBox *pb_Cancel;
    QLineEdit *v_DB_name;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(370, 220);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        v_login = new QLineEdit(Dialog);
        v_login->setObjectName("v_login");

        gridLayout->addWidget(v_login, 2, 1, 1, 1);

        lbl_password = new QLabel(Dialog);
        lbl_password->setObjectName("lbl_password");

        gridLayout->addWidget(lbl_password, 3, 0, 1, 1);

        lbl_DB_name = new QLabel(Dialog);
        lbl_DB_name->setObjectName("lbl_DB_name");

        gridLayout->addWidget(lbl_DB_name, 1, 0, 1, 1);

        lbl_host_name = new QLabel(Dialog);
        lbl_host_name->setObjectName("lbl_host_name");

        gridLayout->addWidget(lbl_host_name, 0, 0, 1, 1);

        lbl_login = new QLabel(Dialog);
        lbl_login->setObjectName("lbl_login");

        gridLayout->addWidget(lbl_login, 2, 0, 1, 1);

        lbl_port_numbr = new QLabel(Dialog);
        lbl_port_numbr->setObjectName("lbl_port_numbr");

        gridLayout->addWidget(lbl_port_numbr, 4, 0, 1, 1);

        v_host_name = new QLineEdit(Dialog);
        v_host_name->setObjectName("v_host_name");

        gridLayout->addWidget(v_host_name, 0, 1, 1, 1);

        v_password = new QLineEdit(Dialog);
        v_password->setObjectName("v_password");

        gridLayout->addWidget(v_password, 3, 1, 1, 1);

        v_port_numbr = new QSpinBox(Dialog);
        v_port_numbr->setObjectName("v_port_numbr");
        v_port_numbr->setMaximum(65535);
        v_port_numbr->setValue(5432);

        gridLayout->addWidget(v_port_numbr, 4, 1, 1, 1);

        pb_OK = new QDialogButtonBox(Dialog);
        pb_OK->setObjectName("pb_OK");
        pb_OK->setLayoutDirection(Qt::LeftToRight);
        pb_OK->setStandardButtons(QDialogButtonBox::Ok);
        pb_OK->setCenterButtons(true);

        gridLayout->addWidget(pb_OK, 5, 0, 1, 1);

        pb_Cancel = new QDialogButtonBox(Dialog);
        pb_Cancel->setObjectName("pb_Cancel");
        pb_Cancel->setStandardButtons(QDialogButtonBox::Cancel);
        pb_Cancel->setCenterButtons(true);

        gridLayout->addWidget(pb_Cancel, 5, 1, 1, 1);

        v_DB_name = new QLineEdit(Dialog);
        v_DB_name->setObjectName("v_DB_name");

        gridLayout->addWidget(v_DB_name, 1, 1, 1, 1);

#if QT_CONFIG(shortcut)
        lbl_password->setBuddy(v_password);
        lbl_DB_name->setBuddy(v_DB_name);
        lbl_host_name->setBuddy(v_host_name);
        lbl_login->setBuddy(v_login);
        lbl_port_numbr->setBuddy(v_port_numbr);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Dialog);
        QObject::connect(pb_OK, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(pb_Cancel, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \320\221\320\224", nullptr));
        lbl_password->setText(QCoreApplication::translate("Dialog", "&\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lbl_DB_name->setText(QCoreApplication::translate("Dialog", "&\320\230\320\274\321\217 \320\221\320\224", nullptr));
        lbl_host_name->setText(QCoreApplication::translate("Dialog", "&\320\230\320\274\321\217 \321\205\320\276\321\201\321\202\320\260", nullptr));
        lbl_login->setText(QCoreApplication::translate("Dialog", "&\320\233\320\276\320\263\320\270\320\275", nullptr));
        lbl_port_numbr->setText(QCoreApplication::translate("Dialog", "&\320\237\320\276\321\200\321\202 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \320\272 \320\221\320\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
