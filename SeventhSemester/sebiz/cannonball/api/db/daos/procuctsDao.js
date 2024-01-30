import { DAO } from "../Dao.js";

class productsDao extends DAO {
  constructor() {
    super('products')
    this.init();
  }
}

export default new productsDao();