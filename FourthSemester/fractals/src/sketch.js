let lines;
let len;

function setup() {
  let cnv = createCanvas(windowWidth, windowHeight);
  len = windowWidth/3;
  lines = [];
  lines.push(new Side(new Point(windowWidth/3+len, windowHeight/3*2), new Point(windowWidth/3, windowHeight/3*2)));
  lines.push(new Side(lines[0].p2, new Point(lines[0].p2.x+lines[0].length/2, lines[0].p2.y - Math.sqrt(Math.pow(lines[0].length, 2) - Math.pow(lines[0].length/2, 2)))));
  lines.push(new Side(lines[1].p2, lines[0].p1));

  cnv.mouseClicked(step);
}

function draw() {
  background(60);
  stroke(255);
  lines.forEach(
    l => l.show()
    );
}

function step() {
  let newLines = [];

  lines.forEach(l => {
    let pt1 = new Point(l.p1.x+(l.p2.x-l.p1.x)/3,l.p1.y+(l.p2.y-l.p1.y)/3);
    let pt2 = new Point(l.p1.x+(l.p2.x-l.p1.x)/3*2,l.p1.y+(l.p2.y-l.p1.y)/3*2);
    let pt3 = new Point(((pt1.x+pt2.x) + Math.sqrt(3)*(pt2.y-pt1.y))/2,((pt2.y+pt1.y)+Math.sqrt(3)*(pt1.x-pt2.x))/2);
    newLines.push(new Side(l.p1, pt1));
    newLines.push(new Side(pt2, l.p2));
    newLines.push(new Side(pt1,pt3));
    newLines.push(new Side(pt3,pt2));
  });

  lines = newLines;
}

function Point(x, y) {
  this.x = x;
  this.y = y;
}

function Side(p1, p2) {
  this.p1 = p1;
  this.p2 = p2;
  this.length = Math.sqrt(Math.pow(Math.abs(p1.x-p2.x),2) + Math.pow(Math.abs(p1.y-p2.y), 2));

  this.show = () => {
    line(p1.x, p1.y, p2.x, p2.y);
  }
}