"use strict";/*Compiled using Cheerp (R) by Leaning Technologies Ltd*/var B=Math.imul;var C=Math.fround;var oSlot=0;var nullArray=[null];var nullObj={d:nullArray,o:0};function w(){var n=0,l=-0.,k=-0.,h=-0.,d=-0.,a=null,b=-0.,g=-0.,j=-0.,f=null;n=e.length;if((n|0)<=0)return 0;l=(+(n|0));d=0;h=0;while(1){a=e;a=a[0+~~h|0];b=+a.d3;g=+a.d4;j=+a.d5;d+=( +a.d6*.5*(b*b+g*g+j*j));h+=1;if(!(h<l))return d;b=h;while(1){f=e;f=f[0+~~b|0];g= +a.d0- +f.d0;j= +a.d1- +f.d1;k= +a.d2- +f.d2;g=+Math.sqrt(g*g+j*j+k*k);d-=( +a.d6* +f.d6/g);b+=1;if(b<l)continue;break;}continue;}}function x(A){var s=0,r=-0.,l=-0.,k=-0.,j=-0.,h=-0.,b=null,c=0,f=-0.,a=null,g=-0.,q=-0.,p=-0.,n=-0.,d=-0.;s=e.length;if((s|0)>0){b=e;r=(+(s|0));if((s|0)===1){c=0;b=b;}else{b=b[0];f=1;while(1){g=f;q=+b.d5;p=+b.d3;n=+b.d4;while(1){a=e;a=a[0+~~g|0];l= +b.d0- +a.d0;k= +b.d1- +a.d1;j= +b.d2- +a.d2;d=l*l+k*k+j*j;h=A/( +Math.sqrt(d)*d);d=+a.d6;p-=(l*d*h);n-=(k*d*h);q-=(j*d*h);d=+b.d6;a.d3= +a.d3+h*(l*d);a.d4=h*(k*d)+ +a.d4;a.d5=h*(j*d)+ +a.d5;g+=1;if(g<r)continue;break;}b.d3=p;b.d4=n;b.d5=q;b=e;g=f+1;if(g<r){b=b[0+~~f|0];f=g;continue;}c=0;b=b;break;}}f=0;while(1){a=b[c+~~f|0];a.d0= +a.d0+ +a.d3*A;a.d1= +a.d1+ +a.d4*A;a.d2= +a.d2+ +a.d5*A;f+=1;if(f<r)continue;break;}}}function y(){var k=0,l=-0.,h=null,j=-0.,a=null,g=-0.,f=-0.,d=-0.,b=-0.;k=e.length;if((k|0)>0){a=e;l=(+(k|0));b=0;d=0;f=0;g=0;while(1){h=a[0+~~g|0];j=+h.d6;b+=(j* +h.d3);d+=(j* +h.d4);f+=(j* +h.d5);g+=1;if(g<l)continue;break;}}else{f=0;d=0;b=0;}a=e;a=a[0];a.d3=b/-39.478417604357432;a.d4=d/-39.478417604357432;a.d5=f/-39.478417604357432;}function z(){var a=null,b=null;e=new Array();a={d0:-0.,d1:-0.,d2:-0.,d3:-0.,d4:-0.,d5:-0.,d6:-0.};a.d0=0;a.d1=0;a.d2=0;a.d3=0;a.d4=0;a.d5=0;a.d6=39.478417604357432;b=e;b[0]=a;a={d0:-0.,d1:-0.,d2:-0.,d3:-0.,d4:-0.,d5:-0.,d6:-0.};a.d0=4.8414314424647209;a.d1=-1.1603200440274284;a.d2=-0.10362204447112311;a.d3=.606326392995832;a.d4=2.81198684491626;a.d5=-0.025218361659887629;a.d6=.037693674870389493;b=e;b[0+1|0]=a;a={d0:-0.,d1:-0.,d2:-0.,d3:-0.,d4:-0.,d5:-0.,d6:-0.};a.d0=8.34336671824458;a.d1=4.1247985641243048;a.d2=-0.40352341711432138;a.d3=-1.0107743461787924;a.d4=1.8256623712304119;a.d5=.0084157613765841535;a.d6=.011286326131968767;b=e;b[0+2|0]=a;a={d0:-0.,d1:-0.,d2:-0.,d3:-0.,d4:-0.,d5:-0.,d6:-0.};a.d0=12.894369562139131;a.d1=-15.111151401698631;a.d2=-0.22330757889265573;a.d3=1.0827910064415354;a.d4=.86871301816960822;a.d5=-0.010832637401363636;a.d6=.0017237240570597112;b=e;b[0+3|0]=a;a={d0:-0.,d1:-0.,d2:-0.,d3:-0.,d4:-0.,d5:-0.,d6:-0.};a.d0=15.379697114850917;a.d1=-25.919314609987964;a.d2=.17925877295037118;a.d3=.97909073224389798;a.d4=.59469899864767617;a.d5=-0.034755955504078104;a.d6=.0020336868699246304;b=e;b[0+4|0]=a;}var e=null;var advance=x;var energy=w;var initialize=z;var offsetMomentum=y;advance.promise=energy.promise=initialize.promise=offsetMomentum.promise=Promise.resolve();

/////BENCHMARKING CODE
onmessage = function (e)
{
	const n = e.data[0];
	initialize();
	offsetMomentum();
	for (let i=0; i < n; i++)
	{
    		advance(0.01);
	}
	postMessage(energy());
}
