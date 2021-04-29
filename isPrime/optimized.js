"use strict";/*Compiled using Cheerp (R) by Leaning Technologies Ltd*/var i=Math.imul;var j=Math.fround;var oSlot=0;var nullArray=[null];var nullObj={d:nullArray,o:0};function g(h){var d=-0.,f=0,b=-0.,a=-0.,c=-0.;if(!(h>0))return 1;a=0;b=1;while(1){b+=1;d=+Math.sqrt(b);if(d>=2){f=~~b;c=2;while(1){if(((f|0)%(~~c|0)|0)!==0){c+=1;if(c<=d)continue;a+=1;}break;}}else{a+=1;}if(a<h)continue;break;}return b;}var prime=g;prime.promise=Promise.resolve();

/////BENCHMARKING CODE
onmessage = function (e)
{
	postMessage(prime(e.data[0]));
}
