#include<iostream>
#include<thread>
#include <windows.h>

using namespace std;

void taskA(){
  for(int i=0;i<10;i++){
    Sleep(1);
    cout<<"TaskA is running: "<<i<<endl;
    fflush(stdout);
  }
}

void taskB(){
  for(int i=0;i<10;i++){
    Sleep(1);
    cout<<"TaskB is running: "<<i<<endl;
    fflush(stdout);
  }
}

int main(){
  thread t1(taskA);
  thread t2(taskB);
  // join() is used to wait for the thread to finish and will not let main thread to finish
  t1.join();
  t2.join();
  return 0;
}