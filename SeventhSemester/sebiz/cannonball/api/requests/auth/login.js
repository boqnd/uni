import bcrypt from 'bcrypt';
import usersDao from "../../db/daos/usersDao.js";

export let loginRoute = '/auth/login';

async function comparePasswords(plainPassword, hashedPassword) {
  try {
    const isMatch = await bcrypt.compare(plainPassword, hashedPassword);
    return isMatch;
  } catch (error) {
    throw error;
  }
}

export async function login (req, res) {
  const {username, password} = req.body;
  if (!username || !password) res.status(400).send('Invalid params');
  else {
    const user = await usersDao?.getAll({username});
    if (user.length !== 1) res.status(400).send('Invalid credentials');
    else {
      const hashedPassword = user[0].password;
      const isPasswordMatch = await comparePasswords(password, hashedPassword);

      if (!isPasswordMatch) res.status(400).send('Invalid credentials');
      else {
        // TODO: token?
        res.send(user)
      };
    }
  }
};