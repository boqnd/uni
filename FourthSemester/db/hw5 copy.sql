SET SCHEMA FN72029;

CREATE TABLE Locations (
    id integer NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1) PRIMARY KEY,
    name VARCHAR(25),
    address VARCHAR(25)
);

CREATE TABLE Consumables (
    id integer NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1) PRIMARY KEY,
    name VARCHAR(25),
    quantity double,
    price double,
    location integer NOT NULL,
    FOREIGN KEY (location) references Locations(id)
);

CREATE TABLE Clients (
    id integer NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1) PRIMARY KEY,
    name VARCHAR(25),
    phone_number varchar(13),
    address VARCHAR(25)
);

CREATE TABLE Animals (
    id integer NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1) PRIMARY KEY,
    name VARCHAR(25),
    type VARCHAR(25),
    breed VARCHAR(25),
    age integer,
    owner integer NOT NULL,
    FOREIGN KEY (owner) references Clients(id)
);

CREATE TABLE Examinations (
    id integer NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1) PRIMARY KEY,
    animal integer NOT NULL,
    location integer NOT NULL,
    description VARCHAR(100),
    price double,
    FOREIGN KEY (animal) references Animals(id),
    FOREIGN KEY (location) references Locations(id)
);