#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DrawImage(QString imagePath);

private slots:
    void on_openButton_pressed();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage *imageObject;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
