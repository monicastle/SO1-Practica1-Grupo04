#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "tipo_empleado.h"
#include <QSharedMemory>
#include <iostream>
#include <vector>
#include <string>
#include <semaphore.h>

using namespace std;

struct Segmento {
    constexpr static int numMax_Empleados = 1000;
    empleado_tipo empleados[numMax_Empleados];
    int numEmpleados_Arreglo = 0;
    int nTotal = 0;
    sem_t mutex;
    sem_t sem_Lector;
    int nLector = 0;
};

#endif // SEGMENTO_H
