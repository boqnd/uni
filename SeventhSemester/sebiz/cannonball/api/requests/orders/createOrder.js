import ordersDao from "../../db/daos/ordersDao.js";
import usersDao from "../../db/daos/usersDao.js";

export let createOrderRoute = '/orders/createOrder';

export async function createOrder (req, res) {
  const { userId, name, email, address, products } = req.body;
  if (!userId || !name || !email || !address || !products) res.status(400).send('Invalid params');
  else {
    const user = await usersDao?.getOne(userId);
    if (!user) res.status(400).send('User doesnt exist');
    else {
      const order = await ordersDao?.insert({userId, name, email, address, products});
      res.send(order);
    }
  }
};