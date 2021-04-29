"use strict";/*Compiled using Cheerp (R) by Leaning Technologies Ltd*/var h=Math.imul;var i=Math.fround;var oSlot=0;var nullArray=[null];var nullObj={d:nullArray,o:0};function f(g){var e=-0.,c=-0.,a=-0.,b=-0.;if(!(g>0))return 0*4/g;a=0;c=0;while(1){b=+Math.random();b=b*2+ -1;e= +Math.random()*2+ -1;if(b*b+e*e<1){a+=1;}c+=1;if(c<g)continue;break;}return a*4/g;}var calculatePI=f;calculatePI.promise=Promise.resolve();

/////BENCHMARKING CODE
onmessage = function (e)
{
	postMessage(calculatePI(e.data[0]));
}
