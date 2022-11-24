var http = require('http');
const url = require('url');

const serverObj = {
  test: "123",
  test2: "000"
}

const server = http.createServer(function (req, res) {
  var path = url.parse(req.url).pathname;
  var spl = path.split('/');

  if (spl.length === 3 && spl[1] === "load") {
    if (spl[2][0] === ":" && serverObj[spl[2].substring(1)]) {
      res.write(serverObj[spl[2].substring(1)]);
    } else {
      res.write("undefined");
    }
  }
  res.end();
});

server.listen(3000, () => {
  console.log("Listening server2...");
})