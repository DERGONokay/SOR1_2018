#!/bin/bash
NOMBRE=$1
RUTA=$2
#TODO: chequear cantidad de argumentos

cat $RUTA | grep -n $NOMBRE >> salida.out
