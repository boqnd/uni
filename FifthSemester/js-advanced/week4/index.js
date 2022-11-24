const fs = require("fs");

function Student() {
  this.setName = (name) => {
    this.name = name;
  }
  this.setFn = (fn) => {
    this.fn = fn;
  }
}
const students = [];

fs.readFile("./Students.txt", 'utf-8', (err, data) => {
  const lines = data.split('\n');

  lines.forEach(line => {
    if (line[0] !== '#') {
      var lineData = line.split(' ');
      var s = new Student();
      s.setFn(lineData.pop());
      s.setName(lineData.join(' '));
      students.push(s);
      console.log(s)
    }
  });

  fs.readFile("./Marks.txt", 'utf-8', (err, data) => {
    const lines = data.split('\n');
  
    lines.forEach(line => {
      if (line[0] !== '#') {
        var lineData = line.split(' ');
        var s = new Student();
        s.setFn(lineData.pop());
        s.setName(lineData.join(' '));
        students.push(s);
        console.log(s)
      }
    });
  })
})