//=============================================================
// Nombre      : prog_MAC210097tp1
// Universidad : FRC-UTN
// Materia     : Programación
// Docente     : José Luis Martinez
// Autor       : Miguel A. Calveiro
// Version     : 1.0
// Description : Trabajo Práctico Nro 1
//=============================================================

#include "taxiclass.h"
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

//*************************************************************
// INDICE
//*************************************************************
/*
    1.  Definición de la clase Taxiclass, en el archivo Taxiclass.h
    2.  Datos inyectados a la clase, a través de la "struct DatosTaxi", definida en Taxiclass.h
    3.  Contructor por defecto en el presente archivo de implementación, con valores de incialización en cero.
    4.  Contructor con valores aceptados por la estructura DatosTaxi.
    5.  Constructor de copia
    6.  Destructor
    7.  Setters
    8.  Métodos - Imprimir datos
    9.  Métodos - Alarmas
    10. Métodos - Cálculo (ubicación, recorrido y distancias)
*/

//*************************************************************
// SECCIÓN CONSTRUCTORES & DESTRUCTOR
//*************************************************************

// 3. Constructor por defecto
Taxiclass::Taxiclass()
    : numeroInterno(0), marcaAuto(""), patente(""), propietario(""), chofer(""),
      telContacto(""), fechaAltaServicio(""), fechaBajaServicio(""),
      latitud(0.0), longitud(0.0), horaUnix(0), alarmas(0), distanciaRecorrida(0.0) {
    // Lógica de validación o manipulación a propietario y chofer si es necesario
    setPropietario("");
    setChofer("");
}

// 4. Constructor que acepta la estructura de inicialización
Taxiclass::Taxiclass(const DatosTaxi& datos)
    : numeroInterno(datos.numeroInterno), marcaAuto(datos.marcaAuto), patente(datos.patente),
      telContacto(datos.telContacto), fechaAltaServicio(datos.fechaAltaServicio),
      fechaBajaServicio(datos.fechaBajaServicio), latitud(datos.latitud),
      longitud(datos.longitud), horaUnix(datos.horaUnix), alarmas(datos.alarmas),
      distanciaRecorrida(datos.distanciaRecorrida) {
    // Utilizar los setters para propietario y chofer
    setPropietario(datos.propietario);
    setChofer(datos.chofer);
}

// 5. Constructor de copia
Taxiclass::Taxiclass(const Taxiclass& other)
    : numeroInterno(other.numeroInterno), marcaAuto(other.marcaAuto), patente(other.patente),
      telContacto(other.telContacto), fechaAltaServicio(other.fechaAltaServicio),
      fechaBajaServicio(other.fechaBajaServicio), latitud(other.latitud),
      longitud(other.longitud), horaUnix(other.horaUnix), alarmas(other.alarmas),
      distanciaRecorrida(other.distanciaRecorrida) {
    // Utilizar los setters para propietario y chofer
    setPropietario(other.propietario);
    setChofer(other.chofer);
}

// 6. Destructor
Taxiclass::~Taxiclass() {}

//*************************************************************
// SECCIÓN SETTERS
//*************************************************************

// 7. Setters
//  a. Propietario
void Taxiclass::setPropietario(const string& prop) {
    // Lógica de validación o cualquier otra manipulación necesaria
    propietario = prop;
}
//  b. Chofer
void Taxiclass::setChofer(const string& chof) {
    // Lógica de validación o cualquier otra manipulación necesaria
    chofer = chof;
}

//*************************************************************
// SECCIÓN MÉTODOS (IMPRIMIR TAXI)
//*************************************************************

// 8. Métodos públicos de la clase
void Taxiclass::imprimirTaxi() {
    cout << "Numero Interno: " << numeroInterno << endl;
    cout << "Marca del Automovil: " << marcaAuto << endl;
    cout << "Patente: " << patente << endl;
    cout << "Propietario: " << propietario << endl;
    cout << "Chofer: " << chofer << endl;
    cout << "Telefono de Contacto: " << telContacto << endl;
    cout << "Fecha de Alta de Servicio: " << fechaAltaServicio << endl;
    cout << "Fecha de Baja de Servicio: " << fechaBajaServicio << endl;
    cout << "Latitud: " << latitud << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Hora Unix: " << horaUnix << endl;
    cout << "Alarmas: " << std::bitset<8>(alarmas) << endl;
    cout << "Distancia Recorrida: " << distanciaRecorrida << endl;
}

void Taxiclass::obtenerChofer() {
    cout << "Chofer actual: " << chofer << endl;
}

//*************************************************************
// SECCIÓN MÉTODOS (ALARMAS)
//*************************************************************

void Taxiclass::imprimirAlarmasActivas() {
    // Definición de la estructura que almacena la alarma y su descripción
    struct AlarmaDescripcion {
        Alarmas alarma;
        const char* descripcion; // Puntero a una cadena de caracteres, el cual almacena la descripción asociada con la alarma.
    };

    // Arreglo de objetos AlarmaDescripcion con las alarmas y sus descripciones
    AlarmaDescripcion alarmasDescripciones[] = {
        { Alarma1, "Alarma 1: Boton de Panico (Asalto)" },
        { Alarma2, "Alarma 2: Vehiculo detenido por mas de 10 minutos" },
        { Alarma3, "Alarma 3: Pasajeros sospechosos, avisar a policia para control" },
        { Alarma4, "Alarma 4: Chofer descansando ignorar alarma" },
        { Alarma5, "Alarma 5: Cambio de chofer" },
        { Alarma6, "Alarma 6: Operacion normal" },
        { Alarma7, "Alarma 7: No usada" },
        { Alarma8, "Alarma 8: No usada" }
    };

    // Recorremos cada AlarmaDescripcion en el arreglo alarmasDescripciones
    for (const AlarmaDescripcion& alarmaDesc : alarmasDescripciones) {
        // Verificamos si la alarma está activa utilizando la función verificarAlarma
        if (verificarAlarma(alarmaDesc.alarma)) {
            // Si la alarma está activa, imprimimos su descripción en la consola
            cout << alarmaDesc.descripcion << endl;
        }
    }
}

// Métodos privados de la clase
bool Taxiclass::verificarAlarma(Alarmas alarma) {
    return (alarmas & alarma) == alarma; // Instrucción de retorno
}

//*************************************************************
// SECCIÓN CÁLCULO DE UBICACIÓN, RECORRIDO Y DISTANCIAS
//*************************************************************

void Taxiclass::calcularDistancia(float lat, float lon) {
    const double PI = 3.14159265359; // Valor de PI
    const double radioTerrestre = 6372797.560856; // Radio de la Tierra en metros

    // Convertir las latitudes y longitudes de grados a radianes
    double lat1 = latitud * PI / 180.0;
    double lon1 = longitud * PI / 180.0;
    double lat2 = lat * PI / 180.0;
    double lon2 = lon * PI / 180.0;

    // Diferencias entre las latitudes y longitudes en radianes
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    // Cálculo de la parte "a" de la fórmula de Haversine
    double a = pow(sin(dLat / 2.0), 2) +
               cos(lat1) * cos(lat2) * pow(sin(dLon / 2.0), 2);

    // Cálculo del ángulo central "c" y la distancia en metros
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distancia = radioTerrestre * c;

    // Sumar la distancia calculada a la distancia recorrida total
    distanciaRecorrida += distancia;
}

float Taxiclass::obtenerDistanciaRecorrida() {
    return distanciaRecorrida; // Instrucción de retorno
}

void Taxiclass::calcularLatitudLongitud(uint32_t unixTime, float lat, float lon, uint8_t alarmasActivas) {
    horaUnix = unixTime;
    latitud = lat;
    longitud = lon;
    alarmas = alarmasActivas;
}
//*************************************************************
// FIN DEL ARCHIVO
//*************************************************************
