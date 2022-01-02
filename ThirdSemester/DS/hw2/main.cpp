#include "implementation.cpp"
#include "tree.cpp"
#include <fstream>

int main() {
  string command = "";
  string input = "";

  vector<Hierarchy*> trees;
  vector<string> names;

  while (true)
  {
    std::cout << ">> ";
    std::cin >> input;
    command = input.substr(0, input.find(" "));

    if (command == "help")
    {
      std::cout  << std::endl << "help" << std::endl;
      std::cout << "load" << std::endl;
      std::cout << "save" << std::endl;
      std::cout << "find" << std::endl;
      std::cout << "num_subordinates" << std::endl;
      std::cout << "manager" << std::endl;
      std::cout << "num_employees" << std::endl;
      std::cout << "overloaded" << std::endl;
      std::cout << "join" << std::endl;
      std::cout << "fire" << std::endl;
      std::cout << "hire" << std::endl;
      std::cout << "salary" << std::endl;
      std::cout << "incorporate" << std::endl;
      std::cout << "modernize" << std::endl;
      std::cout << "exit" << std::endl << std::endl;

    } else if (command == "load") {
      string filename;
      string name;

      std::cin >> name >> filename;

      std::ifstream MyReadFile(filename);

      string createH;
      string create;


      while (getline (MyReadFile, createH)) {
        create+=createH + "\n";
      }

      trees.push_back(new Hierarchy(create));
      names.push_back(name);

      std::cout << "file loaded" << std::endl;
    } else if (command == "save") {
      string filename;
      string name;

      std::cin >> name >> filename;

      std::ofstream MyFile(filename);

      int index = 0;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }
      

      MyFile << trees[index]->print();

      MyFile.close();
      std::cout << "file saved" << std::endl;
    } else if (command == "find") {

      string who;
      string name;

      std::cin >> name >> who;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }

      if (trees[index]->find(who))
      {
        std::cout<<"found" <<std::endl;
      } else {
        std::cout<<"not found" <<std::endl;
      }
    } else if (command == "num_subordinates") {
      
      string who;
      string name;

      std::cin >> name >> who;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }


        std::cout<<trees[index]->num_subordinates(who) <<std::endl;

    } else if (command == "manager") {
      string who;
      string name;

      std::cin >> name >> who;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }


      std::cout<<trees[index]->manager(who) <<std::endl;
    } else if (command == "num_employees") {
      string name;

      std::cin >> name;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }


      std::cout<<trees[index]->num_employees() <<std::endl;
    } else if (command == "overloaded") {
      string name;

      std::cin >> name;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }


      std::cout<<trees[index]->num_overloaded() <<std::endl;
    } else if (command == "join") {
      string name;
      string name2;
      string newName;


      std::cin >> name >> name2 >> newName;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }

      int index2 = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name2)
        {
          index2 = i;
          break;
        }
      }

      names.push_back(newName);
      trees.push_back(new Hierarchy(trees[index]->join(*trees[index2])));

      std::cout << "joined" <<std::endl;

    } else if (command == "fire") {
      string who;
      string name;

      std::cin >> name >> who;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }

      trees[index]->fire(who);


      std::cout<<"fired" <<std::endl;
    } else if (command == "hire") {
      string who;
      string name;
      string boss;


      std::cin >> name >> who >> boss;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }

      trees[index]->hire(who, boss);

      std::cout<<"hired" <<std::endl;
    } else if (command == "salary") {
      string who;
      string name;

      std::cin >> name >> who;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }


      std::cout<<trees[index]->getSalary(who) <<std::endl;
    } else if (command == "incorporate") {
      string name;

      std::cin >> name;

      int index = -1;

      for (size_t i = 0; i < names.size(); i++)
      {
        if (names[i] == name)
        {
          index = i;
          break;
        }
      }
      trees[index]->incorporate();

      std::cout<<"incorporated" <<std::endl;
    } else if (command == "modernize") {
          string name;

        std::cin >> name;

        int index = -1;

        for (size_t i = 0; i < names.size(); i++)
        {
          if (names[i] == name)
          {
            index = i;
            break;
          }
        }
        trees[index]->modernize();

        std::cout<<"modernized" <<std::endl;
    } else if (command == "exit") {
        std::cout<<"bye" <<std::endl;

      break;
    }
  }
  

  return 0;
}