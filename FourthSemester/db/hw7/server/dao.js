const ibmdb = require('ibm_db');
const connStr = "DATABASE=SAMPLE;HOSTNAME=62.44.108.24;UID=db2admin;PWD=db2admin;PORT=50000;";

let query = (query) => {
  return ibmdb.open(connStr).then(
    conn => {
      return conn.query(query).then(data => {
        conn.closeSync();
        return data;
      }, err => {
        console.log(err);
      });
    }, err => {
      console.log(err);
    }
  )
}

module.exports.getAnimals = () => {
  return query("SELECT * FROM FN72029.Animals;");
}

module.exports.getLocations = () => {
  return query("SELECT * FROM FN72029.Locations;");
}

module.exports.getConsumables = () => {
  return query("SELECT * FROM FN72029.Consumables;");
}

module.exports.getClients = () => {
  return query("SELECT * FROM FN72029.Clients;");
}

module.exports.getExaminations = () => {
  return query("SELECT * FROM FN72029.Examinations;");
}

module.exports.createLocation = (name, address) => {
  return query(`INSERT INTO FN72029.Locations (name, address) VALUES ('${name}', '${address}');`);
}

module.exports.createConsumable = (name, quantity, price, location) => {
  return query(`INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('${name}', ${quantity}, ${price}, ${location});`);
}

module.exports.createClient = (name, phone_number, address) => {
  return query(`INSERT INTO FN72029.Clients (name, phone_number, address) VALUES ('${name}', '${phone_number}', '${address}');`);
}

module.exports.createAnimal = (name, type, breed, age, owner) => {
  return query(`INSERT INTO FN72029.Animals (name, type, breed, age, owner) VALUES ('${name}', '${type}', '${breed}', ${age}, ${owner});`);
}

module.exports.createExamination = (animal, location, description, price) => {
  return query(`INSERT INTO FN72029.Examinations (animal, location, description, price) VALUES (${animal}, ${location},'${description}', ${price});`);
}

module.exports.deleteExamination = (id) => {
  return query(`DELETE FROM FN72029.Examinations WHERE id = ${id}`);
}