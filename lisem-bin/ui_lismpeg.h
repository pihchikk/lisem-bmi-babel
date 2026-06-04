/********************************************************************************
** Form generated from reading UI file 'lismpeg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISMPEG_H
#define UI_LISMPEG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_lismpeg
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *E_resultsDir;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpin_mpegFps;
    QComboBox *comboBox_mpegResolution;
    QToolButton *toolButton_createMP4;
    QLineEdit *E_mencoderDir;
    QLabel *label_5;
    QLabel *label_4;
    QToolButton *toolButton_resultDir;
    QToolButton *toolButton_mencoderDir;
    QToolButton *toolButton_stpMP4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QToolButton *toolButton_showMP4;
    QTextEdit *E_mpegProcessOutput;

    void setupUi(QDialog *lismpeg)
    {
        if (lismpeg->objectName().isEmpty())
            lismpeg->setObjectName("lismpeg");
        lismpeg->resize(655, 392);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/2X/film.png"), QSize(), QIcon::Normal, QIcon::Off);
        lismpeg->setWindowIcon(icon);
        gridLayout = new QGridLayout(lismpeg);
        gridLayout->setObjectName("gridLayout");
        buttonBox = new QDialogButtonBox(lismpeg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 2);

        E_resultsDir = new QLineEdit(lismpeg);
        E_resultsDir->setObjectName("E_resultsDir");

        gridLayout->addWidget(E_resultsDir, 2, 3, 1, 3);

        label = new QLabel(lismpeg);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 1, 0, 1, 3);

        label_2 = new QLabel(lismpeg);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        doubleSpin_mpegFps = new QDoubleSpinBox(lismpeg);
        doubleSpin_mpegFps->setObjectName("doubleSpin_mpegFps");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpin_mpegFps->sizePolicy().hasHeightForWidth());
        doubleSpin_mpegFps->setSizePolicy(sizePolicy1);
        doubleSpin_mpegFps->setDecimals(0);
        doubleSpin_mpegFps->setMinimum(1.000000000000000);
        doubleSpin_mpegFps->setMaximum(30.000000000000000);
        doubleSpin_mpegFps->setSingleStep(1.000000000000000);
        doubleSpin_mpegFps->setValue(12.000000000000000);

        gridLayout->addWidget(doubleSpin_mpegFps, 3, 1, 1, 1);

        comboBox_mpegResolution = new QComboBox(lismpeg);
        comboBox_mpegResolution->setObjectName("comboBox_mpegResolution");

        gridLayout->addWidget(comboBox_mpegResolution, 3, 4, 1, 1);

        toolButton_createMP4 = new QToolButton(lismpeg);
        toolButton_createMP4->setObjectName("toolButton_createMP4");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton_createMP4->sizePolicy().hasHeightForWidth());
        toolButton_createMP4->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/2X/play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_createMP4->setIcon(icon1);
        toolButton_createMP4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(toolButton_createMP4, 4, 0, 1, 6);

        E_mencoderDir = new QLineEdit(lismpeg);
        E_mencoderDir->setObjectName("E_mencoderDir");

        gridLayout->addWidget(E_mencoderDir, 1, 3, 1, 3);

        label_5 = new QLabel(lismpeg);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 0, 1, 7);

        label_4 = new QLabel(lismpeg);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 2, 1, 2);

        toolButton_resultDir = new QToolButton(lismpeg);
        toolButton_resultDir->setObjectName("toolButton_resultDir");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2X/Folder-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_resultDir->setIcon(icon2);

        gridLayout->addWidget(toolButton_resultDir, 2, 6, 1, 1);

        toolButton_mencoderDir = new QToolButton(lismpeg);
        toolButton_mencoderDir->setObjectName("toolButton_mencoderDir");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/2X/Folder-Open-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_mencoderDir->setIcon(icon3);

        gridLayout->addWidget(toolButton_mencoderDir, 1, 6, 1, 1);

        toolButton_stpMP4 = new QToolButton(lismpeg);
        toolButton_stpMP4->setObjectName("toolButton_stpMP4");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/2X/Stop-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_stpMP4->setIcon(icon4);

        gridLayout->addWidget(toolButton_stpMP4, 4, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(261, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 5, 1, 1);

        label_3 = new QLabel(lismpeg);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        toolButton_showMP4 = new QToolButton(lismpeg);
        toolButton_showMP4->setObjectName("toolButton_showMP4");
        toolButton_showMP4->setIcon(icon);
        toolButton_showMP4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(toolButton_showMP4, 4, 7, 1, 1);

        E_mpegProcessOutput = new QTextEdit(lismpeg);
        E_mpegProcessOutput->setObjectName("E_mpegProcessOutput");

        gridLayout->addWidget(E_mpegProcessOutput, 5, 0, 1, 8);


        retranslateUi(lismpeg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, lismpeg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, lismpeg, qOverload<>(&QDialog::reject));

        comboBox_mpegResolution->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(lismpeg);
    } // setupUi

    void retranslateUi(QDialog *lismpeg)
    {
        lismpeg->setWindowTitle(QCoreApplication::translate("lismpeg", "Convert screenshots to mpeg", nullptr));
        label->setText(QCoreApplication::translate("lismpeg", "Mencoder lcation", nullptr));
        label_2->setText(QCoreApplication::translate("lismpeg", "Result folder", nullptr));
        toolButton_createMP4->setText(QCoreApplication::translate("lismpeg", "Create mp4", nullptr));
        label_5->setText(QCoreApplication::translate("lismpeg", "<html><head/><body><p>You can only create a movie AFTER you have run a simulation and saved screenshots</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("lismpeg", "Resolution", nullptr));
        toolButton_resultDir->setText(QCoreApplication::translate("lismpeg", "...", nullptr));
        toolButton_mencoderDir->setText(QCoreApplication::translate("lismpeg", "...", nullptr));
        toolButton_stpMP4->setText(QCoreApplication::translate("lismpeg", "...", nullptr));
        label_3->setText(QCoreApplication::translate("lismpeg", "Fps: ", nullptr));
        toolButton_showMP4->setText(QCoreApplication::translate("lismpeg", "Show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lismpeg: public Ui_lismpeg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISMPEG_H
