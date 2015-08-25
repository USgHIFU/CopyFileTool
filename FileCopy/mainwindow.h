#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QPushButton;
class QLabel;

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void copyFile();

private:
    QPushButton* m_update;
    QLabel* m_status;

    QString m_dstFileDir;
    QString m_srcFileDir;
    QString m_fileName;
};

#endif // MAINWINDOW_H
