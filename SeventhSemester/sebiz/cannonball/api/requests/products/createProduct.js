import productsDao from "../../db/daos/procuctsDao.js";

export let createProductRoute = '/products/createProduct';

export async function createProduct (req, res) {
  const {name, description, price, image} = req.body;

  if (!name || !description || !price || !image) res.status(400).send('Invalid params');
  else {
      const product = await productsDao?.insert({name, description, price, image});
      res.send(product);
  }
};