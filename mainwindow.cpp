#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    origin = imageObject;
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

void MainWindow::CVFilter(){


}

QImage MainWindow::MaskedBlurFilter(QImage *origin){
    QImage *newImage = new QImage(*origin);

    int kernel [5][5]= {{0,0,1,0,0},
                        {0,1,3,1,0},
                        {1,3,7,3,1},
                        {0,1,3,1,0},
                        {0,0,1,0,0}};
    int kernelSize = 5;
    int sumKernel = 27;
    int r,g,b;
    QColor color;

    for(int x=kernelSize/2; x<newImage->width()-(kernelSize/2); x++){
        for(int y=kernelSize/2; y<newImage->height()-(kernelSize/2); y++){

            r = 0;
            g = 0;
            b = 0;

            for(int i = -kernelSize/2; i<= kernelSize/2; i++){
                for(int j = -kernelSize/2; j<= kernelSize/2; j++){
                    color = QColor(origin->pixel(x+i, y+j));
                    r += color.red()*kernel[kernelSize/2+i][kernelSize/2+j];
                    g += color.green()*kernel[kernelSize/2+i][kernelSize/2+j];
                    b += color.blue()*kernel[kernelSize/2+i][kernelSize/2+j];
                }
            }

            r = qBound(0, r/sumKernel, 255);
            g = qBound(0, g/sumKernel, 255);
            b = qBound(0, b/sumKernel, 255);
            newImage->setPixel(x,y, qRgb(r,g,b));
            destinationImage = newImage;
        }
    }
    SetMask();
}

void MainWindow::SetMask() {
    QImage *mask = new QImage(":mask.png");
    QPainter painter;

    painter.begin(mask);
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter.drawImage(0, 0, *destinationImage);
    painter.end();

    painter.begin(origin);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, *mask);
    painter.end();

    maskedImage = origin;
}

void MainWindow::SetResultImage(QImage *maskedImage) {
    image = QPixmap::fromImage(*maskedImage);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void MainWindow::on_blurButton_pressed()
{
    MaskedBlurFilter(origin);
    SetResultImage(maskedImage);
}
