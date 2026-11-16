
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QFont>
#include <QPainter>
#include "ventanajuego.h"

#include "crash.h"
#include "plataforma.h"

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);

    Crash crash;
    Plataforma plataforma1(0, -3, 10, 1);


    QGraphicsScene escena;
    escena.setSceneRect(0, 0, 640, 360);
    escena.setBackgroundBrush(QColor("#DDF3FF"));

    const double escala = 20.0;
    const double sueloY = 300.0;

    escena.addRect(0, sueloY, 640, 25,QPen(Qt::NoPen), QBrush(QColor("#64748B")));


    escena.addRect(plataforma1.getX() * escala,sueloY + plataforma1.getY() * escala, plataforma1.getAncho() * escala,plataforma1.getAlto() * escala,QPen(Qt::NoPen),
    QBrush(QColor("#16A085")));


    QGraphicsRectItem *crashGrafico = escena.addRect(0, 0, 24, 32,QPen(Qt::NoPen),QBrush(QColor("#F28C28")));


    crashGrafico->setPos(crash.getX() * escala,sueloY + crash.getY() * escala - 32);


    QGraphicsTextItem *titulo =escena.addText("Crash - PTAR San Fernando");

    titulo->setDefaultTextColor(QColor("#233754"));
    titulo->setFont(QFont("Arial", 15, QFont::Bold));
    titulo->setPos(20, 10);


    VentanaJuego vista(&escena, &crash);
    vista.setWindowTitle("Crash Bandicoot - Nivel 1");
    vista.setRenderHint(QPainter::Antialiasing);
    vista.setFixedSize(660, 380);
    vista.show();
    vista.setFocus();


    QTimer temporizador;
    temporizador.setInterval(50);

    QObject::connect(&temporizador, &QTimer::timeout, [&]()
    {

    crash.limitarMovimiento(0, (640.0 - 24.0) / escala);


    crash.verificarApoyo(plataforma1);


    crash.actualizarFisica(0.05, plataforma1);


    crashGrafico->setPos(crash.getX() * escala,sueloY + crash.getY() * escala - 32);});


    temporizador.start();


    return aplicacion.exec();
}
