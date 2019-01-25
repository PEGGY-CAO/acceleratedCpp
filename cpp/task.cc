#include <iostream>
#include <string>
#include <tuple>
#include <list>
#include <cstdint>
#include <inttypes.h>
#include <exception>
#include <functional>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Don't forget to add your necessary header files here
 */
#include "meta.hh"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <fstream>

//#error "Please write your full name here thanks, I'm MuLei, glad to know you"
//#define your_name_here
#define MY_NAME "Yuqi(Peggy) Cao"

/* From now on, don't look any code here unless you're told so, don't be lost.
 * Save your time, you don't have much time.
 * I expect you have good editor for coding, and you should be good at it, since
 * you have to follow the WHITE-RABBITs in order.
 * Pay attention, I'll give you hints if any necessary.
 * Good luck!
 * Now, find WHITE-RABBIT(1), go!
 */

class MyTask : public DrTask
{
public:
  MyTask(std::string your_name) : DrTask(your_name) {};
  ~MyTask() { /* feel free to add your destroy code */ };
  void greeting(void) override;
  void run(void) override;
  void load(std::string filename) override;
  void do_the_maths(void) override;
  void finish_the_work(void) override;
  std::string jabberwocky(std::string s);
  static bool is_prime(uint64_t n);
  static std::list<uint64_t> get_all_prime_divisors(uint64_t n);
protected:
  /* WHITE-RABBIT(5):
   * Define a protected attribute to hold the data which should be processed later.
   *        The attribute name must be `data_', but the type of `data_' depends on your
   *        design.
   * HINT: The test data could be very large, so you may consider the efficiency.
   * When you finish, go for WHITE-RABBIT(6)
   */
  //protected double data_;
//#error "uncomment the lines below to define data_ with your preferred type"
  // Feel free to set the size of data if you need it
  size_t size_;
  
  std::string data_;
};

std::string MyTask::jabberwocky(std::string s)
{
  /* WHITE-RABBIT(2)
   * Let's warm up, MyTask class ought to be initialized with your name and stored
   * to name_, now let's do some magic to encode your name:
   * In a given string, change the position of each neighbour characters, each time
   * the character has been moved, it won't be moved again. If there's no neighbour
   * then just keep it.
   * For example: MuLei -> uMeLi
   */

  // TODO
  const std::string::size_type nums = s.size();
  std::string::size_type c = 0;
  int x = nums % 2;
  //if x == 0, even; else odd

  std::string result;
  while (c < nums - 1 && c + 1 <= nums - 1) {
    result += s[c+1];
    result += s[c];
    c += 2;
  }

  if (x == 1)
    result += s[nums - 1];
  
  /* When you finish, return your result and go for WHITE-RABBIT(3) */
  return result;
}

void MyTask::greeting(void)
{
  std::cout << "Dorabot programming test version " << version_ << std::endl;
  std::cout << "The candidate name is " << name_ << std::endl;

  if(!jabberwocky(jabberwocky(name_)).compare(name_))
    printf("Good! You killed Jabberwocky!\n");
  else
    printf("Jabberwocky killed you! Try it again!\n");
}

void MyTask::finish_the_work(void)
{
  /* WHITE-RABBIT(13)
   * Now you have 3 attributes computed by you before: sn_, pk_, sk_
   *
   * Step-1
   * Read each character C in data_ one by one, and encrypt them, then write to
   * a new file. The output filename should be "letter".
   * The encryption method is:
   * C multiply itself sk_ times, then mod sn_
   *
   * Step-2
   * Write pk_ to a file named "key.pub" in string, the format is: pk_[newline]sn_
   * Write sk_ to a file named "key.prv" in string, the format is: sk_[newline]sn_
   * NOTE: [newline] means a newline, don't output a string "[newline]" or you'll
   *       be mocked just like someone before.
   */
  
  // TODO
  //step-1
  std::ofstream myfile0;
  myfile0.open("letter");
  const std::string::size_type sizeC = data_.size();
  for (uint64_t i = 0; i < sizeC; i++) {
    char c = data_[i];
    uint64_t x = 0, y = c;
    while (x != sk_) {
      y *= c;
      x++;
    }
    myfile0 << (y % sn_);
    
  }
  myfile0.close();

  //step-2
  std::ofstream myfile1, myfile2;
  myfile1.open("key.pub");

  myfile1 << pk_;
  myfile1 << "\n";
  myfile1 << sn_;
  myfile1.close();

  myfile2.open("key.prv");
  myfile2 << sk_;
  myfile2 << sn_;
  myfile2.close();


//#error "Don't miss finish_the_work()"
  // Go for WHITE-RABBIT(14)
}

void MyTask::run(void)
{
  /* WHITE-RABBIT(1)
   * Finish this function to run the task. 
   */

  /* The first task is not hard.
   * Take it easy, you should be good enough to get the 1st point here.
   * Now jump to WHITE-RABBIT(2)
   */
  greeting();

  /* WHITE-RABBIT(3)
   * Now you should finish load() function
   * Go for WHITE-RABBIT(4)
   */
  load(TEST_DATA);

  /* WHITE-RABBIT(7)
   * Now you should finish do_the_math() function
   * Go for WHITE-RABBIT(8)
   */
  do_the_maths();
  
  /* WHITE-RABBIT(12)
   * I need you do me a favor, I have a letter for someone, but it's too dangerous
   * to deliver it by myself. I trust you, and you happened to finish some maths work
   * to help to encrypt it. Now I want you to encrypt it, the data was loaded to data_
   * by you, remember it?
   * Now go for WHITE-RABBIT(13), it's the final coding work, good luck! 
   */
  finish_the_work();

  /* WHITE-RABBIT(14)
   * Good, if you think you finished all the tasks so far, just save and quit,
   * then run `make run' and follow the instructions. You must debug your code
   * before next step if there's any error.
   */

  end();
}

void MyTask::load(std::string filename)
{
  /* WHITE-RABBIT(4)
   * Finish this function to load data, and store it to data_
   * HINT: When I review your program, I'll load huge data set for testing.
   *       So try your best to make it efficient as possible.
   *       You'll get extra point as reward for good performance.
   */

  /* Go for WHITE-RABBIT(5) to finish the data type define. */
  
  /* WHITE-RABBIT(6) here */

  // TODO
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    //std::string contents;
    in.seekg(0, std::ios::end);
    data_.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&data_[0], data_.size());
    in.close();
    //std::cout << "successfully read file" << std::endl;
    //data_ = contents;
  }
  //throw(errno);

  // int i;
  // int fd;
  // int *map;
  // fd = open(filename, O_RDONLY);
  // if (fd == -1) {
  //   perror("Error opening file for reading");
  //   exit(EXIT_FAILURE);
  // }

  // map = mmap(0, size_, PROT_READ, MAP_SHARED, fd, 0);
  // if (map == MAP_FAILED) {
  //   close(fd);
  //   perror("Error opening file for reading");
  //   exit(EXIT_FAILURE);
  // }

  // for (i = 1; i <= size_; ++i) {

  // }

//#error "Please finish load(filename)"
  /* When you finish, go for WHITE-RABBIT(7) */
}

bool MyTask::is_prime(uint64_t n)
{
  bool result = true;

  // WHITE-RABBIT(10)
  
  for (uint64_t i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      result = false;
      break;
    }
  }

//#error "Please implement is_prime(n)"
  // Go for WHITE-RABBIT(11) to finish the rest task
  return result;
}

std::list<uint64_t> MyTask::get_all_prime_divisors(uint64_t n)
{
  /* WHITE-RABBIT(9)
   * For example:
   * get_all_prime_divisors(45) returns {5, 3} as a list.
   * HINT-1: The order matters, make sure it's sorted from max to min.
   * HINT-2: Don't include 1.
   */
  std::list<uint64_t> result; 
  /* Go for WHITE-RABBIT(10) to implement is_prime(n) then come back.
   * WHITE-RABBIT(11)
   * Finish the rest task
   */

  // TODO
  if (n % 2 == 0) {
    result.push_front(2);
  }
  for (uint64_t i = 3; i <= n / 2; i+=2) {
    if (n % i == 0 && is_prime(i)) {
      result.push_front(i);
      
    }
  }
//#error "Please finish get_all_prime_divisors(n) function"

  // When you finish, go for WHITE-RABBIT(12)
  return result;
}

void MyTask::do_the_maths(void)
{
  /* WHITE-RABBIT(8)
   * Now I give you two integers, n1 and n2
   * I promise they're NOT prime number.
   */
  uint64_t n1, n2;
  _M(n1, n2) = get_my_numbers();

  /* Do you know prime divisors?
   * That is to say, 5 is divisor of 45, since 45/5 is an integer 9,
   * and 5 is a prime number, which can only be divided by 1 and itself.
   * So 5 is prime divisor of 45.
   * Please find out all prime divisors of given integer, and return as a list.
   * HINT: We've used a lot of uint64_t integer. Any time you want to print them
   *       out for debugging, you have to use PRId64 by C/C++ standard, for example:
   *       printf("%" PRId64 "\n", t);
   * Now go for WHITE-RABBIT(9) to finish get_all_prime_divisors(n)
   */
  let_me_check_it(get_all_prime_divisors);

  uint64_t p1 = min(get_all_prime_divisors(n1));
  uint64_t p2 = min(get_all_prime_divisors(n2));
  sn_ = p1*p2;
  phi_ = (p1-1)*(p2-1);
  sk_ = get_exponent();
  pk_ = multiplicative_inverse();
}

int main(void)
{
  MyTask t(MY_NAME);
  t.run();
  
  return 0;
}
