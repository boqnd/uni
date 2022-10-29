console.log('start');

let list = [7,2,1,6,8,5,3,4];
let sorted = [1,2,3,4,5,6,7,8];
let oneEl = [1];
let rad = [132, 543, 783, 63, 7, 49, 898];


const swap = (list, a, b) => {
  let temp = list[a];
  list[a] = list[b];
  list[b] = temp;
}

const quickSort = list => {
  if (list.length === 2) {
    if (list[0] > list[1]) {
      swap(list,0,1);
    }
    return list;
  }

  if (list.length === 1) return list;

  let pivot = list[list.length-1];
  let pointer = -1;

  for (let i = 0; i < list.length - 1; i++) {
    const element = list[i];

    if (pointer === -1) {
      if (element > pivot) {
        pointer = i
      };
    } else {
      if (element < pivot) {
        swap(list, i, pointer);
        pointer = i;
      }
    }
  }

  let pivotIndx = list.length-1;
  for (let i = list.length - 2; i >= 0; i--) {
    if (list[i] > list[pivotIndx]) {
      swap(list, i, pivotIndx)
      pivotIndx = i;
    } else {
      break;
    }
  }

  return pivotIndx === list.length-1 ? quickSort(list.slice(0, pivotIndx)).concat([pivot]) : quickSort(list.slice(0, pivotIndx)).concat([pivot]).concat(quickSort(list.slice(pivotIndx+1)));
}

const toArr = (num, maxLen) => {
  let res = [];
  let counter = 0;
  while (num > 0) {
    res.push(num % 10);
    num = Math.floor(num/10);
    counter++;
  }
  while (counter < maxLen) {
    res.push(0);
    counter++;
  }
  return res;
}

function radixSortHelper(arr, c){
  for(var i = 0; i < arr.length; i++){
    for(var j = 0; j < ( arr.length - i -1 ); j++){
      if(arr[j][c] > arr[j+1][c]){
        var temp = arr[j][c]
        arr[j][c] = arr[j + 1][c]
        arr[j+1][c] = temp
      }
    }
  }
}

const radixSort = list => {
  let maxLen = Math.max(...list).toString().length;

  let helper = list.map(x => toArr(x, maxLen));

  console.log(helper);

  for (let i = 0; i < maxLen; i++) {
    radixSortHelper(helper, i);
  }

  console.log(helper);
}

console.log(radixSort(rad));




