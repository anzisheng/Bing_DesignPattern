#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QPushButton>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private    slots :
    void OnIncrementClicked();
private:
    QLabel* m_CountLabel;
    QPushButton *m_incrementBtn;
    
    int m_count;



};
#endif // MAINWINDOW_H
