const parse = str => {
  return Function(`return (${str})`)()
}

const grade = eq => {
  const arr = eq.split('=');
  let counter = 0;

  for (let i = 0; i < arr.length - 1; i++) {
    const left = arr[i];
    const right = arr[i+1];

    if (parse(left) === parse(right)) counter++;
  }

  return `${counter}/${arr.length-1}`
}

console.log(grade("7 - 3 * 2 + 1 = 4 * 2 + 1 = 8 + 1 = 9"))