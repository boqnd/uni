async function getClients() {
  let response = await fetch("http://127.0.0.1:3000/clients")

  return response.json();
}

async function getAnimals() {
  let response = await fetch("http://127.0.0.1:3000/animals")

  return response.json();
}

async function getLocations() {
  let response = await fetch("http://127.0.0.1:3000/locations")

  return response.json();
}

async function getConsumables() {
  let response = await fetch("http://127.0.0.1:3000/consumables")

  return response.json();
}

async function getExaminations() {
  let response = await fetch("http://127.0.0.1:3000/examinations")

  return response.json();
}

function loadClients() {
  getClients().then(res => {
    let table = document.getElementById("clients");

    res.forEach(el => {
      let row = document.createElement("tr");

      let id = document.createElement("td");
      let name = document.createElement("td");
      let phone = document.createElement("td");
      let address = document.createElement("td");

      id.appendChild(document.createTextNode(el.ID))
      name.appendChild(document.createTextNode(el.NAME))
      phone.appendChild(document.createTextNode(el.PHONE_NUMBER))
      address.appendChild(document.createTextNode(el.ADDRESS))

      row.appendChild(id)
      row.appendChild(name)
      row.appendChild(phone)
      row.appendChild(address)

      table.appendChild(row)
    })
  })
}

function loadAnimals() {
  getAnimals().then(res => {
    let table = document.getElementById("animals");

    res.forEach(el => {
      let row = document.createElement("tr");

      let id = document.createElement("td");
      let name = document.createElement("td");
      let type = document.createElement("td");
      let breed = document.createElement("td");
      let age = document.createElement("td");
      let owner = document.createElement("td");

      id.appendChild(document.createTextNode(el.ID))
      name.appendChild(document.createTextNode(el.NAME))
      type.appendChild(document.createTextNode(el.TYPE))
      breed.appendChild(document.createTextNode(el.BREED))
      age.appendChild(document.createTextNode(el.AGE))
      owner.appendChild(document.createTextNode(el.OWNER))

      row.appendChild(id)
      row.appendChild(name)
      row.appendChild(type)
      row.appendChild(breed)
      row.appendChild(age)
      row.appendChild(owner)

      table.appendChild(row)
    })
  })
}

function loadConsumables() {
  getConsumables().then(res => {
    let table = document.getElementById("consumables");

    res.forEach(el => {
      let row = document.createElement("tr");

      let id = document.createElement("td");
      let name = document.createElement("td");
      let quantity = document.createElement("td");
      let price = document.createElement("td");
      let location = document.createElement("td");

      id.appendChild(document.createTextNode(el.ID))
      name.appendChild(document.createTextNode(el.NAME))
      quantity.appendChild(document.createTextNode(el.QUANTITY))
      price.appendChild(document.createTextNode(el.PRICE))
      location.appendChild(document.createTextNode(el.LOCATION))

      row.appendChild(id)
      row.appendChild(name)
      row.appendChild(quantity)
      row.appendChild(price)
      row.appendChild(location)

      table.appendChild(row)
    })
  })
}

function loadExaminations() {
  getExaminations().then(res => {
    let table = document.getElementById("examinations");

    res.forEach(el => {
      let row = document.createElement("tr");

      let id = document.createElement("td");
      let animal = document.createElement("td");
      let location = document.createElement("td");
      let description = document.createElement("td");
      let price = document.createElement("td");

      id.appendChild(document.createTextNode(el.ID))
      animal.appendChild(document.createTextNode(el.ANIMAL))
      location.appendChild(document.createTextNode(el.LOCATION))
      description.appendChild(document.createTextNode(el.DESCRIPTION))
      price.appendChild(document.createTextNode(el.PRICE))

      row.appendChild(id)
      row.appendChild(animal)
      row.appendChild(location)
      row.appendChild(description)
      row.appendChild(price)

      table.appendChild(row)
    })
  })
}

function loadLocations() {
  getLocations().then(res => {
    let table = document.getElementById("locations");

    res.forEach(el => {
      let row = document.createElement("tr");

      let id = document.createElement("td");
      let name = document.createElement("td");
      let address = document.createElement("td");

      id.appendChild(document.createTextNode(el.ID))
      name.appendChild(document.createTextNode(el.NAME))
      address.appendChild(document.createTextNode(el.ADDRESS))

      row.appendChild(id)
      row.appendChild(name)
      row.appendChild(address)

      table.appendChild(row)
    })
  })
}