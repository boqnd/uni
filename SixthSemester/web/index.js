setTimeout(() => {
  // prints out "2", meaning that the callback is not called immediately after 500 milliseconds.
  for (let i = 0; i < 100; i++) {
    console.log('AAAAA');
  }
}, 500);

while (true) {
  console.log('test');
}