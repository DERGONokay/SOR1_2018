#!/bin/bash
echo $! >> id.txt
./bucle.sh &  #Se ejecuta en segundo plano
top | grep $! #Se filtra el id del proceso en top


