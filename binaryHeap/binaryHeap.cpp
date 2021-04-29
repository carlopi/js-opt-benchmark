#include <cheerp/clientlib.h>
#include "ArrayTyped.h"
using namespace client;
struct [[cheerp::jsexport]] BinaryHeap
{
private:
ArrayTyped<Double__*>*  content;
ArrayTyped<Double__*>*& get_content() 
{
	return content;
}
double scoreFunction(Double__* node)
{
return (node)->getD();
}
public:

BinaryHeap()
{
}
void push(Double__* element)
{
(((this)->content)->push(element));
((this)->bubbleUp((((this)->get_content())->get_length())-((1*1.0))));
}
Double__* pop()
{
auto result{(this)->get_content()->operator[]((0*1.0))};
auto end{((this)->content)->pop()};
if ((((this)->get_content())->get_length())>((0*1.0)))
{
(((this)->get_content()->operator[]((0*1.0)))=(end));
((this)->sinkDown((0*1.0)));
}
return result;
}
Double__* peek()
{
return (this)->get_content()->operator[]((0*1.0));
}
void remove(Double__* node)
{
auto len{((this)->get_content())->get_length()};
for (auto i{(0*1.0)}; (i)<(len); i++)
{
if (((this)->get_content()->operator[](i))==(node))
{
auto end{((this)->content)->pop()};
if ((i)!=((len)-((1*1.0))))
{
(((this)->get_content()->operator[](i))=(end));
if (((this)->scoreFunction(end))<((this)->scoreFunction(node)))
((this)->bubbleUp(i));
else
((this)->sinkDown(i));
}
return ;
}
}
//This was a throw... 
}
double size()
{
return ((this)->get_content())->get_length();
}
void bubbleUp(double n)
{
auto element{(this)->get_content()->operator[](n)};
while ((n)>((0*1.0)))
{
auto parentN{((Math)->floor(((doSum(n, (1*1.0))))/((2*1.0))))-((1*1.0))}; auto parent{(this)->get_content()->operator[](parentN)};
if (((this)->scoreFunction(element))<((this)->scoreFunction(parent)))
{
(((this)->get_content()->operator[](parentN))=(element));
(((this)->get_content()->operator[](n))=(parent));
((n)=(parentN));
}
else
{
break;
}
}
}
void sinkDown(double n)
{
auto length{((this)->get_content())->get_length()}; auto element{(this)->get_content()->operator[](n)}; auto elemScore{(this)->scoreFunction(element)};
while (true)
{
auto child2N{((doSum(n, (1*1.0))))*((2*1.0))}; auto child1N{(child2N)-((1*1.0))};
Double__* swap{nullptr};
auto child1Score{0.0};
if ((child1N)<(length))
{
auto child1{(this)->get_content()->operator[](child1N)}; child1Score = (this)->scoreFunction(child1);
if ((child1Score)<(elemScore))
((swap)->getD()=(child1N));
}
if ((child2N)<(length))
{
auto child2{(this)->get_content()->operator[](child2N)}; auto child2Score{(this)->scoreFunction(child2)};
if ((child2Score)<(((swap)==(nullptr ) ? elemScore : child1Score)))
{
((swap)->getD()=(child2N));
}
}
if ((swap)!=(nullptr ))
{
(((this)->get_content()->operator[](n))=((this)->get_content()->operator[](swap->getD())));
(((this)->get_content()->operator[](swap->getD()))=(element));
((n)=(swap)->getD());
}
else
{
break;
}
}
}
};

