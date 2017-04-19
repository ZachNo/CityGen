#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage *display;
    double x, y;

private slots:
    void generate();
    void changeZoom();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // MAINWINDOW_H
