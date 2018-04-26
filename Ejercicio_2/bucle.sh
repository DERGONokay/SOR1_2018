#!/bin/bash
tiempo=6
cont=0
clear
while [[ $cont -lt $tiempo ]];do
	
	for(( i=0; i<100000;i++ ));do
		echo $i >> temporal.txt
	done
	rm temporal.txt	
	
	sleep 3

	let cont=$cont+1
	
done
