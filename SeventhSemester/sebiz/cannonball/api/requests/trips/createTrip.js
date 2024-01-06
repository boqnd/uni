import tripsDao from "../../db/daos/tripsDao.js";

export let createTripRoute = '/trips/createTrip';

export async function createTrip (req, res) {
  const {startLocation, endLocation} = req.body;
  if (!startLocation || !endLocation) res.status(400).send('Invalid params');
  else {
    const old = await tripsDao?.getAll({startLocation, endLocation});
    if (old.length) res.status(400).send('Trip exists');
    else {
      const trip = await tripsDao?.insert({startLocation, endLocation});
      res.send(trip);
    }
  }
};