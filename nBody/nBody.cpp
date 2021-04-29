#include <cheerp/clientlib.h>
#include "ArrayTyped.h"
using namespace client;
const auto PI{3.1415926535897932384626};
const auto SOLAR_MASS{(((4*1.0))*(PI))*(PI)};
const auto DAYS_PER_YEAR{(365.24*1.0)};
class [[cheerp::client_layout]] Body_
{
public: double x;
public: double y;
public: double z;
public: double vx;
public: double vy;
public: double vz;
public: double mass;
	double& get_x() {return x;}
	double& get_y() {return y;}
	double& get_z() {return z;}
	double& get_vx() {return vx;}
	double& get_vy() {return vy;}
	double& get_vz() {return vz;}
	double& get_mass() {return mass;}
public: Body_(double x, double y, double z, double vx, double vy, double vz, double mass)
{
(((this)->get_x())=(x));
(((this)->get_y())=(y));
(((this)->get_z())=(z));
(((this)->get_vx())=(vx));
(((this)->get_vy())=(vy));
(((this)->get_vz())=(vz));
(((this)->get_mass())=(mass));
}
};
Body_* Jupiter()
{
return new Body_((4.841431442464721*1.0), -(1.1603200440274284*1.0), -(0.10362204447112311*1.0), ((0.001660076642744037*1.0))*(DAYS_PER_YEAR), ((0.007699011184197404*1.0))*(DAYS_PER_YEAR), (-(0.0000690460016972063*1.0))*(DAYS_PER_YEAR), ((0.0009547919384243266*1.0))*(SOLAR_MASS));
}
Body_* Saturn()
{
return new Body_((8.34336671824458*1.0), (4.124798564124305*1.0), -(0.4035234171143214*1.0), (-(0.002767425107268624*1.0))*(DAYS_PER_YEAR), ((0.004998528012349172*1.0))*(DAYS_PER_YEAR), ((0.000023041729757376393*1.0))*(DAYS_PER_YEAR), ((0.0002858859806661308*1.0))*(SOLAR_MASS));
}
Body_* Uranus()
{
return new Body_((12.894369562139131*1.0), -(15.111151401698631*1.0), -(0.22330757889265573*1.0), ((0.002964601375647616*1.0))*(DAYS_PER_YEAR), ((0.0023784717395948095*1.0))*(DAYS_PER_YEAR), (-(0.000029658956854023756*1.0))*(DAYS_PER_YEAR), ((0.00004366244043351563*1.0))*(SOLAR_MASS));
}
Body_* Neptune()
{
return new Body_((15.379697114850917*1.0), -(25.919314609987964*1.0), (0.17925877295037118*1.0), ((0.0026806777249038932*1.0))*(DAYS_PER_YEAR), ((0.001628241700382423*1.0))*(DAYS_PER_YEAR), (-(0.00009515922545197159*1.0))*(DAYS_PER_YEAR), ((0.000051513890204661145*1.0))*(SOLAR_MASS));
}
Body_* Sun()
{
return new Body_((0*1.0), (0*1.0), (0*1.0), (0*1.0), (0*1.0), (0*1.0), SOLAR_MASS);
}
ArrayTyped<Body_*>* bodies;
[[cheerp::jsexport]] void initialize()
{
bodies = new ArrayTyped<Body_*>();
bodies->operator[](0) = Sun();
bodies->operator[](1) = Jupiter();
bodies->operator[](2) = Saturn();
bodies->operator[](3) = Uranus();
bodies->operator[](4) = Neptune();
}
[[cheerp::jsexport]] void offsetMomentum()
{
auto px{(0*1.0)};
auto py{(0*1.0)};
auto pz{(0*1.0)};
auto size{(bodies)->get_length()};
for (auto i{(0*1.0)}; (i)<(size); i++)
{
auto body{bodies->operator[](i)};
auto mass{(body)->get_mass()};
(doSumEqual(px, ((body)->get_vx())*(mass)));
(doSumEqual(py, ((body)->get_vy())*(mass)));
(doSumEqual(pz, ((body)->get_vz())*(mass)));
}
auto body{bodies->operator[]((0*1.0))};
(((body)->get_vx())=((-px)/(SOLAR_MASS)));
(((body)->get_vy())=((-py)/(SOLAR_MASS)));
(((body)->get_vz())=((-pz)/(SOLAR_MASS)));
}
[[cheerp::jsexport]] void advance(double dt)
{
auto size{(bodies)->get_length()};
for (auto i{(0*1.0)}; (i)<(size); i++)
{
auto bodyi{bodies->operator[](i)};
auto vxi{(bodyi)->get_vx()};
auto vyi{(bodyi)->get_vy()};
auto vzi{(bodyi)->get_vz()};
for (auto j{doSum(i, (1*1.0))}; (j)<(size); j++)
{
auto bodyj{bodies->operator[](j)};
auto dx{((bodyi)->get_x())-((bodyj)->get_x())};
auto dy{((bodyi)->get_y())-((bodyj)->get_y())};
auto dz{((bodyi)->get_z())-((bodyj)->get_z())};
auto d2{doSum(doSum((dx)*(dx), (dy)*(dy)), (dz)*(dz))};
auto mag{(dt)/(((d2)*((Math)->sqrt(d2))))};
auto massj{(bodyj)->get_mass()};
((vxi)-=(((dx)*(massj))*(mag)));
((vyi)-=(((dy)*(massj))*(mag)));
((vzi)-=(((dz)*(massj))*(mag)));
auto massi{(bodyi)->get_mass()};
(doSumEqual((bodyj)->get_vx(), ((dx)*(massi))*(mag)));
(doSumEqual((bodyj)->get_vy(), ((dy)*(massi))*(mag)));
(doSumEqual((bodyj)->get_vz(), ((dz)*(massi))*(mag)));
}
(((bodyi)->get_vx())=(vxi));
(((bodyi)->get_vy())=(vyi));
(((bodyi)->get_vz())=(vzi));
}
for (auto i{(0*1.0)}; (i)<(size); i++)
{
auto body{bodies->operator[](i)};
(doSumEqual((body)->get_x(), (dt)*((body)->get_vx())));
(doSumEqual((body)->get_y(), (dt)*((body)->get_vy())));
(doSumEqual((body)->get_z(), (dt)*((body)->get_vz())));
}
}
[[cheerp::jsexport]] double energy()
{
auto e{(0*1.0)};
auto size{(bodies)->get_length()};
for (auto i{(0*1.0)}; (i)<(size); i++)
{
auto bodyi{bodies->operator[](i)};
(doSumEqual(e, (((0.5*1.0))*((bodyi)->get_mass()))*((doSum(doSum(((bodyi)->get_vx())*((bodyi)->get_vx()), ((bodyi)->get_vy())*((bodyi)->get_vy())), ((bodyi)->get_vz())*((bodyi)->get_vz()))))));
for (auto j{doSum(i, (1*1.0))}; (j)<(size); j++)
{
auto bodyj{bodies->operator[](j)};
auto dx{((bodyi)->get_x())-((bodyj)->get_x())};
auto dy{((bodyi)->get_y())-((bodyj)->get_y())};
auto dz{((bodyi)->get_z())-((bodyj)->get_z())};
auto distance{(Math)->sqrt(doSum(doSum((dx)*(dx), (dy)*(dy)), (dz)*(dz)))};
((e)-=(((((bodyi)->get_mass())*((bodyj)->get_mass())))/(distance)));
}
}
return e;
}

