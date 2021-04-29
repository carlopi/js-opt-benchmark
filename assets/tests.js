function runTestPromise (directory, N) {
  return new Promise(async function (resolve) {
	var suite = new Benchmark.Suite;
	var originalWorker = new Worker('./' + directory + '/original.js');
	var optimizedWorker = new Worker('./' + directory + '/optimized.js');

	function runWorkerPromise(worker, input, deferred)
	{
		return new Promise((res, rej) => {
			worker.onmessage = ({data}) => {
			deferred.resolve();
			res();
		};
	worker.postMessage(input);
		});
	}


	async function runWorker(worker, input, deferred)
	{
		return runWorkerPromise(worker, input, deferred);
	}

	// Standard Normal variate using Box-Muller transform.
	function randn_bm() {
		var u = 0, v = 0;
		while(u === 0) u = Math.random(); //Converting [0,1) to (0,1)
		while(v === 0) v = Math.random();
		return Math.sqrt( -2.0 * Math.log( u ) ) * Math.cos( 2.0 * Math.PI * v );
	}
	function getProbabilityIsBetter(A, B)
	{
		//This could have been done without Monte Carlo simulation...
		var c = 0;
		const N = 1e6;
		for (var i = 0; i<N; i++)
		{
			var a = A.mean + randn_bm() * A.deviation;
			var b = B.mean + randn_bm() * B.deviation;
			if (a > b)
				c++;
		}
		return c / N;
	}
	function get256(percentage)
	{
		var X = (percentage * 255.99) | 0;
		if (percentage >= 256)
			percentage = 255;
		if (percentage < 0)
			percentage = 0;
		var Y = "";
		const code = "0123456789abcdef";
		return code[(X/16) | 0] + code[(X%16)|0];
	}
	function getColor(percentage)
	{
		const lowColor = [1.0, 0.0, 0.0];
		const mediumColor = [1.0, 1.0, 0.0];
		const highColor = [0.0, 1.0, 0.0];

		var mixColor;
		if (percentage <= 0.5)
		{
			const a = percentage*2;
			const b = 1.0 - a;
			mixColor = [	lowColor[0] * b + mediumColor[0] * a,
					lowColor[1] * b + mediumColor[1] * a,
					lowColor[2] * b + mediumColor[2] * a];
		}
		else
		{
			const a = (percentage-0.5)*2;
			const b = 1.0 - a;
			mixColor = [	mediumColor[0] * b + highColor[0] * a,
					mediumColor[1] * b + highColor[1] * a,
					mediumColor[2] * b + highColor[2] * a];
		}

		return "#" + get256(mixColor[0]) + get256(mixColor[1]) + get256(mixColor[2]);
	}
	function addProgress(percentageA, percentageB)
	{
		document.body.innerHTML += '<span class="progress"><span style="width:' + (percentageA*100.0) + '%; background-color:' + getColor(percentageA) + '" class="optimal progress-item"></span></span>';
	}

	function runSuite(workerA, workerB, input)
	{
		  document.body.innerHTML += '<br>';
		document.body.innerHTML += '<h3>' + directory + ' <span class="disappear">⏳</span></h3>';
		return new Promise((resolve) =>
		{
		suite
		.add('original', {
			'defer': true,
			'fn': function(deferred) {
				runWorker(workerA, input, deferred);
				}
		})
		.add('optimized', {
			'defer': true,
			'fn': function(deferred) {
				runWorker(workerB, input, deferred);
				}
		})
		// add listeners
		.on('cycle', function(event) {
		  document.body.innerHTML += '<div>' + String(event.target) + '</div>';
		})
		.on('complete', function() {
			addProgress(getProbabilityIsBetter(this[0].stats, this[1].stats));
			resolve();
		})
		// run async
		.run({ 'async': true, 'maxTime' : 5 });
		});
	}

	async function callRunSuite(wA, wB, input)
	{
		return runSuite(wA, wB, input);
	}

	await callRunSuite(originalWorker, optimizedWorker, [N]);

	originalWorker.terminate();
	optimizedWorker.terminate();
	resolve();
  })
}

function doRunTestAsync (directory, N) {
  	console.log("Start executing " + directory);
	return runTestPromise(directory, N);
}

async function doAsync () {
  console.log("Welcome to the benchmarks for 'A JavaScript optimizing compiler'");
  await doRunTestAsync("blur", 1024);
  await doRunTestAsync("binaryHeap", 1000000);
  await doRunTestAsync("bubblesort", 15000);
  await doRunTestAsync("estimatePi", 5000000);
  await doRunTestAsync("fibonacci", 35);
  await doRunTestAsync("isPrime", 100000);
  await doRunTestAsync("nBody", 1000000);
  document.body.innerHTML += '<br>';
  document.body.innerHTML += '<h3>Benchmark completed!</h3>';
  console.log("Computations are done!");
}

doAsync();
