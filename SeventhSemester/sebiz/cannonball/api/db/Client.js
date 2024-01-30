import { MongoClient, ServerApiVersion, ObjectId } from 'mongodb';

const uri = "mongodb+srv://cannonball:cannonball@cannonball.gcvkcdq.mongodb.net/?retryWrites=true&w=majority";

// const uri = "mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+2.1.1";
export class Client {
  constructor() {
    this.client = new MongoClient(uri, {
      serverApi: {
        version: ServerApiVersion.v1,
        strict: true,
        deprecationErrors: true,
      }
    });
  }

  async connect() {
    try {
      await this.client.connect();
      const db = await this.client.db("cannonball");

      await db.command({ ping: 1 });
      // console.log("Pinged your deployment. You successfully connected to MongoDB!");

      return db;
    } catch (e) {
      console.dir(e);
    }
  }

  async disconnect() {
    await this.client.close();
  }
}