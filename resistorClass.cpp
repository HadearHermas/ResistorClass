#include <iostream>
using namespace std;

class Resistor
{
  private:
      float res_value;
  public:
      Resistor(float val);
      Resistor();
      void print();
      float series(Resistor& R2);
      float parallel(Resistor& R2);
      float current(float volt);
};

Resistor::Resistor(float val): res_value(val)
   {}

Resistor::Resistor()
   {res_value=0;}

void Resistor::print()
    {
        cout<<res_value;
    }
float Resistor::series(Resistor& R1)
    {
        float s=this->res_value+R1.res_value;
        return s;
    }

float Resistor::parallel(Resistor& R1)
    {
        float s=this->res_value+R1.res_value;
        return (1/s);
    }

float Resistor::current(float volt)
    {
       float current =volt/(this->res_value);
       return current;
    }

float Resistor operator +(Resistor& R1)
    {
        float s=this->res_value+R1.res_value;
        return s;
    }

float Resistor operator *(Resistor& R1)
    {
        float s=this->res_value+R1.res_value;
        return (1/s);
    }


int main()
{
    Resistor r1(50);
    Resistor r2(20);
    Resistor r3(40);
    Resistor r4(20);
    Resistor r5(70);
    Resistor r6(20);

    /*Using series and parallel functions*/

    /*
    float s1=r3.series(r4);
    float s2=r5.series(r6);

    Resistor S1(s1);
    Resistor S2(s2);
    float r_total_1 = S1.parallel(S2);
    Resistor R_total_1(r_total_1);
    float r_total_2 = r1.series(R_total_1);
    Resistor R_total_2(r_total_2);
    float r_total= r2.series(R_total_2);
     Resistor R_total(r_total);
     float curr= R_total.current(120);
     cout<<curr;
     */

    /*Using + and * operators functions*/
    float s1=r3.series(r4);
    float s2=r5.series(r6);

    Resistor S1(s1);
    Resistor S2(s2);
    float r_total_1 = S1.parallel(S2);
    Resistor R_total_1(r_total_1);
    float r_total_2 = r1.series(R_total_1);
    Resistor R_total_2(r_total_2);
    float r_total= r2.series(R_total_2);
     Resistor R_total(r_total);
     float curr= R_total.current(120);
     cout<<curr;

    return 0;
}
