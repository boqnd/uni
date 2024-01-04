import {Client} from './Client.js'
import { ObjectId } from 'mongodb';

export class DAO {

  constructor(collectionName) {
    this.client = new Client;
    this.collectionName = collectionName;
  }

  async init() {
    const db = await this.client.connect()
    this.collection = db.collection(this.collectionName);
  }

  async getAll(params) {
    return await this.collection.find(params).toArray();
  }

  async getOne(id) {
    try {
      const oid = new ObjectId(id);
      return await this.collection.findOne(oid);
    } catch {
      console.dir("Invalid id")
    }
  }

  async insert(data) {
    return await this.collection.insertOne(data);
  }
}