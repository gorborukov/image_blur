#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawImage(QString imagePath) {
    imageObject = new QImage();
    imageObject->load(imagePath);
    image = QPixmap::fromImage(*imageObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void MainWindow::on_openButton_pressed()
{
    QString imagePath = QFileDialog::getOpenFileName (
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.jpg *jpeg)")
                );
    DrawImage(imagePath);
}

void MainWindow::BlurImage() {
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect(scene);
    blur->setBlurRadius(20.0);
    ui->graphicsView->setGraphicsEffect(blur);
}

void MainWindow::on_blurButton_pressed()
{
    BlurImage();
}
