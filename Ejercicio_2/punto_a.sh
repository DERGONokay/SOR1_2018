#!/bin/bash
read -p "Nombre del programa:" NAME 
A=true
#echo "Parametro = $*"
#if [[ $# -lt 1 ]]; then
#	echo 'Cantidad de parametros invalida'
#	exit 0
#fi
#if [[ $# -eq 1 ]]; then
    while $A; do
	case NAME in
	man | --help)
		echo "Instalado permite saber si un programa esta instalado o no."
		echo "Recibe como primer parametro el nombre del programa que sedesea conocer si está o no instalado."
		echo "------------------------------------------------------------"
		echo "Syntaxys"
		echo "instalado <NOMBRE_DEL_PROGRAMA>	Imprime por consola 'Programa instalado'  y retora 0"
		echo "instalado man		Muestra este manual"
		echo "instalado --help	Muestra este manual"
		exit 0
		;;
	*)
		A=false
		;;
	esac
    done
#fi
INSTALADO=`dpkg -l "*$NAME*" &> /dev/null`
if dpkg -l "*$NAME*" &> /dev/null; then
	echo 'Programa instalado'
	exit 0
fi

echo 'Programa no instalado'
exit 1
