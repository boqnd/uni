var http = require('http');

const app = () => {
  const handlers = [];

  const server = http.createServer(function (req, res) {
    const path = req.url;
    const method = req.method;

    handlers.forEach(handler => {
      if (path == handler.path && method == handler.method) {
        handler.handler(req,res);
      }
    });

    res.end();
  });

  return {
    get(path, handler) {
      handlers.push({path, handler, method: 'GET'});
    },
    post() {
      handlers.push({path, handler, method: 'POST'});
    },
    put() {
      handlers.push({path, handler, method: 'PUT'});
    },
    delete() {
      handlers.push({path, handler, method: 'DELETE'});
    },
    listen(port, cb) {
      server.listen(port, cb);
    }
  }
}

module.exports = app;