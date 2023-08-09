#ifndef TAXICLASS_H_
#define TAXICLASS_H_

#include <string>

using namespace std;

/* Registro de alarmas de 8 bits con los siguientes datos:
-Bit 0: Botón de pánico (Asalto)
-Bit 1: Vehículo detenido por más de 10 minutos
-Bit 2: Pasajeros sospechosos, avisar a policía para control
-Bit 3: Chofer descansando ignorar alarma bit 1
-Bit 4: Cambio de chofer
-Bit 5: Operación normal
-Bit 6: No usado
-Bit 7: No usado  */

enum Alarmas {
    Alarma1 = 0b00000001,
    Alarma2 = 0b00000010,
    Alarma3 = 0b00000100,
    Alarma4 = 0b00001000,
    Alarma5 = 0b00010000,
    Alarma6 = 0b00100000,
    Alarma7 = 0b01000000,
    Alarma8 = 0b10000000,
};

// Estructura para almacenar los datos de inicialización
struct DatosTaxi {
    int numeroInterno = 0;
    string marcaAuto = "";
    string patente = "";
    string propietario = "";
    string chofer = "";
    string telContacto = "";
    string fechaAltaServicio = "";
    string fechaBajaServicio = "";
    float latitud = 0.0;
    float longitud = 0.0;
    uint32_t horaUnix = 0;
    uint8_t alarmas = 0;
    float distanciaRecorrida = 0.0;

    // Constructor por defecto
    DatosTaxi() {}
};

class Taxiclass {
private:
    int numeroInterno;
    string marcaAuto;
    string patente;
    string propietario;
    string chofer;
    string telContacto;
    string fechaAltaServicio;
    string fechaBajaServicio;
    float latitud;
    float longitud;
    uint32_t horaUnix;
    uint8_t alarmas;
    float distanciaRecorrida;

    // Declaración función (Toma por parametro la enumeración definida)
    bool verificarAlarma(Alarmas alarma);

public:
    // Constructor por defecto
    Taxiclass();

    // Constructor que acepta la estructura de inicialización
    Taxiclass(const DatosTaxi& datos);

    // Constructor de copia
    Taxiclass(const Taxiclass& other);

    // Destructor
    ~Taxiclass();

    void imprimirTaxi();
    void calcularLatitudLongitud(uint32_t unixTime, float lat, float lon, uint8_t alarmasActivas);
    void obtenerChofer();
    void imprimirAlarmasActivas();
    void calcularDistancia(float lat, float lon);
    float obtenerDistanciaRecorrida();

    // Setters
    void setPropietario(const string& prop);
    void setChofer(const string& chof);

};

#endif /* TAXICLASS_H_ */
