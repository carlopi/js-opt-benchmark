"use strict";/*Compiled using Cheerp (R) by Leaning Technologies Ltd*/var i=Math.imul;var j=Math.fround;var oSlot=0;var nullArray=[null];var nullObj={d:nullArray,o:0};function g(h){var d=-0.,c=-0.,a=-0.,b=-0.;a=(+(h.length|0))+ -1;if(a>=0)while(1){if(a>=1){b=1;while(1){d=+h[0+~~(b+ -1)|0];c=+h[0+~~b|0];if(d>c){h[0+~~(b+ -1)|0]=c;h[0+~~b|0]=d;}b+=1;if(b<=a)continue;break;}}a+= -1;if(a>=0)continue;break;}}var sort=g;sort.promise=Promise.resolve();

/////BENCHMARKING CODE
onmessage = function (e)
{
	var X = [];
	var LEN = e.data[0];
	for (var i=0; i<LEN; i++)
	{
		X[i] = (i ^ 123412) * 1.3;
	}
	postMessage(sort(X));
}
