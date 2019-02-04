/********************************************************************************
** Form generated from reading UI file 'cuacsview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUACSVIEW_H
#define UI_CUACSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CUACSView
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *addAnimalBtn;
    QLabel *emptyItemlbl;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameTxt;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *breedTxt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *DOBTxt;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *yearsSpn;
    QLabel *label_5;
    QSpinBox *monthsSpn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *genderCombo;
    QCheckBox *vaccinatedChk;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QComboBox *speciesCombo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CUACSView)
    {
        if (CUACSView->objectName().isEmpty())
            CUACSView->setObjectName(QStringLiteral("CUACSView"));
        CUACSView->resize(661, 279);
        centralWidget = new QWidget(CUACSView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 671, 481));
        tabWidget->setFocusPolicy(Qt::ClickFocus);
        tabWidget->setToolTipDuration(-2);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        addAnimalBtn = new QPushButton(tab_2);
        addAnimalBtn->setObjectName(QStringLiteral("addAnimalBtn"));
        addAnimalBtn->setEnabled(true);
        addAnimalBtn->setGeometry(QRect(490, 170, 82, 25));
        addAnimalBtn->setToolTipDuration(-1);
        addAnimalBtn->setCheckable(false);
        emptyItemlbl = new QLabel(tab_2);
        emptyItemlbl->setObjectName(QStringLiteral("emptyItemlbl"));
        emptyItemlbl->setGeometry(QRect(0, 150, 231, 17));
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 641, 151));
        horizontalLayout_13 = new QHBoxLayout(widget);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameTxt = new QLineEdit(widget);
        nameTxt->setObjectName(QStringLiteral("nameTxt"));

        horizontalLayout->addWidget(nameTxt);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        breedTxt = new QLineEdit(widget);
        breedTxt->setObjectName(QStringLiteral("breedTxt"));

        horizontalLayout_2->addWidget(breedTxt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        DOBTxt = new QLineEdit(widget);
        DOBTxt->setObjectName(QStringLiteral("DOBTxt"));
        DOBTxt->setToolTipDuration(-1);

        horizontalLayout_5->addWidget(DOBTxt);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_13->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        yearsSpn = new QSpinBox(widget);
        yearsSpn->setObjectName(QStringLiteral("yearsSpn"));

        horizontalLayout_3->addWidget(yearsSpn);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        monthsSpn = new QSpinBox(widget);
        monthsSpn->setObjectName(QStringLiteral("monthsSpn"));
        monthsSpn->setMaximum(12);

        horizontalLayout_3->addWidget(monthsSpn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        genderCombo = new QComboBox(widget);
        genderCombo->setObjectName(QStringLiteral("genderCombo"));

        horizontalLayout_4->addWidget(genderCombo);

        vaccinatedChk = new QCheckBox(widget);
        vaccinatedChk->setObjectName(QStringLiteral("vaccinatedChk"));
        vaccinatedChk->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(vaccinatedChk);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        speciesCombo = new QComboBox(widget);
        speciesCombo->setObjectName(QStringLiteral("speciesCombo"));

        horizontalLayout_6->addWidget(speciesCombo);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_13->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_2, QString());
        CUACSView->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CUACSView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CUACSView->setStatusBar(statusBar);

        retranslateUi(CUACSView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CUACSView);
    } // setupUi

    void retranslateUi(QMainWindow *CUACSView)
    {
        CUACSView->setWindowTitle(QApplication::translate("CUACSView", "CUACSView", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CUACSView", "View Animals", Q_NULLPTR));
        addAnimalBtn->setText(QApplication::translate("CUACSView", "Add animal", Q_NULLPTR));
        emptyItemlbl->setText(QApplication::translate("CUACSView", "Items marked with a * are required", Q_NULLPTR));
        label->setText(QApplication::translate("CUACSView", "*Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("CUACSView", "*Breed:", Q_NULLPTR));
        label_7->setText(QApplication::translate("CUACSView", "Date of Birth:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        DOBTxt->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("CUACSView", "*Age:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CUACSView", "Years", Q_NULLPTR));
        yearsSpn->setPrefix(QString());
        label_5->setText(QApplication::translate("CUACSView", "Months", Q_NULLPTR));
        label_6->setText(QApplication::translate("CUACSView", "*Gender:", Q_NULLPTR));
        genderCombo->setCurrentText(QString());
        vaccinatedChk->setText(QApplication::translate("CUACSView", "Vaccinated?", Q_NULLPTR));
        label_8->setText(QApplication::translate("CUACSView", "*Species:", Q_NULLPTR));
        speciesCombo->setCurrentText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CUACSView", "Add Animal", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CUACSView: public Ui_CUACSView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUACSVIEW_H
