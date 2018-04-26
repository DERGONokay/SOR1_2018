#!/bin/bash
./../Ejercicio_2/bucle.sh &  #Se ejecuta en segundo plano
top | grep $! #Se filtra el id del proceso en top


