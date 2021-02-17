#include <iostream>
using std::string;
using std::endl;
using std::cout;


class Heli {
public:
  string Brand;
  string Pilot;
  int YearsService;

  Heli(string brand, string pilot, int yearsService) {
    Brand = brand;
    Pilot = pilot;
    YearsService = yearsService;
  }

  void HeliInfo() {
    cout << "This brand of heli is a " << Brand << " and the pilot is " << Pilot << endl;
    cout << "The number of years this heli has been in service is " << YearsService << endl;
  }

};

class RescueHeli : public Heli {
public:
  string Callsign;

  RescueHeli(string brand, string pilot, int yearsService, string callsign)
    :Heli(brand, pilot, yearsService)
  {
    Callsign = callsign;
  }

  void Rescue() {
    cout << Callsign << " is going on a rescue!" << endl;
  }
};



int main()
{
  Heli heli1 = Heli("Robinson", "Gary", 4);
  heli1.HeliInfo();

  RescueHeli rescueheli1 = RescueHeli("Apache", "Jeff", 5, "Eagle4");
  rescueheli1.Rescue();
}
