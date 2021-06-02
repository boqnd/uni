#include "../../include/controller.h"

class Controller{
public:
  Vector<Discipline*> disciplines;
  Vector<Program*> programs;
  Vector<Student*> students;
  Vector<Record*> records;
  char* fileName;

public:
  Controller() :fileName(nullptr) {}
  ~Controller() { fileName = nullptr; }

  void load() {
    if (this->fileName != nullptr) {
      std::ifstream in(this->fileName);

      while (!in.eof()){
        String type;
        in >> type;

        if (type == "Discipline") {
          Discipline d;
          String _name, _required, _year;
          in >> _name >> _required >> _year;

          d.setName(_name);
          if (_required == "0") {
            d.setRequired(false);
          } else if (_required == "1") {
            d.setRequired(true);
          } else {
            throw std::invalid_argument( "received non-bool value from file" );
          }

          d.setYear(_year.parseInt());

          bool disciplineFound = false;
          for (size_t i = 0; i < this->disciplines.getSize(); i++)
          {
            if (_name == this->disciplines[i]->getName()) {
              disciplineFound = true;

              std::cout << std::endl << "WARNING: duplicating discipline names found in the file. Only the first will be saved." << std::endl << std::endl;

              break;
            }
          }

          if (!disciplineFound) {
            this->disciplines.push_back(new Discipline(d));
          }
        } else if (type == "Program") {
          Program p;
          String _name, _count;
          in >> _name >> _count;
          
          p.setName(_name);

          for (size_t i = 0; i < _count.parseInt(); i++)
          {
            String currentDiscipline;
            in >> currentDiscipline;

            bool disciplineFound = false;
            for (size_t d = 0; d < this->disciplines.getSize(); d++)
            {
              if(currentDiscipline == this->disciplines[d]->getName()) {
                bool duplicateDiscipline = false;
                for (size_t pd = 0; pd < p.getDisciplines().getSize(); pd++)
                {
                  if (currentDiscipline == p.getDisciplines()[pd]->getName()) {
                    duplicateDiscipline = true;
                    std::cout << std::endl << "WARNING: duplicating disciplines in the same program found in the file. Only one will be saved." << std::endl << std::endl;

                    break;
                  }
                  
                }
                
                if (!duplicateDiscipline) {
                  p.addDiscipline(this->disciplines[d]);
                }

                disciplineFound = true;
              }
            }

            if (!disciplineFound) {
              throw std::invalid_argument( "received non-existing discipline name from file" );
            }
          }

          bool programFound = false;
          for (size_t i = 0; i < this->programs.getSize(); i++)
          {
            if (_name == this->programs[i]->getName()) {
              programFound = true;

              std::cout << std::endl << "WARNING: duplicating program names found in the file. Only the first will be saved." << std::endl << std::endl;

              break;
            }
          }

          if (!programFound) {
            this->programs.push_back(new Program(p));
          }
        } else if (type == "Student") {
          String _name, _fn, _program, _group, _year, _status, _averageGrade;
          Student s;
      
          in >> _name >> _fn >> _program >> _group >> _year >> _status >> _averageGrade;

          s.setName(_name);
          s.setFn(_fn.parseInt());
          s.setGroup(_group.parseInt());
          s.setYear(_year.parseInt());
          s.setStatus((Status)_status.parseInt());
          s.setAverageGrade(_averageGrade.parseInt());

          bool programFound = false;
          for (size_t p = 0; p < this->programs.getSize(); p++)
          {
            if(_program == this->programs[p]->getName()) {
              programFound = true;
              s.setProgram(this->programs[p]);
              break;
            }
          }

          if (!programFound) {
            throw std::invalid_argument( "received non-existing program name from file" );
          }

          bool studentFound = false;
          for (size_t i = 0; i < this->students.getSize(); i++)
          {
            if(_name == this->students[i]->getName()) {
              studentFound = true;

              std::cout << std::endl << "WARNING: duplicating student names found in the file. Only the first will be saved." << std::endl << std::endl;

              break;
            }
          }

          if (!studentFound) {
            this->students.push_back(new Student(s));
          }
        } else if (type == "Record") {

          String _studentFn, _discipline, _grade;
          Record r;
      
          in >> _studentFn >> _discipline >> _grade;

          bool studentFound = false;
          for (size_t s = 0; s < this->students.getSize(); s++)
          {
            if(_studentFn.parseInt() == this->students[s]->getFn()) {
              studentFound = true;
              r.setStudent(this->students[s]);
              break;
            }
          }

          if (!studentFound) {
            throw std::invalid_argument( "received non-existing student fn from file" );
          }

          bool disciplineFound = false;
          for (size_t d = 0; d < this->disciplines.getSize(); d++)
          {
            if(_discipline == this->disciplines[d]->getName()) {
              disciplineFound = true;
              r.setDiscipline(this->disciplines[d]);
              break;
            }
          }

          if (!disciplineFound) {
            throw std::invalid_argument( "received non-existing discipline name from file" );
          }

          r.setGrade(_grade.parseDouble());

          records.push_back(new Record(r));
        }
      }
      
      in.close();
    }
  }

  void open(char* _fileName) {
    if (_fileName != nullptr) {
      this->fileName = new char[strlen(_fileName)];
      strcpy(this->fileName, _fileName);
    }
  }

  void close() {
    this->fileName = nullptr;
    records.destroy();
    students.destroy();
    programs.destroy();
    disciplines.destroy();
  }

  void save() {
    if (this->fileName != nullptr) {
      std::ofstream out (fileName);
      out.close();

      for (size_t i = 0; i < disciplines.getSize(); i++) {
        disciplines[i]->saveToFile(fileName);
      }
      for (size_t i = 0; i < programs.getSize(); i++) {
        programs[i]->saveToFile(fileName);
      }
      for (size_t i = 0; i < students.getSize(); i++) {
        students[i]->saveToFile(fileName);
      }
      for (size_t i = 0; i < records.getSize(); i++) {
        records[i]->saveToFile(fileName);
      }
    }
  }

  void saveAs(char* _fileName) {
    if (_fileName != nullptr) {
      this->open(_fileName);
      this->save();
    }
  }

  String readCommand() {
    char command[1024];

    std::cout << "command -> ";
    std::cin.getline(command, 1024);

    String result = command;

    return result;
  }

  void processCommand(String input) {
    Vector<String> words = input.split(' ');
    String command = ((words.getSize() > 0) ? (words[0]) : (""));

    if (command == "open") {
      if ((words.getSize() > 1)) {
        this->open(words[1].getData());
        this->load();
        std::cout << "Successfully opened " << words[1] << std::endl;
      } else {
        std::cout << "File failed to open" << std::endl;
      }
    } else if (command == "close") {   
      if ((words.getSize() > 0)) {
        if (this->fileName == nullptr) {
          std::cout << "No file is open" << std::endl;
        } else {
          std::cout << "Successfully closed " << this->fileName  << std::endl;
          this->close();
        }
      } else {
        std::cout << "File failed to close" << std::endl;
      }
    } else if (command == "save") {
      if ((words.getSize() > 0)) {
        if (this->fileName == nullptr) {
          std::cout << "No file is open" << std::endl;
        } else {
          this->save();
          std::cout << "Successfully saved " << this->fileName  << std::endl;
        }
      } else {
        std::cout << "File failed to save" << std::endl;
      }
    } else if (command == "saveas") {
      if ((words.getSize() > 1)) {
        this->saveAs(words[1].getData());
        std::cout << "Successfully saved " << words[1] << std::endl;
      } else {
        std::cout << "File failed to save" << std::endl;
      }
    } else if (command == "help") {
      std::cout << "The following commands are supported:" << std::endl;
      std::cout << "open <file>         opens <file>" << std::endl;
      std::cout << "close               closes currently opened file" << std::endl;
      std::cout << "save                saves the currently open file" << std::endl;
      std::cout << "saveas <file>       saves the currently open file in <file>" << std::endl;
      std::cout << "help                prints this information" << std::endl;
      std::cout << "exit                exists the program" << std::endl;
    } else if (command == "enroll") {
      try {
        if (this->fileName != nullptr) {
          if ((words.getSize() > 4)) {
            unsigned int _fn = words[1].parseInt();
            String _program = words[2];
            unsigned int _group = words[3].parseInt();
            String _name = words[4];

            bool validFn = true;
            int programIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                std::cout << "Student with fn " << _fn << " is already enrolled." << std::endl;
                validFn = false;
                break;
              }
            } 
            
            for (size_t j = 0; j < programs.getSize(); j++)
            {
              if (_program == programs[j]->getName())
              {
                programIndex = j;
                break;
              }
            }

            if(validFn) {  
              if (programIndex > -1)
              {
                Student newStud;
                newStud.setName(_name);
                newStud.enroll(_fn, programs[programIndex], _group);
                students.push_back(new Student(newStud));
                std::cout << "Successfully enrolled " << _name << std::endl;
              }else {
                std::cout << "No program with name " << _program << " was found" << std::endl;
              }
            }
          } else {
            std::cout << "Failed to enroll" << std::endl;
          }
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "advance") {
      try {
        if (this->fileName != nullptr) {
          if ((words.getSize() > 1)) {
            unsigned int _fn = words[1].parseInt();

            int studentIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                studentIndex = i;
                break;
              }
            }

            if (studentIndex > -1)
            {
              students[studentIndex]->advance();
              std::cout << "Successfully advanced " << students[studentIndex]->getName() << std::endl;
            } else {
              std::cout << "Student with fn " << _fn << " does not exist." << std::endl;
            }
          } else {
            std::cout << "Failed to advance" << std::endl;
          } 
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "change") {
      //todo
      std::cout << "----- not implemented -----" << std::endl;
    } else if (command == "graduate") {
      //todo
      try{
        if (this->fileName != nullptr) {
          if ((words.getSize() > 1)) {
            unsigned int _fn = words[1].parseInt();

            int studentIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                studentIndex = i;
                break;
              }
            }

            if (studentIndex > -1)
            {
              students[studentIndex]->graduate();
              std::cout << "Successfully graduated " << students[studentIndex]->getName() << std::endl;
            } else {
              std::cout << "Student with fn " << _fn << " does not exist." << std::endl;
            }
          } else {
            std::cout << "Failed to graduate." << std::endl;
          } 
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "interupt") {
      //todo
      try{
        if (this->fileName != nullptr) {
          if ((words.getSize() > 1)) {
            unsigned int _fn = words[1].parseInt();

            int studentIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                studentIndex = i;
                break;
              }
            }

            if (studentIndex > -1)
            {
              students[studentIndex]->interrupt();
              std::cout << "Successfully interrupted " << students[studentIndex]->getName() << std::endl;
            } else {
              std::cout << "Student with fn " << _fn << " does not exist." << std::endl;
            }
          } else {
            std::cout << "Failed to interrupt." << std::endl;
          } 
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "resume") {
      try{
        if (this->fileName != nullptr) {
          if ((words.getSize() > 1)) {
            unsigned int _fn = words[1].parseInt();

            int studentIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                studentIndex = i;
                break;
              }
            }

            if (studentIndex > -1)
            {
              students[studentIndex]->resume();
              std::cout << "Successfully resumed " << students[studentIndex]->getName() << std::endl;
            } else {
              std::cout << "Student with fn " << _fn << " does not exist." << std::endl;
            }
          } else {
            std::cout << "Failed to resume." << std::endl;
          } 
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "print") {
      try{
        if (this->fileName != nullptr) {
          if ((words.getSize() > 1)) {
            unsigned int _fn = words[1].parseInt();

            int studentIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                studentIndex = i;
                break;
              }
            }

            if (studentIndex > -1)
            {
              students[studentIndex]->print();
            } else {
              std::cout << "Student with fn " << _fn << " does not exist." << std::endl;
            }
          } else {
            std::cout << "Failed to print." << std::endl;
          } 
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "printall") {
      try{
        if (this->fileName != nullptr) {
          if ((words.getSize() > 2)) {
            String _program = words[1];
            unsigned int _year = words[2].parseInt();

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_program == students[i]->getProgram()->getName() && _year == students[i]->getYear())
              {
                students[i]->print();
              }
            }
          } else {
            std::cout << "Failed to print all." << std::endl;
          } 
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "enrollin") {
      try {
        if (this->fileName != nullptr) {
          if ((words.getSize() > 2)) {
            unsigned int _fn = words[1].parseInt();
            String _discipline = words[2];

            int studentIndex = -1;
            int disciplineIndex = -1;

            for (size_t i = 0; i < students.getSize(); i++)
            {
              if (_fn == students[i]->getFn())
              {
                studentIndex = i;
                break;
              }
            } 
            
            for (size_t j = 0; j < disciplines.getSize(); j++)
            {
              if (_discipline == disciplines[j]->getName())
              {
                disciplineIndex = j;
                break;
              }
            }

            if(studentIndex > -1) {  
              if (disciplineIndex > -1)
              {
                Record newRec;
                newRec.setDiscipline(disciplines[disciplineIndex]);
                newRec.setStudent(students[studentIndex]);
                records.push_back(new Record(newRec));
                std::cout << "Successfully enrolled " << students[studentIndex]->getName() << " in " << _discipline << std::endl;
              }else {
                std::cout << "No discipline with name " << _discipline << " was found." << std::endl;
              }
            } else {
              std::cout << "No student with fn " << _fn << " was found." << std::endl;
            }
          } else {
            std::cout << "Failed to enroll" << std::endl;
          }
        } else {
          std::cout << "No opened file." << std::endl;
        }
      } catch(const std::exception& e) {
        std::cout << std::endl << "|    <error>    |" << std::endl << std::endl;

        std::cout << "exception: " << e.what() << std::endl << std::endl;
      } 
    } else if (command == "addgrade") {
      std::cout << "----- not implemented -----" << std::endl;
    } else if (command == "protocol") {
      std::cout << "----- not implemented -----" << std::endl;
    } else if (command == "report") {
      std::cout << "----- not implemented -----" << std::endl;
    } else {
      std::cout << "----- not recognised -----" << std::endl;
    }
  }

  void start() {
    String command;
    do {
      command = readCommand();
      processCommand(command);
    } while (!(command == "exit"));
  }
};