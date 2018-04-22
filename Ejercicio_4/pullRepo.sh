#!/bin/bash

read -p "Ingrese el branch que desea realizar pull: " rama

echo "Actualizando $rama..."
git pull origin $rama
echo "$rama actualizado!"
