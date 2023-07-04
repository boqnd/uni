let debug = true;

function myDisplayer(some) {
 console.log(some)
}

let myPromise = new Promise(function(myResolve, myReject) {
  let x = 0;


  if (x == 0) {
    setTimeout(()=>{myResolve("OK")}, 10000);
  } else {
    myReject("Error");
  }
});

myPromise.then(
  function(value) {myDisplayer(value);},
  function(error) {myDisplayer(error);}
);