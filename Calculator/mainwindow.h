#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_action_triggered();

    void on_button_sign_1_clicked();

    void on_button_sign_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
