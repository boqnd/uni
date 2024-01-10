import { DAO } from "../Dao.js";

class ordersDao extends DAO {
  constructor() {
    super('orders')
    this.init();
  }
}

export default new ordersDao();