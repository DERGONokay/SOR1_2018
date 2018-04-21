#!/bin/bash
#------------------------------------------------------
#Prueba de ANIMACION
#------------------------------------------------------
animacionCarga () {
    cont=2
    echo -n "Cargando opciones, espere "
    while [ $cont -lt 2 ]; do 
        for i in / - \\ '|'; do 
            echo -n $i
            sleep 0.5
            echo -ne '\b'
        done
        let cont=cont+1
    done
    echo -ne '\b\b\b\b\b\b\b'
    echo -n "finalizado"
    echo ""
    sleep 1
}
#------------------------------------------------------
# PALETA DE COLORES
#------------------------------------------------------
#setaf para color de letras/setab: color de fondo
    red=`tput setaf 1`;
    green=`tput setaf 2`;
    blue=`tput setaf 4`;
    bg_blue=`tput setab 4`;
    reset=`tput sgr0`;
    bold=`tput setaf bold`;
#------------------------------------------------------
# VARIABLES GLOBALES
#------------------------------------------------------
user=$(whoami)
proyectoActual="/home/$user/SOR1_2018";
proyectos="/home/$user/Documentos";

#------------------------------------------------------
# DISPLAY MENU
#------------------------------------------------------
imprimir_menu () {
       imprimir_encabezado "\t\t S  U  P  E  R  -  M  E  N U ";
       animacionCarga 
    echo ""
    echo -e "\t\t El proyecto actual es:";
    echo -e "\t\t $proyectoActual";
    
    echo -e "\t\t";
    echo -e "\t\t Opciones:";
    echo "";
    echo -e "\t\t\t a.  Ver estado del proyecto";
    echo -e "\t\t\t b.  Buscar instalado";
    echo -e "\t\t\t c.  Buscar en directorio";
    echo -e "\t\t\t d.  Buscar en archivo";        
    echo -e "\t\t\t e.  Buscar cambio de estado";        
    echo -e "\t\t\t f.  Actualizar repositorio";
    echo -e "\t\t\t q.  Salir";
    echo "";
    echo -e "Escriba la opción y presione ENTER";
}

#------------------------------------------------------
# FUNCTIONES AUXILIARES
#------------------------------------------------------

imprimir_encabezado () {
    clear;
    #Se le agrega formato a la fecha que muestra
    #Se agrega variable $USER para ver que usuario está ejecutando
    echo -e "`date +"%d-%m-%Y %T" `\t\t\t\t\t USERNAME:$USER";
    echo "";
    #Se agregan colores a encabezado
    echo -e "\t\t ${bg_blue} ${red} ${bold}--------------------------------------\t${reset}";
    echo -e "\t ${bold}${bg_blue}${red}$1\t\t${reset}";
    echo -e "\t\t ${bg_blue}${red} ${bold} --------------------------------------\t${reset}";
    echo "";
}

esperar () {
    echo "";
    echo -e "Presione enter para continuar";
    read ENTER ;
}

malaEleccion () {
    echo -e "Selección Inválida ..." ;
}

decidir () {
    echo $1;
    while true; do
        echo "desea ejecutar? (s/n)";
	read respuesta;
            case $respuesta in
                [Nn]* ) break;;
                   [Ss]* ) eval $1
                break;;
                * ) echo "Por favor tipear S/s ó N/n.";;
            esac
    done
}

#------------------------------------------------------
# FUNCTIONES del MENU
#------------------------------------------------------
a_funcion () {
        imprimir_encabezado "\tOpción a.  Ver estado del proyecto";
        decidir "cd $proyectoActual; git status";
}

b_funcion () {
           imprimir_encabezado "\tOpción b. Buscar si un programa esta instalado";
	   #sh ~/SOR1_2018/Ejercicio_2 punto_a
    	   decidir "./../Ejercicio_2/punto_a.sh"
	   #completar
}

c_funcion () {
          imprimir_encabezado "\tOpción c. Buscar archivo en ruta";
	  decidir "./../Ejercicio_2/punto_b.sh"
          #completar       
}

d_funcion () {
    imprimir_encabezado "\tOpción d. Buscar String en ruta";
    decidir "./../Ejercicio_2/punto_c.sh"
    #completar
}


e_funcion () {
    imprimir_encabezado "\tOpción e";        
    #completar
}

f_funcion() {
	imprimir_encabezado "\tOpcion f. Actualizar el repositorio"
	decidir "./../Ejercicio_4/actualizarRepo.sh"	
}


#------------------------------------------------------
# LOGICA PRINCIPAL
#------------------------------------------------------
while  true
do
    # 1. mostrar el menu
    imprimir_menu;
    # 2. leer la opcion del usuario
    read opcion;
    
    case $opcion in
        a|A) a_funcion;;
        b|B) b_funcion;;
        c|C) c_funcion;;
        d|D) d_funcion;;
        e|E) e_funcion;;
	f|F) f_funcion;;
        q|Q) break;;
        *) malaEleccion;;
    esac
    esperar
done
 


