import postsDao from "../../db/daos/postsDao.js";

export let getPostsRoute = '/posts/getPosts';

export async function getPosts (req, res) {
  const posts = await postsDao?.getAll();
  res.send(posts);
};