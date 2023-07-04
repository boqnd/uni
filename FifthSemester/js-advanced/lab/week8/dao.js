module.exports = () => {
  const db = new Map();

  function newId() {
    return db.size + "";
  }

  return {
    set(data) {
      let id = newId();
      db.set(id, {id, ...data});
      return db.get(id);
    },
    getAll() {
      return Array.from(db.values());
    },
    get(id) {
      return db.get(id);
    },
    delete(id) {
      let deleted = db.get(id);
      db.delete(id);
      return deleted;
    }
  }
}