#!/bin/bash
read -p "Ingrese el String a buscar: " NOMBRE
read -p "Ingrese la ruta: " RUTA

cat $RUTA | grep -n $NOMBRE >> salida.out
if [[ $? -gt 0 ]]; then
	echo "Error durante la ejecucion del script"
else
	echo "salida.out:"
	cat salida.out
fi
