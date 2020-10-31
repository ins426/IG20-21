#ifndef EJE_RUEDA_H
#define EJE_RUEDA_H

#include "rueda.h"
#include "eje.h"

class eje_rueda
{
public:
    eje_rueda();
    rueda Rueda;
    eje Eje;

    void draw_line();
    void draw_point();
};

#endif // EJE_RUEDA_H
