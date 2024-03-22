
// упражнения 1.1.1
// № 1 
#include <iostream>
#include <thread>  
void hello(){
  std::cout<<"Hello parallel World!\n";
}
int main() { 
  std::thread th(hello);  //  запуск нового потока
  th.join();              //  слияние потоков
}



/*
№ 2
Когда объект потока выходит за пределы области видимости и находится в состоянии присоединения, программа завершается. 
Еще имеется два варианта деструктора соединяемого потока. Он может незаметно присоединиться, но соединение может никогда не вернуться, 
если поток застрял. Или он может отсоединить поток. Отсоединенные потоки очень сложны, так как они могут дожить до конца программы и 
испортить высвобождение ресурсов. 

 */
 
 //№ 3
 
#include <thread>  
#include <iostream>
#include <string>
using namespace std;

void hello(const std::string& first, const std::string& second) {
cout << first << second;
}

int main()
{
thread th(hello, "Hello, ", "threads!");
th.join();
return 0;
}
// №4 

#include <thread>  
#include <iostream>
#include <string>
using namespace std;

std::thread::id main_thread_id = std::this_thread::get_id();

void is_main_thread() {
  if ( main_thread_id == std::this_thread::get_id() )
    std::cout << "This is the main thread.\n";
  else
    std::cout << "This is not the main thread.\n";
}

void hello(const std::string& first, const std::string& second) {
  cout << first << second;
  is_main_thread();
}

int main()
{
  thread th(hello, "Hello, ", "threads!");
  th.join();
  is_main_thread();
  return 0;
}

//Назначение данного кода - это определить поток, главный или нет.


//№5

#include <iostream>       
#include <thread>         

std::thread::id main_thread_id = std::this_thread::get_id();
void is_main_thread() {
    if (main_thread_id == std::this_thread::get_id())
        std::cout << "This is the main thread.\n";
    else
        std::cout << "This is the "<< std::this_thread::get_id()  <<" thread.\n";
}

int main()
{
    is_main_thread();
    std::thread th(is_main_thread);
    th.join();
    std::thread th2(is_main_thread);
    th2.join();
}