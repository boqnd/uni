import productsDao from "../../db/daos/procuctsDao.js";

export let getProductsRoute = '/products/getProducts';

export async function getProducts (req, res) {
  const products = await productsDao?.getAll();
  res.send(products);
};