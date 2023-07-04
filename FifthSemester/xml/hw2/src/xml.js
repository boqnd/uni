function createXMLDocument() {
  let documentImplementation = document.implementation;
  let doc = documentImplementation.createDocument(null, null);
  var pi = doc.createProcessingInstruction("xml",
      "version= \"1.0\"encoding=\"UTF-8\"");
  doc.appendChild(pi);

  let vet_clinic = doc.createElement("vet_clinic");
  doc.appendChild(vet_clinic);


  let client = doc.createElement("client");
  client.setAttribute('id', 'c1');

  let full_name = doc.createElement("full_name");
  full_name.appendChild(doc.createTextNode('Boyan'));
  client.appendChild(full_name);

  let address = doc.createElement("address");
  address.appendChild(doc.createTextNode('Sofia'));
  client.appendChild(address);

  let phone = doc.createElement("phone");
  phone.appendChild(doc.createTextNode('0881234567'));
  client.appendChild(phone);

  let animal = doc.createElement("animal");
  animal.setAttribute('id', 'a1');
  animal.setAttribute('client_id', 'c1');

  let name = doc.createElement("name");
  name.appendChild(doc.createTextNode('Bau'));
  animal.appendChild(name);

  let type = doc.createElement("type");
  type.appendChild(doc.createTextNode('Dog'));
  animal.appendChild(type);

  let breed = doc.createElement("breed");
  breed.appendChild(doc.createTextNode('Street'));
  animal.appendChild(breed);

  let age = doc.createElement("age");
  age.appendChild(doc.createTextNode('Street'));
  animal.appendChild(age);

  let examination = doc.createElement("examination");
  examination.setAttribute('id', 'e1');
  examination.setAttribute('id', 'a1');

  let description = doc.createElement("description");
  description.appendChild(doc.createTextNode('Grooming'));
  examination.appendChild(description);

  let price = doc.createElement("price");
  price.appendChild(doc.createTextNode(60));
  examination.appendChild(price);

  vet_clinic.appendChild(client);
  vet_clinic.appendChild(animal);
  vet_clinic.appendChild(examination);

  return doc;
}