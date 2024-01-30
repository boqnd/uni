import ordersDao from "../../db/daos/ordersDao.js";
import usersDao from "../../db/daos/usersDao.js";

export let createOrderRoute = '/orders/createOrder';

export async function createOrder (req, res) {
  const { userId, name, email, address, products, transaction } = req.body;
  if (!userId || !name || !email || !address || !products || !transaction) res.status(400).send('Invalid params');
  else {
    const user = await usersDao?.getOne(userId);
    if (!user) res.status(400).send('User doesnt exist');
    else {
      const total = products.reduce((total, item) => total + item.quantity*item.price, 0).toFixed(2);
      const order = await ordersDao?.insert({userId, name, email, address, products, total, transaction});
      res.send(order);
    }
  }
};