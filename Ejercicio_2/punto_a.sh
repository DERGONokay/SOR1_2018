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
		echo "Preguntenle a Damian como funciona, yo no se nada"
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
