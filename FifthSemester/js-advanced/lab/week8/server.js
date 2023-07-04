const express = require('express');
const bodyParser = require('body-parser');
const dao = require('./dao');

const PORT = 8080;
const app = express();
const events = dao();
const bookings = dao();

app.use(bodyParser.json());

app.post('/event', (req, res) => {
  const body = req.body;
  let inserted = {};

  if( body.name && body.capacity ) {
    let obj = {
      name: body.name,
      capacity: body.capacity
    };

    inserted = events.set(obj);
  }

  res.json(inserted);
});

app.get('/event/:id', (req, res) => {
  const params = req.params;
  const event = events.get(params.id) || {};

  res.json(event);
});

app.delete('/event/:id', (req, res) => {
  const params = req.params;
  const event = events.delete(params.id) || {};

  res.json(event);
});

app.post('/event/:id/booking', (req, res) => {
  const params = req.params;
  const event = events.get(params.id);
  const body = req.body;
  let inserted = {};

  //TODO: capacity check.
  if (event && body.firstName && body.lastName) {
    let obj = {
          eventId: event.id,
          firstName: body.firstName,
          lastName: body.lastName
        };

    inserted = bookings.set(obj);
  }

  res.json(inserted);
});

app.get('/event/:id/booking', (req, res) => {
  const params = req.params;
  const event = events.get(params.id);
  const bookingsFromEvent = []

  if (event) {
    const eventId = event.id;
    const bookingsArr = bookings.getAll();

    bookingsArr.forEach(booking => {
      if (booking.eventId === eventId) {
        bookingsFromEvent.push(booking);
      }
    })
  }

  res.send(bookingsFromEvent);
});

app.get('/event/:id/booking/:bookingId', (req, res) => {
  const params = req.params;
  const event = events.get(params.id);
  var booking = {}

  if (event) {
    const eventId = event.id;
    const bookingsArr = bookings.getAll();

    bookingsArr.forEach(b => {
      if (b.eventId === eventId && b.id === params.bookingId) {
        booking = b;
      }
    })
  }

  res.send(booking);
});

app.delete('/event/:id/booking/:bookingId', (req, res) => {
  const params = req.params;
  const event = events.get(params.id);
  var booking = {}

  if (event) {
    const eventId = event.id;
    const bookingsArr = bookings.getAll();

    bookingsArr.forEach(b => {
      if (b.eventId === eventId && b.id === params.bookingId) {
        booking = b;
      }
    })
  }

  if (booking.id) {
    bookings.delete(booking.id);
  }

  res.send(booking);
});

app.listen(PORT, () => {
  console.log(`Listening on ${PORT}...`);
});