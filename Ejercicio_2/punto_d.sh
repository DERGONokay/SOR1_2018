#!/bin/bash
./Ejercicio_2/bucle.sh &  #Se ejecuta en segundo plano
top -d 2 -n 12 | grep $! #Se filtra el id del proceso en top
						 #con un delay de 2 segundos cada actualizacion
						 #y se muestra las veces indicadas en -n



