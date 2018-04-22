#!/bin/bash

#ejecuta estadoDeProceso en segundo plano
./punto_d/estadoDeProceso&

#guarda en $id el id del ultimo proceso ejecutado en segundo plano
id=$!

#se filtra top mediante grep para ver solo el proceso con el id guardado
#top | grep $id 

#kill $id

for (( i=5; i>0; i-- ));do
	top | grep $id 
	sleep 5
done

kill $id



