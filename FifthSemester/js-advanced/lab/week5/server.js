var http = require('http');
var https = require('https');
const url = require('url');

const server = http.createServer(function (req, res) {
  const queryObject = url.parse(req.url, true).query;
  const target = queryObject.url
  // res.writeHead(200, { 'Content-Type': 'text/html' });

  if (target) {
    https.get('https://www.reddit.com/.rss', (resp) => {
      let data = '';

      resp.on('data', (chunk) => {
        data += chunk;
      });

      resp.on('end', () => {
        res.write(data);
        res.end();
      });
    })
  } else {
    res.end();
  }
});



server.listen(3000, () => {
  console.log("Listening server...");
})