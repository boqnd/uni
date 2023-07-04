var addOne = (x) => x + 1;
var sqrt = (x) => x * x;
var log = (x) => console.log(x);

addOneSqrtAndPrint = compose(log, sqrt, addOne);

addOneSqrtAndPrint(1); // 4

function compose() {
  let args = [].slice.call(arguments)
  return function() {
    args.push(arguments[0]);
    args.reduceRight((acc, crr) => {
      return crr(acc);
    })
  }
}