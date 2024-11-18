#!/bin/bash

# Comando para convertir imágenes .png en .xpm y guardarlas en una carpeta llamada "destino"
mogrify -path destino -format xpm *.png

