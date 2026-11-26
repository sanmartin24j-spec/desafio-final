#include "ventanaaguasclaras.h"

#include <QBrush>
#include <QColor>
#include <QPen>
#include <QString>
#include <QFont>
#include <cmath>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>



VentanaAguasClaras::VentanaAguasClaras()

    : QGraphicsView(),

    escena(0, 0, 640, 400),
    crashGrafico(nullptr),
    tiempoTexto(nullptr),
    agente(3, 12),
    agenteGrafico(nullptr),
    agenteTexto(nullptr),
    indiceObjetivo(-1)



{
    setScene(&escena);
    setWindowTitle("Nivel 2 - PTAR Aguas Claras");
    setFixedSize(660, 430);
    setFocusPolicy(Qt::StrongFocus);

    nivel.iniciar();


    escena.setBackgroundBrush(QColor("#D6F0F5"));
    QPixmap fondo(":/imagenes/Recursos/fondo_aguasclaras.png");

    if (fondo.isNull())
    {
        qDebug() << "ERROR: No se pudo cargar el fondo de Aguas Claras";
    }
    else
    {
        QGraphicsPixmapItem* fondoGrafico = escena.addPixmap(
            fondo.scaled(
                640, 400,
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation
                )
            );

        fondoGrafico->setPos(0, 0);
        fondoGrafico->setZValue(-100);
    }


    crashGrafico = escena.addRect(0, 0, 24, 32,QPen(Qt::NoPen),QBrush(QColor("#F97316")));
    // El rectan invisible
    crashGrafico->setBrush(QBrush(Qt::NoBrush));
    crashGrafico->setPen(QPen(Qt::NoPen));

    // Zorro
    QPixmap imagenCrash(":/imagenes/Recursos/Crashstatico.png");

    spriteCrash = nullptr;

    if (!imagenCrash.isNull())
    {
        spriteCrash = escena.addPixmap(imagenCrash.scaled(36, 44,Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation));

        spriteCrash->setZValue(10);
    }
    else
    {
        //rectan
        crashGrafico->setBrush(QBrush(QColor("#F97316")));
    }

    if (spriteCrash != nullptr)
    {
        spriteCrash->setPos(
            crash.getX() * 20 - 6,
            crash.getY() * 20 - 6
            );
    }



    compuertaGrafica1 = escena.addRect(0, 0, 34, 34,QPen(Qt::NoPen),QBrush(QColor("#DC2626")));

    compuertaGrafica2 = escena.addRect(0, 0, 34, 34,QPen(Qt::NoPen),QBrush(QColor("#DC2626")));

    compuertaGrafica3 = escena.addRect(0, 0, 34, 34,QPen(Qt::NoPen),QBrush(QColor("#DC2626")));


    agenteGrafico = escena.addEllipse(0, 0, 24, 24,QPen(Qt::NoPen),QBrush(QColor("#2563EB")));

    agenteGrafico->setPos(agente.getX() * 20,agente.getY() * 20);



    agenteGrafico->setBrush(QBrush(Qt::NoBrush));
    agenteGrafico->setPen(QPen(Qt::NoPen));

    QPixmap imagenRobot(":/imagenes/Recursos/robot.png");

    spriteRobot = nullptr;

    if (!imagenRobot.isNull())
    {
        spriteRobot = escena.addPixmap(
            imagenRobot.scaled(
                32, 32,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
                )
            );

        spriteRobot->setZValue(10);
    }
    else
    {
        agenteGrafico->setBrush(QBrush(QColor("#2563EB")));
    }
    if (spriteRobot != nullptr)
    {
        spriteRobot->setPos(
            agente.getX() * 20 - 4,
            agente.getY() * 20 - 4
            );
    }

    residuos.push_back({20, 12, true, nullptr});
    residuos.push_back({8, 5, true, nullptr});
    residuos.push_back({26, 16, true, nullptr});

    for (ResiduoNivel& residuo : residuos)
    {
        residuo.grafico = escena.addEllipse(
            0, 0, 18, 18,
            QPen(Qt::NoPen),
            QBrush(QColor("#92400E"))
            );

        residuo.grafico->setPos(
            residuo.x * 20,
            residuo.y * 20
            );
    }

    agenteTexto = escena.addText("RESIDUOS: 0");

    agenteTexto->setDefaultTextColor(QColor("#1D4ED8"));
    agenteTexto->setPos(250, 10);
    agenteTexto->setZValue(10);

    compuertaGrafica1->setPos(
        nivel.getCompuerta1().getX() * 20,
        nivel.getCompuerta1().getY() * 20
        );

    compuertaGrafica2->setPos(
        nivel.getCompuerta2().getX() * 20,
        nivel.getCompuerta2().getY() * 20
        );

    compuertaGrafica3->setPos(
        nivel.getCompuerta3().getX() * 20,
        nivel.getCompuerta3().getY() * 20
        );


    compuertasTexto = escena.addText("COMPUERTAS: 0/3");
    compuertasTexto->setDefaultTextColor(QColor("#123456"));
    compuertasTexto->setPos(430, 10);
    compuertasTexto->setZValue(10);


    resultadoTexto = escena.addText("NIVEL 2 COMPLETADO");
    resultadoTexto->setDefaultTextColor(QColor("#15803D"));
    resultadoTexto->setFont(QFont("Arial", 22, QFont::Bold));
    resultadoTexto->setPos(155, 180);
    resultadoTexto->setZValue(100);
    resultadoTexto->setVisible(false);


    tiempoTexto = escena.addText("TIEMPO: 120");

    tiempoTexto->setDefaultTextColor(QColor("#123456"));
    tiempoTexto->setPos(10, 10);
    tiempoTexto->setZValue(10);

    // Actualización del nivel
    temporizador.setInterval(50);

    connect(&temporizador, &QTimer::timeout,
            this, [this]()
            {
                actualizarJuego();
            });

    temporizador.start();
}

void VentanaAguasClaras::actualizarCompuertas()
{
    if (nivel.getCompuerta1().estaAbierta())
    {
        compuertaGrafica1->setBrush(QColor("#16A34A"));
    }

    if (nivel.getCompuerta2().estaAbierta())
    {
        compuertaGrafica2->setBrush(QColor("#16A34A"));
    }

    if (nivel.getCompuerta3().estaAbierta())
    {
        compuertaGrafica3->setBrush(QColor("#16A34A"));
    }

    compuertasTexto->setPlainText(
        "COMPUERTAS: " +
        QString::number(nivel.getCompuertasAbiertas()) +
        "/3"
        );
}

void VentanaAguasClaras::keyPressEvent(QKeyEvent* evento)
{
    if (nivel.getTiempoRestante() <= 0 ||
        nivel.estaCompletado())
    {
        return;
    }

    if (evento->key() == Qt::Key_W)
    {
        crash.moverArriba(1);
    }
    else if (evento->key() == Qt::Key_S)
    {
        crash.moverAbajo(1);
    }
    else if (evento->key() == Qt::Key_A)
    {
        crash.movimientoizquierda(1);
    }
    else if (evento->key() == Qt::Key_D)
    {
        crash.movimientoderecha(1);
    }

    else if (evento->key() == Qt::Key_C)
    {
        bool abierta = nivel.intentarAbrirCompuerta(
            crash.getX(),
            crash.getY()
            );

        if (abierta)
        {
            actualizarCompuertas();
        }

        if (nivel.estaCompletado())
        {
            resultadoTexto->setVisible(true);
            temporizador.stop();
        }
    }

    crash.limitarMovimientoCenital(
        0, 30.8,
        0, 18.4
        );

    crashGrafico->setPos(
        crash.getX() * 20,
        crash.getY() * 20
        );

    if (spriteCrash != nullptr)
    {
        spriteCrash->setPos(
            crash.getX() * 20 - 6,
            crash.getY() * 20 - 6
            );
    }
}

void VentanaAguasClaras::actualizarJuego()
{
    if (indiceObjetivo == -1)
    {
        indiceObjetivo = buscarResiduoMasCercano();

        if (indiceObjetivo != -1)
        {
            agente.percibir(
                residuos[indiceObjetivo].x,
                residuos[indiceObjetivo].y
                );

            agente.razonar();
        }
    }

    if (indiceObjetivo == -1)
    {
        agente.patrullar(0.05);

        agenteGrafico->setPos(agente.getX() * 20,agente.getY() * 20
            );
    }
    if (spriteRobot != nullptr)
    {
        spriteRobot->setPos(
            agente.getX() * 20 - 4,
            agente.getY() * 20 - 4
            );
    }

    if (indiceObjetivo != -1)
    {
        int recogidosAntes = agente.getResiduosRecolectados();
        agente.actuar(0.05);

        agenteGrafico->setPos(agente.getX() * 20,agente.getY() * 20);

        if (spriteRobot != nullptr)
        {
            spriteRobot->setPos(
                agente.getX() * 20 - 4,
                agente.getY() * 20 - 4
                );
        }

        // Comprobar si el agente alcanzó el residuo
        double dx = residuos[indiceObjetivo].x - agente.getX();
        double dy = residuos[indiceObjetivo].y - agente.getY();

        double distancia = std::sqrt(dx * dx + dy * dy);

        if (agente.getResiduosRecolectados() > recogidosAntes)
        {
            residuos[indiceObjetivo].disponible = false;
            residuos[indiceObjetivo].grafico->setVisible(false);

            indiceObjetivo = -1;

            agenteTexto->setPlainText("RESIDUOS: " +QString::number(agente.getResiduosRecolectados()) +"/3");
        }
    }


    nivel.actualizar(0.05);

    tiempoTexto->setPlainText("TIEMPO: " + QString::number(nivel.getTiempoRestante(), 'f', 1));

    if (nivel.getTiempoRestante() <= 0)
    {
        temporizador.stop();

        resultadoTexto->setPlainText("TIEMPO AGOTADO");
        resultadoTexto->setDefaultTextColor(QColor("#B91C1C"));
        resultadoTexto->setVisible(true);
    }
}

int VentanaAguasClaras::buscarResiduoMasCercano() const
{
    int mejorIndice = -1;
    double menorDistancia = -1;

    for (int i = 0; i < static_cast<int>(residuos.size()); i++)
    {
        if (!residuos[i].disponible)
        {
            continue;
        }

        double dx = residuos[i].x - agente.getX();
        double dy = residuos[i].y - agente.getY();

        double distancia = std::sqrt(dx * dx + dy * dy);

        if (mejorIndice == -1 || distancia < menorDistancia)
        {
            menorDistancia = distancia;
            mejorIndice = i;
        }
    }

    return mejorIndice;
}