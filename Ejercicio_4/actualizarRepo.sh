#!/bin/bash
read -p "Ingrese el branch que desea actualizar: " RAMA
read -p "Ingrese un mensaje para el commit: " MENSAJE
echo "Agregando los cambios..."
git add -A
echo "Realizando commit..."
git commit -m "$MENSAJE"
echo "Realizando push..."
git push origin $RAMA
echo "Repositorio actualizado!"
