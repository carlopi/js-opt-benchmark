function isPrime(p:number):boolean {
    const upper = Math.sqrt(p);
    for(let i = 2; i <= upper; i++) {
        if (p % i === 0 ) {
            return false;
        }
    }
    return true;
}

// Return n-th prime
export function prime(n:number) :number {
    if (n < 1) {
        throw Error("n too small: " + n);
    }
    let count = 0;
    let result = 1;
    while(count < n) {
        result++;        
        if (isPrime(result)) {
            count++;
        }
    }
    return result;
}
