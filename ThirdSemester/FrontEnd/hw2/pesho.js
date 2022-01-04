function processData(input) {
  var result = [0];
  input = eval(input);
  
  input.forEach(element => {
    switch (typeof element) {
      case (typeof 1):
        result[0]++
        break;
      case (typeof ""):
        result.push(element.split("").reverse().join(""))
        break;
      case (typeof {}):
        if (Array.isArray(element)) {
          if (JSON.stringify(element) == JSON.stringify(element.flat())) {
            result.push(element.sort())
          } else {
            while (JSON.stringify(element) != JSON.stringify(element.flat())) {
              element = element.flat()
            }
            result.push(element)
          }
        } else {
          //what if the object is empty?
          result.push(`${Object.keys(element)[0]}: ${Object.values(element)[0]}`)
        }
        break;
      case (typeof (()=>{})):
        result.push(element(42))
        break;
    }
  });

  if(result[0] == 0) result.shift();
  
  console.log(JSON.stringify(result));
} 

processData('[1,2,3,4]')

processData('["test", 1, "world", "42", 2]')

processData('[1, "123456789", [1, 2, [3, 4]], function(a) { return a; }, { "name": "Martin" }, 3, 4, 5, function(a) { return (a + 1)}]')


// console.log(Array.isArray([]))
// let arr = [1,2,3]
// let arr2 = [1,2,3]

// console.log(JSON.stringify(arr)==JSON.stringify(arr.flat()))
