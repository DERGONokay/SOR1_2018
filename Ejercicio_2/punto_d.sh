#!/bin/bash

read -p "Ingrese el proceso a filtrar: " proceso

$proceso&

PID=$!

top | grep $PID