import { DAO } from "../Dao.js";

class postsDAO extends DAO {
  constructor() {
    super('posts')
    this.init();
  }
}

export default new postsDAO();