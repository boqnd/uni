function trippleAdd(a, b, c) {
  return a + b + c;
}

cTrippleAdd = curry(trippleAdd);

console.log(cTrippleAdd(1)(2)(3)); //6
console.log(cTrippleAdd(1, 2)(3)); //6
console.log(cTrippleAdd(1, 2, 3)); //6
console.log(cTrippleAdd(1)(2, 3)); //6

function curry(func) {
  let len = func.length;
  let args = [];

  return function a() {
    for (let i = 0; i < arguments.length; i++) {
      args.push(arguments[i]);
    }

    if (args.length < len) {
      return a;
    }

    let temp = args.slice();
    args = [];
    return func.apply(undefined, temp);
  }
}