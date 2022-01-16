// 1 zadacha
var person = {
  _salary: 1000,
  getSecretSalaryInfo: function (){
    return this._salary;
  }
};

var stoleSalaryInfo = person.getSecretSalaryInfo;

console.log(person.getSecretSalaryInfo()); //принтира 1000
console.log(stoleSalaryInfo.call(person)); //принтира undefined

// 2 zadacha

class Person {
  
  constructor(name) {
    this.name = name;
    this.planet = 'Земя';
  }
  
  printPerson = function() {
    console.log(`Здравей ${this.name} от планетата ${this.planet}`);
  }
};


var p1 = new Person("FMI1");
var p2 = new Person("FXF");
var p3 = new Person("FMI41321");

p1.printPerson();
p2.printPerson();
p3.printPerson();

// 3 zadacha

class Item {
  constructor(name, discount) {
    this.name = name;
    this.discount = discount;
    //this.price = 1000
  }

  calculatePrice = function(price) {
    return this.price - (this.price * (this.discount / 100)); 
  }
}

Item.prototype.price = 1000;

var it = new Item("item", 50);

console.log(it.calculatePrice());

// 4 zadacha  
function privatePerson() {
  let _salary = 1000;
  this.getSecretSalaryInfo = function (){
    return _salary;
  }
}

let privateP = new privatePerson();
console.log(privateP.getSecretSalaryInfo());


class PaymentMethod {
  getAmount() {
    return "Your amount in the account is: ";
  }
}

class CashMethod extends PaymentMethod {
  constructor() {
    super();
    let amount = 0;

    this.getAmount = () => super.getAmount() + amount;
    this.addToAmount = (newAmount) => amount += newAmount;
    this.reduceFromAmount = (reduceAmount) => amount -= reduceAmount;
  }
}

class CreditMethod extends PaymentMethod {
  constructor() {
    super();
    let amount = 0;
    const PERCENT = 90/100;

    this.getAmount = () => super.getAmount() + amount;
    this.addToAmount = (newAmount) => amount += newAmount*PERCENT;
    this.reduceFromAmount = (reduceAmount) => amount -= reduceAmount;
  }
}






let p = new CashMethod();
p.addToAmount(200)
console.log(p.getAmount())
p.addToAmount(300)
console.log(p.getAmount())

let pp = new CreditMethod();
pp.addToAmount(200)
console.log(pp.getAmount())
pp.addToAmount(300)
console.log(pp.getAmount())

function F() {
  let a = 0;
  function get() {
    return a;
  }

  return function add() {
    add += 10;
  }
}

let f = F();

console.log(f)