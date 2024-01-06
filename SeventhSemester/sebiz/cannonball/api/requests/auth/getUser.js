import usersDao from "../../db/daos/usersDao.js";

export let getUserRoute = '/auth/getUser/:id';

export async function getUser (req, res) {
  const id = req.params['id'];
  const user = await usersDao?.getOne(id);
  res.send(user);
};