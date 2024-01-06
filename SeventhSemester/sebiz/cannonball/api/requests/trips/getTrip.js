import tripsDao from "../../db/daos/tripsDao.js";

export let getTripRoute = '/trips/getTrip/:id';

export async function getTrip (req, res) {
  const id = req.params['id'];
  const trip = await tripsDao?.getOne(id);
  res.send(trip);
};