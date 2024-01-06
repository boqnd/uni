import { DAO } from "../Dao.js";

class tripsDao extends DAO {
  constructor() {
    super('trips')
    this.init();
  }
}

export default new tripsDao();