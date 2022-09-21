# TP1Algoritmos
*Resolucion del primer trabajo practico de Algoritmos y Estructuras de datos por Zoe Mancini*

(Esta branch es exactamente la misma que "main" pero fue subida con Git.)

***Enunciado del TP***

Una empresa logística trabaja para 8 clientes transportando 5 tipos de productos diferentes. En cada 
entrega que hacen para cualquiera de los clientes registran los siguientes datos:
Código de Cliente (un entero que va de 0 a 7), Código de Tipo de Producto (un entero que va de 0 a 4), 
Peso total transportado (en Kg con decimales) y Distancia recorrida (en Km con decimales).

Se dispone un archivo de texto, donde hay un registro (renglón) por cada entrega, con los datos 
descriptos, separados mediantes tabuladores. Dicho archivo tiene registradas las entregas de la última 
semana.
Se dispone también de un archivo con los nombres de los clientes seguidos inmediatamente del 
nombre de los tipos de productos. En ambos casos, ordenados según el código que les corresponde.
Se requiere un programa que procese este archivo y obtenga:

1. Emita un listado donde para cada cliente liste los tipos de producto tal que la cantidad total de 
kilos transportados es mayor a 13000.
2. Para el cliente con mayor cantidad tipos de productos que hayan superado 13000 kg en el punto
anterior, emita un listado con nombre de tipo de producto y total de kilómetros recorridos, 
ordenado por total de kilómetros en forma ascendente.
3. Del listado anterior, tome el tipo de producto con mayor cantidad de kilómetros recorridos e 
informe cuantas entregas se hicieron para ese tipo de producto (sin importar para que cliente).
