#!/bin/bash

read -p "Ingrese la ruta: " RUTA
read -p "Ingrese la extension del archivo: " EXTENSION
read -p "Ingrese el nombre del archivo: " NOMBRE
#if [[ $# -lt 3 ]]; then
#	echo "Cantidad de parametros invalida. $#"
#	exit 0
#fi
cd $RUTA

ls | grep $NOMBRE$EXTENSION 2> /dev/null 
if [[ $? == 1 ]]; then
	echo "Arichivo $NOMBRE$EXTENSION no encontrado en $RUTA"
else
	echo "Archivo encontrado"
fi
