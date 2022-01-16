const promise = new Promise ((resolve, reject) => {
  setTimeout(() => {
    reject()
    //resolve()
  }, 5000)
})
.then(() => {
  console.log("ready")
})
.catch(() => {
  console.log("down")
})

console.log(promise)