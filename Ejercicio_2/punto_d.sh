#!/bin/bash

read -p "Ingrese el proceso a filtrar: " proceso

$proceso
		top | grep $proceso
