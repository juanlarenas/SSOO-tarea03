# SSOO-tarea03
para compilar utilizar siguiente comando:
g++ -o main main.cc -pthread

Se define una variable LIMIT que define un entero en 50 con la cantidad,
que define el ciclo, Tambien se definio un variable booleana y count con el fin de 
detener el programa en la iteración 50 según lo necesitado,
Se crearon dos funciones:
1- fibonacci
2- impar

dentro de cada una de las funciones se lleva el conteo de cada iteracio


Dentro del main se impide las señales:
ctrl+C, ctrt+Z, ctrt+\
para que le den termino al programa,
Luego se hace un fork en el cual le sigue un ciclo while
infinito con un variable seguir que dentro de las 
funciones fibonacci e impar lo maneja para el 
termino del programa en la iteración número 50.
Luego dentro del ciclo  se hacen condiciones
para verificar cuál es el hijo o el padre, 
y dependiendo de eso se llama a un thread
con una función antes mencionada.



