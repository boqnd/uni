async function countries() {
  const res = await fetch('https://restcountries.com/v2/all')

  return res.json()
}

console.log (countries())
