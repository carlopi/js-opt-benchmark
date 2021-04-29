    function calculatePI(cycles) {
        var inside = 0;
        for (var i = 0; i < cycles; i++) {
            var x = Math.random() * 2 - 1;
            var y = Math.random() * 2 - 1;
            if ((x * x + y * y) < 1) {
                inside++;
            }
        }
        return 4.0 * inside / cycles;
    }

/////BENCHMARKING CODE
onmessage = function (e)
{
	postMessage(calculatePI(e.data[0]));
}
