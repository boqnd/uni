const express = require('express')
const app = express()
const port = 3000
const bodyParser = require('body-parser')
const dao = require('./dao');
let cors = require("cors");

app.use(cors());
app.use(bodyParser.json());

app.get('/animals', (req, res) => {
  dao.getAnimals().then(response => {
    console.log("GET /animals")
    console.log(response)
    console.log('--')
    if(response) {
      res.json(response)
    } else {
      res.status(400).send("Database error")
    }
  })
})

app.get('/locations', (req, res) => {
  dao.getLocations().then(response => {
    console.log("GET /locations")
    console.log(response)
    console.log('--')
    if(response) {
      res.json(response)
    } else {
      res.status(400).send("Database error")
    }
  })
})

app.get('/consumables', (req, res) => {
  dao.getConsumables().then(response => {
    console.log("GET /consumables")
    console.log(response)
    console.log('--')
    if(response) {
      res.json(response)
    } else {
      res.status(400).send("Database error")
    }
  })
})

app.get('/clients', (req, res) => {
  dao.getClients().then(response => {
    console.log("GET /clients")
    console.log(response)
    console.log('--')
    if(response) {
      res.json(response)
    } else {
      res.status(400).send("Database error")
    }
  })
})

app.get('/examinations', (req, res) => {
  dao.getExaminations().then(response => {
    console.log("GET /examinations")
    console.log(response)
    console.log('--')
    if(response) {
      res.json(response)
    } else {
      res.status(400).send("Database error")
    }
  })
})

app.post('/location', (req, res) => {
  let name = req.body.name
  let location = req.body.location

  if (name && location) {
    dao.createLocation(name, location).then(response => {
      console.log("POST /location")
      console.log(response)
      console.log('--')
      if(response) {
        res.json(response)
      } else {
        res.status(400).send("Database error")
      }
    })
  } else {
    res.status(400).send("Invalid arguments")
  }
})

app.post('/consumable', (req, res) => {
  let name = req.body.name
  let quantity = req.body.quantity
  let price = req.body.price
  let location = req.body.location

  if (name && quantity && price && location) {
    dao.createConsumable(name, quantity, price, location).then(response => {
      console.log("POST /consumable")
      console.log(response)
      console.log('--')
      if(response) {
        res.json(response)
      } else {
        res.status(400).send("Database error")
      }
    })
  } else {
    res.status(400).send("Invalid arguments")
  }
})

app.post('/client', (req, res) => {
  let name = req.body.name
  let phone_number = req.body.phone_number
  let address = req.body.address

  if (name && phone_number && address) {
    dao.createClient(name, phone_number, address).then(response => {
      console.log("POST /client")
      console.log(response)
      console.log('--')
      if(response) {
        res.json(response)
      } else {
        res.status(400).send("Database error")
      }
    })
  } else {
    res.status(400).send("Invalid arguments")
  }
})

app.post('/animal', (req, res) => {
  let name = req.body.name
  let type = req.body.type
  let breed = req.body.breed
  let age = req.body.age
  let owner = req.body.owner

  if (name && type && breed && age && owner) {
    dao.createAnimal(name, type, breed, age, owner).then(response => {
      console.log("POST /animal")
      console.log(response)
      console.log('--')
      if(response) {
        res.json(response)
      } else {
        res.status(400).send("Database error")
      }
    })
  } else {
    res.status(400).send("Invalid arguments")
  }
})

app.post('/examination', (req, res) => {
  let animal = req.body.animal
  let location = req.body.location
  let description = req.body.description
  let price = req.body.price

  if (animal && location && description && price) {
    dao.createExamination(animal, location, description, price).then(response => {
      console.log("POST /examination")
      console.log(response)
      console.log('--')
      if(response) {
        res.json(response)
      } else {
        res.status(400).send("Database error")
      }
    })
  } else {
    res.status(400).send("Invalid arguments")
  }
})

app.delete('/examinations/:id', (req, res) => {
  let id = req.params.id;

  dao.deleteExamination(id).then(response => {
    console.log("DELETE /examination")
    console.log(response)
    console.log('--')
    if(response) {
      res.json(response)
    } else {
      res.status(400).send("Database error")
    }
  })
})



app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})