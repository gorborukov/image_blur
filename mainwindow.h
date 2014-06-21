#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QGraphicsEffect>

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
    void BlurImage();
    void CVFilter();
    void MaskedBlurFilter(QImage *origin);
    void SetResultImage(QImage *destinationImage);


private slots:
    void on_openButton_pressed();
    void on_blurButton_pressed();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage *imageObject;
    QImage *origin;
    QImage *destinationImage;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
