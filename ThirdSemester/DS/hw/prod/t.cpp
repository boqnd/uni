#include <iostream>
#include <queue>
#include "queue.cpp"


struct Worker {
  int time;
 

  Worker(int time) : time(time) {}
};

int main() {
	// std::queue<Worker> busyWorkers;
  // busyWorkers.push(Worker(1));

  // std::cout << busyWorkers.front().time;

  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  while (!q.empty()) {
    std::cout << q.front() << std::endl;
    q.pop();
  }

}
