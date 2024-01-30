import productsDao from "../../db/daos/procuctsDao.js";

export let getProductRoute = '/products/getProduct/:id';

export async function getProduct (req, res) {
  const id = req.params['id'];
  const product = await productsDao?.getOne(id);
  res.send(product);
};