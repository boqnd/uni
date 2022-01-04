#include <iostream>
#include <string>
#include <vector>

class Question {
protected:
  std::string question;
  std::string answer;
  unsigned int points;

public:
  virtual void print(std::ostream out) = 0;
  virtual void read(std::istream in) = 0;
  virtual unsigned ask() const = 0;
};

class ClosedQuestion : public Question {
private:
  std::vector<std::string> answers;
public:
  ClosedQuestion(std::string _question, std::vector<std::string> _answers, std::string _answer, unsigned int _points) {
    this->question = _question;
    this->answers = _answers;
    this->answer = _answer;
    this->points = _points;
  }

  void print(std::ostream out) {
    out << "closedQuestion \"";
    out << this->question << "\" ";
    out << this->answers.size() << " ";
    for (size_t i = 0; i < this->answers.size(); i++)
    {
      out << "\"" << this->answers[i] << "\" ";
    }
    out << "\"" << answer << "\" ";
    out << points << std::endl;
  }

  void read(std::istream in) {
    // TODO not working for sentances
    std::string type;
    in >> type;
    if (type == "closedQuestion")
    {
      in >> this->question;
      int n;
      in >> n;

      for (size_t i = 0; i < n; i++)
      {
        std::string possibleAnswer;
        in >> possibleAnswer;
        this->answers.push_back(possibleAnswer);
      }
      
      std::string correctAnswer;
      in >> correctAnswer;
      this->answer = correctAnswer;
      in >> this->points;
    }
  }

  unsigned ask() const {
    std::cout << this->question << std::endl;
    std::cout << "answers:" << std::endl;
    for (size_t i = 0; i < this->answers.size(); i++)
    {
      std::cout << this->answers[i] << std::endl;
    }

    std::string userAnswer;
    std::getline(std::cin, userAnswer);
    
    if(userAnswer == answer) {
      return this->points;
    }else {
      return 0;
    }
  }
};

class OpenQuestion : public Question {
public:
  OpenQuestion(std::string _question, std::string _answer, unsigned int _points) {
    this->question = _question;
    this->answer = _answer;
    this->points = _points;
  }

  void print(std::ostream out) {
    out << "openQuestion \"";
    out << this->question << "\" ";
    out << "\"" << answer << "\" ";
    out << this->points << std::endl;
  }

  void read(std::istream in) {
    // TODO not working for sentances
    std::string type;
    in >> type;
    if (type == "openQuestion")
    {
      in >> this->question;
      in >> this->answer;
      in >> this->points;
    }
  }

  unsigned ask() const {
    std::cout << this->question << std::endl;
    
    std::string userAnswer;
    std::getline(std::cin, userAnswer);
    
    if(userAnswer == answer) {
      return this->points;
    }else {
      return 0;
    }
  }
};

class Test {
private:
  std::vector<Question*> questions;
public:
  void read(std::istream in) {
    // while (!in.eof())
    // {
    //   Question* current;
    //   current->read(in);
    //   questions.push_back(current);
    // }
  }

  void ask() {
    unsigned int result = 0;
    for (size_t i = 0; i < this->questions.size(); i++)
    {
      result += this->questions[i]->ask();
    }
    std::cout << "all points: " << result << std::endl;
  }

  void write(std::ostream out) {
    for (size_t i = 0; i < this->questions.size(); i++)
    {
      // //not working?
      // this->questions[i]->print(out);
    }
  }
};

class WorkItem {
public:
  virtual bool status(long now) = 0;
  std::string name;
};

class SingleTask : public WorkItem {
private:
  long start; 
  long duration;

public:
  SingleTask(std::string _name, long _start, long _duration) {
    this->name = _name;
    this->start = _start;
    this->duration = _duration;
  }

  bool status(long now) {
    if(now >= this->start + this->duration) {
      return true;
    } else {
      return false;
    }
  }
};

class TaskGroup : public WorkItem {
private:
  std::vector<WorkItem*> tasks;

public:
  TaskGroup(std::string _name) {
    this->name = _name;
  }

  void addTask(WorkItem* task) {
    this->tasks.push_back(task);
  }

  bool status(long now) {
    for (size_t i = 0; i < this->tasks.size(); i++)
    {
      if (!this->tasks[i]->status(now))
      {
        return false;
      }
    }
    return true;
  }

  void print() {
    for (size_t i = 0; i < this->tasks.size(); i++)
    {
      std::cout << this->tasks[i]->name;
    }
  }
};

bool allDone(std::vector<WorkItem*> tasks, long now) {
  for (size_t i = 0; i < tasks.size(); i++)
  {
    if (!tasks[i]->status(now))
    {
      return false;
    }
  }
  return true;
}

int main() {
  std::string q = "two plus two equals?";
  std::string a1 = "four";
  std::string a2 = "five";
  std::vector<std::string> as;
  as.push_back(a1);
  as.push_back(a2);

  ClosedQuestion cq(q,as,a1,2);
  std::cout << cq.ask() << std::endl;

  OpenQuestion oq(q,a1,5);
  std::cout << oq.ask() << std::endl;

  
  
  std::string n1 = "name1";
  std::string n2 = "name2";
  std::string n3 = "name3";


  SingleTask s(n1, 1621425050, 10);
  std::cout << s.status(1621425060) << std::endl;
  SingleTask ss(n2, 1621425050, 20);
  std::cout << ss.status(1621425060) << std::endl;

  TaskGroup tg(n3);

  tg.addTask(&s);
  tg.addTask(&ss);

  std::cout << tg.status(1621425060) << std::endl;



  return 0;
}