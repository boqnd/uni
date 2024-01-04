import { DAO } from "../Dao.js";

class usersDao extends DAO {
  constructor() {
    super('users')
    this.init();
  }
}

export default new usersDao();