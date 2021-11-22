#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <thread>
#include <sys/types.h>
#include <sys/wait.h>
#include <csignal>

#define LIMIT 50
int count = 0;
bool seguir = true;

void signal_handler( int signal_num ) { 
	std::cout << "Detencion no permitida"<< "\n";   
}

void fibonacci(){
  unsigned long first = 0;
  unsigned long second = 1;
  while (seguir){
    unsigned long long sum = first + second;
    std::cout << "Valor Fibonacci: " << sum <<" - PPIDE = "<< getpid()<< std::endl;
    first = second;
    second = sum;
    count++; 
    if(count == LIMIT) seguir = false;  
    sleep(1);
  }
}

void impar(){
  int aux = 1;
  while (seguir)
  {
    std::cout << "Valor Impar: " << aux <<" - PID = "<< getpid() << std::endl;
    aux = aux + 2;
    count++; 
    if(count == LIMIT) seguir = false;  
    sleep(1);
  }
}

int main(){
	std::signal(SIGTERM, signal_handler);   
	std::signal(SIGINT, signal_handler); 
	std::signal(SIGTSTP, signal_handler); 

  int proc=fork();

  while(seguir) { 
    if(proc >1){
      std::thread t1 (fibonacci);
      t1.join();      
    }
    else if(proc == 0){
      std::thread t2 (impar);
     t2.join();    
    }
    else{
      std::cout << "ERROR"<<std::endl;
      return EXIT_FAILURE;
    }
	}
  return EXIT_SUCCESS;  
}


