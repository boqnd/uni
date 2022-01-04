function processData(input) {
  let table = {}

  for (let i = 0; i < input.length; i++) {
    if (table[input[i].toLowerCase()] == undefined) {
      table[input[i].toLowerCase()] = 0
    } else {
      table[input[i].toLowerCase()]++
    }
  }
  let values = Object.values(table).sort()
  let table2 = {}

  if (values[0] == values[values.length - 1]) {
    console.log('GOOD')
  } else {
    for (let i = 0; i < values.length; i++) {
      if (table2[values[i]] == undefined) {
        table2[values[i]] = 0
      } else {
        table2[values[i]]++
      }
    }

    if (Object.values(table2).length == 2) {
      if (Object.values(table2).includes(0) || Math.abs(Object.values(table2)[0]-Object.values(table2)[1] == 1)) {
        console.log('BAD')
      } else {
        console.log('UGLY')
      }
    } else {
      console.log('UGLY')
    }
  }
  
  
  // else if(values[0] == values[values.length - 2]) {
  //   if (values[0] == values[values.length - 1]-1) {
  //     console.log('BAD')
  //   } else {
  //     console.log('UGLY')
  //   }
  // } else if(values[1] == values[values.length - 1]) {
  //   if (values[0]+1 == values[1]) {
  //     console.log('BAD')
  //   } else {
  //     console.log('UGLY')
  //   }
  // } else {
  //   console.log('UGLY')
  // }
}

processData('ggghhhmmmdddlll')
processData('gghmmmdddll')
processData('asfdgf')
processData('')
processData('GgHH')
processData('abbcc')
processData('aBA')
processData('kaabbccc')
processData('v')

// processData('')
// processData('a')
// processData('A')
// processData('')
// processData('')
// processData('')
// processData('')




