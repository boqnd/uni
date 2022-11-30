var myExpress = require('./myExpress');

const app = myExpress();

app.get('/hui', (req,res) => {res.write('HUI')})

app.listen(8080, () => {console.log("Listening...")})