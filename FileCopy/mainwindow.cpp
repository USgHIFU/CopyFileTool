#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_update = new QPushButton("update",this);
    m_status = new QLabel(this);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_update);
    layout->addWidget(m_status);
    QWidget* widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    m_dstFileDir = "../dst/";
    m_srcFileDir = "../src/";
    m_fileName = "test.txt";

    connect(m_update,SIGNAL(clicked(bool)),this,SLOT(copyFile()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::copyFile()
{
    QFile srcFile(m_srcFileDir+m_fileName);
    QFile dstFile(m_dstFileDir+m_fileName);

    if (srcFile.exists() && dstFile.exists())
    {
        dstFile.remove();
        srcFile.copy(m_srcFileDir+m_fileName,m_dstFileDir+m_fileName);
        m_status->setText("Copied file successfully.");
    }else
    {
        //  TODO
        m_status->setText("Failed to copy file.");
    }
}
