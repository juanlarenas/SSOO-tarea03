# SSOO-tarea03
para compilar utilizar siguiente comando:
g++ -o main main.cc -pthread

Se define una variable **LIMIT** que define un entero en 50 con la cantidad,
que define el ciclo, Tambien se definio un variable booleana **seguir** y **count** con el fin de 
detener el programa en la iteración 50 según lo requerido en la tarea.  
Se crearon dos funciones:
1. fibonacci
2. impar

Dentro de cada una de las funciones se lleva el conteo de cada iteración en la 
cual se aumenta a la variable **count** hasta que llegue al **LIMIT** y se para la funciones

Dentro del main se impide las señales que le den termino al programa:
- ctrl+C, 
- ctrt+Z, 
- ctrt+\  

Luego se hace un fork en el cual le sigue un ciclo while
con la variable seguir que se manipula dentro de las 
funciones fibonacci e impar esto con el fin de parar el 
programa en la iteración número 50.
Luego dentro del ciclo  se hacen condiciones
para verificar cuál es el hijo o el padre, 
y dependiendo de eso se llama a un thread
con una de las funciones antes mencionada para que se imprima lo solicitado.

Si se desea para el programa antes de la iteración termine se debe utilizar:  
- kill -s SIGUSR1  __*PID del proceso*__ proceso padre
- kill -s SIGUSR2  __*PID del proceso*__ proceso hijo



