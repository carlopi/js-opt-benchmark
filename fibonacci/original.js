function fibonacci(num) {
    if (num <= 1)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

/////BENCHMARKING CODE
onmessage = function (e)
{
	postMessage(fibonacci(e.data[0]));
}
