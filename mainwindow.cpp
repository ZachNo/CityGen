#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "noise.h"
//#include "OpenSimplex.h"
//#include "cellnoise.h"
#include "FastNoise.h"

#include <iostream>
#include <algorithm>

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
    //OpenSimplex os(seed);
    //CellNoise cn(seed);
    //FastNoiseSIMD *noise = FastNoiseSIMD::NewFastNoiseSIMD(seed);
    FastNoise noise1(seed);
    FastNoise noise2(seed);
    FastNoise noise3(seed);

    noise1.SetNoiseType(FastNoise::CubicFractal);
    noise1.SetFractalGain(1.0);
    noise1.SetFractalLacunarity(1.0);
    noise1.SetFrequency(pow(cos(scale/10000.),8));
    noise1.SetFractalOctaves(1.0);
    noise1.SetFractalType(FastNoise::Billow);

    noise2.SetNoiseType(FastNoise::Simplex);
    noise2.SetFrequency(pow(cos(scale/10000.),8)/10);
    //noise2

    noise3.SetNoiseType(FastNoise::SimplexFractal);
    noise3.SetFrequency(pow(cos(scale/10000.),8)/10);

    for(int i = 0; i < ui->viewport->width(); ++i)
    {
        for(int j = 0; j < ui->viewport->height(); ++j)
        {
            //double n1 = octave(i/scale + x, j/scale + y, 64, &os);
            //double n2 = 1.0 - octave(i/scale + x, j/scale + y, 64, &cn);
            //double n = n1*0.7 + n2*0.3;
            FN_DECIMAL n1 = (noise1.GetCubicFractal(i+x, j+y) + 1.)/2;
            FN_DECIMAL n2 = (noise2.GetSimplex(i+x, j+y) + 1.)/2.;
            FN_DECIMAL n3 = (noise3.GetSimplexFractal(i+x, j+y) + 1.)/2.;

            QRgb color = qRgb(n1 < 0.05 || n3 < 0.4 ? 0.4*255 : n3*255, /*n2*255*/0, 0);// n1 < 0.05 || n3 < 0.4 ? 255 : 0);
            display->setPixel(i ,j, color);
        }
    }

    ui->viewport->setPixmap(QPixmap::fromImage(*display));

    //FeatureGenerator gen(seed, x, y);
    //showGenerated(gen);
}

void MainWindow::changeZoom()
{
    ui->zoomLevel->setText(QString::number(pow(cos((double)ui->sizeSlider->value()/10000.),8)));
    generate();
}

void MainWindow::moveDown()
{
    y += MOVESPEED / pow(cos((double)ui->sizeSlider->value()/10000.),8);
    generate();
}

void MainWindow::moveUp()
{
    y -= MOVESPEED / pow(cos((double)ui->sizeSlider->value()/10000.),8);
    generate();
}

void MainWindow::moveLeft()
{
    x -= MOVESPEED / pow(cos((double)ui->sizeSlider->value()/10000.),8);
    generate();
}

void MainWindow::moveRight()
{
    x += MOVESPEED / pow(cos((double)ui->sizeSlider->value()/10000.),8);
    generate();
}
