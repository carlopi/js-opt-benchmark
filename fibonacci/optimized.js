"use strict";/*Compiled using Cheerp (R) by Leaning Technologies Ltd*/var c=Math.imul;var d=Math.fround;var oSlot=0;var nullArray=[null];var nullObj={d:nullArray,o:0};function a(b){if(b<=1)return 1;return  +a(b+ -1)+ +a(b+ -2);}var fibonacci=a;fibonacci.promise=Promise.resolve();

/////BENCHMARKING CODE
onmessage = function (e)
{
	postMessage(fibonacci(e.data[0]));
}
