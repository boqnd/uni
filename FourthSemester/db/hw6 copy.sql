SET SCHEMA FN72029;

INSERT INTO FN72029.Locations (name, address) VALUES ('Sofia', 'addr1');
INSERT INTO FN72029.Locations (name, address) VALUES ('Plovdiv', 'addr2');
INSERT INTO FN72029.Locations (name, address) VALUES ('Varna', 'addr3');
INSERT INTO FN72029.Locations (name, address) VALUES ('Pernik', 'addr4');

INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog food', 5, 2, 1);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog food', 10, 2, 2);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog food', 2, 2, 3);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('cat food', 6, 3, 1);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('cat food', 14, 3, 2);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('cat food', 7, 3, 3);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('cat food', 12, 3, 4);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog pills', 8, 15, 1);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog pills', 5, 15, 2);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog pills', 7, 15, 3);
INSERT INTO FN72029.Consumables (name, quantity, price, location) VALUES ('dog pills', 5, 15, 4);

INSERT INTO FN72029.Clients (name, phone_number, address) VALUES ('Ivan', '088888888', 'addr1');
INSERT INTO FN72029.Clients (name, phone_number, address) VALUES ('Georgi', '0899999999', 'addr2');
INSERT INTO FN72029.Clients (name, phone_number, address) VALUES ('Boyan', '0777777777', 'addr3');

INSERT INTO FN72029.Animals (name, type, breed, age, owner) VALUES ('dogo', 'dog', 'golden', 7, 1);
INSERT INTO FN72029.Animals (name, type, breed, age, owner) VALUES ('dari', 'dog', 'street', 1, 3);
INSERT INTO FN72029.Animals (name, type, breed, age, owner) VALUES ('lori', 'cat', 'street', 9, 2);

INSERT INTO FN72029.Examinations (animal, location, description, price) VALUES (1,1,'burz pregled', 50);
INSERT INTO FN72029.Examinations (animal, location, description, price) VALUES (2,1,'golyam pregled', 100);
INSERT INTO FN72029.Examinations (animal, location, description, price) VALUES (3,3,'sreden pregled', 80);

CREATE VIEW ClientAnimals
    AS
        SELECT c.name as Client, a.name as animal
        FROM Clients c, Animals a
        WHERE c.id = a.owner;

CREATE VIEW AnimalExamination
    AS
        SELECT e.description as Examination, a.name as animal
        FROM Examinations e, Animals a
        WHERE e.animal = a.id;