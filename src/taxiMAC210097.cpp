//=============================================================
// Nombre      : progMAC210097tp1
// Universidad : FRC-UTN
// Materia     : Programación
// Docente     : José Luis Martinez
// Autor       : Miguel A. Calveiro
// Version     : 1.0
// Description : Trabajo Práctico Nro 1
//=============================================================

//*************************************************************
// MAIN - FUNCIÓN PRINCIPAL
//*************************************************************


#include "taxiclass_taxiMAC210097.h"
#include <iostream>

int main() {
    // Crear un objeto Taxiclass de ejemplo 1
    DatosTaxi datos1;
    datos1.numeroInterno = 379;
    datos1.marcaAuto = "Fiat";
    datos1.patente = "AA 223 AZ";
    datos1.propietario = "Lina Morales";
    datos1.chofer = "Carina Sandres";
    datos1.telContacto = "555-9623";
    datos1.fechaAltaServicio = "2019-07-03";
    datos1.fechaBajaServicio = "2022-05-01";

    Taxiclass taxi1(datos1);

    // Actualizar datos de latitud y longitud del taxi 1
    taxi1.calcularLatitudLongitud(1645, -34.567, -58.789, Alarma1 | Alarma3 | Alarma5);

    // Calcular distancia entre dos puntos para el taxi 1
    taxi1.calcularDistancia(-34.123, -58.456);

    // Imprimir todos los detalles del taxi 1
    cout << "Detalles del Taxi 1:" << endl;
    taxi1.imprimirTaxi();
    cout << "Distancia Recorrida: " << taxi1.obtenerDistanciaRecorrida() << " metros" << endl;

    // Imprimir eventos de alarmas activas del taxi 1
    cout << "\nEventos de Alarmas Activas:" << endl;
    taxi1.imprimirAlarmasActivas();

    // Crear otro objeto Taxiclass con datos adicionales - taxi 2
    DatosTaxi datos2;
    datos2.numeroInterno = 456;
    datos2.marcaAuto = "Ford";
    datos2.patente = "AC 335 AG";
    datos2.propietario = "Maria Lopez";
    datos2.chofer = "Luis Rodriguez";
    datos2.telContacto = "555-5678";
    datos2.fechaAltaServicio = "2020-02-01";
    datos2.fechaBajaServicio = "2023-02-01";

    Taxiclass taxi2(datos2);

    // Actualizar datos de latitud y longitud del taxi 2
    taxi2.calcularLatitudLongitud(1232, -34.678, -58.901, Alarma4 | Alarma5 | Alarma6);

    // Calcular distancia entre dos puntos para el taxi 2
    taxi2.calcularDistancia(-22.223, -43.246);

    // Imprimir todos los detalles del taxi 2
    cout << "\nDetalles del Taxi 2:" << endl;
    taxi2.imprimirTaxi();
    cout << "Distancia Recorrida: " << taxi2.obtenerDistanciaRecorrida() << " metros" << endl;

    // Imprimir eventos de alarmas activas del taxi 2
    cout << "\nEventos de Alarmas Activas:" << endl;
    taxi2.imprimirAlarmasActivas();

    // Crear otro objeto Taxiclass con más datos adicionales - taxi 3
    DatosTaxi datos3;
    datos3.numeroInterno = 789;
    datos3.marcaAuto = "Chevrolet";
    datos3.patente = "AF 237 AB";
    datos3.propietario = "Laura Martinez";
    datos3.chofer = "Carlos Sanchez";
    datos3.telContacto = "555-9876";
    datos3.fechaAltaServicio = "2021-03-01";
    datos3.fechaBajaServicio = "2023-03-01";

    Taxiclass taxi3(datos3);

    // Actualizar datos de latitud y longitud del taxi 3
    taxi3.calcularLatitudLongitud(827, -34.789, -58.123, Alarma2 | Alarma5 | Alarma6);

    // Calcular distancia entre dos puntos para el taxi 3
    taxi3.calcularDistancia(-74.121, -88.354);

    // Imprimir todos los detalles del taxi 3
    cout << "\nDetalles del Taxi 3:" << endl;
    taxi3.imprimirTaxi();
    cout << "Distancia Recorrida: " << taxi3.obtenerDistanciaRecorrida() << " metros" << endl;

    // Imprimir eventos de alarmas activas del taxi 3
    cout << "\nEventos de Alarmas Activas:" << endl;
    taxi3.imprimirAlarmasActivas();

    return 0;
}
