#include "systemtray.h"

#include <QApplication>
#include <QDebug>


void SystemTray::setup()
{
    qDebug() << __PRETTY_FUNCTION__;

    m_systemTrayIcon = new QSystemTrayIcon(0);

    m_minimizeAction = new QAction(tr("Mi&nimize"), m_systemTrayIcon);
    connect(m_minimizeAction, SIGNAL(triggered()), m_mainWindow, SLOT(hide()));

    m_maximizeAction = new QAction(tr("Ma&ximize"), m_systemTrayIcon);
    connect(m_maximizeAction, SIGNAL(triggered()), m_mainWindow, SLOT(showMaximized()));

    m_restoreAction = new QAction(tr("&Restore"), m_systemTrayIcon);
    connect(m_restoreAction, SIGNAL(triggered()), m_mainWindow, SLOT(showNormal()));

    m_quitAction = new QAction(tr("&Quit"), m_systemTrayIcon);
    connect(m_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    m_trayIconMenu = new QMenu(this);
    m_trayIconMenu->addAction(m_minimizeAction);
    m_trayIconMenu->addAction(m_maximizeAction);
    m_trayIconMenu->addAction(m_restoreAction);
    m_trayIconMenu->addSeparator();
    m_trayIconMenu->addAction(m_quitAction);

    m_systemTrayIcon->setContextMenu(m_trayIconMenu);

    m_icon = new QIcon(":/heart.svg");
    m_systemTrayIcon->setIcon(QIcon(":/heart.svg"));


}

SystemTray::SystemTray(MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    m_mainWindow(mainWindow)
{
    qDebug() << __PRETTY_FUNCTION__;
}


void SystemTray::show()
{
    m_systemTrayIcon->show();
}