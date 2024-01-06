import postsDao from "../../db/daos/postsDao.js";
import usersDao from "../../db/daos/usersDao.js";
import tripsDao from "../../db/daos/tripsDao.js";

export let createPostRoute = '/posts/createPost';

export async function createPost (req, res) {
  const {userId, startLocation, endLocation, tripTime, comment} = req.body;

  if (!userId || !startLocation || !endLocation || !tripTime || !comment) res.status(400).send('Invalid params');
  else {
    const user = await usersDao?.getOne(userId);
    if (!user) res.status(400).send('User doesnt exist');
    else {
      const trips = await tripsDao?.getAll({startLocation, endLocation});
      let trip;

      if (trips.length === 0) {
        try {
          const newTrip = await tripsDao?.insert({startLocation, endLocation});
          trip = await tripsDao?.getOne(newTrip.insertedId);
        } catch (e) {
          return res.status(400).send('Trip err');
        }
      } else {
        trip = trips[0];
      }

      const tripId = trip._id;
      const timeCreated = Date.now();

      const post = await postsDao?.insert({userId, tripId, timeCreated, tripTime, comment});
      res.send(post);
    }
  }
};