#!/bin/bash

# Establecer el nombre base para los archivos
nombre_base="fox"

# Contador para numerar los archivos
contador=1

# Iterar sobre cada archivo en la carpeta
for archivo in archivos/*; do
    # Obtener la extensión del archivo
    extension="${archivo##*.}"
    # Renombrar el archivo con el nombre base seguido del número y la extensión
    nuevo_nombre="${nombre_base}_${contador}.${extension}"
    # Mover el archivo a su nuevo nombre
    mv "$archivo" "archivos/${nombre_base}_${contador}.${extension}"
    # Incrementar el contador
    contador=$((contador+1))
done

