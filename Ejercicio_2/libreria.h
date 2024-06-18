#ifndef LIBRERIA_H
#define LIBRERIA_H

#ifdef _WIN32
    #define DLLExport __declspec(dllexport)
#else
    #define DLLExport
#endif

DLLExport void imprimirMensaje();

#endif
