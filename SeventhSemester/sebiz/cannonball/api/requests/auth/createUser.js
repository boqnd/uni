import bcrypt from 'bcrypt';
import usersDao from "../../db/daos/usersDao.js";

export let createUserRoute = '/auth/createUser';

async function hashPassword(password) {
  try {
    const salt = await bcrypt.genSalt(5);
    const hashedPassword = await bcrypt.hash(password, salt);
    return hashedPassword;
  } catch (error) {
    throw error;
  }
}

export async function createUser (req, res) {
  const {username, password} = req.body;
  if (!username || !password) res.status(400).send('Invalid params');
  else {
    const old = await usersDao?.getAll({username});
    if (old.length) res.status(400).send('Username taken');
    else {
      const hashedPassword = await hashPassword(password);

      const user = await usersDao?.insert({username, password: hashedPassword});
      res.send(user);
    }
  }
};