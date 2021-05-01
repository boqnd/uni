#include <fstream>
#include <iostream>
#include <string>
#include "Vector.cpp"

enum Format {AudioCD, SuperAudioCD, CD_MIDI, CD_ROM, VCD, SuperVideoCD, CD_i, CD_iReady};


class CD {
private:
  std::string manufacturer;
  double freeSpace;
  double allSpace;
  bool overwittenable;
  double price;
  Format format;

public:
  CD() {
    manufacturer = "";
    freeSpace = 0;
    allSpace = 0;
    overwittenable = false;
    price = 0;
    format = CD_ROM;
  }

  CD(std::string _manufacturer, double _allSpace, bool _overwittenable, double _price) {
    manufacturer = _manufacturer;
    freeSpace = _allSpace;
    allSpace = _allSpace;
    overwittenable = _overwittenable;
    price = _price;
    format = CD_ROM;
  }

  std::string getFormat() {
    switch (format)
    {
    case AudioCD:
      return "Audio CD";
    case SuperAudioCD:
      return "Super Audio CD";
    case CD_MIDI:
      return "CD-MIDI";
    case CD_ROM:
      return "CD-ROM";
    case VCD:
      return "VCD";
    case SuperVideoCD:
      return "Super Video CD";
    case CD_i:
      return "CD-i";
    case CD_iReady:
      return "CD-i ready";
    default:
      return "";
    }
  }

  void print() {
    std::ofstream output("CD.txt", std::fstream::app);

    output << "Manufacturer: " << manufacturer 
      << ", Free Space: " << freeSpace 
      << ", All Space: " << allSpace 
      << ", Overwittenable: " << std::boolalpha << overwittenable 
      << ", Price: " << price 
      << ", Format: " << getFormat()
      << std::endl;
    output.close();
  }
};

void getCDData() {
  std::ifstream input("CD.txt", std::ifstream::in);
  std::string row = "";

  while(!input.eof()) {
    std::getline(input, row);

    std::string _manufacturer = "";
    std::string _allSpace = "";
    bool _overwittenable;
    std::string _price = "";

    std::string key = "";
    std::string value = "";
    int index = 0;
    bool keyFlag = true;

    for(; index < row.size(); index++) {
      //std::cout << key << std::endl;
      if (keyFlag) {
        if(row[index] == ':') {
          index ++;
          keyFlag = false;
          continue;
        }
        key += row[index];
      } else {
        if(row[index] == ',') {
          index ++;

          if (key == "Manufacturer") {
              _manufacturer = value;
          } else if (key == "All Space") {
              _allSpace = value;
          } else if (key == "Overwittenable") {
            if (value == "true") {
              _overwittenable = true;
            } else {
              _overwittenable = false;
            }
          } else if (key == "Price") {
              _price = value;
          } else {
          }
          key = "";
          value = "";
          keyFlag = true;
          continue;
        }

        value += row[index];
      }
    }

    std::cout << "_manufacturer: " << _manufacturer << " " << "_allSpace: " << _allSpace << " " << "_overwittenable: " << _overwittenable << " " << "_price: " << _price << std::endl;
  }
  input.close(); 
}


int main() {
  CD cd1;
  CD cd2 ("CDcompany", 150, true, 2.50);
  cd1.print();
  cd2.print();
  getCDData();
  return 0;
}