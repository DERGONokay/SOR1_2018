#!/bin/bash
tiempo=6
#clear
while [[ $cont -lt $tiempo ]];do
	##############################
	#echo ""
	#echo "======================================================================================"
	#echo ""
	##############################
	#echo "ejecutando------>R"
	for(( i=0; i<100000;i++ ));do
		echo $i >> temporal.txt
	done
	rm temporal.txt	
	##############################
	#echo "durmiendo------->S"
	sleep 3
	##############################
	let cont=$cont+1
	##############################
done
#echo ""
#echo "=========================================="
#echo " Finalizado, presiones ctrl+c para salir"
#echo "=========================================="
