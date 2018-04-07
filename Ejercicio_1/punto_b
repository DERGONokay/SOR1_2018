#!/bin/bash

RUTA=$1
EXTENSION=$2
NOMBRE=$3
if [[ $# -lt 3 ]]; then
	echo "Cantidad de parametros invalida. $#"
	exit 0
fi
cd $RUTA

ls | grep $NOMBRE$EXTENSION
if [[ $? == 1 ]]; then
	echo "Arichivo $NOMBRE$EXTENSION no encontrado en $RUTA"
fi
