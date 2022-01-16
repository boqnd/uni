// const actions = document.getElementsByClassName("wrapper")[0];
const input = document.getElementsByClassName("input")[0];
const operation = document.getElementsByClassName("operation")[0];
const operationNumber = document.getElementsByClassName("operation-number")[0];
const operationActive = document.getElementsByClassName("operation-active")[0];
const operationButtons = document.getElementsByClassName("orange");
const history = document.getElementsByClassName("calculation-list")[0];
let item;

window.addEventListener('load', () => {
  for(let i = 0; i < localStorage.length; i++) {
    item = document.createElement("li");
    item.textContent = localStorage.getItem(i);
    history.appendChild(item);
  }
});

document.addEventListener("click", event => {
  const element = event.target;

  if (element.classList.contains('action')) {
    if(element.classList.length == 1 || (element.classList.contains('zero') && element.classList.length == 2)) {
      if (input.value == 0) {
        if(element.textContent != '.') {
          input.value = element.textContent;
        }
      } else {
        if (operationActive.textContent == '1') {
          input.value = element.textContent;
          operationActive.textContent = '0';
        } else {
          input.value += element.textContent;
        }
      }
    } else if (element.classList.contains('action-btn')) {
      switch (element.textContent) {
        case 'C': 
          input.value = 0;
          for (let i = 0; i < operationButtons.length; i++) {
            operationButtons[i].classList.remove("operationSelect");
          }
          operation.textContent = '';
          operationNumber.textContent = '';
          operationActive.textContent = '0';
          break;
        case '√':
          localStorage.setItem(`${localStorage.length}`, `√${input.value} = ${Math.sqrt(input.value)}`);
          item = document.createElement("li");
          item.textContent = localStorage.getItem(localStorage.length-1);
          history.appendChild(item);
          input.value = Math.sqrt(input.value);
          for (let i = 0; i < operationButtons.length; i++) {
            operationButtons[i].classList.remove("operationSelect");
          }
          operation.textContent = '';
          operationNumber.textContent = '';
          operationActive.textContent = '1';
          break;
        case 'n2':
          localStorage.setItem(`${localStorage.length}`, `${input.value}^2 = ${input.value*input.value}`);
          item = document.createElement("li");
          item.textContent = localStorage.getItem(localStorage.length-1);
          history.appendChild(item);
          input.value *= input.value;
          for (let i = 0; i < operationButtons.length; i++) {
            operationButtons[i].classList.remove("operationSelect");
          }
          operation.textContent = '';
          operationNumber.textContent = '';
          operationActive.textContent = '1';
          break;
        default:
          break;
      }
    } else if(element.classList.contains('orange') && element.classList.length == 2) {
      for (let i = 0; i < operationButtons.length; i++) {
        operationButtons[i].classList.remove("operationSelect");
      }

      switch (element.textContent) {
        case '÷':
          operation.textContent = '÷';
          operationNumber.textContent = input.value;
          operationActive.textContent = '1';
          element.classList.add("operationSelect");
          break;
        case '×':
          operation.textContent = '×';
          operationNumber.textContent = input.value;
          operationActive.textContent = '1';
          element.classList.add("operationSelect");
          break;
        case '−':
          operation.textContent = '−';
          operationNumber.textContent = input.value;
          operationActive.textContent = '1';
          element.classList.add("operationSelect");
          break;
        case '+':
          operation.textContent = '+';
          operationNumber.textContent = input.value;
          operationActive.textContent = '1';
          element.classList.add("operationSelect");
          break;
        case '=':
          switch (operation.textContent) {
            case '÷':
              localStorage.setItem(`${localStorage.length}`, `${operationNumber.textContent} ÷ ${input.value} = ${Number(operationNumber.textContent) / Number(input.value)}`);
              item = document.createElement("li");
              item.textContent = localStorage.getItem(localStorage.length-1);
              history.appendChild(item);
              input.value = Number(operationNumber.textContent) / Number(input.value);
              break;
            case '×':
              localStorage.setItem(`${localStorage.length}`, `${operationNumber.textContent} * ${input.value} = ${Number(operationNumber.textContent) * Number(input.value)}`);
              item = document.createElement("li");
              item.textContent = localStorage.getItem(localStorage.length-1);
              history.appendChild(item);
              input.value *= operationNumber.textContent;
              break;
            case '−':
              localStorage.setItem(`${localStorage.length}`, `${operationNumber.textContent} - ${input.value} = ${Number(operationNumber.textContent) - Number(input.value)}`);
              item = document.createElement("li");
              item.textContent = localStorage.getItem(localStorage.length-1);
              history.appendChild(item);
              input.value = Number(operationNumber.textContent) - Number(input.value);
              break;
            case '+':
              localStorage.setItem(`${localStorage.length}`, `${operationNumber.textContent} + ${input.value} = ${Number(operationNumber.textContent) + Number(input.value)}`);
              item = document.createElement("li");
              item.textContent = localStorage.getItem(localStorage.length-1);
              history.appendChild(item);
              input.value = Number(input.value) + Number(operationNumber.textContent);
              break;
            default:
              break;
          }
          operation.textContent = '';
          operationNumber.textContent = '';
          operationActive.textContent = '1';
        break;
        default:
          break;
      }
    }
  } else if (element.classList.contains('clear')) {
    console.log(localStorage)
    localStorage.clear();
  }
})