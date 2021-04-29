"use strict";
function sort(arr) {
    var len = arr.length;
    for (var i = len - 1; i >= 0; i--) {
        for (var j = 1; j <= i; j++) {
            if (arr[j - 1] > arr[j]) {
                var temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

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
