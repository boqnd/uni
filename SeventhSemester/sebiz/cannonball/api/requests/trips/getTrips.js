import tripsDao from "../../db/daos/tripsDao.js";

export let getTripsRoute = '/trips/getTrips';

export async function getTrips (req, res) {
  const trips = await tripsDao?.getAll();
  res.send(trips);
};