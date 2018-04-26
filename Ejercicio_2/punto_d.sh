#!/bin/bash
~/SOR1_2018/Ejercicio_2/bucle.sh &  #Se ejecuta en segundo plano
PROCID=$!
A=0

while true ; do
	top -bn1 | grep $PROCID #Se filtra el id del proceso en top
	if [[ $A -eq 2 ]]; then
		sudo kill $PROCID &> /dev/null
		exit 0
	fi
	sleep 3
	A=$A+1
done

