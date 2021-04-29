#include <cheerp/clientlib.h>
#include "ArrayTyped.h"
using namespace client;
double a0{}; double a1{}; double a2{}; double a3{}; double b1{}; double b2{}; double left_corner{}; double right_corner{};
Float32Array* gaussCoef(double sigma)
{
if ((sigma)<((0.5*1.0)))
{
((sigma)=((0.5*1.0)));
}
auto a{((Math)->exp(((0.726*1.0))*((0.726*1.0))))/(sigma)}; auto g1{(Math)->exp(-a)}; auto g2{(Math)->exp((-(2*1.0))*(a))}; auto k{((((((1*1.0))-(g1)))*((((1*1.0))-(g1)))))/(((doSum((1*1.0), (((2*1.0))*(a))*(g1)))-(g2)))};
((a0)=(k));
((a1)=(((k)*(((a)-((1*1.0)))))*(g1)));
((a2)=(((k)*((doSum(a, (1*1.0)))))*(g1)));
((a3)=((-k)*(g2)));
((b1)=(((2*1.0))*(g1)));
((b2)=(-g2));
((left_corner)=(((doSum(a0, a1)))/(((((1*1.0))-(b1))-(b2)))));
((right_corner)=(((doSum(a2, a3)))/(((((1*1.0))-(b1))-(b2)))));
return new Float32Array(new ArrayTyped(a0, a1, a2, a3, b1, b2, left_corner, right_corner));
}
void convolveRGBA(Uint32Array* src, Uint32Array* out, Float32Array* line, Float32Array* coeff, double width, double height)
{
double rgba{};
double prev_src_r{}; double prev_src_g{}; double prev_src_b{}; double prev_src_a{};
double curr_src_r{}; double curr_src_g{}; double curr_src_b{}; double curr_src_a{};
double curr_out_r{}; double curr_out_g{}; double curr_out_b{}; double curr_out_a{};
double prev_out_r{}; double prev_out_g{}; double prev_out_b{}; double prev_out_a{};
double prev_prev_out_r{}; double prev_prev_out_g{}; double prev_prev_out_b{}; double prev_prev_out_a{};
double src_index{}; double out_index{}; double line_index{};
double i{}; double j{};
double coeff_a0{}; double coeff_a1{}; double coeff_b1{}; double coeff_b2{};
for ((i)=((0*1.0)); (i)<(height); i++)
{
((src_index)=((i)*(width)));
((out_index)=(i));
((line_index)=((0*1.0)));
((rgba)=(src->operator[](src_index)));
((prev_src_r)=((rgba)&((255*1.0))));
((prev_src_g)=((((rgba)>>((8*1.0))))&((255*1.0))));
((prev_src_b)=((((rgba)>>((16*1.0))))&((255*1.0))));
((prev_src_a)=((((rgba)>>((24*1.0))))&((255*1.0))));
((prev_prev_out_r)=((prev_src_r)*(coeff->operator[]((6*1.0)))));
((prev_prev_out_g)=((prev_src_g)*(coeff->operator[]((6*1.0)))));
((prev_prev_out_b)=((prev_src_b)*(coeff->operator[]((6*1.0)))));
((prev_prev_out_a)=((prev_src_a)*(coeff->operator[]((6*1.0)))));
((prev_out_r)=(prev_prev_out_r));
((prev_out_g)=(prev_prev_out_g));
((prev_out_b)=(prev_prev_out_b));
((prev_out_a)=(prev_prev_out_a));
((coeff_a0)=(coeff->operator[]((0*1.0))));
((coeff_a1)=(coeff->operator[]((1*1.0))));
((coeff_b1)=(coeff->operator[]((4*1.0))));
((coeff_b2)=(coeff->operator[]((5*1.0))));
for ((j)=((0*1.0)); (j)<(width); j++)
{
((rgba)=(src->operator[](src_index)));
((curr_src_r)=((rgba)&((255*1.0))));
((curr_src_g)=((((rgba)>>((8*1.0))))&((255*1.0))));
((curr_src_b)=((((rgba)>>((16*1.0))))&((255*1.0))));
((curr_src_a)=((((rgba)>>((24*1.0))))&((255*1.0))));
((curr_out_r)=(doSum(doSum(doSum((curr_src_r)*(coeff_a0), (prev_src_r)*(coeff_a1)), (prev_out_r)*(coeff_b1)), (prev_prev_out_r)*(coeff_b2))));
((curr_out_g)=(doSum(doSum(doSum((curr_src_g)*(coeff_a0), (prev_src_g)*(coeff_a1)), (prev_out_g)*(coeff_b1)), (prev_prev_out_g)*(coeff_b2))));
((curr_out_b)=(doSum(doSum(doSum((curr_src_b)*(coeff_a0), (prev_src_b)*(coeff_a1)), (prev_out_b)*(coeff_b1)), (prev_prev_out_b)*(coeff_b2))));
((curr_out_a)=(doSum(doSum(doSum((curr_src_a)*(coeff_a0), (prev_src_a)*(coeff_a1)), (prev_out_a)*(coeff_b1)), (prev_prev_out_a)*(coeff_b2))));
((prev_prev_out_r)=(prev_out_r));
((prev_prev_out_g)=(prev_out_g));
((prev_prev_out_b)=(prev_out_b));
((prev_prev_out_a)=(prev_out_a));
((prev_out_r)=(curr_out_r));
((prev_out_g)=(curr_out_g));
((prev_out_b)=(curr_out_b));
((prev_out_a)=(curr_out_a));
((prev_src_r)=(curr_src_r));
((prev_src_g)=(curr_src_g));
((prev_src_b)=(curr_src_b));
((prev_src_a)=(curr_src_a));
((line->operator[](line_index))=(prev_out_r));
((line->operator[](doSum(line_index, (1*1.0))))=(prev_out_g));
((line->operator[](doSum(line_index, (2*1.0))))=(prev_out_b));
((line->operator[](doSum(line_index, (3*1.0))))=(prev_out_a));
((line_index)+=((4*1.0)));
(src_index++);
}
(src_index--);
((line_index)-=((4*1.0)));
((out_index)+=((height)*(((width)-((1*1.0))))));
((rgba)=(src->operator[](src_index)));
((prev_src_r)=((rgba)&((255*1.0))));
((prev_src_g)=((((rgba)>>((8*1.0))))&((255*1.0))));
((prev_src_b)=((((rgba)>>((16*1.0))))&((255*1.0))));
((prev_src_a)=((((rgba)>>((24*1.0))))&((255*1.0))));
((prev_prev_out_r)=((prev_src_r)*(coeff->operator[]((7*1.0)))));
((prev_prev_out_g)=((prev_src_g)*(coeff->operator[]((7*1.0)))));
((prev_prev_out_b)=((prev_src_b)*(coeff->operator[]((7*1.0)))));
((prev_prev_out_a)=((prev_src_a)*(coeff->operator[]((7*1.0)))));
((prev_out_r)=(prev_prev_out_r));
((prev_out_g)=(prev_prev_out_g));
((prev_out_b)=(prev_prev_out_b));
((prev_out_a)=(prev_prev_out_a));
((curr_src_r)=(prev_src_r));
((curr_src_g)=(prev_src_g));
((curr_src_b)=(prev_src_b));
((curr_src_a)=(prev_src_a));
((coeff_a0)=(coeff->operator[]((2*1.0))));
((coeff_a1)=(coeff->operator[]((3*1.0))));
for ((j)=((width)-((1*1.0))); (j)>=((0*1.0)); j--)
{
((curr_out_r)=(doSum(doSum(doSum((curr_src_r)*(coeff_a0), (prev_src_r)*(coeff_a1)), (prev_out_r)*(coeff_b1)), (prev_prev_out_r)*(coeff_b2))));
((curr_out_g)=(doSum(doSum(doSum((curr_src_g)*(coeff_a0), (prev_src_g)*(coeff_a1)), (prev_out_g)*(coeff_b1)), (prev_prev_out_g)*(coeff_b2))));
((curr_out_b)=(doSum(doSum(doSum((curr_src_b)*(coeff_a0), (prev_src_b)*(coeff_a1)), (prev_out_b)*(coeff_b1)), (prev_prev_out_b)*(coeff_b2))));
((curr_out_a)=(doSum(doSum(doSum((curr_src_a)*(coeff_a0), (prev_src_a)*(coeff_a1)), (prev_out_a)*(coeff_b1)), (prev_prev_out_a)*(coeff_b2))));
((prev_prev_out_r)=(prev_out_r));
((prev_prev_out_g)=(prev_out_g));
((prev_prev_out_b)=(prev_out_b));
((prev_prev_out_a)=(prev_out_a));
((prev_out_r)=(curr_out_r));
((prev_out_g)=(curr_out_g));
((prev_out_b)=(curr_out_b));
((prev_out_a)=(curr_out_a));
((prev_src_r)=(curr_src_r));
((prev_src_g)=(curr_src_g));
((prev_src_b)=(curr_src_b));
((prev_src_a)=(curr_src_a));
((rgba)=(src->operator[](src_index)));
((curr_src_r)=((rgba)&((255*1.0))));
((curr_src_g)=((((rgba)>>((8*1.0))))&((255*1.0))));
((curr_src_b)=((((rgba)>>((16*1.0))))&((255*1.0))));
((curr_src_a)=((((rgba)>>((24*1.0))))&((255*1.0))));
((rgba)=(doSum(doSum(doSum((((doSum(line->operator[](line_index), prev_out_r)))<<((0*1.0))), (((doSum(line->operator[](doSum(line_index, (1*1.0))), prev_out_g)))<<((8*1.0)))), (((doSum(line->operator[](doSum(line_index, (2*1.0))), prev_out_b)))<<((16*1.0)))), (((doSum(line->operator[](doSum(line_index, (3*1.0))), prev_out_a)))<<((24*1.0))))));
((out->operator[](out_index))=(rgba));
(src_index--);
((line_index)-=((4*1.0)));
((out_index)-=(height));
}
}
}
[[cheerp::jsexport]] Uint8ClampedArray* blurRGBA(Uint8ClampedArray* src, double width, double height, double radius)
{
if (!radius)
{
return ;
}
auto src32{new Uint32Array((src)->get_buffer())};
auto out{new Uint32Array((src32)->get_length())}; auto tmp_line{new Float32Array(((Math)->max(width, height))*((4*1.0)))};
auto coeff{gaussCoef(radius)};
(convolveRGBA(src32, out, tmp_line, coeff, width, height));
(convolveRGBA(out, src32, tmp_line, coeff, height, width));
}

