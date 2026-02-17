/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *lblSelect;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QComboBox *selectText;
    QSpacerItem *verticalSpacer_5;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStart;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblTimeNow;
    QFrame *line_4;
    QLabel *lblSpeedNow;
    QFrame *line_5;
    QLabel *lblAccuracyNow;
    QFrame *line;
    QLabel *lblMainText;
    QFrame *line_2;
    QGridLayout *gridKeyboard;
    QPushButton *pushButton_6;
    QPushButton *pushButton_32;
    QPushButton *pushButton_13;
    QPushButton *pushButton_50;
    QPushButton *pushButton_21;
    QPushButton *pushButton_47;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_49;
    QPushButton *pushButton_42;
    QPushButton *pushButton_53;
    QPushButton *pushButton_44;
    QPushButton *pushButton_22;
    QPushButton *pushButton_30;
    QPushButton *pushButton_41;
    QPushButton *pushButton_33;
    QPushButton *pushButton_40;
    QPushButton *pushButton_51;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_48;
    QPushButton *pushButton_20;
    QPushButton *pushButton_5;
    QPushButton *pushButton_34;
    QPushButton *pushButton_18;
    QPushButton *pushButton;
    QPushButton *pushButton_36;
    QPushButton *pushButton_31;
    QPushButton *pushButton_45;
    QPushButton *pushButton_16;
    QPushButton *pushButton_25;
    QPushButton *pushButton_9;
    QPushButton *pushButton_27;
    QPushButton *pushButton_46;
    QPushButton *pushButton_17;
    QPushButton *pushButton_29;
    QPushButton *pushButton_14;
    QPushButton *pushButton_56;
    QPushButton *pushButton_58;
    QPushButton *pushButton_15;
    QPushButton *pushButton_52;
    QPushButton *pushButton_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_54;
    QPushButton *pushButton_19;
    QPushButton *pushButton_10;
    QPushButton *pushButton_26;
    QPushButton *pushButton_28;
    QPushButton *pushButton_55;
    QPushButton *pushButton_35;
    QPushButton *pushButton_43;
    QPushButton *pushButton_37;
    QPushButton *pushButton_57;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblSessionResult;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QLabel *lblTime;
    QFrame *line_6;
    QLabel *TimeResult;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_10;
    QLabel *lblSpeed;
    QFrame *line_7;
    QLabel *SpeedResult;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblAccuracy;
    QFrame *line_3;
    QLabel *AccuracyResult;
    QSpacerItem *verticalSpacer_6;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRestart;
    QPushButton *btnRetutn;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuhelp;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 600);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_4 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        lblSelect = new QLabel(page);
        lblSelect->setObjectName("lblSelect");
        QFont font;
        font.setPointSize(24);
        lblSelect->setFont(font);

        verticalLayout->addWidget(lblSelect);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 43, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        selectText = new QComboBox(page);
        selectText->addItem(QString());
        selectText->addItem(QString());
        selectText->addItem(QString());
        selectText->addItem(QString());
        selectText->addItem(QString());
        selectText->addItem(QString());
        selectText->setObjectName("selectText");
        QFont font1;
        font1.setPointSize(18);
        selectText->setFont(font1);

        verticalLayout->addWidget(selectText);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label = new QLabel(page);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        label->setFont(font2);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnStart = new QPushButton(page);
        btnStart->setObjectName("btnStart");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy);
        btnStart->setMinimumSize(QSize(200, 0));
        btnStart->setFont(font);

        horizontalLayout_2->addWidget(btnStart);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 0, 0);
        lblTimeNow = new QLabel(page_2);
        lblTimeNow->setObjectName("lblTimeNow");

        horizontalLayout_4->addWidget(lblTimeNow);

        line_4 = new QFrame(page_2);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_4->addWidget(line_4);

        lblSpeedNow = new QLabel(page_2);
        lblSpeedNow->setObjectName("lblSpeedNow");

        horizontalLayout_4->addWidget(lblSpeedNow);

        line_5 = new QFrame(page_2);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_4->addWidget(line_5);

        lblAccuracyNow = new QLabel(page_2);
        lblAccuracyNow->setObjectName("lblAccuracyNow");

        horizontalLayout_4->addWidget(lblAccuracyNow);


        verticalLayout_2->addLayout(horizontalLayout_4);

        line = new QFrame(page_2);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line);

        lblMainText = new QLabel(page_2);
        lblMainText->setObjectName("lblMainText");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblMainText->sizePolicy().hasHeightForWidth());
        lblMainText->setSizePolicy(sizePolicy1);
        lblMainText->setMinimumSize(QSize(0, 250));

        verticalLayout_2->addWidget(lblMainText);

        line_2 = new QFrame(page_2);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line_2);

        gridKeyboard = new QGridLayout();
        gridKeyboard->setObjectName("gridKeyboard");
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName("pushButton_6");

        gridKeyboard->addWidget(pushButton_6, 0, 5, 1, 1);

        pushButton_32 = new QPushButton(page_2);
        pushButton_32->setObjectName("pushButton_32");

        gridKeyboard->addWidget(pushButton_32, 2, 6, 1, 1);

        pushButton_13 = new QPushButton(page_2);
        pushButton_13->setObjectName("pushButton_13");

        gridKeyboard->addWidget(pushButton_13, 0, 6, 1, 1);

        pushButton_50 = new QPushButton(page_2);
        pushButton_50->setObjectName("pushButton_50");

        gridKeyboard->addWidget(pushButton_50, 3, 12, 1, 1);

        pushButton_21 = new QPushButton(page_2);
        pushButton_21->setObjectName("pushButton_21");

        gridKeyboard->addWidget(pushButton_21, 1, 7, 1, 1);

        pushButton_47 = new QPushButton(page_2);
        pushButton_47->setObjectName("pushButton_47");

        gridKeyboard->addWidget(pushButton_47, 3, 9, 1, 1);

        pushButton_23 = new QPushButton(page_2);
        pushButton_23->setObjectName("pushButton_23");

        gridKeyboard->addWidget(pushButton_23, 1, 9, 1, 1);

        pushButton_24 = new QPushButton(page_2);
        pushButton_24->setObjectName("pushButton_24");

        gridKeyboard->addWidget(pushButton_24, 1, 10, 1, 1);

        pushButton_49 = new QPushButton(page_2);
        pushButton_49->setObjectName("pushButton_49");

        gridKeyboard->addWidget(pushButton_49, 3, 11, 1, 1);

        pushButton_42 = new QPushButton(page_2);
        pushButton_42->setObjectName("pushButton_42");

        gridKeyboard->addWidget(pushButton_42, 3, 4, 1, 1);

        pushButton_53 = new QPushButton(page_2);
        pushButton_53->setObjectName("pushButton_53");

        gridKeyboard->addWidget(pushButton_53, 4, 2, 1, 1);

        pushButton_44 = new QPushButton(page_2);
        pushButton_44->setObjectName("pushButton_44");

        gridKeyboard->addWidget(pushButton_44, 3, 6, 1, 1);

        pushButton_22 = new QPushButton(page_2);
        pushButton_22->setObjectName("pushButton_22");

        gridKeyboard->addWidget(pushButton_22, 1, 8, 1, 1);

        pushButton_30 = new QPushButton(page_2);
        pushButton_30->setObjectName("pushButton_30");

        gridKeyboard->addWidget(pushButton_30, 2, 4, 1, 1);

        pushButton_41 = new QPushButton(page_2);
        pushButton_41->setObjectName("pushButton_41");

        gridKeyboard->addWidget(pushButton_41, 3, 3, 1, 1);

        pushButton_33 = new QPushButton(page_2);
        pushButton_33->setObjectName("pushButton_33");

        gridKeyboard->addWidget(pushButton_33, 2, 7, 1, 1);

        pushButton_40 = new QPushButton(page_2);
        pushButton_40->setObjectName("pushButton_40");

        gridKeyboard->addWidget(pushButton_40, 3, 0, 1, 3);

        pushButton_51 = new QPushButton(page_2);
        pushButton_51->setObjectName("pushButton_51");

        gridKeyboard->addWidget(pushButton_51, 3, 13, 1, 3);

        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");

        gridKeyboard->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName("pushButton_7");

        gridKeyboard->addWidget(pushButton_7, 0, 8, 1, 1);

        pushButton_48 = new QPushButton(page_2);
        pushButton_48->setObjectName("pushButton_48");

        gridKeyboard->addWidget(pushButton_48, 3, 10, 1, 1);

        pushButton_20 = new QPushButton(page_2);
        pushButton_20->setObjectName("pushButton_20");

        gridKeyboard->addWidget(pushButton_20, 1, 6, 1, 1);

        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName("pushButton_5");

        gridKeyboard->addWidget(pushButton_5, 0, 4, 1, 1);

        pushButton_34 = new QPushButton(page_2);
        pushButton_34->setObjectName("pushButton_34");

        gridKeyboard->addWidget(pushButton_34, 2, 8, 1, 1);

        pushButton_18 = new QPushButton(page_2);
        pushButton_18->setObjectName("pushButton_18");

        gridKeyboard->addWidget(pushButton_18, 1, 4, 1, 1);

        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");

        gridKeyboard->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_36 = new QPushButton(page_2);
        pushButton_36->setObjectName("pushButton_36");

        gridKeyboard->addWidget(pushButton_36, 2, 10, 1, 1);

        pushButton_31 = new QPushButton(page_2);
        pushButton_31->setObjectName("pushButton_31");

        gridKeyboard->addWidget(pushButton_31, 2, 5, 1, 1);

        pushButton_45 = new QPushButton(page_2);
        pushButton_45->setObjectName("pushButton_45");

        gridKeyboard->addWidget(pushButton_45, 3, 7, 1, 1);

        pushButton_16 = new QPushButton(page_2);
        pushButton_16->setObjectName("pushButton_16");

        gridKeyboard->addWidget(pushButton_16, 1, 0, 1, 2);

        pushButton_25 = new QPushButton(page_2);
        pushButton_25->setObjectName("pushButton_25");

        gridKeyboard->addWidget(pushButton_25, 1, 11, 1, 1);

        pushButton_9 = new QPushButton(page_2);
        pushButton_9->setObjectName("pushButton_9");

        gridKeyboard->addWidget(pushButton_9, 0, 10, 1, 1);

        pushButton_27 = new QPushButton(page_2);
        pushButton_27->setObjectName("pushButton_27");

        gridKeyboard->addWidget(pushButton_27, 1, 13, 1, 1);

        pushButton_46 = new QPushButton(page_2);
        pushButton_46->setObjectName("pushButton_46");

        gridKeyboard->addWidget(pushButton_46, 3, 8, 1, 1);

        pushButton_17 = new QPushButton(page_2);
        pushButton_17->setObjectName("pushButton_17");

        gridKeyboard->addWidget(pushButton_17, 1, 3, 1, 1);

        pushButton_29 = new QPushButton(page_2);
        pushButton_29->setObjectName("pushButton_29");

        gridKeyboard->addWidget(pushButton_29, 2, 3, 1, 1);

        pushButton_14 = new QPushButton(page_2);
        pushButton_14->setObjectName("pushButton_14");

        gridKeyboard->addWidget(pushButton_14, 0, 7, 1, 1);

        pushButton_56 = new QPushButton(page_2);
        pushButton_56->setObjectName("pushButton_56");

        gridKeyboard->addWidget(pushButton_56, 4, 13, 1, 1);

        pushButton_58 = new QPushButton(page_2);
        pushButton_58->setObjectName("pushButton_58");

        gridKeyboard->addWidget(pushButton_58, 4, 14, 1, 2);

        pushButton_15 = new QPushButton(page_2);
        pushButton_15->setObjectName("pushButton_15");

        gridKeyboard->addWidget(pushButton_15, 1, 2, 1, 1);

        pushButton_52 = new QPushButton(page_2);
        pushButton_52->setObjectName("pushButton_52");

        gridKeyboard->addWidget(pushButton_52, 4, 0, 1, 2);

        pushButton_12 = new QPushButton(page_2);
        pushButton_12->setObjectName("pushButton_12");

        gridKeyboard->addWidget(pushButton_12, 0, 13, 1, 3);

        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");

        gridKeyboard->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName("pushButton_11");
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setMinimumSize(QSize(0, 0));
        pushButton_11->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setPointSize(9);
        pushButton_11->setFont(font3);
        pushButton_11->setIconSize(QSize(16, 16));

        gridKeyboard->addWidget(pushButton_11, 0, 12, 1, 1);

        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName("pushButton_8");

        gridKeyboard->addWidget(pushButton_8, 0, 9, 1, 1);

        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName("pushButton_4");

        gridKeyboard->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_54 = new QPushButton(page_2);
        pushButton_54->setObjectName("pushButton_54");

        gridKeyboard->addWidget(pushButton_54, 4, 3, 1, 9);

        pushButton_19 = new QPushButton(page_2);
        pushButton_19->setObjectName("pushButton_19");

        gridKeyboard->addWidget(pushButton_19, 1, 5, 1, 1);

        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName("pushButton_10");

        gridKeyboard->addWidget(pushButton_10, 0, 11, 1, 1);

        pushButton_26 = new QPushButton(page_2);
        pushButton_26->setObjectName("pushButton_26");

        gridKeyboard->addWidget(pushButton_26, 1, 12, 1, 1);

        pushButton_28 = new QPushButton(page_2);
        pushButton_28->setObjectName("pushButton_28");

        gridKeyboard->addWidget(pushButton_28, 2, 0, 1, 3);

        pushButton_55 = new QPushButton(page_2);
        pushButton_55->setObjectName("pushButton_55");

        gridKeyboard->addWidget(pushButton_55, 4, 12, 1, 1);

        pushButton_35 = new QPushButton(page_2);
        pushButton_35->setObjectName("pushButton_35");

        gridKeyboard->addWidget(pushButton_35, 2, 9, 1, 1);

        pushButton_43 = new QPushButton(page_2);
        pushButton_43->setObjectName("pushButton_43");

        gridKeyboard->addWidget(pushButton_43, 3, 5, 1, 1);

        pushButton_37 = new QPushButton(page_2);
        pushButton_37->setObjectName("pushButton_37");

        gridKeyboard->addWidget(pushButton_37, 2, 11, 1, 1);

        pushButton_57 = new QPushButton(page_2);
        pushButton_57->setObjectName("pushButton_57");

        gridKeyboard->addWidget(pushButton_57, 1, 14, 1, 2);

        pushButton_38 = new QPushButton(page_2);
        pushButton_38->setObjectName("pushButton_38");

        gridKeyboard->addWidget(pushButton_38, 2, 12, 1, 1);

        pushButton_39 = new QPushButton(page_2);
        pushButton_39->setObjectName("pushButton_39");

        gridKeyboard->addWidget(pushButton_39, 2, 13, 1, 3);


        verticalLayout_2->addLayout(gridKeyboard);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lblSessionResult = new QLabel(page_3);
        lblSessionResult->setObjectName("lblSessionResult");
        lblSessionResult->setFont(font);

        verticalLayout_3->addWidget(lblSessionResult);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        lblTime = new QLabel(page_3);
        lblTime->setObjectName("lblTime");
        QFont font4;
        font4.setPointSize(14);
        lblTime->setFont(font4);
        lblTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(lblTime);

        line_6 = new QFrame(page_3);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_9->addWidget(line_6);

        TimeResult = new QLabel(page_3);
        TimeResult->setObjectName("TimeResult");
        TimeResult->setFont(font4);
        TimeResult->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(TimeResult);


        verticalLayout_8->addLayout(verticalLayout_9);


        horizontalLayout_6->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        lblSpeed = new QLabel(page_3);
        lblSpeed->setObjectName("lblSpeed");
        lblSpeed->setFont(font4);
        lblSpeed->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(lblSpeed);

        line_7 = new QFrame(page_3);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_10->addWidget(line_7);

        SpeedResult = new QLabel(page_3);
        SpeedResult->setObjectName("SpeedResult");
        SpeedResult->setFont(font4);
        SpeedResult->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(SpeedResult);


        verticalLayout_7->addLayout(verticalLayout_10);


        horizontalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lblAccuracy = new QLabel(page_3);
        lblAccuracy->setObjectName("lblAccuracy");
        lblAccuracy->setFont(font4);
        lblAccuracy->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(lblAccuracy);

        line_3 = new QFrame(page_3);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_6->addWidget(line_3);

        AccuracyResult = new QLabel(page_3);
        AccuracyResult->setObjectName("AccuracyResult");
        AccuracyResult->setFont(font4);
        AccuracyResult->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(AccuracyResult);


        verticalLayout_5->addLayout(verticalLayout_6);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 216, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_6);

        line_8 = new QFrame(page_3);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::Shape::HLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        btnRestart = new QPushButton(page_3);
        btnRestart->setObjectName("btnRestart");
        btnRestart->setFont(font4);

        horizontalLayout_8->addWidget(btnRestart);

        btnRetutn = new QPushButton(page_3);
        btnRetutn->setObjectName("btnRetutn");
        btnRetutn->setFont(font4);

        horizontalLayout_8->addWidget(btnRetutn);

        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(page_3);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 910, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuhelp = new QMenu(menubar);
        menuhelp->setObjectName("menuhelp");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuhelp->menuAction());
        menuFile->addAction(actionExit);
        menuhelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        lblSelect->setText(QCoreApplication::translate("MainWindow", "Select text to practice", nullptr));
        selectText->setItemText(0, QCoreApplication::translate("MainWindow", "Starter text", nullptr));
        selectText->setItemText(1, QCoreApplication::translate("MainWindow", "Numbers and symbols", nullptr));
        selectText->setItemText(2, QCoreApplication::translate("MainWindow", "Common words part 1", nullptr));
        selectText->setItemText(3, QCoreApplication::translate("MainWindow", "Common words part 2", nullptr));
        selectText->setItemText(4, QCoreApplication::translate("MainWindow", "Python code sample", nullptr));
        selectText->setItemText(5, QCoreApplication::translate("MainWindow", "Random text", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Simple text training texts which will show and upgrade your type skills", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start Training", nullptr));
        lblTimeNow->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        lblSpeedNow->setText(QCoreApplication::translate("MainWindow", "CPM", nullptr));
        lblAccuracyNow->setText(QCoreApplication::translate("MainWindow", "Accuracy", nullptr));
        lblMainText->setText(QCoreApplication::translate("MainWindow", "Some text", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_50->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        pushButton_47->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        pushButton_49->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_42->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_53->setText(QCoreApplication::translate("MainWindow", "Alt", nullptr));
        pushButton_44->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        pushButton_41->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        pushButton_40->setText(QCoreApplication::translate("MainWindow", "\342\207\247", nullptr));
        pushButton_51->setText(QCoreApplication::translate("MainWindow", "\342\207\247", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_48->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_36->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        pushButton_45->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Tab", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainWindow", "}", nullptr));
        pushButton_46->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_56->setText(QCoreApplication::translate("MainWindow", "Fn", nullptr));
        pushButton_58->setText(QCoreApplication::translate("MainWindow", "Crtl", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        pushButton_52->setText(QCoreApplication::translate("MainWindow", "Crtl", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_54->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "{", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "Caps", nullptr));
        pushButton_55->setText(QCoreApplication::translate("MainWindow", "Alt", nullptr));
        pushButton_35->setText(QCoreApplication::translate("MainWindow", "J", nullptr));
        pushButton_43->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_37->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        pushButton_57->setText(QCoreApplication::translate("MainWindow", "\\", nullptr));
        pushButton_38->setText(QCoreApplication::translate("MainWindow", ";", nullptr));
        pushButton_39->setText(QCoreApplication::translate("MainWindow", "\342\217\216", nullptr));
        lblSessionResult->setText(QCoreApplication::translate("MainWindow", "Session Results", nullptr));
        lblTime->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        TimeResult->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblSpeed->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        SpeedResult->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblAccuracy->setText(QCoreApplication::translate("MainWindow", "Accuracy", nullptr));
        AccuracyResult->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnRestart->setText(QCoreApplication::translate("MainWindow", "Restart Training", nullptr));
        btnRetutn->setText(QCoreApplication::translate("MainWindow", "Return to main", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
