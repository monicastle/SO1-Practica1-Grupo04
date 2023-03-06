#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "tipo_empleado.h"
#include <QSharedMemory>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Segmento {
    constexpr static int numMax_Empleados = 1000;
    vector<empleado_tipo> empleados;
    int numEmpleados_Arreglo;
};

#endif // SEGMENTO_H
