#include "rtc_base/thread.h"
#include "rtc_base/task_queue.h"
#include "api/task_queue/task_queue_factory.h"

class Session : rtc::MessageHandler {
 public:
  Session() {
    test_thread1 = rtc::Thread::Create();
    test_thread1->SetName("testThread1", nullptr);
    test_thread1->Start();
    //task_queue_factory_ = CreateTaskQueue("SessionTaskQueuq", webrtc::TaskQueueFactory::Priority::HIGH);
  }
  
  void FuncationA(const std::string& text) {
    test_thread1->PostTask(RTC_FROM_HERE, [this, text]() {
      std::cout << "FuncationA: " << text << " " << count << std::endl;
      ++count;
      usleep(2*1000*1000);
    });
  }

  void FuncationB(const std::string& text) {
    test_thread1->PostTask(RTC_FROM_HERE, [this, text]() {
      std::cout << "FuncationB: " << text << " " << count << std::endl;
      ++count;
      usleep(2*1000*1000);
    });
  }

  void FuncationC(const std::string& text) {
    std::cout << "FuncationC in" << std::endl;
    test_thread1->Invoke<void>(RTC_FROM_HERE, [this, text]() {
      std::cout << "FuncationC: " << text << " " << count << std::endl;
      std::cout << "FuncationC ing" << std::endl;
      ++count;
    });
    std::cout << "FuncationC out" << std::endl;
  }

  void FUncationD(const std::string& text) {

  }

  void OnMessage(rtc::Message* msg) override {}

 private:
  std::unique_ptr<rtc::Thread> test_thread1;
  int count = {1};
  std::unique_ptr<webrtc::TaskQueueFactory> task_queue_factory_;
  std::unique_ptr<rtc::TaskQueue> task_queue_;
};