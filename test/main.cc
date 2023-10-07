#include <iostream>
#include "rtc_base/thread.h"



int main(int argc, char * argv[]) {

  std::unique_ptr<rtc::Thread> test1_thread = rtc::Thread::Create();
  test1_thread->SetName("Test1Thread", nullptr);
  test1_thread->Start();
  //test1_thread->PostDelayed()
  
  return 0;
}