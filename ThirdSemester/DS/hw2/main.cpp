#include "implementation.cpp"
#include "tree.cpp"

int main() {
  // Tree t;

  // node* n = new node("kur");
  
  // t.root=n;

  // t.root->addCild(new node("penis"));
  // t.root->addCild(new node("penis2"));
  // t.root->addCild(new node("penis3"));

  // t.root->children[1]->addCild(new node("krastavica"));
  // node* n1 = new node("kura");
  // t.getChild("krastavica")->addCild(n1);

  // std::cout << t.getChild("penis2")->value << std::endl;
  // std::cout << t.getLevel(n1) << std::endl;

  const std::string s = "Uspeshnia-Gosho\nUspeshnia-Misho\nUspeshnia-Slavi\nGosho-Dancho\nGosho-Pesho\nSlavi-Slav1\nSlavi-Slav2\nDancho-Boris\nDancho-Kamen\nPesho-Alex\nSlav1-Mecho\nMecho-Q12Adl\n";
  const std::string sa = "";

  Hierarchy ha(sa);
// ha.print();

  // std::cout << ha.getSalary("Uspeshnia") << std::endl;

  ha.incorporate();
  // for (size_t i = 0; i < ha.data.root->children.size(); i++)
  // {
  //   std::cout << ha.data.root->children[i]->value << std::endl;
  // }
  
  // std::cout << "ha.print()" << std::endl;

  std::cout << ha.print() << std::endl;

  // h.hire( "badjo", "Uspeshnia");

  // std::cout << h.data.getLevel(h.data.getChild("Q12Adl"));
  // std::cout << h.print() << std::endl;
  // std::cout << h.fire("Gosho") << std::endl;
  // std::cout << h.fire("Slav1") << std::endl;

  // const string loz_print = "Uspeshnia-MishoPetrov\nMishoPetrov-Misho\nMishoPetrov-Slav\n";
  // const string loz_new =
  //   " Uspeshnia   -  MishoPetrov \n"
  //   " MishoPetrov -  Misho       \n"
  //   " MishoPetrov -  Slav        \n";

  // Hierarchy h(loz_new);
  // h.hire("Ico_Petrov", "MishoPetrov");
  // h.hire("Ico_Petrov", "Misho");
  // std::cout << h.print() << std::endl;

  // std::cout << h.num_employees() << std::endl;

  // std::cout << h.longest_chain() << std::endl;

  // std::cout << h.num_overloaded(3) << std::endl;

  // std::cout << h.manager("Uspeshnia") << std::endl;
  // std::cout << h.getSalary("Uspeshnia") << std::endl;
  // h.incorporate();
  // std::cout << h.print() << std::endl;




  // std::cout << h.fire("Gosho") << std::endl;

  // std::cout << h.find("Gosho") << std::endl;

  // std::cout << std::endl;
  // std::cout << h.print();





  
  return 0;
}