import usersDao from "../../db/daos/usersDao.js";

export let getUsersRoute = '/auth/getUsers';

export async function getUsers (req, res) {
  const users = await usersDao?.getAll();
  res.send(users);
};