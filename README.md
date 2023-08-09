# Trabajo Práctico Nro 1 - Sistema de Control de Taxis

Este documento describe un sistema de control de taxis implementado en C++ como parte del Trabajo Práctico Nro 1 de la materia Programación (UTN - FRC) para el año 2023.

## Encabezado
Nombre : prog_MAC210097tp1
Universidad : FRC-UTN
Materia : Programación
Docente : José Luis Martinez
Autor : Miguel A. Calveiro
Version : 1.0
Description : Trabajo Práctico Nro 1

## Descripción del Programa

El sistema tiene como objetivo gestionar y monitorear taxis, calculando su ubicación, distancias recorridas y activación de alarmas.

## Flujo del Programa Principal

El flujo del programa principal se realiza de la siguiente manera:

1. Se inicia el programa.
2. Se crea un objeto `Taxi1` con datos iniciales.
3. Se calcula la latitud y longitud del `Taxi1` con las alarmas activas.
4. Se calcula la distancia recorrida por el `Taxi1`.
5. Se imprimen los detalles del `Taxi1`, incluida la distancia recorrida.
6. Se imprimen los eventos de alarmas activas para el `Taxi1`.
7. Se repiten los pasos 2-6 para `Taxi2` y `Taxi3`.

Este flujo secuencial refleja cómo el programa crea, calcula y muestra información para cada taxi individualmente.

## Estructura de las Clases

El sistema se compone de las siguientes clases:

- `Taxiclass`: Representa un taxi con atributos como número interno, marca, patente, ubicación, alarmas y distancia recorrida. Contiene métodos para establecer propietario y chofer, calcular latitud y longitud, imprimir detalles y alarmas, y calcular distancias.

- `DatosTaxi`: Clase utilizada para almacenar los datos iniciales de un taxi.

- `Alarmas`: Enumeración que define distintos tipos de alarmas.

La relación `1 a 1` entre `Taxiclass` y `DatosTaxi` indica que un objeto `Taxiclass` contiene datos de un objeto `DatosTaxi`. Además, `Taxiclass` utiliza la enumeración `Alarmas` para representar y manejar diferentes tipos de alarmas.

## Conclusión

Este trabajo práctico demuestra cómo implementar un sistema de control de taxis en C++, utilizando diagramas de actividad y de clase para representar el flujo del programa y la estructura de las clases. El sistema logra gestionar información detallada sobre los taxis y sus actividades.

### Carpetas & Link

- **src**: Contiene el código fuente del programa implementado como un proyecto en Qt Creator.
- **doc**: Contiene los archivos PlantUML para generar el diagrama de clase principal y el diagrama de actividad de la función principal Main.
- **link**: [Youtube Link: https://www.youtube.com/watch?v=mUuowT4ywPM](https://www.youtube.com/watch?v=mUuowT4ywPM)
