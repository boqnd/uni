const fieldElement = document.getElementById("field");
const listElement = document.querySelector("#task-list");

fieldElement.addEventListener("change", event => {
  const task = document.createElement("li")

  task.innerHTML = `
    <input type="checkbox"/>
    <span> ${event.target.value} </span>
    <button class="delete-btn">X</button> 
  `
  event.target.value = ""

  listElement.appendChild(task);
})

listElement.addEventListener("change", event => {
  const chackboxElement = event.target;
  const spanElement = chackboxElement.parentElement.querySelector("span");
  spanElement.classList.toggle("line-through", chackboxElement.checked);//???
})

listElement.addEventListener("click", event => {
  const element = event.target;

  if (element.classList.contains('delete-btn')) {
    const listElement = element.parentElement;
    const list = listElement.parentElement;

    list.removeChild(listElement);
  }
})


