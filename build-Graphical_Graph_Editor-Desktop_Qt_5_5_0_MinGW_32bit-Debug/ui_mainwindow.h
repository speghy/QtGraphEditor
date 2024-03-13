/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMenuFileExit;
    QAction *actionDeleteItem;
    QAction *action;
    QAction *action_Open_file;
    QAction *action_Save_File;
    QAction *action_createNode;
    QAction *action_createEdge;
    QAction *action_delEdge;
    QAction *action_clear_all;
    QAction *action_Algoritm;
    QAction *action_About;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *OpenButton;
    QPushButton *pb_IncidenceListFile;
    QPushButton *saveButton;
    QPushButton *pb_Help;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_ConnectGraph;
    QPushButton *pb_DisconnectGraph;
    QPushButton *pb_LengthOfEdges;
    QPushButton *pb_CoordinatesOfAllNode;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_DeleteSelectedNodes;
    QPushButton *pb_RemoveEdges;
    QPushButton *pb_ClearAll;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_CreateNode;
    QPushButton *pb_CreateEdge;
    QLineEdit *lineEdit_Source;
    QLineEdit *lineEdit_Dest;
    QPushButton *pushAlgorithm;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLineEdit *lineEdit_AlgSource;
    QPushButton *pushFind;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushStop;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *textBrowser;
    GraphWidget *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuItems;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 800);
        MainWindow->setMinimumSize(QSize(900, 400));
        MainWindow->setAutoFillBackground(false);
        actionMenuFileExit = new QAction(MainWindow);
        actionMenuFileExit->setObjectName(QStringLiteral("actionMenuFileExit"));
        actionDeleteItem = new QAction(MainWindow);
        actionDeleteItem->setObjectName(QStringLiteral("actionDeleteItem"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_Open_file = new QAction(MainWindow);
        action_Open_file->setObjectName(QStringLiteral("action_Open_file"));
        action_Save_File = new QAction(MainWindow);
        action_Save_File->setObjectName(QStringLiteral("action_Save_File"));
        action_createNode = new QAction(MainWindow);
        action_createNode->setObjectName(QStringLiteral("action_createNode"));
        action_createEdge = new QAction(MainWindow);
        action_createEdge->setObjectName(QStringLiteral("action_createEdge"));
        action_delEdge = new QAction(MainWindow);
        action_delEdge->setObjectName(QStringLiteral("action_delEdge"));
        action_clear_all = new QAction(MainWindow);
        action_clear_all->setObjectName(QStringLiteral("action_clear_all"));
        action_Algoritm = new QAction(MainWindow);
        action_Algoritm->setObjectName(QStringLiteral("action_Algoritm"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 0));
        horizontalWidget->setStyleSheet(QLatin1String("background-color: rgb(190, 232, 232);\n"
"border-radius: 15px;"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        OpenButton = new QPushButton(horizontalWidget);
        OpenButton->setObjectName(QStringLiteral("OpenButton"));
        OpenButton->setMinimumSize(QSize(40, 40));
        OpenButton->setMaximumSize(QSize(40, 40));
        OpenButton->setCursor(QCursor(Qt::PointingHandCursor));
        OpenButton->setToolTipDuration(0);
        OpenButton->setStyleSheet(QStringLiteral("image: url(:/icons/open.png);"));

        horizontalLayout->addWidget(OpenButton);

        pb_IncidenceListFile = new QPushButton(horizontalWidget);
        pb_IncidenceListFile->setObjectName(QStringLiteral("pb_IncidenceListFile"));
        pb_IncidenceListFile->setMinimumSize(QSize(40, 40));
        pb_IncidenceListFile->setMaximumSize(QSize(40, 40));
        pb_IncidenceListFile->setCursor(QCursor(Qt::PointingHandCursor));
        pb_IncidenceListFile->setStyleSheet(QStringLiteral("image: url(:/icons/openlist.png);"));

        horizontalLayout->addWidget(pb_IncidenceListFile);

        saveButton = new QPushButton(horizontalWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(40, 40));
        saveButton->setMaximumSize(QSize(40, 40));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton->setStyleSheet(QStringLiteral("image: url(:/icons/savef.png);"));

        horizontalLayout->addWidget(saveButton);

        pb_Help = new QPushButton(horizontalWidget);
        pb_Help->setObjectName(QStringLiteral("pb_Help"));
        pb_Help->setMinimumSize(QSize(40, 40));
        pb_Help->setMaximumSize(QSize(40, 40));
        pb_Help->setCursor(QCursor(Qt::PointingHandCursor));
        pb_Help->setStyleSheet(QStringLiteral("image: url(:/icons/help.png);"));

        horizontalLayout->addWidget(pb_Help);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_ConnectGraph = new QPushButton(horizontalWidget);
        pb_ConnectGraph->setObjectName(QStringLiteral("pb_ConnectGraph"));
        pb_ConnectGraph->setMinimumSize(QSize(40, 40));
        pb_ConnectGraph->setMaximumSize(QSize(40, 40));
        pb_ConnectGraph->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ConnectGraph->setStyleSheet(QStringLiteral("image: url(:/icons/fullgraph.png);"));

        horizontalLayout->addWidget(pb_ConnectGraph);

        pb_DisconnectGraph = new QPushButton(horizontalWidget);
        pb_DisconnectGraph->setObjectName(QStringLiteral("pb_DisconnectGraph"));
        pb_DisconnectGraph->setMinimumSize(QSize(40, 40));
        pb_DisconnectGraph->setMaximumSize(QSize(40, 40));
        pb_DisconnectGraph->setCursor(QCursor(Qt::PointingHandCursor));
        pb_DisconnectGraph->setStyleSheet(QStringLiteral("image: url(:/icons/breakgraph.png);"));

        horizontalLayout->addWidget(pb_DisconnectGraph);

        pb_LengthOfEdges = new QPushButton(horizontalWidget);
        pb_LengthOfEdges->setObjectName(QStringLiteral("pb_LengthOfEdges"));
        pb_LengthOfEdges->setMinimumSize(QSize(40, 40));
        pb_LengthOfEdges->setMaximumSize(QSize(40, 40));
        pb_LengthOfEdges->setCursor(QCursor(Qt::PointingHandCursor));
        pb_LengthOfEdges->setStyleSheet(QStringLiteral("image: url(:/icons/edges.png);"));

        horizontalLayout->addWidget(pb_LengthOfEdges);

        pb_CoordinatesOfAllNode = new QPushButton(horizontalWidget);
        pb_CoordinatesOfAllNode->setObjectName(QStringLiteral("pb_CoordinatesOfAllNode"));
        pb_CoordinatesOfAllNode->setEnabled(true);
        pb_CoordinatesOfAllNode->setMinimumSize(QSize(40, 40));
        pb_CoordinatesOfAllNode->setMaximumSize(QSize(40, 40));
        pb_CoordinatesOfAllNode->setCursor(QCursor(Qt::PointingHandCursor));
        pb_CoordinatesOfAllNode->setStyleSheet(QStringLiteral("image: url(:/icons/nodes.png);"));

        horizontalLayout->addWidget(pb_CoordinatesOfAllNode);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pb_DeleteSelectedNodes = new QPushButton(horizontalWidget);
        pb_DeleteSelectedNodes->setObjectName(QStringLiteral("pb_DeleteSelectedNodes"));
        pb_DeleteSelectedNodes->setMinimumSize(QSize(40, 40));
        pb_DeleteSelectedNodes->setMaximumSize(QSize(40, 40));
        pb_DeleteSelectedNodes->setCursor(QCursor(Qt::PointingHandCursor));
        pb_DeleteSelectedNodes->setStyleSheet(QStringLiteral("image: url(:/icons/delnode.png);"));

        horizontalLayout->addWidget(pb_DeleteSelectedNodes);

        pb_RemoveEdges = new QPushButton(horizontalWidget);
        pb_RemoveEdges->setObjectName(QStringLiteral("pb_RemoveEdges"));
        pb_RemoveEdges->setMinimumSize(QSize(40, 40));
        pb_RemoveEdges->setMaximumSize(QSize(40, 40));
        pb_RemoveEdges->setCursor(QCursor(Qt::PointingHandCursor));
        pb_RemoveEdges->setStyleSheet(QStringLiteral("image: url(:/icons/deledge.png);"));

        horizontalLayout->addWidget(pb_RemoveEdges);

        pb_ClearAll = new QPushButton(horizontalWidget);
        pb_ClearAll->setObjectName(QStringLiteral("pb_ClearAll"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(40);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(pb_ClearAll->sizePolicy().hasHeightForWidth());
        pb_ClearAll->setSizePolicy(sizePolicy);
        pb_ClearAll->setMinimumSize(QSize(40, 40));
        pb_ClearAll->setMaximumSize(QSize(40, 40));
        pb_ClearAll->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ClearAll->setStyleSheet(QStringLiteral("image: url(:/icons/dellall.png);"));

        horizontalLayout->addWidget(pb_ClearAll);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pb_CreateNode = new QPushButton(horizontalWidget);
        pb_CreateNode->setObjectName(QStringLiteral("pb_CreateNode"));
        pb_CreateNode->setMinimumSize(QSize(40, 40));
        pb_CreateNode->setMaximumSize(QSize(40, 40));
        pb_CreateNode->setCursor(QCursor(Qt::PointingHandCursor));
        pb_CreateNode->setStyleSheet(QStringLiteral("image: url(:/icons/addnode.png);"));

        horizontalLayout->addWidget(pb_CreateNode);

        pb_CreateEdge = new QPushButton(horizontalWidget);
        pb_CreateEdge->setObjectName(QStringLiteral("pb_CreateEdge"));
        pb_CreateEdge->setMinimumSize(QSize(40, 40));
        pb_CreateEdge->setMaximumSize(QSize(40, 40));
        pb_CreateEdge->setCursor(QCursor(Qt::PointingHandCursor));
        pb_CreateEdge->setStyleSheet(QStringLiteral("image: url(:/icons/addedge.png);"));

        horizontalLayout->addWidget(pb_CreateEdge);

        lineEdit_Source = new QLineEdit(horizontalWidget);
        lineEdit_Source->setObjectName(QStringLiteral("lineEdit_Source"));
        lineEdit_Source->setMinimumSize(QSize(40, 0));
        lineEdit_Source->setMaximumSize(QSize(50, 16777215));
        lineEdit_Source->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));

        horizontalLayout->addWidget(lineEdit_Source);

        lineEdit_Dest = new QLineEdit(horizontalWidget);
        lineEdit_Dest->setObjectName(QStringLiteral("lineEdit_Dest"));
        lineEdit_Dest->setMinimumSize(QSize(40, 0));
        lineEdit_Dest->setMaximumSize(QSize(50, 16777215));
        lineEdit_Dest->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));

        horizontalLayout->addWidget(lineEdit_Dest);

        pushAlgorithm = new QPushButton(horizontalWidget);
        pushAlgorithm->setObjectName(QStringLiteral("pushAlgorithm"));
        pushAlgorithm->setEnabled(false);
        sizePolicy.setHeightForWidth(pushAlgorithm->sizePolicy().hasHeightForWidth());
        pushAlgorithm->setSizePolicy(sizePolicy);
        pushAlgorithm->setMinimumSize(QSize(40, 40));
        pushAlgorithm->setMaximumSize(QSize(40, 40));
        pushAlgorithm->setCursor(QCursor(Qt::PointingHandCursor));
        pushAlgorithm->setStyleSheet(QStringLiteral("image: url(:/icons/algo.png);"));
        pushAlgorithm->setCheckable(false);
        pushAlgorithm->setFlat(false);

        horizontalLayout->addWidget(pushAlgorithm);

        label = new QLabel(horizontalWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(25, 25));
        label->setMaximumSize(QSize(25, 25));
        label->setStyleSheet(QStringLiteral("image: url(:/icons/speed.png);"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setMinimumSize(QSize(55, 0));
        spinBox->setMaximumSize(QSize(55, 16777215));
        spinBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));
        spinBox->setMinimum(0);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(50);
        spinBox->setValue(800);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(25, 25));
        label_2->setMaximumSize(QSize(25, 25));
        label_2->setStyleSheet(QLatin1String("font: 75 9pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        lineEdit_AlgSource = new QLineEdit(horizontalWidget);
        lineEdit_AlgSource->setObjectName(QStringLiteral("lineEdit_AlgSource"));
        lineEdit_AlgSource->setEnabled(false);
        lineEdit_AlgSource->setMinimumSize(QSize(40, 0));
        lineEdit_AlgSource->setMaximumSize(QSize(50, 16777215));
        lineEdit_AlgSource->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));

        horizontalLayout->addWidget(lineEdit_AlgSource);

        pushFind = new QPushButton(horizontalWidget);
        pushFind->setObjectName(QStringLiteral("pushFind"));
        pushFind->setEnabled(false);
        sizePolicy.setHeightForWidth(pushFind->sizePolicy().hasHeightForWidth());
        pushFind->setSizePolicy(sizePolicy);
        pushFind->setMinimumSize(QSize(40, 40));
        pushFind->setMaximumSize(QSize(40, 40));
        pushFind->setStyleSheet(QStringLiteral("border-image: url(:/icons/find.png);"));

        horizontalLayout->addWidget(pushFind);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushStop = new QPushButton(horizontalWidget);
        pushStop->setObjectName(QStringLiteral("pushStop"));
        pushStop->setEnabled(false);
        sizePolicy.setHeightForWidth(pushStop->sizePolicy().hasHeightForWidth());
        pushStop->setSizePolicy(sizePolicy);
        pushStop->setMinimumSize(QSize(40, 40));
        pushStop->setMaximumSize(QSize(40, 40));
        pushStop->setCursor(QCursor(Qt::PointingHandCursor));
        pushStop->setStyleSheet(QStringLiteral("image: url(:/icons/return.png);"));

        horizontalLayout->addWidget(pushStop);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushAlgorithm->raise();
        OpenButton->raise();
        pb_IncidenceListFile->raise();
        saveButton->raise();
        pb_Help->raise();
        pb_ConnectGraph->raise();
        pb_DisconnectGraph->raise();
        pb_LengthOfEdges->raise();
        pb_CoordinatesOfAllNode->raise();
        pb_DeleteSelectedNodes->raise();
        pb_RemoveEdges->raise();
        pb_ClearAll->raise();
        pb_CreateNode->raise();
        pb_CreateEdge->raise();
        lineEdit_Source->raise();
        lineEdit_Dest->raise();
        label->raise();
        spinBox->raise();
        label_2->raise();
        lineEdit_AlgSource->raise();
        pushFind->raise();
        pushStop->raise();

        verticalLayout_2->addWidget(horizontalWidget);

        horizontalWidget1 = new QWidget(centralWidget);
        horizontalWidget1->setObjectName(QStringLiteral("horizontalWidget1"));
        horizontalWidget1->setStyleSheet(QLatin1String("border-radius: 15px;\n"
"background-color: rgb(225, 225, 225);"));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textBrowser = new QTextBrowser(horizontalWidget1);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMaximumSize(QSize(300, 16777215));
        textBrowser->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(textBrowser);

        graphicsView = new GraphWidget(horizontalWidget1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(graphicsView);


        verticalLayout_2->addWidget(horizontalWidget1);

        verticalLayout_2->setStretch(1, 5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuItems = new QMenu(menuBar);
        menuItems->setObjectName(QStringLiteral("menuItems"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setTearOffEnabled(false);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuItems->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(action_Open_file);
        menuFile->addAction(action_Save_File);
        menuFile->addAction(actionMenuFileExit);
        menuItems->addAction(actionDeleteItem);
        menuItems->addAction(action_delEdge);
        menuItems->addAction(action_clear_all);
        menu_2->addAction(action_createNode);
        menu_2->addAction(action_createEdge);
        menu_3->addAction(action_Algoritm);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\263\321\200\320\260\321\204\320\276\320\262 (Graphical graph editor)", 0));
        actionMenuFileExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        actionDeleteItem->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", 0));
        action->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", 0));
        action_Open_file->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        action_Save_File->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        action_createNode->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214  \320\262\320\265\321\200\321\210\320\270\320\275\321\203", 0));
        action_createEdge->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\264\321\203\320\263\321\203", 0));
        action_delEdge->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\321\221\320\261\321\200\320\260", 0));
        action_clear_all->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\321\221", 0));
        action_Algoritm->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", 0));
        action_About->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
#ifndef QT_NO_TOOLTIP
        OpenButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \320\263\321\200\320\260\321\204\320\260</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        OpenButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_IncidenceListFile->setToolTip(QApplication::translate("MainWindow", "<html><head/><body style=\"background-color:white\"><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 \321\201\320\276 \321\201\320\277\320\270\321\201\320\272\320\276\320\274 \320\270\320\275\321\206\320\270\320\264\320\265\320\275\321\202\320\275\320\276\321\201\321\202\320\270</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_IncidenceListFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body style=\"background-color:white\"><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\260 \320\262 \321\204\320\260\320\271\320\273</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_Help->setToolTip(QApplication::translate("MainWindow", "<html><head/><body style=\"background-color:white\"><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_Help->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_ConnectGraph->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\224\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\264\320\276 \320\277\320\276\320\273\320\275\320\276\320\263\320\276 \320\263\321\200\320\260\321\204\320\260</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_ConnectGraph->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_DisconnectGraph->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \321\200\320\265\320\261\321\200\320\260</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_DisconnectGraph->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_LengthOfEdges->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \321\200\320\265\320\261\320\265\321\200</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_LengthOfEdges->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_CoordinatesOfAllNode->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \320\262\320\265\321\200\321\210\320\270\320\275</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_CoordinatesOfAllNode->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_DeleteSelectedNodes->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_DeleteSelectedNodes->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_RemoveEdges->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\260</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_RemoveEdges->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_ClearAll->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_ClearAll->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_CreateNode->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_CreateNode->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_CreateEdge->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276 \320\274\320\265\320\266\320\264\321\203 \320\264\320\262\321\203\320\274\321\217 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\321\213\320\274\320\270 \320\262\320\265\321\200\321\210\320\270\320\275\320\260\320\274\320\270</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pb_CreateEdge->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_Source->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\321\207\320\260\320\273\320\276 \320\264\321\203\320\263\320\270</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lineEdit_Source->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_Dest->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\272\320\276\320\275\320\265\321\206 \320\264\321\203\320\263\320\270</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushAlgorithm->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushAlgorithm->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushAlgorithm->setText(QString());
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\210\320\260\320\263\320\260, \320\274\321\201</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QString());
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QString());
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\235\320\276\320\274\320\265\321\200 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\271 \320\262\320\265\321\200\321\210\320\270\320\275\321\213</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "S:", 0));
#ifndef QT_NO_TOOLTIP
        pushFind->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\270\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\271 \320\262\320\265\321\200\321\210\320\270\320\275\321\213</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushFind->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushStop->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\263\321\200\320\260\321\204 \320\262 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushStop->setText(QString());
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\262\320\276\320\271\320\275\320\276\320\271 \320\272\320\273\320\270\320\272 \320\273\320\265\320\262\320\276\320\271 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \320\274\321\213\321\210\320\270 - \320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\262\320\265\321\200\321\210\320\270\320\275\321\203.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p s"
                        "tyle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\262\320\276\320\271\320\275\320\276\320\271 \320\272\320\273\320\270\320\272 \320\277\321\200\320\260\320\262\320\276\320\271 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \320\274\321\213\321\210\320\270 \320\270 \320\272\320\273\320\260\320\262\320\270\321\211\320\260 Shift - \321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213 \321\201 \321\202\320\276\320\271, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \320\272\320\273\320\270\320\272\320\260\320\273\320\270.</p></body></html>", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273\321\213", 0));
        menuItems->setTitle(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        menu->setTitle(QString());
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
