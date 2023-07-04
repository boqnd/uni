const express = require('express');
const bodyParser = require('body-parser')
var https = require('https');
const fs = require('fs');

const app = express();
app.use(bodyParser.json());

var coditions = {};

function stringToRegex(s, m) {
  return (m = s.match(/^([\/~@;%#'])(.*?)\1([gimsuy]*)$/)) ? new RegExp(m[2], m[3].split('').filter((i, p, s) => s.indexOf(i) === p).join('')) : new RegExp(s);
}

function loadConditions() {
  var data = fs.readFileSync("./conditions.json");
  if (data) {
    data = JSON.parse(data);
    conditions = data;
  }
}

function sanitize(data) {
  if (!conditions.conditions) {
    return data;
  }

  conditions.conditions.forEach(condition => {
    if (condition.condition) {
      data = data.replace(stringToRegex(condition.condition), '');
    }
  });

  return data;
}

//'https://www.reddit.com/.rss'
app.get('/sanitize', (req, res) => {
  const url = req.query.url;
  if (url) {
    try {
      https.get(url, (resp) => {
        let data = '';
  
        resp.on('data', (chunk) => {
          data += chunk;
        });
  
        resp.on('end', () => {
          data = sanitize(data);

          console.log(data);
          res.send('OK')
        });
      })
    } catch (error) {
      res.send('Invalid URL')
    }
  } else {
    res.send('No URL')
  }
})

/*{
	"id": 5,
	"condition": "/title/g"
}*/
app.post('/condition', (req, res) => {
  const body = req.body;

  if (!conditions.conditions) {
    res.send('No conditions');
    return;
  }

  if(body.id && body.condition) {
    const condition = {id: body.id, condition: body.condition};
    var validId = true;

    conditions.conditions.forEach(condition => {
      if (validId && condition.id === body.id) {
        validId = false;
        res.send('invalid id');
      }
    });

    if (validId) {
      conditions.conditions.push(condition);

      fs.writeFile ("./conditions.json", JSON.stringify(conditions), () => {
        console.log('done');
      });
  
      res.json(condition);
    }
  } else {
    res.send('invalid body');
  }
})

app.delete('/condition/:id', (req, res) => {
  const id = req.params.id;

  if (id) {
    if (!conditions.conditions) {
      res.send('No conditions');
      return;
    }
    conditions.conditions = conditions.conditions.filter(c => c.id != id);

    fs.writeFile ("./conditions.json", JSON.stringify(conditions), () => {
      console.log('done');
    });

    res.send('ok');
  } else {
    res.send('no id')
  }
})

app.listen(8000, () => {
  loadConditions();
  console.log("listening..");
})