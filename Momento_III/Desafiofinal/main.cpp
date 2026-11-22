#include <vector>
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
#include "nivelrio.h"
#include <QGraphicsEllipseItem>
#include <iostream>
#include <QDebug>
#include "ventanaaguasclaras.h"

#include "crash.h"
#include "plataforma.h"


int probarAguasClaras()
{
    int argc = 1;
    char nombrePrograma[] = "Desafiofinal";
    char* argv[] = {nombrePrograma, nullptr};

    QApplication aplicacion(argc, argv);

    VentanaAguasClaras ventana;
    ventana.show();

    return aplicacion.exec();
}

int main(int argc, char *argv[])
{
    return probarAguasClaras();
    QApplication aplicacion(argc, argv);

    NivelRio nivel1;
    nivel1.iniciar();

    Crash& crash = nivel1.getCrash();
    std::vector<Plataforma> plataformas = {
        Plataforma(0, 0, 7, 1),
        Plataforma(12, 0, 8, 1),
        Plataforma(4, -3, 7, 1),
        Plataforma(13, -6, 7, 1),
        Plataforma(5, -9, 7, 1)
    };

    QGraphicsScene escena;
    escena.setSceneRect(0, 0, 640, 360);
    escena.setBackgroundBrush(QColor("#DDF3FF"));

    const double escala = 20.0;
    const double sueloY = 300.0;

    for (const Plataforma& plataforma : plataformas)
    {
        escena.addRect(
            plataforma.getX() * escala,
            sueloY + plataforma.getY() * escala,
            plataforma.getAncho() * escala,
            plataforma.getAlto() * escala,
            QPen(Qt::NoPen),
            QBrush(QColor("#16A085"))
            );
    }


    for (const Plataforma& plataforma : plataformas)
    {
        escena.addRect(
            plataforma.getX() * escala,
            sueloY + plataforma.getY() * escala,
            plataforma.getAncho() * escala,
            plataforma.getAlto() * escala,
            QPen(Qt::NoPen),
            QBrush(QColor("#16A085"))
            );
    }

    QGraphicsRectItem *crashGrafico = escena.addRect(0, 0, 24, 32,QPen(Qt::NoPen),QBrush(QColor("#F28C28")));


    crashGrafico->setPos(crash.getX() * escala,sueloY + crash.getY() * escala - 32);


    QGraphicsTextItem *titulo =escena.addText("Crash - PTAR San Fernando");

    titulo->setDefaultTextColor(QColor("#233754"));
    titulo->setFont(QFont("Arial", 15, QFont::Bold));
    titulo->setPos(20, 10);

    QGraphicsTextItem *vidasTexto =escena.addText("VIDAS: 3");

    vidasTexto->setDefaultTextColor(QColor("#D62828"));
    vidasTexto->setFont(QFont("Arial", 14, QFont::Bold));
    vidasTexto->setPos(490, 10);

    QGraphicsTextItem *piezasTexto = escena.addText("PIEZAS: 0/3");

    piezasTexto->setDefaultTextColor(QColor("#B8860B"));
    piezasTexto->setFont(QFont("Arial", 13, QFont::Bold));
    piezasTexto->setPos(330, 10);

    QGraphicsTextItem *victoriaTexto =
        escena.addText("NIVEL 1 COMPLETADO");

    victoriaTexto->setDefaultTextColor(QColor("#008000"));
    victoriaTexto->setFont(QFont("Arial", 24, QFont::Bold));
    victoriaTexto->setPos(145, 140);


    victoriaTexto->setVisible(false);


    victoriaTexto->setZValue(100);

    QGraphicsRectItem *maquinaGrafica = escena.addRect( 0, 0, 40, 50,QPen(Qt::NoPen), QBrush(QColor("#475569")));

    VentanaJuego vista(&escena, &crash, &nivel1,crashGrafico,maquinaGrafica,victoriaTexto);
    vista.setWindowTitle("Crash Bandicoot - Nivel 1");
    vista.setRenderHint(QPainter::Antialiasing);
    vista.setFixedSize(660, 380);
    vista.show();
    vista.setFocus();
    QGraphicsRectItem *barreraGrafica = escena.addRect(0, 0, 30, 50,QPen(Qt::NoPen),QBrush(QColor("#D62828")));

    QGraphicsRectItem *barreraSuperiorGrafica =escena.addRect(0, 0, 30, 50,QPen(Qt::NoPen),QBrush(QColor("#B91C1C")));

    QGraphicsEllipseItem *residuoGrafico = escena.addEllipse(0, 0, 18, 18,QPen(Qt::NoPen),QBrush(QColor("#8B5E3C")) );

    QGraphicsEllipseItem *piezaGrafica1 = escena.addEllipse( 0, 0, 16, 16,QPen(Qt::NoPen), QBrush(QColor("#FFD700")));

    QGraphicsEllipseItem *piezaGrafica2 = escena.addEllipse(0, 0, 16, 16,QPen(Qt::NoPen), QBrush(QColor("#FFD700")));

    QGraphicsEllipseItem *piezaGrafica3 = escena.addEllipse(0, 0, 16, 16,QPen(Qt::NoPen), QBrush(QColor("#FFD700")));

    // Las mismas posiciones definidas en NivelRio
    piezaGrafica1->setPos(2 * escala,sueloY - 16);

    piezaGrafica2->setPos(6 * escala,sueloY - 3 * escala - 16);

    piezaGrafica3->setPos(8 * escala,sueloY - 9 * escala - 16);

    QTimer temporizador;
    temporizador.setInterval(50);

    QObject::connect(&temporizador, &QTimer::timeout,[&]()
    {
    if (nivel1.estaCompletado() || !crash.estaVivo())
    {
        temporizador.stop();
        return;
    }

    crash.limitarMovimiento(0, (640.0 - 24.0) / escala);
    crash.actualizarFisicaNivel(0.05, plataformas);

    if (crash.getY() > 6 && crash.estaVivo())
    {
        std::cout << "Crash cayo al vacio" << std::endl;

        nivel1.recibirGolpe(false);

        std::cout << "Vidas restantes: "
                  << crash.getVidas() << std::endl;
    }

    if (crash.getY() > 6 && crash.estaVivo())
    {
        nivel1.recibirGolpe(false);
    }


    nivel1.actualizarPeligros(0.05);


    crashGrafico->setPos(crash.getX() * escala,sueloY + crash.getY() * escala - 32);

    barreraGrafica->setPos(nivel1.getBarreraX() * escala,sueloY + nivel1.getBarreraY() * escala - 50);

    barreraSuperiorGrafica->setPos(nivel1.getBarreraSuperiorX() * escala,sueloY + nivel1.getBarreraSuperiorY() * escala - 50);

    residuoGrafico->setPos(nivel1.getResiduoX() * escala,sueloY + nivel1.getResiduoY() * escala - 18);

    bool golpeResiduo =residuoGrafico->collidesWithItem(crashGrafico);

    bool golpeBarrera =barreraGrafica->collidesWithItem(crashGrafico);

    bool golpeBarreraSuperior =barreraSuperiorGrafica->collidesWithItem(crashGrafico);

    piezaGrafica1->setVisible(!nivel1.pieza1Recogida());
    piezaGrafica2->setVisible(!nivel1.pieza2Recogida());
    piezaGrafica3->setVisible(!nivel1.pieza3Recogida());



    maquinaGrafica->setPos(nivel1.getMaquinaX() * escala,sueloY + nivel1.getMaquinaY() * escala - 50);

    QGraphicsTextItem *maquinaTexto =escena.addText("MAQUINA");

    maquinaTexto->setDefaultTextColor(QColor("#233754"));
    maquinaTexto->setFont(QFont("Arial", 10, QFont::Bold));

    maquinaTexto->setPos(nivel1.getMaquinaX() * escala - 8, sueloY + nivel1.getMaquinaY() * escala - 75);

    piezasTexto->setPlainText(QString("PIEZAS: %1/3")
    .arg(nivel1.getPiezasRecolectadas()) );


    if (golpeResiduo || golpeBarrera || golpeBarreraSuperior)
    {
    nivel1.recibirGolpe(golpeResiduo);

    crashGrafico->setPos(crash.getX() * escala,sueloY + crash.getY() * escala - 32 );

    residuoGrafico->setPos(nivel1.getResiduoX() * escala,sueloY + nivel1.getResiduoY() * escala - 18);
    }

    vidasTexto->setPlainText(QString("VIDAS: %1").arg(crash.getVidas()));

    if (!crash.estaVivo())
    {
    temporizador.stop();

    QGraphicsTextItem *mensaje = escena.addText("GAME OVER");

    mensaje->setDefaultTextColor(QColor("#D62828"));
    mensaje->setFont(QFont("Arial", 28, QFont::Bold));
    mensaje->setPos(205, 140);}
    });

    if (nivel1.estaCompletado())
    {
        victoriaTexto->setVisible(true);
        temporizador.stop();
    }

    temporizador.start();


    return aplicacion.exec();
}
