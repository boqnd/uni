import express from 'express';
import cors from 'cors';

import { createUser, createUserRoute } from './requests/auth/createUser.js';
import { getUsers, getUsersRoute } from './requests/auth/getUsers.js';
import { getUser, getUserRoute } from './requests/auth/getUser.js';
import { updateUser, updateUserRoute } from './requests/auth/updateUser.js';
import { login, loginRoute } from './requests/auth/login.js';
import { getTrips, getTripsRoute } from './requests/trips/getTrips.js';
import { getTrip, getTripRoute } from './requests/trips/getTrip.js';
import { createTrip, createTripRoute } from './requests/trips/createTrip.js';
import { getPosts, getPostsRoute } from './requests/posts/getPosts.js';
import { getPost, getPostRoute } from './requests/posts/getPost.js';
import { createPost, createPostRoute } from './requests/posts/createPost.js';
import { createOrder, createOrderRoute } from './requests/orders/createOrder.js';
import { getProduct, getProductRoute } from './requests/products/getProduct.js';
import { getProducts, getProductsRoute } from './requests/products/getProducts.js';
import { createProduct, createProductRoute } from './requests/products/createProduct.js';


const app = express();
const port = 4000;

app.use(cors());
app.use(express.json());

app.post(createUserRoute, createUser);
app.post(getUsersRoute, getUsers);
app.post(getUserRoute, getUser);
app.post(updateUserRoute, updateUser);
app.post(loginRoute, login);

app.post(getTripsRoute, getTrips);
app.post(getTripRoute, getTrip);
app.post(createTripRoute, createTrip);

app.post(getPostsRoute, getPosts);
app.post(getPostRoute, getPost);
app.post(createPostRoute, createPost);

app.post(createOrderRoute, createOrder);

app.post(getProductRoute, getProduct);
app.post(getProductsRoute, getProducts);
app.post(createProductRoute, createProduct);

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
