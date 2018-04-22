#!/bin/bash
read -p "Ingrese el branch que desea actualizar: " RAMA
read -p "Ingrese un mensaje para el commit: " MENSAJE

#Chequeo si hay commit para hacer:
estado=`git status | grep "nothing to commit"`
if [[ $estado -gt 0 ]]; then\
	echo "El repositorio ya esta actualizado!"
	exit 0
fi
#Verifico que el branch exista
existe=`git branch | grep $RAMA`
if [[ $? -gt 0 ]]; then
	echo "La rama $RAMA no existe"
	exit 2
fi
#Agrego los cambios
echo "Agregando los cambios..."
git add -A
if [[ $? -gt 0 ]]; then
	echo "Error agregando el nuevo contenido"
	exit 1
fi
#Realizo el commit
echo "Realizando commit..."
git commit -m "$MENSAJE"
if [[ $? -gt 0 ]]; then
	echo "Error realizando el commit!"
	exit 1
fi
#Realizo el push
echo "Realizando push..."
git push origin $RAMA
if [[ $? -gt 0 ]]; then
	echo "Error realizando el push!"
	exit 1
fi
echo "Repositorio actualizado!"
