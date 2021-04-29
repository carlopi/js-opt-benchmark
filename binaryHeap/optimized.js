"use strict";/*Compiled using Cheerp (R) by Leaning Technologies Ltd*/var D=Math.imul;var E=Math.fround;var oSlot=0;var nullArray=[null];var nullObj={d:nullArray,o:0};function n(l,k){var r=-0.,j=-0.,q=-0.,p=-0.,g=0,i=null,a=-0.,d=-0.,e=null,c=-0.;g=l.a0.length;i=l.a0;i=i[0+~~k|0];r=+i;j=(+(g|0));q=k;while(1){a=(q+1)*2;d=a+ -1;a:{b:{if(d<j){e=l.a0;c=+e[0+~~d|0];if(c<r){if(a<j){g=0;break b;}a=d;break a;}}else{c=0;}if(!(a<j))break;d=0;g=1;}e=l.a0;p=+e[0+~~a|0];if(g){if(!(p<r))break;}else{a=p<c?a:d;}}e=l.a0;g=~~a;e[0+~~q|0]=e[0+g|0];e=l.a0;e[0+g|0]=i;q=a;continue;}}function o(g,e){var k=-0.,j=0,l=-0.,d=null,a=-0.,c=null,i=null;d=g.a0;d=d[0+~~e|0];if(e>0){k=e;while(1){a=+Math.floor((k+1)*.5);c=g.a0;a+= -1;j=~~a;c=c[0+j|0];l=+d;if(l< +c){i=g.a0;i[0+j|0]=d;i=g.a0;i[0+~~k|0]=c;if(a>0){k=a;continue;}}break;}}}function z(a){return (+(a.a0.length|0));}function y(j,i){var g=null,c=0,e=null,d=-0.,a=-0.;c=j.a0.length;if((c|0)>0){e=j.a0;d=(+(c|0));a=0;while(1){c=~~a;if(e[0+c|0]===i){e=e.pop();if(!(a===d+ -1)){g=j.a0;g[0+c|0]=e;d=+e;if(d< +i)o(j,a);else n(j,a);}}else{a+=1;if(a<d)continue;}break;}}}function C(c){var a=null;a=c.a0;return a[0];}function B(e){var d=null,c=null,a=null;a=e.a0;d=a[0];a=a.pop();if((e.a0.length|0)>0){c=e.a0;c[0]=a;n(e,0);}return d;}function A(d,c){var a=null;a=d.a0;a.push(c);o(d,(+(d.a0.length|0))+ -1);}function x(a){a.a0=new Array();}function BinaryHeap(){this.a0=null;;this.d=[this];if (arguments.length===1&&arguments[0]===undefined){return;}x(this);};BinaryHeap.prototype.push=function (a0){return A(this,a0);};BinaryHeap.prototype.pop=function (){return B(this);};BinaryHeap.prototype.peek=function (){return C(this);};BinaryHeap.prototype.remove=function (a0){return y(this,a0);};BinaryHeap.prototype.size=function (){return z(this);};BinaryHeap.prototype.bubbleUp=function (a0){return o(this,a0);};BinaryHeap.prototype.sinkDown=function (a0){return n(this,a0);};BinaryHeap.promise=Promise.resolve();

/////BENCHMARKING CODE
onmessage = function (e)
{
    var LEN = e.data[0];
    const heap = new BinaryHeap();
    for (let i = 0; i < LEN; i++) {
      heap.push(Math.random());
    }
    let last = Number.NEGATIVE_INFINITY;
    let current;
    while (heap.size() > 0) {
      if (current < last) {
        throw Error("Invalid ordering!");
      }
      last = current;
      current = heap.pop();
    }

    postMessage("Done");
}
