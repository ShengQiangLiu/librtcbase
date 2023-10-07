#include <thread>

#include "gtest/gtest.h"
#include "rtc_base/thread.h"
#include "session.h"

class RtcBaseTest : public testing::Test {
 protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(RtcBaseTest, thread_test) {
  Session* session = new Session();
  for (size_t i = 0; i < 10; i++) {
    session->FuncationC("thread1");
    session->FuncationA("thread1");
    session->FuncationB("thread1");
  }

  // std::thread t1 = std::thread([session]() {
  //   std::cout<<"thread1"<<std::endl;
  //   session->FuncationA("thread1");
  //   session->FuncationB("thread1");
  // });
  // std::thread t2 = std::thread([session]() {
  //   std::cout<<"thread2"<<std::endl;
  //   session->FuncationA("thread2");
  //   session->FuncationB("thread2");
  // });
  // std::thread t3 = std::thread([session]() {
  //   std::cout<<"thread3"<<std::endl;
  //   session->FuncationC("thread3");
  // });
  // t1.join();
  // t2.join();
  // t3.join();
  delete session;
}