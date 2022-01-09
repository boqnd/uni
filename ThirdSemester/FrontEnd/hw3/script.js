const mealsList = document.getElementById("mealsList")
let recBtn
let closeBtn

const nameFilter = document.getElementById("filterName")
const regionFilter = document.getElementById("filterRegion")
const categoryFilter = document.getElementById("filterCategory")

function filter() {
  for(let i = 0; i < mealsList.children.length; i++) {
    if (mealsList.children[i].children[1].children[0].textContent.split(',')[1].includes(regionFilter.value) && mealsList.children[i].children[1].children[0].textContent.split(',')[0].includes(categoryFilter.value) && mealsList.children[i].children[0].children[1].textContent.includes(nameFilter.value)) {
      mealsList.children[i].classList.remove('display')
    } else {
      mealsList.children[i].classList.add('display')
    }
  }
}

regionFilter.addEventListener('keyup', event => {
  filter()
})

categoryFilter.addEventListener('keyup', event => {
  filter()
})

nameFilter.addEventListener('keyup', event => {
  filter()
})


async function getData() {
  let recepiesObj = await fetch("https://api.npoint.io/51ed846bdd74ff693d7e")

  let recepies = await recepiesObj.json()
  
  return recepies
}

function createLi() {
  getData().then(
    res => {
      for (let i = 0; i < res.meals.length; i++) {
        let td = ``
        for (let j = 0; j < res.meals[i].ingredients.length; j++) {
          td += 
            `
              <tr>
                <td>${res.meals[i].ingredients[j].name}</td>
                <td>${res.meals[i].ingredients[j].measure}</td>
              </tr>
            `
        }
        let li = 
        ` <li>
            <div class="left">
            <img src="${res.meals[i].image}" alt="pic">
            <p class="text">${res.meals[i].name}</p>
            </div>
            <div class="right">
            <p class="category">${res.meals[i].category}, ${res.meals[i].region}</p>
            <button class="rec">See recepe</button>
            </div>

            <div class="modal" style="visibility: hidden;">
            <header>
              <h1>${res.meals[i].name}</h1>
            </header>
            <img src="${res.meals[i].image}" alt="pic">
            <p>${res.meals[i].instruction}</p>
            <table>
              <tr>
                <th>Ingrediants</th>
                <th>Measure</th>
              </tr>
              ${td}
            </table>
            <footer>
              <button class="close">Close</button>
            </footer>
          </div>
          </li>`

        mealsList.innerHTML += li
      }
      recBtn = document.getElementsByClassName("rec")
      closeBtn = document.getElementsByClassName("close")


      for (let i = 0; i < recBtn.length; i++) {
        recBtn[i].addEventListener("click", function() {
          document.getElementById("dim").style.visibility = "visible"
          recBtn[i].parentElement.parentElement.children[2].style.visibility = "visible"
        })
      }

      for (let i = 0; i < closeBtn.length; i++) {
        closeBtn[i].addEventListener("click", function() {
          document.getElementById("dim").style.visibility = "hidden"
          recBtn[i].parentElement.parentElement.children[2].style.visibility = "hidden"
        })
      }
    }
  )
}

createLi()

