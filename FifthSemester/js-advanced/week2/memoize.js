var sum = function (x, y) { return x + y; }
var memSum = memoize(sum);

console.log(memSum(2,3)); // пресмята, връща 5
console.log(memSum(3,3)); // пресмята, връща 6
console.log(memSum(2,3)); // директно връща 5 без да смята

function memoize(func) {
  var cache = []

  return function() {
    let x = arguments[0];
    let y = arguments[1];

    for(let i = 0; i < cache.length; i++) {
      let elem = cache[i];
      if (elem.x === x && elem.y === y) {
        return elem.res;
      }
    }

    console.log("Calculating...");
    let res = func(arguments[0], arguments[1]);
    cache.push({ x, y, res });

    return res;
  }
}