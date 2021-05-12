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

  void open(char* _fileName) {
    if (_fileName != nullptr) {
      this->fileName = new char[strlen(_fileName)];
      strcpy(this->fileName, _fileName);
    }
  }

  void close() {
    this->fileName = nullptr;
  }

  void saveAs(char* _fileName) {
    if (_fileName != nullptr) {
      this->open(_fileName);
      this->save();
    }
  }
};