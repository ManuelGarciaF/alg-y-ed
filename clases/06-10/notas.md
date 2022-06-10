# Clase del 10 de Junio

## Archivos

Conjunto de bytes ordenados, identificados con un nombre, y almacenados en un 
dispositivo de almacenamiento.

Funciones utiles:

- `fopen(s1,s2)`: retorna un FILE* asociado al archivo abierto. Recibe f1, el nombre
  del archivo, y s2 el modo de apertura archivo ("w", "r", "rb", "rw", "w+b", etc),
  b representa abrirlo en modo binario, '+' representa poder apendar al archivo.

- `fwrite(&d, s, n, f)`: graba datos, toma d, un puntero a una variable, s, el número
  de bits a escribir, n, el numero de elementos (si se pasa un array), y f, un FILE*.

- `fread(&d, s, n, f)`: lee datos, mismos argumentos que fwrite.

- `fseek(f, offset, origin)`: mueve el indicador de posición, offset representa un
  nro de bytes, y origin tiene 3 constantes definidas, {SEEK_SET, SEEK_CUR, SEEK_END}
  que representan el inicio, la posición actual, y el final del archivo respectivamente.

- `feof(f)`: devuelve true si f se encuentra en el fin del archivo.
