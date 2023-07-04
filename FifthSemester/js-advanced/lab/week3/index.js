console.log("Start")


function Point(x, y) {
  this.x = x;
  this.y = y;
}

Point.prototype.getDistance = function (p2) {
  return Math.sqrt(((p2.x - this.x) ** 2) + ((p2.y - this.y) ** 2));
}

function Circle (x, y, r) {
  Point.call(this, x, y);

  this.r = r;
}

Circle.prototype = Object.create(Point.prototype)

Circle.prototype.getCircumference = function () {
  return Math.PI*2*this.r;
}

Circle.prototype.getArea = function () {
  return Math.PI*this.r**2;
}

var p = new Point(1,2);
var p2 = new Point(4,8);
console.log(p.getDistance(p2));

var c = new Circle(1,1,1);
var c2 = new Circle(1,2,1);
console.log(c.getDistance(c2));
console.log(c.getCircumference());
console.log(c.getArea());



