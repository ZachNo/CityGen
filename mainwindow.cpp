#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OpenSimplex.h"

static const int MOVESPEED = 50;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Setup basic GUI
    ui->setupUi(this);

    //Connect to functions
    connect(ui->generateRoads, SIGNAL(triggered()), this, SLOT(generate()));
    connect(ui->sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(changeZoom()));
    connect(ui->moveDown, SIGNAL(clicked(bool)), this, SLOT(moveDown()));
    connect(ui->moveUp, SIGNAL(clicked(bool)), this, SLOT(moveUp()));
    connect(ui->moveLeft, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
    connect(ui->moveRight, SIGNAL(clicked(bool)), this, SLOT(moveRight()));

    //Initialize variables
    display = new QImage(ui->viewport->width(),
                         ui->viewport->height(),
                         QImage::Format_RGB32);
    x = 0.0;
    y = 0.0;
    generate();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete display;
}

//Handles generation of features
void MainWindow::generate()
{
    int seed = ui->customSeed->text().toInt();
    double scale = ui->sizeSlider->value();
    OpenSimplex o(seed);
    double min = -1910., max = 1910.;
    for(int i = 0; i < ui->viewport->width(); ++i)
    {
        for(int j = 0; j < ui->viewport->height(); ++j)
        {
            double c = (o.noise(i/scale + x, j/scale + y)-min)/(max-min)*255.;
            display->setPixel(i,j,qRgb(c, c, c));
        }
    }
    ui->viewport->setPixmap(QPixmap::fromImage(*display));
    //FeatureGenerator gen(seed, x, y);
    //showGenerated(gen);
}

void MainWindow::changeZoom()
{
    ui->zoomLevel->setText(QString::number(1/static_cast<float>(ui->sizeSlider->value())));
    generate();
}

void MainWindow::moveDown()
{
    y += MOVESPEED / ui->sizeSlider->value();
    generate();
}

void MainWindow::moveUp()
{
    y -= MOVESPEED / ui->sizeSlider->value();
    generate();
}

void MainWindow::moveLeft()
{
    x -= MOVESPEED / ui->sizeSlider->value();
    generate();
}

void MainWindow::moveRight()
{
    x += MOVESPEED / ui->sizeSlider->value();
    generate();
}
