const fs = require("fs");
const { pipeline, Readable, Writable, Transform } = require('stream');

const testStream = fs.createReadStream('./test.txt', {highWaterMark: 10})

function createWritable(onCompleted) {
  const writableStream = new Writable();
  let allData = '';
  writableStream.write = function (chunk) {
    allData += chunk.toString();
  };
  writableStream.on('finish', () => {
    onCompleted(allData);
  });
  return writableStream;
}

function createTransform() {
  let data = '';

  const tStream = new Transform({
    transform(chunk, encoding, cb) {
      let text = chunk.toString().split('');
      let curr = '';

      text.forEach(l => {
        if (l === '\n') {
          curr += l;
          data += curr;
          curr = '';
        } else {
          curr += l;
        }
      });
      data = data.replace(/kur/, '***');
      cb(null, data);
      data = curr;
    }
  });

  return tStream;
}

const tStream = createTransform();

const ws = createWritable(allData => console.log(allData));

testStream.pipe(tStream).pipe(ws);