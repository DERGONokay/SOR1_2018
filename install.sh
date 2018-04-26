#!/bin/bash

MEDIO="SOR1_2018/supermenu/supermenu"

cp ~/SOR1_2018/Supermenu.desktop $HOME/Desktop/Supermenu.desktop

EJECUTABLE="$HOME/$MEDIO.sh"
ICONO="$HOME/$MEDIO.png"
sed -i "s+ejecutable+$EJECUTABLE+g" $HOME/Desktop/Supermenu.desktop
sed -i "s+icono+$ICONO+g" $HOME/Desktop/Supermenu.desktop
